#include <iostream>
#include "test_structs.hpp"
#include "../src/common.hpp"

int main(){
  SharedMemory<Position> shm("Position_info", false);
  return 0;
}
