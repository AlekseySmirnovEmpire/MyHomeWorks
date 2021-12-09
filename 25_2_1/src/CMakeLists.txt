cmake_minimum_required (VERSION 3.8)

add_executable (25_2_1 main.cpp cpu.cpp disk.cpp gpu.cpp  kbd.cpp RAM.cpp)
target_include_directories (25_2_1 PUBLIC ${MY_INCLUDE_PATH})