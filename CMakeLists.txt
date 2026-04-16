cmake_minimum_required(VERSION 3.10)
project(ImageSharedMemory LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED)

add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(test)
