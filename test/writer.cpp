#include <iostream>

#include "../src/common.hpp"
#include "test_structs.hpp"

int main(){
  std::cout << "hello world, writer" << std::endl;

  SharedMemory<Position> shm("Position_info", true);

  std::cout << "writer ran" << std::endl;
  return 0;
}
