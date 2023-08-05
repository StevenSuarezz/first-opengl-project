cmake_minimum_required(VERSION 3.10)
project(first-opengl-project)

set(CMAKE_CXX_STANDARD 17)

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)
add_subdirectory(third-party/glfw)
add_subdirectory(src)
