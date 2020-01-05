#ifndef NMINECRAFTPP_BLOCK_HPP
#define NMINECRAFTPP_BLOCK_HPP

#include "vertex.hpp"
#include "core/types.hpp"
#include "texture/assets.hpp"

#include <array>

namespace minecraft {
    struct block {
        assets::block_type type;

        explicit block(const assets::block_type& type);
        bool is_opaque() const;
    };
}

#endif //NMINECRAFTPP_BLOCK_HPP
