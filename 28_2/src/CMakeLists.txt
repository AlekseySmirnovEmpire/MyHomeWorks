cmake_minimum_required (VERSION 3.8)

add_executable(28_2 main.cpp "train.cpp")

target_include_directories(28_2 PUBLIC ${MY_INCLUDE_DIR})