cmake_minimum_required(VERSION 3.21)

project(My_Favourite_Movie VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(My_Favourite_Movie        main.cpp)

target_link_libraries(My_Favourite_Movie PRIVATE nlohmann_json::nlohmann_json)