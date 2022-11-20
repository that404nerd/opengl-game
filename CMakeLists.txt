# Projects Settings
cmake_minimum_required (VERSION 3.14)
project (opengl-game)

set(CMAKE_CXX_STANDARD 17)

# The main executable
add_executable(opengl-game
  # Core Utils Implementation Includes
  src/core/impl/Buffer.cpp
  src/core/impl/Shader.cpp
  src/core/impl/Texture.cpp
  src/core/impl/SpriteRenderer.cpp
  src/core/impl/ResourceManager.cpp

  # Actual Game Files
  src/game/Application.cpp
  src/game/Game.cpp

  # External libraries (vendor)
  lib/stb_image/stb_image.cpp
)

set_property(TARGET opengl-game PROPERTY CXX_STANDARD 11)
target_compile_options(opengl-game PRIVATE -Wall)

add_definitions(-DGLEW_STATIC)
add_subdirectory(lib/glew EXCLUDE_FROM_ALL)
add_subdirectory(lib/glm EXCLUDE_FROM_ALL)

target_link_libraries(opengl-game
  PRIVATE glfw
  PRIVATE libglew_static
  PRIVATE glm
)

target_include_directories(opengl-game
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)