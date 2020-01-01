cmake_minimum_required(VERSION 3.15)
project(NMinecraftPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(NMinecraftPP src/main.cpp include/game.hpp include/window.hpp)