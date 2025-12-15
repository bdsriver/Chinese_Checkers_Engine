#include <iostream>
#include "board.h"
#include "transpositionTable.h"
#include "eval.h"
#include <unordered_map>
#include <vector>
#include <utility>
#include <cstdint>

int main(){
  setMovesAndJumps();
  std::vector<int> myPieces = initPieces(startBoard,3);
  __uint128_t occupied = boardToOccupiedBitboard(startBoard);
  std::vector<std::pair<int,int>> myMoves = generateMoves(occupied,myPieces);
  
  for (auto m:myMoves){
    int from = m.first;
    int to = m.second;
    std::cout << from << ',' << to << std::endl;
  }
  // to check if bit is set while in debug console: 
  // p (bool)(occupied & ((__uint128_t)1 << bit))
  int myPiece = 111;
  makeMove(&occupied,myMoves[0],&myPiece);
  unMakeMove(&occupied,myMoves[0],&myPiece);

  std::vector<std::vector<int>> pieces = startPoints;
  std::cout << eval(pieces, 0,0) << std::endl;
  

}