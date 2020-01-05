#ifndef NMINECRAFTPP_CHUNK_HPP
#define NMINECRAFTPP_CHUNK_HPP

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "block.hpp"
#include "core/globals.hpp"
#include "texture/assets.hpp"

#include <array>
#include <vector>

namespace minecraft {
    class chunk {
        std::vector<block> data;
        std::vector<glm::ivec3> to_draw{};
        glm::ivec3 pos{};
    public:
        unsigned vbo{};

        chunk(const std::array<assets::block_type, 4096>& btype, const glm::ivec3& pos);

        block block_at(const types::i32, const types::i32, const types::i32) const;

        void trim();
        void draw() const;
    };
}

#endif //NMINECRAFTPP_CHUNK_HPP
