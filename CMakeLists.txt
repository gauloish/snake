cmake_minimum_required( VERSION 3.26 )

project( Snake )

find_package( OpenGL REQUIRED )

include_directories( "glfw/include" )
include_directories( ${OPENGL_INCLUDE_DIRS} )

set( GLFW_BUILD_EXAMPLES OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_BUILD_TESTS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_BUILD_DOCS OFF CACHE BOOL  "GLFW lib only" )
set( GLFW_BUILD_INSTALL OFF CACHE BOOL  "GLFW lib only" )

add_subdirectory( glfw )

if( WIN32 )
    SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup" )
endif()
if( UNIX )
    SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17" )
endif()
if( APPLE )
    SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++" )
endif()

add_executable( snake source/main.cpp )
target_link_libraries( snake ${OPENGL_LIBRARIES} glfw ${GLFW_LIBRARIES} )
