cmake_minimum_required(VERSION 3.12)

project(school_rapport LANGUAGES CXX)

add_executable(
    output
    Database.cpp
    Student.cpp
    PythonCode.cpp
    main.cpp
)

set_target_properties(output PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

find_package(Python3 COMPONENTS Development.Embed REQUIRED)

find_path(MYSQL_INCLUDE_DIR 
  NAMES
  mysql.h
  PATHS
  /usr/local/include/mysql
  /usr/include/mysql
  REQUIRED
)

find_library(MYSQL_CLIENT_LIBRARY NAMES mysqlclient libmysqlclient REQUIRED)

target_include_directories(
    output PUBLIC
    ${Python3_INCLUDE_DIRS}
    ${MYSQL_INCLUDE_DIR}
)

target_link_libraries(
    output
    Python3::Python
    ${MYSQL_CLIENT_LIBRARY}
)