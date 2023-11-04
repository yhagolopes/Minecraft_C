#include "Chunk.h"

#include "../Util.h"

Chunk::Chunk(const glm::vec3& position, const Array2D& matrix) : 
    m_position(position)
{
    blocksGeneration(matrix);
}

void Chunk::blocksGeneration(const Array2D& matrix) {
    for (int x = 0; x < CHUNK_SIZE_X; x++) {
        for (int z = 0; z < CHUNK_SIZE_Z; z++) {
            int blockHeight = matrix[x][z];

            for (int y = 0; y < blockHeight; y++) {
                BlockId id;
                if (y == blockHeight - 1)
                    id = GRASS;
                else if (y >= blockHeight - CHUNK_DIRT_LAYER_NUM)
                    id = DIRT;
                else
                    id = STONE;

                m_blocks.push_back(Block(id,  {x + m_position.x, y + m_position.y, z + m_position.z}));
            }
        }
    }
}

void Chunk::bindMesh() {
    for (const auto& block : m_blocks) {
        m_mesh.addBlock(block);
    }

    m_mesh.create();
}