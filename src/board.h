#pragma once

#include <cstdint>
#include <unordered_map>
#include <utility>
#include <vector>

#define PLAYER_AMOUNT 6
#define BOARD_DIM 17
#define PLAYER_PIECE_AMOUNT 10
#define SPACE_AMOUNT 121

extern char startBoard[][BOARD_DIM];
extern bool inBounds[][BOARD_DIM];
extern std::unordered_map<int, std::pair<int,int>> bitToIndices;
extern std::unordered_map<int, __uint128_t> moves;
extern std::unordered_map<int, __uint128_t> jumps;

//refer to diagram for mapping explanation
//must be called to set the global moves and jumps tables
void setMovesAndJumps();

//copy the original onto the copy
void copyBoard(char original[][BOARD_DIM], char copy[][BOARD_DIM]);

//return a vector of {space1, space2} pairs
//occupied is a bitboard of piece locations on the board
//pieces is a map of {<0-9>,<piece location>} for the player's piece
std::vector<std::pair<int,int>> generateMoves(char board[][BOARD_DIM], __uint128_t occupied, std::vector<int> pieces);

// return a vector with the locations of each piece
std::vector<int> initPieces(char board[][BOARD_DIM], char playerID);

// return the bitboard that represents if a piece is at each space
__uint128_t boardToOccupiedBitboard(char board[][BOARD_DIM]);