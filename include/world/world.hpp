#ifndef NMINECRAFTPP_WORLD_HPP
#define NMINECRAFTPP_WORLD_HPP

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "core/globals.hpp"
#include "renderer/renderer.hpp"
#include "chunk.hpp"

#include <vector>

namespace minecraft {
    class world {
        std::vector<chunk> chunks;
    public:
        world() = default;
        std::vector<chunk>& get_chunks();
        void generate_chunk(const glm::ivec3& pos);
    };
}

#endif //NMINECRAFTPP_WORLD_HPP
