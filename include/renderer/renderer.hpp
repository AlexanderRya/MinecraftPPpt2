#ifndef NMINECRAFTPP_RENDERER_HPP
#define NMINECRAFTPP_RENDERER_HPP

#include "core/globals.hpp"
#include "world/chunk.hpp"

namespace minecraft {
    class renderer {
        constexpr static auto cube_data = generate_non_indexed_cube_geometry();
        const std::vector<chunk>& chunks;

        unsigned vao{}, vbo{};
    public:
        constexpr static auto block_offset = 36 * sizeof(vertex);

        explicit renderer(const std::vector<chunk>&);

        void render() const;
    };
}

#endif //NMINECRAFTPP_RENDERER_HPP
