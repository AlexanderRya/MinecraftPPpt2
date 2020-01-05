#ifndef NMINECRAFTPP_CALLBACKS_HPP
#define NMINECRAFTPP_CALLBACKS_HPP

#include "GLFW/glfw3.h"

#include "logger.hpp"

#include <iostream>

namespace minecraft {
    inline void framebuffer_size_callback(GLFWwindow*, const int vwidth, const int vheight) {
        glViewport(0, 0, vwidth, vheight);
    }

    static void debug_callback(const GLenum source, const GLenum type, GLuint, const GLenum severity, GLsizei, const GLchar* const message, const void*) {
        auto stringify_source = [](const GLenum source) -> const char* {
            switch (source) {
                case GL_DEBUG_SOURCE_API:
                    return "API";
                case GL_DEBUG_SOURCE_APPLICATION:
                    return "Application";
                case GL_DEBUG_SOURCE_SHADER_COMPILER:
                    return "Shader Compiler";
                case GL_DEBUG_SOURCE_WINDOW_SYSTEM:
                    return "Window System";
                case GL_DEBUG_SOURCE_THIRD_PARTY:
                    return "Third Party";
                case GL_DEBUG_SOURCE_OTHER:
                    return "Other";
                default:
                    return "Unknown";
            }
        };

        auto stringify_type = [](const GLenum type) -> const char* {
            switch (type) {
                case GL_DEBUG_TYPE_ERROR:
                    return "Error";
                case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
                    return "Deprecated Behavior";
                case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
                    return "Undefined Behavior";
                case GL_DEBUG_TYPE_PORTABILITY:
                    return "Portability";
                case GL_DEBUG_TYPE_PERFORMANCE:
                    return "Performance";
                case GL_DEBUG_TYPE_MARKER:
                    return "Marker";
                case GL_DEBUG_TYPE_PUSH_GROUP:
                    return "Push Group";
                case GL_DEBUG_TYPE_POP_GROUP:
                    return "Pop Group";
                case GL_DEBUG_TYPE_OTHER:
                    return "Other";
                default:
                    return "Unknown";
            }
        };

        auto stringify_severity = [](const GLenum severity) -> const char* {
            switch (severity) {
                case GL_DEBUG_SEVERITY_HIGH:
                    return "Fatal Error";
                case GL_DEBUG_SEVERITY_MEDIUM:
                    return "Error";
                case GL_DEBUG_SEVERITY_LOW:
                    return "Warning";
                case GL_DEBUG_SEVERITY_NOTIFICATION:
                    return "Note";
                default:
                    return "Unknown";
            }
        };

        auto to_print = fmt::format(
            "[{}] [{}/{}] ({}): {}\n",
            logger::get_current_timestamp(),
            stringify_severity(severity),
            stringify_source(source),
            stringify_type(type),
            message);
        (std::cout << to_print).flush();
        if (severity == GL_DEBUG_SEVERITY_HIGH || severity == GL_DEBUG_SEVERITY_MEDIUM) {
            throw std::runtime_error("High severity error, aborting");
        }
    }
}

#endif //NMINECRAFTPP_CALLBACKS_HPP
