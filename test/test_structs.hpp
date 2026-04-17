#pragma once
#include <array>
#include <string>

struct Coordinates{
  std::array<int, 2> xy;
};

struct Person{
  std::string name;
  int age;
  std::array<int, 2> height;
  float weight;
};
