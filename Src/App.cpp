#include "App.h"

#include "Player.h"

namespace {
	Player player(glm::vec3(22.0f, 50.0f, 13.0f));

	float deltaTime = 0.0f;
	float lastMouseX = 250.0f;
	float lastMouseY = 250.0f;
	float windowX = 500;
	float windowY = 500;

	bool firstMouse = true;

	void resizeWindowCallback(GLFWwindow* window, int width, int height) {
	    glViewport(0, 0, width, height);
	}

	void mouseInputCallback(GLFWwindow* window, double x, double y) {
		float xPos = static_cast<float>(x);
		float yPos = static_cast<float>(y);

		if (firstMouse) {
	        lastMouseX = xPos;
	        lastMouseY = yPos;
	        firstMouse = false;
	    }

		float xOffset = xPos - lastMouseX;
		float yOffset = lastMouseY - yPos;
		lastMouseX = xPos;
		lastMouseY = yPos;

		player.updateRotation(xOffset, yOffset);
	}

	void scrollCallback(GLFWwindow* window, double x, double y) {
		float scrollY = static_cast<float>(y);
	}
}

App::App() {
	// Initialize GLFW
	glfwInit();

	// Tell GLFW the version of OpenGL are currently using
	// OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create GLFW window and checks it
    m_window = glfwCreateWindow(windowX, windowY, "Minecraft", NULL, NULL);
    if (!m_window) {
    	std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
    }

    // Introduce the window into the current context
    glfwMakeContextCurrent(m_window);

    glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Set callbacks
    glfwSetFramebufferSizeCallback(m_window, resizeWindowCallback);
    glfwSetScrollCallback(m_window, scrollCallback);
    glfwSetCursorPosCallback(m_window, mouseInputCallback);

    // Load GLAD to configure OpenGL
    gladLoadGL();

    m_camera.init(windowX / windowY, 45.0f);
	m_renderer.init();
	m_world.init(player);
}

App::~App() {
	m_renderer.destroy();
	
	glfwTerminate();
}

void App::run() {
	float lastFrame = 0.0f;

	while (!glfwWindowShouldClose(m_window)) {
		handleInput();

		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		m_renderer.render(m_camera, m_world);
		
		player.update(m_world);
		m_camera.update(player);
		m_world.update(player);

    	glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}

void App::handleInput() {
	if(glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(m_window, true);
	}

	player.updatePosition(m_window, deltaTime);
}