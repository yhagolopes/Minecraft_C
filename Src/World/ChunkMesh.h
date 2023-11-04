#ifndef __CHUNKMESH_H__
#define __CHUNKMESH_H__

#include <vector>
#include <glm/glm.hpp>

class Block;

class ChunkMesh {
public:
	void addBlock(const Block& block);
	void create();

	const unsigned int& getIndicesCount() const;
	const unsigned int& getVAO() const;
private:
	std::vector<float> m_vertices;
	std::vector<unsigned int> m_indices;

	unsigned int m_VAO, m_VBO, m_EBO;

	unsigned int m_indicesCount = 0;
	unsigned int m_index = 0;
};

#endif