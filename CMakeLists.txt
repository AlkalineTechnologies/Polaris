cmake_minimum_required(VERSION 3.20)
project(Polaris)

set(CMAKE_CXX_STANDARD 20)

if (APPLE)
find_library(LIBRARY Cocoa)
elseif(WIN32)
    find_library(LIBRARY user32)
endif()

add_library(polaris Library/Window.h Library/Darwin/Window.mm Library/Game.h Library/Darwin/Game.mm Library/Windows/Game.cpp Library/Component.h Library/Script.h Library/Object.h Library/Windows/Window.cpp)

target_link_libraries(polaris ${LIBRARY})

add_executable(polaris-testing Testing/main.cpp)

include_directories(Library)

target_link_directories(polaris-testing PUBLIC ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
target_link_libraries(polaris-testing polaris)