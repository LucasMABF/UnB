cmake_minimum_required(VERSION 3.10)
project(Lab01)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./../bin)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(Lab01 ${SOURCES})

