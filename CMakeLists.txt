cmake_minimum_required(VERSION 3.17.0)

project(DataStructuresAndAlgorithms)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(DataStructuresAndAlgorithms ${SOURCES})
