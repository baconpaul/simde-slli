cmake_minimum_required(VERSION 3.20)
set(CMAKE_OSX_ARCHITECTURES "x86_64;arm64")
project(simde_slli  VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} src/test.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE simde)


