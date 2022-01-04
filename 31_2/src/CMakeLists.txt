cmake_minimum_required (VERSION 3.8)

add_executable (31_2		main.cpp		matrixGraph.cpp			listGraph.cpp		support.cpp)

target_include_directories(31_2 PUBLIC ${MY_INCLUDE_DIR})