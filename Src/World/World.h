#ifndef __WORLD_H__
#define __WORLD_H__

#include <vector>

#include "Chunk.h"
#include "Generation.h"

#define TERRAIN_SIZE_X 6
#define TERRAIN_SIZE_Z 6
#define TERRAIN_SIZE_XZ (TERRAIN_SIZE_X * TERRAIN_SIZE_Z)

class Player;
class Camera;

class World {
public:
	World() {}

	void init(const Player& player);
	void update(const Player& player);

	const std::vector<Chunk>& getChunks() const {
		return m_chunks;
	}
private:
	glm::vec3 m_position;
	Generation m_generation;

	std::vector<Chunk> m_chunks;
};

#endif
