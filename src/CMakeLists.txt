add_executable(first-opengl-project main.cpp)
target_link_libraries(first-opengl-project glfw)
target_include_directories(first-opengl-project PRIVATE ${CMAKE_SOURCE_DIR}/third-party/glfw/include)