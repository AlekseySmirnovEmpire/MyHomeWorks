cmake_minimum_required(VERSION 3.21)

project(Search_Movie VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(MY_INCLUDE_DIR  ${CMAKE_SOURCE_DIR}/include)
set(MY_SOURCE_DIR   ${CMAKE_SOURCE_DIR}/src)
set(JSON_BuildTests OFF CACHE INTERNAL "")
set(MY_NAME "32_2")

option(TEST "Test mode?" OFF)

add_subdirectory(nlohmann_json)

if(${TEST})
    add_executable(${MY_NAME}       test.cpp)
else()
    add_executable(${MY_NAME}      src/main.cpp         src/Film.cpp         src/menu.cpp)
endif()

target_include_directories(${MY_NAME} PUBLIC ${MY_INCLUDE_DIR})
target_link_libraries(${MY_NAME} PRIVATE nlohmann_json::nlohmann_json)