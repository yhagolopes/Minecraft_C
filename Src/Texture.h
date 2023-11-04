#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <string>
#include <glad/glad.h>
#include <glm/glm.hpp>

class Texture {
public:
	void create(const std::string& filename, GLuint unit);
	void destroy();
	void bind();
	
	const GLuint& getUnitLocation() const;
	const glm::vec2& getImageSize() const;
private:
	GLuint m_id;
	GLuint m_unit;

	glm::vec2 m_imageSize;
};

#endif