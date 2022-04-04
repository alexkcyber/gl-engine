cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(src)

project(gl-engine VERSION 0.0.1)
add_executable(gl-engine gl-engine.cpp src/glad.c)

find_package(glfw3 3.3 REQUIRED)
target_link_libraries(gl-engine glfw)
find_package(OpenGL REQUIRED)
target_link_libraries(gl-engine OpenGL::GL)

