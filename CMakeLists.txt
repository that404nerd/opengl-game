# Projects Settings
cmake_minimum_required (VERSION 3.16)
project (opengl-game)

set(CMAKE_CXX_STANDARD 23)

# The main executable
add_executable(opengl-game
  # Core Utils Implementation Includes
  src/core/impl/Window.cpp
  src/core/impl/Buffer.cpp
  src/core/impl/Shader.cpp
  src/core/impl/Texture.cpp
  src/core/impl/Camera.cpp
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

if (CMAKE_VERSION VERSION_GREATER_EQUAL 3.16)
    message(STATUS "Compiling using pre-compiled header support")
    target_precompile_headers(opengl-game
      PUBLIC 
      src/gpch.h)
else()
    message(STATUS "Disabled pre-compiled header support")
endif()

set_property(TARGET opengl-game PROPERTY CXX_STANDARD 23)
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