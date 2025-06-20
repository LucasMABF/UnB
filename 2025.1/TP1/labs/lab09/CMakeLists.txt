cmake_minimum_required(VERSION 3.10)
project(Lab09)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./../bin)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories("src")

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(Lab09 ${SOURCES})

add_executable(asan-target ${SOURCES})
target_compile_options(asan-target PRIVATE -fsanitize=address)
target_link_options(asan-target PRIVATE -fsanitize=address)

