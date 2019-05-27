cmake_minimum_required(VERSION 3.14)
project(cpp_simple_class)

set(CMAKE_CXX_STANDARD 14)

add_executable(mycomplex mycomplex/mycomplex.h mycomplex/test_mycomplex.cpp)
add_executable(mystring mystring/mystring.h mystring/test_mystring.cc)