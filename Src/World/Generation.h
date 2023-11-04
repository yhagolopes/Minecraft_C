#ifndef __GENERATION_H__
#define __GENERATION_H__

#include "../Util.h"

class Chunk;

class Generation {
public:
	Generation() {}

	void genChunkHeight(Chunk& chunk);
	// Generates new chunks
	void updateTerrainXZ(int x, int z);

	const std::vector<Array2D>& getTerrainMatrices() const {
		return m_terrainMatrices;
	}
private:
	int getBlockHeight(int height);
	Array2D getChunkMatrix(const Array2D& matrix);
	
	Random m_random;

	std::vector<Array2D> m_terrainMatrices;
};

#endif