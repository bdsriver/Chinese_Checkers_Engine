#include <iostream>
#include "board.h"
#include "transpositionTable.h"
#include "eval.h"
#include <unordered_map>
#include <vector>
#include <utility>
#include <cstdint>
#include <string>
#include <algorithm>

int main(){
  setMovesAndJumps();
  __uint128_t occupied = boardToOccupiedBitboard(startBoard);
  std::vector<__uint128_t> pieces = pieceVectorToBitboards(startPoints);
  printBoard(startBoard);
  float startEval = posEval(startPoints, 0,0);
  std::cout << "Start Position Eval: " << startEval << std::endl;
  

  SearchResult s = Search(&occupied,&pieces,SearchNode(-500,500,startEval,0,0,6));
  std::cout << s.bestMove.first << ',' << s.bestMove.second << ':' << s.eval << std::endl;
  std::cout << "Moves: ";
  for (auto m:s.hist){
    std::cout << m.first << ',' << m.second << ' ';
  }
  std::cout << std::endl;
  

}