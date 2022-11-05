# Projects Settings
cmake_minimum_required (VERSION 3.1)
project (opengl-game)

# The main executable
add_executable(opengl-game
  src/Application.cpp
  src/Game.cpp
  src/IndexBuffer.cpp
  src/VertexBuffer.cpp
  src/Texture.cpp
  src/Sprite.cpp
  src/Shader.cpp
  lib/stb_image/stb_image.cpp
)

set_property(TARGET opengl-game PROPERTY CXX_STANDARD 11)
target_compile_options(opengl-game PRIVATE -Wall)

add_definitions(-DGLEW_STATIC)
add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)
add_subdirectory(lib/glew EXCLUDE_FROM_ALL)
add_subdirectory(lib/glm EXCLUDE_FROM_ALL)

target_link_libraries(opengl-game
  PRIVATE glfw
  PRIVATE libglew_static
  PRIVATE glm
)

target_include_directories(opengl-game
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
  PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/src
)