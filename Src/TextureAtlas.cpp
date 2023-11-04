#include "TextureAtlas.h"

std::vector<float> getTexCoordsFromAtlas(float x, float y) {
	float minX, minY, maxX, maxY;

	minX = ((0 + x) * SPRITE_SIZE) / TEXTURE_SIZE;
    minY = ((0 + y) * SPRITE_SIZE) / TEXTURE_SIZE;

    maxX = ((1 + x) * SPRITE_SIZE) / TEXTURE_SIZE;
    maxY = ((1 + y) * SPRITE_SIZE) / TEXTURE_SIZE;

	return {
		maxX, maxY,
		minX, maxY,
		minX, minY,
		maxX, minY
	};
}