#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Player.h"

void Camera::init(float aspect, float fov) {
	m_aspect = aspect;
	m_fov = fov;
}

void Camera::update(const Player& player) {
	auto position = player.getPosition();
	auto rotation = player.getRotation();
	
	m_view = glm::lookAt(position, position + rotation, glm::vec3(0.0f, 1.0f, 0.0f));
	m_projection = glm::perspective(glm::radians(m_fov), m_aspect, 0.1f, 100.0f);
}