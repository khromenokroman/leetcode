cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(leetcode)

message(STATUS "CXX Compiler : ${CMAKE_CXX_COMPILER}")
message(STATUS "CXX Compiler path : ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "CXX Compiler version : ${CMAKE_CXX_COMPILER_VERSION}")

add_executable(${PROJECT_NAME}
        sort_vib.cpp
)
