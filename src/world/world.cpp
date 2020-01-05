#include "world/world.hpp"

namespace minecraft {
    world::world() {
        glGenVertexArrays(1, &vao);
        glGenBuffers(1, &vbo);
        glGenBuffers(1, &chunk_vbo);

        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        glBufferData(GL_ARRAY_BUFFER, sizeof(glm::ivec3) * cube_data.size(), cube_data.data(), GL_STATIC_DRAW);

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_INT, false, sizeof(vertex), reinterpret_cast<void*>(offsetof(vertex, coords)));

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 2, GL_INT, false, sizeof(vertex), reinterpret_cast<void*>(offsetof(vertex, tx_coords)));
    }

    void world::draw() const {
        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        for (const auto& each : chunks) {
            each.draw();
        }
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    std::vector<chunk>& world::get_chunks() {
        return chunks;
    }

    chunk world::generate_chunk(const glm::ivec3& pos) const {
        std::array<assets::block_type, 4096> data{};

        for (int i = 0; i < 4096; ++i) {
            data[i] = assets::block_type::dirt;
        }

        return chunk { data, pos };
    }
}