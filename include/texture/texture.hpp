#ifndef NMINECRAFTPP_TEXTURE_HPP
#define NMINECRAFTPP_TEXTURE_HPP

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#include "stb/stb_image.h"
#include "glad/glad.h"

#include "core/logger.hpp"

#include <filesystem>

namespace minecraft {
    class texture {
        unsigned id{};
    public:
        explicit texture(const std::filesystem::path&);
        texture(const texture&) noexcept;
        void bind() const;
        void unbind() const;
    };
}

#endif //NMINECRAFTPP_TEXTURE_HPP
