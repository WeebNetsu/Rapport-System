cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(COMPILE_FLAGS "-L/usr/include/mariadb/mysql -lmariadbclient")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${COMPILE_FLAGS} -std=c++14")

project(school_rapport)

add_executable(
  output
  main.cpp
  Student.hpp
  Student.cpp
  Database.hpp
  Database.cpp
)
