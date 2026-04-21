#include <iostream>

#include "../src/common.hpp"
#include "test_structs.hpp"

int main(){
  std::cout << "hello world, writer" << std::endl;

  SharedMemory<Position> shm("Position_info", true);
  SharedMemory<Person> person_shm("Person_info", true);

  shm->x = 1;
  shm->y = 1;

  person_shm->age = 12;
  person_shm->weight = 225.5;
  person_shm->height = {5,11};
  std::snprintf(person_shm->name, sizeof(person_shm->name), "%s", "Billy");
  while(true){

  }
  return 0;
}
