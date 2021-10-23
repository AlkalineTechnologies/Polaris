cmake_minimum_required(VERSION 3.20)
project(Polaris)

set(CMAKE_CXX_STANDARD 20)

add_library(polaris Library/Window.h Library/Game.h Library/Component.h Library/Script.h Library/Object.h)

if (APPLE)
    target_sources(polaris PUBLIC Library/Darwin/Game.mm Library/Darwin/Window.mm)
    find_library(LIBRARY Cocoa)
elseif(WIN32)
    target_sources(polaris PUBLIC Library/Windows/Window.cpp Library/Windows/Window.cpp)
    find_library(LIBRARY user32)
elseif(UNIX AND NOT APPLE)
    target_sources(polaris PUBLIC Library/Linux/Game.cpp Library/Linux/Window.cpp)
    find_library(LIBRARY xcb)
endif()

target_link_libraries(polaris ${LIBRARY})

add_executable(polaris-testing Testing/main.cpp)

include_directories(Library)

target_link_directories(polaris-testing PUBLIC ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
target_link_libraries(polaris-testing polaris)