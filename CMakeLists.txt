cmake_minimum_required(VERSION 3.19)
project(simple_chess)

include_directories("/images/")

set(CMAKE_CXX_STANDARD 14)
find_package(SFML 2.5.1 COMPONENTS system graphics audio network REQUIRED)
add_executable (simple-chess "main.cpp" Test.cpp Test.h)
target_link_libraries(simple-chess  PRIVATE sfml-audio sfml-graphics sfml-network sfml-system)


