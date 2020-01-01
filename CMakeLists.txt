cmake_minimum_required(VERSION 3.15)
project(NMinecraftPP)

add_subdirectory(dependencies/glfw)
add_subdirectory(dependencies/fmt)
add_subdirectory(dependencies/glm)

include_directories(dependencies/glfw/include)
include_directories(dependencies/glm/glm)
include_directories(dependencies/glad)
include_directories(dependencies/fmt/include)
include_directories(include)

set(CMAKE_CXX_STANDARD 20)

add_executable(NMinecraftPP
        src/main.cpp
        dependencies/glad/glad/glad.c
        dependencies/glad/glad/glad.h
        include/core/game.hpp
        src/core/game.cpp
        include/core/types.hpp
        include/core/globals.hpp
        include/core/logger.hpp
        src/core/logger.cpp
        include/block/chunk.hpp
        include/block/block.hpp
        include/texture/texture_atlas.hpp
        include/block/vertex.hpp include/renderer/cube_renderer.hpp include/core/shader.hpp src/core/shader.cpp)

target_link_libraries(NMinecraftPP glfw fmt)