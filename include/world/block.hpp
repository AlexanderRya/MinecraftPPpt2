#ifndef NMINECRAFTPP_BLOCK_HPP
#define NMINECRAFTPP_BLOCK_HPP

#include "vertex.hpp"
#include "core/types.hpp"
#include "texture/texture.hpp"

#include <array>

namespace minecraft {
    struct block {
        enum class block_type {
            null,
            air,
            dirt
        } type;

        block() = default;
        explicit block(const block_type& type);

        bool is_opaque() const;
    };
}

#endif //NMINECRAFTPP_BLOCK_HPP
