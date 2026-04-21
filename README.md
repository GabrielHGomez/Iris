WIP

This is a small C++ header-only library for sharing structs between processes using Boost.Interprocess.

Building
cmake -B build
cmake --build build

Running
In one terminal:
./build/src/writer

In another terminal:
./build/src/reader

Dependencies
-CMake 3.16
-Boost
-C++17

TODO
-Add synchronization
-Add Unit Test
-Build Better Examples
-Build up the header more
