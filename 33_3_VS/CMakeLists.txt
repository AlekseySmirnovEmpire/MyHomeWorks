cmake_minimum_required(VERSION 3.0.0)
project(Data_reester VERSION 0.1.0 LANGUAGES CXX)

include(CTest)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(MY_NAME "33_3_VS")
set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

include(CPack)

add_executable(${MY_NAME}          src/main.cpp         src/support.cpp             src/reestr.cpp)

target_include_directories(${MY_NAME} PUBLIC ${MY_INCLUDE_DIR})