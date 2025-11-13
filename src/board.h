#pragma once

#include <cstdint>
#include <unordered_map>
#include <utility>

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