cmake_minimum_required(VERSION 3.15)
project(MinecraftPP)

add_subdirectory(dependencies/glfw)
add_subdirectory(dependencies/fmt)
add_subdirectory(dependencies/glm)

set(CMAKE_CXX_STANDARD 20)

add_executable(MinecraftPP
    src/main.cpp
    dependencies/glad/glad/glad.c
    dependencies/glad/glad/glad.h
    include/core/game.hpp
    src/core/game.cpp
    include/core/types.hpp
    include/core/globals.hpp
    include/core/logger.hpp
    include/world/chunk.hpp
    include/world/block.hpp
    include/texture/texture.hpp
    include/world/vertex.hpp
    include/renderer/renderer.hpp
    include/core/shader.hpp
    src/core/shader.cpp
    include/util/enum.hpp
    src/world/chunk.cpp
    include/core/callbacks.hpp
    include/util/rang.hpp
    src/world/block.cpp
    include/world/world.hpp
    src/world/world.cpp
    include/texture/texture.hpp
    src/texture/texture.cpp
    include/core/camera.hpp
    src/core/camera.cpp
    src/renderer/renderer.cpp)

target_include_directories(MinecraftPP
    PRIVATE
    "dependencies/glfw/include"
    "dependencies/glm"
    "dependencies/glad"
    "dependencies/stb"
    "dependencies/fmt/include"
    "include"
)

target_link_libraries(MinecraftPP glfw fmt pthread dl GL)