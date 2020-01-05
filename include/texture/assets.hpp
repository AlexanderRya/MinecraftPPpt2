#ifndef NMINECRAFTPP_ASSETS_HPP
#define NMINECRAFTPP_ASSETS_HPP

#include "texture.hpp"

namespace minecraft {
    class assets {
    public:
        enum class block_type {
            null,
            air,
            dirt
        };
    private:
        std::unordered_map<block_type, texture> textures;
    public:

        assets();
    };
}

#endif //NMINECRAFTPP_ASSETS_HPP
