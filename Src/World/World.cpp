#include "World.h"

#include <iostream>

#include "../Camera.h"
#include "../Player.h"

void World::init(const Player& player) {
	m_generation.genTerrain();

	int chunkX = 0;
	int chunkZ = 0;

	for (int i = 0; i < TERRAIN_SIZE_XZ; i++) {
		if (chunkZ >= TERRAIN_SIZE_Z) {
			chunkX++;
			chunkZ = 0;
		}
		
		Chunk chunk(glm::vec3(chunkX * CHUNK_SIZE_X, 0, chunkZ * CHUNK_SIZE_Z), m_generation.getTerrainMatrices()[i]);
		chunk.bindMesh();

		m_chunks.push_back(chunk);

		chunkZ++;

	}
}

void World::update(const Player& player) {

	m_generation.updateTerrainXZ(0, 0);
}