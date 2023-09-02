add_executable(first-opengl-project main.cpp shader.cpp stb_image.cpp)

add_library(glad ${CMAKE_SOURCE_DIR}/third-party/glad/src/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_SOURCE_DIR}/third-party/glad/include)

target_link_libraries(first-opengl-project glfw ${OPENGL_LIBRARIES} glad)
target_include_directories(first-opengl-project PRIVATE ${CMAKE_SOURCE_DIR}/third-party/glfw/include ${CMAKE_SOURCE_DIR}/third-party/glad/include ${CMAKE_SOURCE_DIR}/third-party/stb/include)