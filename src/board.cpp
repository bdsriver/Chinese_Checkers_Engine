#include "board.h"
#include <cstdint>



// '<int>' is the player's pieces
// ' ' is an empty space
char startBoard[BOARD_DIM][BOARD_DIM] = {
  {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', 0 ,' ',' ',' ',' '},
  {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', 0 , 0 ,' ',' ',' ',' '},
  {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ', 0 , 0 , 0 ,' ',' ',' ',' '},
  {' ',' ',' ',' ',' ',' ',' ',' ',' ', 0 , 0 , 0 , 0 ,' ',' ',' ',' '},
  {' ',' ',' ',' ', 1 , 1 , 1 , 1 ,' ',' ',' ',' ',' ', 5 , 5 , 5 , 5 },
  {' ',' ',' ',' ', 1 , 1 , 1 ,' ',' ',' ',' ',' ',' ', 5 , 5 , 5 ,' '},
  {' ',' ',' ',' ', 1 , 1 ,' ',' ',' ',' ',' ',' ',' ', 5 , 5 ,' ',' '},
  {' ',' ',' ',' ', 1 ,' ',' ',' ',' ',' ',' ',' ',' ', 5 ,' ',' ',' '},
  {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
  {' ',' ',' ', 2 ,' ',' ',' ',' ',' ',' ',' ',' ', 4 ,' ',' ',' ',' '},
  {' ',' ', 2 , 2 ,' ',' ',' ',' ',' ',' ',' ', 4 , 4 ,' ',' ',' ',' '},
  {' ', 2 , 2 , 2 ,' ',' ',' ',' ',' ',' ', 4 , 4 , 4 ,' ',' ',' ',' '},
  { 2 , 2 , 2 , 2 ,' ',' ',' ',' ',' ', 4 , 4 , 4 , 4 ,' ',' ',' ',' '},
  {' ',' ',' ',' ', 3 , 3 , 3 , 3 ,' ',' ',' ',' ',' ',' ',' ',' ',' '},
  {' ',' ',' ',' ', 3 , 3 , 3 ,' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
  {' ',' ',' ',' ', 3 , 3 ,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '},
  {' ',' ',' ',' ', 3 ,' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}
};

bool inBounds[BOARD_DIM][BOARD_DIM] = {
  {false,false,false,false,false,false,false,false,false,false,false,false,true ,false,false,false,false},
  {false,false,false,false,false,false,false,false,false,false,false,true ,true ,false,false,false,false},
  {false,false,false,false,false,false,false,false,false,false,true ,true ,true ,false,false,false,false},
  {false,false,false,false,false,false,false,false,false,true ,true ,true ,true ,false,false,false,false},
  {false,false,false,false,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true },
  {false,false,false,false,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,false},
  {false,false,false,false,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,false,false},
  {false,false,false,false,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,false,false,false},
  {false,false,false,false,true ,true ,true ,true ,true ,true ,true ,true ,true ,false,false,false,false},
  {false,false,false,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,false,false,false,false},
  {false,false,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,false,false,false,false},
  {false,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,false,false,false,false},
  {true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,true ,false,false,false,false},
  {false,false,false,false,true ,true ,true ,true ,false,false,false,false,false,false,false,false,false},
  {false,false,false,false,true ,true ,true ,false,false,false,false,false,false,false,false,false,false},
  {false,false,false,false,true ,true ,false,false,false,false,false,false,false,false,false,false,false},
  {false,false,false,false,true ,false,false,false,false,false,false,false,false,false,false,false,false}
};