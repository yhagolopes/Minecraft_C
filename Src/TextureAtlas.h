#ifndef __TEXTUREATLAS_H__
#define __TEXTUREATLAS_H__

#include <vector>

#define TEXTURE_SIZE 128
#define SPRITE_SIZE 16

std::vector<float> getTexCoordsFromAtlas(float x, float y);

#endif