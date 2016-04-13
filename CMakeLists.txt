cmake_minimum_required(VERSION 3.3)
project(AssignmentB)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp motionar.cpp motionar.h professionell.cpp professionell.h deltagare.cpp deltagare.h register.cpp register.h)
add_executable(AssignmentB ${SOURCE_FILES})