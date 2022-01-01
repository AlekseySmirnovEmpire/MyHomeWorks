cmake_minimum_required (VERSION 3.8)

set(BUILD_SPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/headers)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG 67e12da316754ff3c6c91b50aafb2658438f3c1e) # the commit hash for 1.7.0
FetchContent_MakeAvailable(cpr)

add_executable(30_3_1		main.cpp	support.cpp		request.cpp)

target_include_directories(30_3_1 PUBLIC ${MY_INCLUDE_DIR})
target_link_libraries(30_3_1 PRIVATE cpr::cpr)