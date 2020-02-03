cmake_minimum_required(VERSION 3.15)
project(OpenGLCourseApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa -framework OpenGL -framework IOKit")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_executable(OpenGLCourseApp main.cpp)

target_link_libraries(OpenGLCourseApp glfw)
target_link_libraries(OpenGLCourseApp glew)