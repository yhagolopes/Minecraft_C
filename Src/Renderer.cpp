#include "Renderer.h"

#include <glad/glad.h>

#include "Camera.h"
#include "World/World.h"

void Renderer::init() {
	m_basicShader.create("Basic.vert", "Basic.frag");
    m_atlasTexture.create("Atlas.png", 0);

	// Wireframe mode
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glEnable(GL_DEPTH_TEST);
}

void Renderer::destroy() {
	
}

void Renderer::render(const Camera& camera, const World& world) {
	glClearColor(0.0f, 0.0f, 1.0f, 0.2f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_atlasTexture.bind();

    m_basicShader.bind();
    m_basicShader.uniformMat4("view", camera.getView());
    m_basicShader.uniformMat4("projection", camera.getProjection());
    m_basicShader.uniformMat4("model", glm::mat4(1.0f));

    for (const auto& chunk : world.getChunks()) {
    	glBindVertexArray(chunk.getChunkMesh().getVAO());
    	glDrawElements(GL_TRIANGLES, chunk.getChunkMesh().getIndicesCount(), GL_UNSIGNED_INT, 0);
    }
}