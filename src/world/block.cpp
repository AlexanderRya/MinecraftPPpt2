#include "world/block.hpp"

namespace minecraft {
    bool block::is_opaque() const {
        return type != assets::block_type::air;
    }

    block::block(const assets::block_type& type)
    : type(type) {}
}