cmake_minimum_required(VERSION 3.26)

project(Snake)

set (CMAKE_CXX_STANDARD 11)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(libraries/glfw)

# GLEW
set(glew-cmake_BUILD_SHARED OFF)

add_subdirectory(libraries/glew)

# OpenGL
find_package(OpenGL REQUIRED)

# System
if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif()

# Setup
set (
	SOURCES
	source/main.cpp
	source/geometry.cpp
	source/settings.cpp
	source/snake.cpp
	source/functions.cpp
	source/object.cpp
	)

add_executable(snake ${SOURCES})
target_link_libraries(snake glfw libglew_static OpenGL::GL)
