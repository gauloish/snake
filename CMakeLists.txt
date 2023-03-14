cmake_minimum_required( VERSION 3.26 )

project( Snake )

find_package( glfw3 REQUIRED )
find_package( GLEW REQUIRED )
find_package( OpenGL REQUIRED )

if( WIN32 )
    SET( CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup" )
endif()
if( UNIX )
    SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17" )
endif()
if( APPLE )
    SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++" )
endif()

set (
	SOURCES
	source/main.cpp
	source/geometry.cpp
	source/settings.cpp
	source/snake.cpp
	source/functions.cpp
	source/render.cpp
	)

add_executable( snake ${SOURCES} )
target_link_libraries( snake glfw GLEW::GLEW OpenGL::GL )
