cmake_minimum_required(VERSION 3.10)
project(Esercitazione10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Eigen3 REQUIRED)

add_executable(test_cg main.cpp)

target_link_libraries(test_cg Eigen3::Eigen)