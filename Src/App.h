#ifndef __APP_H__
#define __APP_H__

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Camera.h"
#include "World/World.h"
#include "Renderer.h"

class App {
public:
	App();
	~App();

	void run();
private:
	GLFWwindow* m_window;

	Camera m_camera;
	Renderer m_renderer;
	World m_world;

	void handleInput();
};

#endif