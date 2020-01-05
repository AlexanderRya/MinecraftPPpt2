#include "texture/texture.hpp"

namespace minecraft {
    texture::texture(const std::filesystem::path& path) {
        glGenTextures(1, &id);
        int pwidth, lheight, nr_components;
        std::string const path_as_string = path.generic_string();
        auto data = stbi_load(path_as_string.c_str(), &pwidth, &lheight, &nr_components, 0);
        if (data) {
            GLenum format = 0;
            if (nr_components == 1) {
                format = GL_RED;
            } else if (nr_components == 3) {
                format = GL_RGB;
            } else if (nr_components == 4) {
                format = GL_RGBA;
            }
            glBindTexture(GL_TEXTURE_2D, id);
            glTexImage2D(GL_TEXTURE_2D, 0, format, pwidth, lheight, 0, format, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            stbi_image_free(data);
        } else {
            std::cout << fmt::format("Texture failed to load at path: {}", path.string());
            assert(false);
        }
    }

    texture::texture(const texture& t) noexcept {
        id = t.id;
    }
}