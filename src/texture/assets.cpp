#include "texture/assets.hpp"

namespace minecraft {
    assets::assets() {
        std::filesystem::directory_iterator it("../assets/textures/");
        for (; it != std::filesystem::end(it); ++it) {
            std::cout << it->path().generic_string();
        }
    }
}