#include "renderer/renderer.hpp"

namespace minecraft {
    renderer::renderer(const std::vector<chunk>& chunks)
    : chunks(chunks) {
        ///@TODO: Make the renderer work with multiple chunks
        ///@TODO: Add frustum culling
        ///@TODO: Make chunks trimming trim chunk-adjacent blocks

        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        glEnableVertexAttribArray(0);
        glVertexAttribFormat(0, 3, GL_INT, false, offsetof(vertex, coords));
        glVertexAttribBinding(0, 0);

        glEnableVertexAttribArray(1);
        glVertexAttribFormat(1, 2, GL_INT, false, offsetof(vertex, tx_coords));
        glVertexAttribBinding(1, 0);

        glEnableVertexAttribArray(2);
        glVertexAttribFormat(2, 3, GL_INT, false, 0);
        glVertexAttribBinding(2, 1);

        glVertexBindingDivisor(1, 1);

        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        glBufferStorage(GL_ARRAY_BUFFER, 36 * sizeof(vertex) + 4194304 * sizeof(glm::ivec3), nullptr, GL_DYNAMIC_STORAGE_BIT);
        glBufferSubData(GL_ARRAY_BUFFER, 0, 36 * sizeof(vertex), cube_data.data());

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void renderer::render() const {
        glBindVertexArray(vao);

        for (const auto& each : chunks) {
            each.draw(vbo);
        }

        glBindVertexArray(0);
    }
}
