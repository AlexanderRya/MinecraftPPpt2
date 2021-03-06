#ifndef NMINECRAFTPP_CHUNK_HPP
#define NMINECRAFTPP_CHUNK_HPP

#include "GLFW/glfw3.h"
#include <renderer/glad.hpp>

#include "block.hpp"
#include "core/globals.hpp"
#include "texture/texture.hpp"

#include <array>
#include <unordered_map>
#include <vector>

namespace minecraft {
    class chunk {
        std::array<block, 4096> data;

        glm::ivec3 pos{};

        ///@TODO: Give this thing a usage
        static inline std::unordered_map<types::i32, texture> textures{};

      public:
        std::vector<glm::ivec3> to_draw{};

        chunk(const std::array<block, 4096>& btype, const glm::ivec3& pos);

        block block_at(const types::i32, const types::i32, const types::i32) const;

        void trim();
        void draw(const unsigned) const;
    };
} // namespace minecraft

#endif //NMINECRAFTPP_CHUNK_HPP
