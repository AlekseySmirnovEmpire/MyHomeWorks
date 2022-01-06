cmake_minimum_required(VERSION 3.21)
project(First_proto VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(MY_NAME "32_3")
set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(${MY_NAME}       src/main.cpp)

target_include_directories(${MY_NAME} PUBLIC ${MY_INCLUDE_DIR})