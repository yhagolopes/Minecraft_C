#include "Shader.h"

#include <iostream>
#include <fstream>
#include <glm/gtc/type_ptr.hpp>

namespace {
	std::string getFileContents(const std::string& filename) {
		std::ifstream inFile(filename, std::ios::binary);
		if (!inFile.is_open()) {
			std::cout << "Unable to open file: " << filename << std::endl;
		}

		std::string source;
		inFile.seekg(0, std::ios::end);
		source.resize(inFile.tellg());
		inFile.seekg(0, std::ios::beg);
		inFile.read(&source[0], source.size());
		inFile.close();

		return source;
	}

	GLuint compileShader(const std::string& filename, GLenum type) {
		GLuint id = glCreateShader(type);

		std::string source = getFileContents("../Resources/Shaders/" + filename);
		const char* csource = source.c_str();
		
		glShaderSource(id, 1, &csource, NULL);
		glCompileShader(id);

		int compiled;
		char log[512];
		glGetShaderiv(id, GL_COMPILE_STATUS, &compiled);
		if (!compiled) {
			glGetShaderInfoLog(id, 512, NULL, log);
    		std::cout << "Shader compilation error: " << log << std::endl;
		}

		return id;
	}

	GLuint linkProgram(GLuint vertexID, GLuint fragmentID) {
		GLuint id = glCreateProgram();

		glAttachShader(id, vertexID);
		glAttachShader(id, fragmentID);
		
		glLinkProgram(id);

		int linked;
		char log[512];
		glGetProgramiv(id, GL_LINK_STATUS, &linked);
		if(!linked) {
			glGetProgramInfoLog(id, 512, NULL, log);
			std::cout << "Shader linkage error: " << log << std::endl;
		}

		return id;
	}
} // Namespace

void Shader::create(const std::string& vertexFile, const std::string& fragmentFile) {
	GLuint vertexID = compileShader(vertexFile, GL_VERTEX_SHADER);
	GLuint fragmentID = compileShader(fragmentFile, GL_FRAGMENT_SHADER);

	m_id = linkProgram(vertexID, fragmentID);

	glDeleteShader(vertexID);
	glDeleteShader(fragmentID);
}

void Shader::destroy() {
	glDeleteProgram(m_id);
}

void Shader::bind() {
	glUseProgram(m_id);
}

void Shader::uniformInt(const char* name, int value) {
	glUniform1i(glGetUniformLocation(m_id, name), value);
}

void Shader::uniformVec3(const char* name, const glm::vec3& vec) {
	glUniform3f(glGetUniformLocation(m_id, name), vec.x, vec.y, vec.z);
}

void Shader::uniformMat4(const char* name, const glm::mat4& mat) {
	glUniformMatrix4fv(glGetUniformLocation(m_id, name), 1, GL_FALSE, glm::value_ptr(mat));
}