project(main)
cmake_minimum_required(VERSION 3.22)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../bin)

find_package(SFML 2.5 
  COMPONENTS 
    system window graphics network audio REQUIRED)

add_executable(main main.cpp Circle.cpp Root.cpp Enemy.cpp)

include_directories(${CMAKE_SOURCE_DIR}/../Include)

target_link_libraries(main sfml-graphics)