cmake_minimum_required(VERSION 3.10)
project(Lab04)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./../bin)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(Lab04 ${SOURCES})

