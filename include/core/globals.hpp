#ifndef NMINECRAFTPP_GLOBALS_HPP
#define NMINECRAFTPP_GLOBALS_HPP

#include "types.hpp"
#include "world/vertex.hpp"

#include <array>

namespace minecraft {
    constexpr inline auto WIDTH = 1280;
    constexpr inline auto HEIGHT = 720;

    inline types::f64 delta_time = 0;
    inline types::f64 last_frame = 0;

    inline std::array<vertex, 36> generate_nonindexed_cube_geometry() {
        return {{
            {{ 0, 0, 0 }, { 0, 0 }},
            {{ 1, 0, 0 }, { 1, 0 }},
            {{ 1, 1, 0 }, { 1, 1 }},
            {{ 1, 1, 0 }, { 0, 0 }},
            {{ 0, 1, 0 }, { 0, 1 }},
            {{ 0, 0, 0 }, { 0, 0 }},

            {{ 0, 0, 1 }, { 0, 0 }},
            {{ 1, 0, 1 }, { 1, 0 }},
            {{ 1, 1, 1 }, { 1, 1 }},
            {{ 1, 1, 1 }, { 1, 1 }},
            {{ 0, 1, 1 }, { 0, 1 }},
            {{ 0, 0, 1 }, { 0, 0 }},

            {{ 0, 1, 1 }, { 1, 0 }},
            {{ 0, 1, 0 }, { 1, 1 }},
            {{ 0, -1, 0 }, { 0, 1 }},
            {{ 0, 0, 0 }, { 0, 1 }},
            {{ 0, 0, 1 }, { 0, 0 }},
            {{ 0, 1, 1 }, { 1, 0 }},

            {{ 1, 1, 1 }, { 1, 0 }},
            {{ 1, 1, 0 }, { 1, 1 }},
            {{ 1, 0, 0 }, { 0, 1 }},
            {{ 1, 0, 0 }, { 0, 1 }},
            {{ 1, 0, 1 }, { 0, 0 }},
            {{ 1, 1, 1 }, { 1, 0 }},

            {{ 0, 0, 0 }, { 0, 1 }},
            {{ 1, 0, 0 }, { 1, 1 }},
            {{ 1, 0, 1 }, { 1, 0 }},
            {{ 1, 0, 1 }, { 1, 0 }},
            {{ 0, 0, 1 }, { 0, 0 }},
            {{ 0, 0, 0 }, { 0, 1 }},

            {{ 0, 1, 0 }, { 0, 1 }},
            {{ 1, 1, 0 }, { 1, 1 }},
            {{ 1, 1, 1 }, { 1, 0 }},
            {{ 1, 1, 1 }, { 1, 0 }},
            {{ 0, 1, 1 }, { 0, 0 }},
            {{ 0, 1, 0 }, { 0, 1 }}
        }};
    }

    constexpr inline auto CHUNK_LAYER = 16;
    constexpr inline auto CHUNK_SIZE = 16 * CHUNK_LAYER;
    constexpr inline auto CHUNK_VOLUME = 16 * CHUNK_SIZE;
} // namespace minecraft


#endif //NMINECRAFTPP_GLOBALS_HPP
