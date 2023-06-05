cmake_minimum_required(VERSION 3.25)
project(lart_common)

set(CMAKE_CXX_STANDARD 20)

include_directories(include ${CGAL_INCLUDE_DIRECTORIES})
find_package(CGAL REQUIRED)

add_library(lart_common SHARED src/Cone.cpp src/Path.cpp src/Point.cpp src/State.cpp)
target_link_libraries(lart_common ${CGAL_LIBRARIES})

