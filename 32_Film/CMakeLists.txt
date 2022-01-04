cmake_minimum_required(VERSION 3.21)
project("My Favourite Movie" VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(32_Film main.cpp)

target_link_libraries(32_Film PRIVATE nlohmann_json::nlohmann_json)