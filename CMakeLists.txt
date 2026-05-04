cmake_minimum_required(VERSION 3.10)
project(ImageSharedMemory LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED)
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.15.2
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(external)
add_subdirectory(src)
add_subdirectory(test)
