#ifndef NMINECRAFTPP_TEXTURE_HPP
#define NMINECRAFTPP_TEXTURE_HPP

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_STATIC
#include "stb_image.h"
#include <renderer/glad.hpp>

#include "core/logger.hpp"

#include <filesystem>

namespace minecraft {
    class texture {
        unsigned id{};

      public:
        explicit texture(const std::filesystem::path&);
        texture() = default;

        void bind() const;
        void unbind() const;
    };
} // namespace minecraft

#endif //NMINECRAFTPP_TEXTURE_HPP
