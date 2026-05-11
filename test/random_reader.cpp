#include <iostream>
#include <csignal>
#include <atomic>
#include <chrono>
#include <thread>
#include "test_structs.hpp"
#include "../src/common.hpp"

std::atomic<bool> running{true};
void handle_signal(int) {running = false;}

int main(){
  std::signal(SIGINT, handle_signal);
  std::signal(SIGTERM, handle_signal);

  SharedMemory<Random> random_shm("Random_info", false);

  //Random rand = *random_shm;

  while(running){
  
	  std::cout << "random_val = " << random_shm->random_val << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
  return 0;
}
