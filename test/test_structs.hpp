#pragma once
#include <array>
#include <string>

struct Coordinates{
  std::array<int, 2> xy;
};

struct Person{
  char name[32];
  int age;
  std::array<int, 2> height;
  float weight;
};

struct Position{
  int x;
  int y;
};

struct Random{
  volatile int random_val;
};
