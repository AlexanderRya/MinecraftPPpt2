#ifndef NMINECRAFTPP_GAME_HPP
#define NMINECRAFTPP_GAME_HPP

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "camera.hpp"
#include "callbacks.hpp"
#include "globals.hpp"
#include "logger.hpp"
#include "shader.hpp"
#include "world/world.hpp"
#include "renderer/renderer.hpp"

#include <utility>
#include <string>

namespace minecraft {
    class game {
        GLFWwindow* window{};
    public:
        game() = default;
        types::i32 run();
        types::i32 init();
    };
}
#endif //NMINECRAFTPP_GAME_HPP
