# Projects Settings

cmake_minimum_required (VERSION 3.16)
project (opengl-game LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)

# The main executable

add_executable(opengl-game
  # Core Utils Implementation Includes
  src/core/impl/Window.cpp
  src/core/impl/Buffer.cpp
  src/core/impl/Shader.cpp
  src/core/impl/Texture.cpp
  src/core/impl/Log.cpp

  # Event Stuff
  src/core/events/Event.cpp

  # Actual Game Files
  src/game/Application.cpp
  src/game/Character.cpp
  src/game/Game.cpp

  # External libraries (vendor)
  lib/stb_image/stb_image.cpp
)

find_package(GLEW REQUIRED)
find_package(glm REQUIRED)

set_property(TARGET opengl-game PROPERTY CXX_STANDARD 23)
target_compile_options(opengl-game PRIVATE -Wall)

add_definitions(-DGLEW_STATIC)
add_subdirectory(lib/glm EXCLUDE_FROM_ALL)

target_link_libraries(opengl-game
  PRIVATE glfw
  PRIVATE GLEW
  PRIVATE GL
  PRIVATE glm
)

target_include_directories(opengl-game
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)