#ifndef __BLOCK_H__
#define __BLOCK_H__

#include <glm/glm.hpp>
#include <vector>

enum BlockId {
	AIR,
	GRASS,
	DIRT,
	STONE,
	SAND,
	WATER,
	LAST_BLOCK
};

std::vector<float> getBlockAtPosition(BlockId id, float x, float y, float z);
std::vector<unsigned int> getBlockIndices();
std::vector<unsigned int> getBlockIndicesInIndex(unsigned int index);

struct Block {
	BlockId id;
	glm::vec3 position;

	Block(BlockId _id, glm::vec3 _position) {
		id = _id;
		position = _position;
	}
};

#endif