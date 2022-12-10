#pragma once

#include "../../gpch.h"

class Camera
{
private:
    glm::vec2 m_CameraCoords;
    glm::vec2 m_CameraTarget;
    glm::vec2 m_CameraDirection;
    glm::vec2 m_UpVector;
    glm::vec2 m_RightVector; // for representing the +ve x-axis for the camera
public:
    Camera();
};