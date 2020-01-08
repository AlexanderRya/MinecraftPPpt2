#include "renderer/renderer.hpp"

namespace minecraft {
    renderer::renderer(const std::vector<chunk>& chunks)
    : chunks(chunks) {
        //@ TODO: Make the renderer work with multiple chunks
        //@ TODO: Add frustum culling
        //@ TODO: Make chunks trimming trim chunk-adjacent blocks

        glGenVertexArrays(1, &vao);

        glGenBuffers(1, &vbo);
        glGenBuffers(1, &off_vbo);

        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        glBufferData(GL_ARRAY_BUFFER, sizeof(vertex) * cube_data.size(), cube_data.data(), GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_INT, false, sizeof(vertex), reinterpret_cast<void*>(offsetof(vertex, coords)));

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_INT, false, sizeof(vertex), reinterpret_cast<void*>(offsetof(vertex, tx_coords)));

        glBindBuffer(GL_ARRAY_BUFFER, off_vbo);

        glBufferData(GL_ARRAY_BUFFER, sizeof(glm::ivec3) * chunks[0].to_draw.size(), chunks[0].to_draw.data(), GL_STATIC_DRAW);

        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 3, GL_INT, false, sizeof(glm::ivec3), reinterpret_cast<void*>(0));
        glVertexAttribDivisor(2, 1);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void renderer::render() const {
        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBindBuffer(GL_ARRAY_BUFFER, off_vbo);

        glDrawArraysInstanced(GL_TRIANGLES, 0, cube_data.size(), chunks[0].to_draw.size());

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }
}
