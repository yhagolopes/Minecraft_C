#ifndef __CAMERA_H__
#define __CAMERA_H__

#include <glm/glm.hpp>

class Player;

class Camera {
public:
	Camera() {}

	void init(float aspect, float fov);
	void update(const Player& player);

	const glm::mat4& getView() const {
		return m_view;
	}

	const glm::mat4& getProjection() const {
		return m_projection;
	}
private:
	float m_aspect;
	float m_fov;

	glm::mat4 m_view;
	glm::mat4 m_projection;
};

#endif