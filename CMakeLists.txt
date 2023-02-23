cmake_minimum_required(VERSION 3.16)
project(pclt CXX)

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_STANDARD 20)
# set include dir to ./core
include_directories(core)

file(GLOB_RECURSE SOURCE_FILES "./core/*.cpp")
file(GLOB_RECURSE HEADER_FILES "./core/*.h")

add_executable(pclt ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(pclt curl zip)
