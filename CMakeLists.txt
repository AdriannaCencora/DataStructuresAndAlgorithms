cmake_minimum_required(VERSION 3.15.7)

project(DataStructuresAndAlgorithms)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(DataStructuresAndAlgorithms ${SOURCES})
