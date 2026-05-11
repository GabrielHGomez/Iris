#include <iostream>
#include <csignal>
#include <atomic>
#include <chrono>
#include <thread>
#include <random>
#include "../src/common.hpp"
#include "test_structs.hpp"

std::atomic<bool> running{true};

void handle_signal(int)
{
  running = false;
}

int main(){
  std::signal(SIGINT, handle_signal);
  std::signal(SIGTERM, handle_signal);

  SharedMemory<Random> random_shm("Random_info", true);

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(0,100);
  

  while(running){
    random_shm->random_val = dist(gen);
    std::cout << dist(gen) << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;
}
