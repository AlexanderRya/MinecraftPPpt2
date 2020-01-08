#ifndef NMINECRAFTPP_CHUNK_HPP
#define NMINECRAFTPP_CHUNK_HPP

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "block.hpp"
#include "core/globals.hpp"
#include "texture/texture.hpp"

#include <array>
#include <vector>

namespace minecraft {
    class chunk {
        std::array<block, 4096> data;

        glm::ivec3 pos{};

        inline static std::unordered_map<types::i32, texture> textures{};
    public:
        std::vector<glm::ivec3> to_draw{};

        chunk(const std::array<block, 4096>& btype, const glm::ivec3& pos);

        block block_at(const types::i32, const types::i32, const types::i32) const;

        void trim();
    };
}

#endif //NMINECRAFTPP_CHUNK_HPP
