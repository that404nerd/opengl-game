// Game Precompiled headers (gpch)

// ---------------------- Dependency Includes ---------------------
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// --------------------- Main Libraries ---------------------------
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <fstream>
#include <cstdint>
#include <map>
#include <unordered_map>


// ---------------------- Core File Includes -------------------------
#include "core/include/Buffer.h"
#include "core/include/Camera.h"
#include "core/include/Log.h"
#include "core/include/Shader.h"
#include "core/include/Texture.h"
#include "core/include/Window.h"

// ------------------------ Event Stuff ------------------------------
#include "core/events/include/Event.h"

// -------------------- Game Files Includes ---------------------------
#include "game/Game.h"
#include "game/Character.h"