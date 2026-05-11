#include <iostream>
#include <csignal>
#include <atomic>
#include <chrono>
#include <thread>

#include "test_structs.hpp"
#include "../src/common.hpp"

std::atomic<bool> running {true};
void handle_signal(int) {running = false;}

int main(){
  std::signal(SIGINT, handle_signal);
  std::signal(SIGTERM,handle_signal);

  SharedMemory<Position> shm("Position_info", false);
  SharedMemory<Person> person_shm("Person_info" , false);
  Position pos = *shm;
  Person person = *person_shm;

  while(running){

  std::cout << "pos x = " << pos.x << "pos y = " << pos.y << std::endl; 

  std::cout << "name = " << person.name << "\n" 
	    << "age = " << person.age << "\n"
	    << "wight = " << person.weight << "\n"
	    << "height = " << person.height[0] << " " << person.height[1] << "\n";

  std::this_thread::sleep_for(std::chrono::milliseconds(100));
		  
  }
  return 0;
}
