cmake_minimum_required (VERSION 3.8)

add_executable (28_3	main.cpp	restaurant.cpp)

target_include_directories(28_3 PUBLIC ${MY_INCLUDE_DIR})