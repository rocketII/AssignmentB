cmake_minimum_required(VERSION 3.3)
project(AssignmentB)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp  StringInstrument.h StringInstrument.cpp AirInstrument.cpp AirInstrument.h Instrument.cpp Instrument.h register.cpp register.h system.h system.cpp )# test.cpp
add_executable(AssignmentB ${SOURCE_FILES})