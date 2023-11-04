#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "Shader.h"
#include "Texture.h"

class Camera;
class World;

class Renderer {
public:
	void init();
	void destroy();
	void render(const Camera& camera, const World& world);
private:
	Shader m_basicShader;
	Texture m_atlasTexture;
};

#endif