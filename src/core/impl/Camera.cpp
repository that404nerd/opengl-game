#include "../include/Camera.h"

Camera::Camera()
    :m_CameraCoords(0.0f, 0.0f), m_CameraTarget(0.0f, 0.0f), 
    m_CameraDirection(glm::normalize(m_CameraCoords - m_CameraTarget))
{
}