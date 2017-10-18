#pragma once

#include "utils.h"

class Camera
{
public:
	Camera();
	~Camera() = default;

	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix();
	
private:
	glm::mat4 m_viewMatrix;
	glm::mat4 m_projectionMatrix;

	glm::vec3 m_position;
	glm::vec3 m_target;
};