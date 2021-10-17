cmake_minimum_required(VERSION 3.20)
project(Polaris)

set(CMAKE_CXX_STANDARD 20)

if (APPLE)
find_library(COCOA_LIBRARY Cocoa)
endif()

add_library(polaris Library/Window.h Library/Darwin/Window.mm Library/Game.h Library/Darwin/Game.mm)

if (APPLE)
target_link_libraries(polaris ${COCOA_LIBRARY})
endif()

add_executable(polaris-testing Testing/main.cpp)

include_directories(Library)

target_link_directories(polaris-testing PUBLIC ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
target_link_libraries(polaris-testing polaris)