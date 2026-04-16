cmake_minimum_required(VERSION 3.10)
project(ImageSharedMemory LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED)

add_executable(main src/main.cpp)
target_include_directories(main PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(main PRIVATE rt pthread)

#add_executable(reader src/reader.cpp)
#target_include_directories(reader PRIVATE ${Boost_INCLUDE_DIRS})
#target_link_libraries(reader PRIVATE rt pthread)
