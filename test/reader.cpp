#include <iostream>
#include "test_structs.hpp"
#include "../src/common.hpp"

int main(){
  SharedMemory<Position> shm("Position_info", false);
  SharedMemory<Person> person_shm("Person_info" , false);
  Position pos = *shm;
  Person person = *person_shm;
  std::cout << "pos x = " << pos.x << "pos y = " << pos.y << std::endl; 

  std::cout << "name = " << person.name << "\n" 
	    << "age = " << person.age << "\n"
	    << "wight = " << person.weight << "\n"
	    << "height = " << person.height[0] << " " << person.height[1] << "\n";
  return 0;
}
