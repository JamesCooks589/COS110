#include "RandomGenerator.h"

RandomGenerator::RandomGenerator(int seed){
    srand(seed);
}

bool RandomGenerator::randomBool(){
  int i = rand();
  if (i % 2 == 0)
  {
    return false;
  }
  else
  {
    return true;
  }
  
  
  

}