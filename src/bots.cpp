#include "bots.h"
#include <string>

int depthForDifficulty(std::string difficulty){
  if (difficulty == "easy"){
    return 0;
  }
  else if ( difficulty == "medium")
  {
    return 1;
  }
  else if (difficulty == "hard"){
    return 3;
  }
  else{
    return 0;
  }
  

}