#ifndef NMINECRAFTPP_WORLD_HPP
#define NMINECRAFTPP_WORLD_HPP

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "core/globals.hpp"
#include "chunk.hpp"

#include <vector>

namespace minecraft {
    class world {
        std::vector<chunk> chunks;
        std::array<vertex, 36> cube_data = generate_nonindexed_cube_geometry();
        unsigned vao{}, vbo{}, chunk_vbo{};
    public:
        world();
        void draw() const;
        std::vector<chunk>& get_chunks();
        chunk generate_chunk(const glm::ivec3& pos) const;
    };
}

#endif //NMINECRAFTPP_WORLD_HPP
