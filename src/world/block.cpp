#include "world/block.hpp"

namespace minecraft {
    block::block(const block_type& type)
    : type(type) {}

    bool block::is_opaque() const {
        return type != block::block_type::air;
    }
}