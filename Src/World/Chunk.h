#ifndef __CHUNK_H__
#define __CHUNK_H__

#include <glm/glm.hpp>
#include <vector>

#include "ChunkMesh.h"
#include "Block.h"

#define CHUNK_SIZE_X 8
#define CHUNK_SIZE_Y 32
#define CHUNK_SIZE_Z 8
#define CHUNK_SIZE_XZ (CHUNK_SIZE_X * CHUNK_SIZE_Z)
#define CHUNK_DIRT_LAYER_NUM 5

class Array2D;

class Chunk {
public:
	Chunk(const glm::vec3& position, const Array2D& matrix);
	
	void blocksGeneration(const Array2D& matrix);
	void bindMesh();

	const ChunkMesh& getChunkMesh() const {
		return m_mesh;
	}

	const glm::vec3& getChunkPosition() const {
		return m_position;
	}

	const std::vector<Block> getBlocks() const {
		return m_blocks;
	}
private:
	ChunkMesh m_mesh;
	glm::vec3 m_position;

	std::vector<Block> m_blocks;
};

#endif