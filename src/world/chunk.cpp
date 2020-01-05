
#include "world/chunk.hpp"

namespace minecraft {
    chunk::chunk(const std::array<assets::block_type, 4096>& btype, const glm::ivec3& pos)
    : pos(pos) {
        glGenBuffers(1, &vbo);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        glBufferData(GL_ARRAY_BUFFER, sizeof(glm::ivec3) * CHUNK_VOLUME, nullptr, GL_DYNAMIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, 0);

        data.reserve(4096);

        for (int i = 0; i < CHUNK_VOLUME; ++i) {
            data.emplace_back(btype[i]);
        }
    }

    void chunk::trim() {
        for (int x = 0; x < 16; ++x) {
            for (int y = 0; y < 16; ++y) {
                for (int z = 0; z < 16; ++z) {
                    bool visible = block_at(x, y, z).is_opaque() &&
                                   (!block_at(x - 1, y, z).is_opaque() || !block_at(x + 1, y, z).is_opaque() ||
                                    !block_at(x, y - 1, z).is_opaque() || !block_at(x, y + 1, z).is_opaque() ||
                                    !block_at(x, y, z - 1).is_opaque() || !block_at(x, y, z + 1).is_opaque());
                    if (visible) {
                        to_draw.emplace_back(pos + glm::ivec3(x, y, z));
                    }
                }
            }
        }

        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        glBufferSubData(GL_ARRAY_BUFFER, 0, to_draw.size() * sizeof(glm::ivec3), to_draw.data());
    }

    void chunk::draw() const {
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glDrawArraysInstanced(GL_ARRAY_BUFFER, 0, 36, to_draw.size());
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    block chunk::block_at(const types::i32 x, const types::i32 y, const types::i32 z) const {
        return data[z * 256 + y * 16 + x];
    }
}

