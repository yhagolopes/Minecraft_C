#include "ChunkMesh.h"

#include <glad/glad.h>
#include <iostream>

#include "Block.h"

void ChunkMesh::addBlock(const Block& block) {
    if (block.id == AIR)
        return;

    auto vertices = getBlockAtPosition(block.id, 
                                       block.position.x, 
                                       block.position.y, 
                                       block.position.z);
    m_vertices.insert(m_vertices.end(), vertices.begin(), vertices.end());

    auto indices = getBlockIndicesInIndex(m_index);
    m_indices.insert(m_indices.end(), indices.begin(), indices.end());

    m_index += 24; 
    m_indicesCount += 120;
}

void ChunkMesh::create() {
    glGenVertexArrays(1, &m_VAO);
    glBindVertexArray(m_VAO);

    glGenBuffers(1, &m_VBO);
    glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
    glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(float), m_vertices.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &m_EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(unsigned int), m_indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    m_vertices.clear();
    m_indices.clear();
}

const unsigned int& ChunkMesh::getIndicesCount() const {
    return m_indicesCount;
}

const unsigned int& ChunkMesh::getVAO() const {
    return m_VAO;
}