cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(src)

FILE(COPY src/shaders/basic.vert DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/src/shaders/)
FILE(COPY src/shaders/basic.frag DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/src/shaders/)

project(gl-engine VERSION 0.0.1)
add_executable(gl-engine
	gl-engine.cpp
	src/glad/glad.c
	src/shader/shader.cpp
	src/lights/dirlight.cpp
	src/file/stb_image.cpp)

find_package(glfw3 3.3 REQUIRED)
target_link_libraries(gl-engine glfw)
find_package(OpenGL REQUIRED)
target_link_libraries(gl-engine OpenGL::GL)

