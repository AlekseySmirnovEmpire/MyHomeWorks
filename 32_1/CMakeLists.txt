cmake_minimum_required(VERSION 3.0)
project(task1)

set(CMAKE_CXX_STANDARD 17)
set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(nlohmann_json)


add_executable(task1 main.cpp)
target_link_libraries(task1 PRIVATE nlohmann_json::nlohmann_json)