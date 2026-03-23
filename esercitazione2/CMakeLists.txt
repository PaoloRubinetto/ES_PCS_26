cmake_minimum_required(VERSION 3.10)
project(Esercitazione2_PCS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

add_executable(es1 es1.cpp)
add_executable(es2 es2.cpp)