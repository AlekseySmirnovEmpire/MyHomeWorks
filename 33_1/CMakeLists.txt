cmake_minimum_required(VERSION 3.21)
project(Online_shop VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(MY_NAME "33_1")
set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(${MY_NAME}           src/main.cpp        src/market.cpp
                                    src/basket.cpp      src/support.cpp)

target_include_directories(${MY_NAME} PUBLIC ${MY_INCLUDE_DIR})