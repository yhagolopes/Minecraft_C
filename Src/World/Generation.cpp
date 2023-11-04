#include "Generation.h"

#include "Chunk.h"
#include "World.h"

const int blockHeightChance = 10;

void Generation::genChunkHeight(Chunk& chunk) {
	
}

void Generation::updateTerrainXZ(int x, int z) {

}


int Generation::getBlockHeight(int height) {
	int blockHeight = height;

	if (m_random.getRandomi(1, blockHeightChance) == 1) {
		blockHeight += m_random.getRandomi(-1, 1);
	}

	return blockHeight;
}

Array2D getChunkMatrix(const Array2D& matrix) {
	Array2D chunkMatrix(CHUNK_SIZE_X, CHUNK_SIZE_Z, 0);

	for (int chunkX = 0; chunkX < CHUNK_SIZE_X; chunkX++) {
		for (int chunkZ = 0; chunkZ < CHUNK_SIZE_Z; chunkZ++) {
			chunkMatrix[chunkX][chunkZ] = getBlockHeight(matrix[chunkX][chunkZ]);
		}
	}

	return chunkMatrix;
}

