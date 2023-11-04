#ifndef __SHADER_H__
#define __SHADER_H__

#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>

class Camera;
class Texture;

class Shader {
public:
	void create(const std::string& vertexFile, const std::string& fragmentFile);
	void destroy();
	void bind();
	
	void uniformInt(const char* name, int value);
	void uniformVec3(const char* name, const glm::vec3& vec);
	void uniformMat4(const char* name, const glm::mat4& mat);
private:
	GLuint m_id;
};

#endif