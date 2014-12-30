cmake_minimum_required(VERSION 2.8)
project(hello)
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED)
find_package(GLUT)
find_package(OpenGL)
if (OPENGL_FOUND)
	MESSAGE("OpenGL Correctly Found")
	include_directories(${OPENGL_INCLUDE_DIR})
else (OPENGL_FOUND)
	MESSAGE("OpenGL environment missing")
endif (OPENGL_FOUND)

add_executable(vertical vertical.cpp)
LINK_DIRECTORIES(${OPENGL_LIBRARIES})
target_link_libraries(vertical ${GLUT_LIBS} ${OPENGL_LIBS} ${OpenCV_LIBS})

#end of CMakeLists.txt
