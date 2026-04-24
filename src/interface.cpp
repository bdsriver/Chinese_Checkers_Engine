#include <string>
#include <cstdint>
#include <vector>
#include <sstream>
#include <iostream>

#include "interface.h"
#include "board.h"
#include "eval.h"
#include "transpositionTable.h"
#include "bots.h"

bool getBoardFromString(std::string input, __uint128_t* board, std::vector<__uint128_t>* pieces,
  int* startPlayerAmount, int* currPlayerAmount, int* currentPlayer, std::string* difficulty, std::string* errorMsg){

  std::stringstream ss(input);
  std::string startPlayerAmountString, currentPlayerString, currPlayerAmountString;
  
  //VALIDATE THIS
  getline(ss, *difficulty, ' ');

  try{
    getline(ss, startPlayerAmountString,' ');
    *startPlayerAmount = std::stoi(startPlayerAmountString);
    if (*startPlayerAmount < 1 || (*startPlayerAmount > 4 && *startPlayerAmount != 6)){
      throw "Invalid Original Player Amount";
    }
  }
  catch(...){
    *errorMsg = "Invalid Original Player Amount";
    return false;
  }

  try{
    getline(ss, currPlayerAmountString,' ');
    *currPlayerAmount = std::stoi(currPlayerAmountString);
    if (*currPlayerAmount < 1 || (*currPlayerAmount > 4 && *currPlayerAmount != 6)){
      throw "Invalid Current Player Amount";
    }
  }
  catch(...){
    *errorMsg = "Invalid Current Player Amount";
    return false;
  }

  try{
    getline(ss, currentPlayerString,' ');
    *currentPlayer = std::stoi(currentPlayerString);
    if (*currentPlayer < 0 || *currentPlayer >= *startPlayerAmount){
      throw "Invalid Current Turn";
    }
  }
  catch(...){
    *errorMsg = "Invalid Current Turn";
    return false;
  }


  std::string positionString, idString;
  int8_t ids = 0;
  for (int i=0; i< *startPlayerAmount; i++){
    pieces->push_back(0);
  }
  try{
    for (int i=0; i< *currPlayerAmount; i++){
      //Get player id
      getline(ss, idString, ' ');
      int id = std::stoi(idString);
      if (id < 0 || id >= *startPlayerAmount){
        throw "Invalid Piece Locations";
      }
      //Check if this player has already been put in input
      if (ids & ((__uint8_t)1 << id)){
        throw "Invalid Piece Locations";
      }
      ids = ids | ((uint8_t)1 << id);
      
      //Get piece locations
      for (int j=0; j<PLAYER_PIECE_AMOUNT; j++){
        getline(ss, positionString, ' ');

        int position = std::stoi(positionString);

        if (position < 0 || position >= SPACE_AMOUNT){
          throw "Invalid Piece Locations";
        }
        //setting bit <position> of the value
        pieces->at(id) =  pieces->at(id) | ((__uint128_t)1 << position);

        //Check if the bit is already set (no 2 pieces on same spot)
        if (*board & ((__uint128_t)1 << position) ){
          throw "Invalid Piece Locations";
        }

        *board = *board | ((__uint128_t)1 << position);
      }
    }
  }
  catch(...){
    *errorMsg = "Invalid Piece Locations";
    return false;
  }
  //Check if the player whose turn it is has pieces
  if (pieces->at(*currentPlayer) == 0){
    *errorMsg = "No pieces given for turn player";
    return false;
  }
  return true;
}

void engineLoop(){
  std::string err, difficulty;
  int currPlayers, currTurn, startPlayers;
  __uint128_t board = 0;
  std::string input;
  std::uint64_t hash;

  Hash::initPieceVals(pieceHashValue);
  Hash::initPlayerVals(playerHashValue);

  while(input != "quit"){
    board = 0;
    std::vector<__uint128_t> pieces;

    getline(std::cin, input);
    if (!std::cin.good()) {
      return;
    }
    if (input == "quit"){
      continue;
    }
    bool valid = getBoardFromString(input,&board, &pieces, &startPlayers, &currPlayers, &currTurn, &difficulty, &err);
    if (!valid){
      std::cout << err << std::endl;
      continue;
    }
    

    setMovesAndJumps(startPlayers);
    hash = Hash::initHash(pieces, playersInGame, currTurn);
    
    
    int depth = depthForDifficulty(difficulty);
    SearchNode n = SearchNode(-500, 500, 0, currTurn, currTurn, depth, hash);
    TranspositionTable t = TranspositionTable();
    SearchResult r = ignorantSearch(&board, &(pieces[currTurn]),n, &t);
    
    makeMove(&(pieces[currTurn]), r.bestMove);
    printBoardState(currTurn, &pieces);

  }

}

void printBoardState(int currTurn, std::vector<__uint128_t>* pieces){
  //Check if the move won the game for the player
  bool done = playerIsDone(currTurn, pieces->at(currTurn));

  if (done){
    std::cout << currTurn;
  }
  else{
    std::cout << "-1";
  }
  
  //print all piece locations 
  for (int i=0; i<playersInGame; i++){
    if (pieces->at(i) == 0){
      //skip players out of the game
      continue;
    }

    std::cout << ':' << i;
    uint64_t low = (uint64_t)(pieces->at(i));
    uint64_t high = (uint64_t)(pieces->at(i) >> 64);
    while (low){
      int trailing_zeros = __builtin_ctzll(low);//supported by gcc
      low &= low-1; //clear that set bit
      std::cout << ' ' << trailing_zeros;
    }
    while (high){
      int trailing_zeros = __builtin_ctzll(high)+64;//add 64 for high address
      high &= high-1;
      std::cout << ' ' << trailing_zeros;
    }
  }
  std::cout << std::endl;
  return;
}

int main(){
  engineLoop();
  return 0;
}

// Tests 
/*
int main(){

  std::string input = "hard 2 2 1 0 120 111 112 113 114 115 116 117 118 119 1 0 1 2 3 4 31 6 7 8 9";
  std::string err, difficulty;
  int players, curr, start;
  __uint128_t board = 0;
  std::vector<__uint128_t> pieces;
  bool result = getBoardFromString(input,&board, &pieces, &start, &players, &curr, &difficulty, &err);
  if (result){
    setMovesAndJumps(start);
    std:: uint64_t hash = Hash::initHash(pieces, playersInGame, curr);
    

    int depth = 2;
    SearchNode n = SearchNode(-500, 500, posEval(&pieces,curr), curr, curr, depth, hash);
    TranspositionTable t = TranspositionTable();
    SearchResult r = ignorantSearch(&board, &(pieces[curr]),n, &t);
    
    makeMove(&(pieces[curr]), r.bestMove);
    printBoardState(curr,&pieces);
  }
  else{
    std::cout << err << std::endl;
  }
  return 0;
}
*/
