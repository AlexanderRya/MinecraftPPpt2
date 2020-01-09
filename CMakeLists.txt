cmake_minimum_required(VERSION 3.15)
project(MinecraftPP)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(dependencies/glfw)
add_subdirectory(dependencies/fmt)
add_subdirectory(dependencies/glm)
add_subdirectory(dependencies/glad)

set(CMAKE_CXX_STANDARD 20)

set(MINECRAFTPP_HEADERS
    "include/renderer/glad.hpp"
    "include/core/types.hpp"
    "include/core/globals.hpp"
    "include/core/logger.hpp"
    "include/world/chunk.hpp"
    "include/world/block.hpp"
    "include/texture/texture.hpp"
    "include/world/vertex.hpp"
    "include/renderer/renderer.hpp"
    "include/core/shader.hpp"
    "include/core/game.hpp"
    "include/util/enum.hpp"
    "include/core/callbacks.hpp"
    "include/util/rang.hpp"
    "include/world/world.hpp"
    "include/texture/texture.hpp"
    "include/core/camera.hpp"
)

add_executable(MinecraftPP
    ${MINECRAFTPP_HEADERS}
    src/main.cpp
    src/core/game.cpp
    src/core/shader.cpp
    src/world/chunk.cpp
    src/world/block.cpp
    src/world/world.cpp
    src/texture/texture.cpp
    src/core/camera.cpp
    src/renderer/renderer.cpp)

target_compile_options(MinecraftPP
    PUBLIC
    # -Wall -Wextra -pedantic
)

target_include_directories(MinecraftPP
    PRIVATE
    "dependencies/glfw/include"
    "dependencies/glm"
    "dependencies/stb"
    "dependencies/fmt/include"
    "include"
)

execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
        WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        RESULT_VARIABLE UPDATE_SUBMODULES_RESULT)

set_target_properties(glfw fmt
        PROPERTIES
        COMPILE_OPTIONS -Wno-everything)

if (NOT WIN32)
    target_link_libraries(MinecraftPP glad glfw fmt pthread dl GL)
else()
    target_compile_definitions(MinecraftPP PRIVATE _CRT_SECURE_NO_WARNINGS)
    target_link_libraries(MinecraftPP glad glfw fmt)
endif()