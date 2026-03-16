#pragma once

#include <string>
#include <cstdint>
#include <vector>

// Return true or false based on if the input string represents a board
// If true, set the appropriate variables to board value and piece bitboard vector
// input string: <difficulty> <original player amount (1-6)> <current player amount> <current turn (0-5)> <player id> <10 space separated positions for player id>...
// pieces vector must be empty
// difficulty as defined in documentation
bool getBoardFromString(std::string input, __uint128_t* board, std::vector<__uint128_t>* pieces,
      int* startPlayerAmount, int* currPlayerAmount, int* currentPlayer, std::string* difficulty, std::string* errorMsg);

// continually takes input and prints either an error or the best move of the position
// input is defined in the getBoardFromString Function
// output as defined in documentation
void engineLoop();

// Print Colon Separated groups
// The first group is an integer that indicates if a player won. -1 if not, else it is the id of the player (0-5)
// The rest: The first number is the player id (0-5) and the next 10 are positions of the player's pieces
void printBoardState(int currTurn, std::vector<__uint128_t>* pieces);