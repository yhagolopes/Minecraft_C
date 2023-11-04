#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Util.h"

class World;
class GLFWwindow;

class Player {
public:
	Player() = default;
	Player(const glm::vec3& position);

	void spawn(const glm::vec3& position);

	void updatePosition(GLFWwindow* window, float deltaTime);
	void updateRotation(float mouseX, float mouseY);

	void update(const World& world);

	const glm::vec3& getPosition() const {
		return m_position;
	}

	const glm::vec3& getRotation() const {
		return m_rotation;
	}
private:
	void collide(const World& world);

	glm::vec3 m_position;
	glm::vec3 m_rotation;

	float m_yaw;
	float m_pitch;

	bool m_hasCollided;

	const glm::vec3 m_dimensions;
};

#endif