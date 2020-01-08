#include <core/shader.hpp>
#include "world/world.hpp"

namespace minecraft {
    std::vector<chunk>& world::get_chunks() {
        return chunks;
    }

    void world::generate_chunk(const glm::ivec3& pos) {
        std::array<block, 4096> data{};

        for (int i = 0; i < 4096; ++i) {
            data[i].type = block::block_type::dirt;
        }

        chunks.emplace_back(data, pos).trim();
    }
}