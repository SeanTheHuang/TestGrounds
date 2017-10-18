#include "camera.h"

Camera::Camera()
{
	m_position = glm::vec3(2, 5, -10);
	m_target = glm::vec3(0, 0, 0);

	m_projectionMatrix = glm::perspective(glm::radians(60.0f), (float)WINDOW_WIDTH/WINDOW_HEIGHT, 1.0f, 100.0f);
	m_viewMatrix = glm::lookAt(m_position, m_target, glm::vec3(0, 1, 0));
}


glm::mat4 Camera::GetViewMatrix()
{
	return m_viewMatrix;
}

glm::mat4 Camera::GetProjectionMatrix()
{
	return m_projectionMatrix;
}
