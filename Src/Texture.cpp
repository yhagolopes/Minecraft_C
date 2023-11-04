#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <iostream>

void Texture::create(const std::string& filename, GLuint unit) {
	m_unit = unit;

	glGenTextures(1, &m_id);
	glActiveTexture(GL_TEXTURE0 + m_unit);
	glBindTexture(GL_TEXTURE_2D, m_id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	int width, height, nrChannels;
	unsigned char* data = stbi_load(("../Resources/Images/" + filename).c_str(), &width, &height, &nrChannels, 0);
	if (!data) {
		std::cout << "Failed to load texture: " << filename << std::endl;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	m_imageSize.x = width;
	m_imageSize.y = height;

	stbi_image_free(data);
}

void Texture::destroy() {
	glDeleteTextures(1, &m_id);
}

void Texture::bind() {
	glBindTexture(GL_TEXTURE_2D, m_id);
}

const GLuint& Texture::getUnitLocation() const {
	return m_unit;
}

const glm::vec2& Texture::getImageSize() const {
	return m_imageSize;
}