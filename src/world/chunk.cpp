
#include "world/chunk.hpp"

namespace minecraft {
    chunk::chunk(const std::array<block, 4096>& btype, const glm::ivec3& pos)
    : data(btype),
      pos(pos) {}

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
    }

    block chunk::block_at(const types::i32 x, const types::i32 y, const types::i32 z) const {
        if (x < 0 || x > 15 || y < 0 || y > 15 || z < 0 || z > 15) {
            return block(block::block_type::air);
        }
        return data[z * 256 + y * 16 + x];
    }
}

