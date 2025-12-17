#pragma once

#include "eval.h"

//search for best move at a position with threads
SearchResult threadSearch(__uint128_t occupied, std::vector<__uint128_t> pieces, float currEval,int depth,
  int turnPlayer);