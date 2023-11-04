#include "Block.h"

#include "../TextureAtlas.h"

/*
 * BACK
 * FRONT
 * LEFT
 * RIGHT
 * BOTTOM
 * TOP
 */

namespace {
	std::vector<glm::vec2> getTexLocation(BlockId id) {
		switch (id) {
		case GRASS:
			return {
				{0, 0},
				{0, 0},
				{0, 0},
				{0, 0},
				{1, 0},
				{2, 0}
			};
		case DIRT:
			return {
				{1, 0},
				{1, 0},
				{1, 0},
				{1, 0},
				{1, 0},
				{1, 0}
			};
		case STONE:
			return {
				{3, 0},
				{3, 0},
				{3, 0},
				{3, 0},
				{3, 0},
				{3, 0}
			};
		case SAND:
			return {
				{4, 0},
				{4, 0},
				{4, 0},
				{4, 0},
				{4, 0},
				{4, 0}
			};
		case WATER:
			return {
				{5, 0},
				{5, 0},
				{5, 0},
				{5, 0},
				{5, 0},
				{5, 0}
			};
		}
	}

	std::vector<float> getTexCoords(BlockId id) {
		auto texLocation = getTexLocation(id);
		std::vector<float> texCoords;

		for (auto& location : texLocation) {
			auto texCoordsFromAtlas = getTexCoordsFromAtlas(location.x, location.y);
			texCoords.insert(texCoords.end(), texCoordsFromAtlas.begin(), texCoordsFromAtlas.end());
		}

		return texCoords;
	}
}

std::vector<float> getBlockAtPosition(BlockId id, float x, float y, float z) {
	auto texCoords = getTexCoords(id);
	int index = 0;

	return {
		1 + x, 0 + y, 0 + z,  texCoords[index++], texCoords[index++],
		0 + x, 0 + y, 0 + z,  texCoords[index++], texCoords[index++],
		0 + x, 1 + y, 0 + z,  texCoords[index++], texCoords[index++],
		1 + x, 1 + y, 0 + z,  texCoords[index++], texCoords[index++],

		1 + x, 0 + y, 1 + z,  texCoords[index++], texCoords[index++],
		0 + x, 0 + y, 1 + z,  texCoords[index++], texCoords[index++],
		0 + x, 1 + y, 1 + z,  texCoords[index++], texCoords[index++],
		1 + x, 1 + y, 1 + z,  texCoords[index++], texCoords[index++],

		0 + x, 0 + y, 1 + z,  texCoords[index++], texCoords[index++],
		0 + x, 0 + y, 0 + z,  texCoords[index++], texCoords[index++],
		0 + x, 1 + y, 0 + z,  texCoords[index++], texCoords[index++],
		0 + x, 1 + y, 1 + z,  texCoords[index++], texCoords[index++],

		1 + x, 0 + y, 1 + z,  texCoords[index++], texCoords[index++],
		1 + x, 0 + y, 0 + z,  texCoords[index++], texCoords[index++],
		1 + x, 1 + y, 0 + z,  texCoords[index++], texCoords[index++],
		1 + x, 1 + y, 1 + z,  texCoords[index++], texCoords[index++],

		1 + x, 0 + y, 1 + z,  texCoords[index++], texCoords[index++],
		0 + x, 0 + y, 1 + z,  texCoords[index++], texCoords[index++],
		0 + x, 0 + y, 0 + z,  texCoords[index++], texCoords[index++],
		1 + x, 0 + y, 0 + z,  texCoords[index++], texCoords[index++],

		1 + x, 1 + y, 1 + z,  texCoords[index++], texCoords[index++],
		0 + x, 1 + y, 1 + z,  texCoords[index++], texCoords[index++],
		0 + x, 1 + y, 0 + z,  texCoords[index++], texCoords[index++],
		1 + x, 1 + y, 0 + z,  texCoords[index++], texCoords[index++]
	};
}

std::vector<unsigned int> getBlockIndices() {
	return {
		0, 1, 2, 2, 3, 0,
		4, 5, 6, 6, 7, 4,
		8, 9, 10, 10, 11, 8,
		12, 13, 14, 14, 15, 12,
		16, 17, 18, 18, 19, 16,
		20, 21, 22, 22, 23, 20
	};
}

std::vector<unsigned int> getBlockIndicesInIndex(unsigned int index) {
	return {
		0  + index, 1  + index, 2  + index, 2  + index, 3  + index, 0  + index,
		4  + index, 5  + index, 6  + index, 6  + index, 7  + index, 4  + index,
		8  + index, 9  + index, 10 + index, 10 + index, 11 + index, 8  + index,
		12 + index, 13 + index, 14 + index, 14 + index, 15 + index, 12 + index,
		16 + index, 17 + index, 18 + index, 18 + index, 19 + index, 16 + index,
		20 + index, 21 + index, 22 + index, 22 + index, 23 + index, 20 + index
	};
}