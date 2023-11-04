#include "Player.h"

#include <GLFW/glfw3.h>

#include "World/World.h"

static const float PLAYER_SPEED = 20.0f;
static const float PLAYER_ROTATION_SPEED = 0.25f;

Player::Player(const glm::vec3& position) :
	// Player body
	m_dimensions(glm::vec3(1.0f, 1.0f, 1.0f)) 
{
	spawn(position);
}

void Player::spawn(const glm::vec3& position) {
	m_position = position;
}

void Player::updatePosition(GLFWwindow* window, float deltaTime) {
	float playerSpeed = PLAYER_SPEED * deltaTime;

	// Just modify XZ to player not fly
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
		m_position += m_rotation * playerSpeed;
		/*
		m_position.x += m_rotation.x * playerSpeed;
		m_position.z += m_rotation.z * playerSpeed;
		*/
	}
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
    	m_position -= m_rotation * playerSpeed;
    	/*
    	m_position.x -= m_rotation.x * playerSpeed;
    	m_position.z -= m_rotation.z * playerSpeed;
    	*/
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
    	m_position += glm::normalize(glm::cross(m_rotation, glm::vec3(0.0f, 1.0f, 0.0f))) * playerSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
    	m_position -= glm::normalize(glm::cross(m_rotation, glm::vec3(0.0f, 1.0f, 0.0f))) * playerSpeed;
    }

    // Jump
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
    	m_position.y += 1.0f;    }
}

void Player::updateRotation(float mouseX, float mouseY) {
	mouseX *= PLAYER_ROTATION_SPEED;
    mouseY *= PLAYER_ROTATION_SPEED;

    m_yaw += mouseX;
    m_pitch += mouseY;

    // Do not flip
	if (m_pitch > 89.0f)
		m_pitch = 89.0f;
	if (m_pitch < -89.0f)
		m_pitch = -89.0f;

    m_rotation.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_rotation.y = sin(glm::radians(m_pitch));
    m_rotation.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
}

void Player::update(const World& world) {
	m_hasCollided = false;
	collide(world);

	if (m_hasCollided == false) {
		//m_position.y -= 0.2f;
	}
}

void Player::collide(const World& world) {
	printVec3(m_position);
	for (const auto& chunk : world.getChunks()) {
		for (const auto& block : chunk.getBlocks()) {
			if (vec3AreEqualIntegers(glm::vec3(m_position.x,
											   m_position.y,
											   m_position.x), block.position)) {
				m_hasCollided = true;
			}
		}
	}
}