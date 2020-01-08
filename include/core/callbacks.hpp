#ifndef NMINECRAFTPP_CALLBACKS_HPP
#define NMINECRAFTPP_CALLBACKS_HPP

#include "fmt/format.h"

#include "logger.hpp"

#include <iostream>

namespace minecraft {
    inline void framebuffer_size_callback(GLFWwindow*, const int vwidth, const int vheight) {
        glViewport(0, 0, vwidth, vheight);
    }

    inline void mouse_callback(GLFWwindow*, const double xpos, const double ypos) {
        static double lastX = HEIGHT / 2.0, lastY = WIDTH / 2.0;
        static bool first = true;

        if (first) {
            lastX = xpos;
            lastY = ypos;
            first = false;
        }

        double xoffset = xpos - lastX;
        double yoffset = lastY - ypos;

        lastX = xpos;
        lastY = ypos;

        cam.process(xoffset, yoffset);
    }

    inline void key_callback(GLFWwindow* w, const int key, const int scancode, const int action, const int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
            glfwSetWindowShouldClose(w, true);
        }
    }

    inline void debug_callback(const GLenum source, const GLenum type, const GLuint id, const GLenum severity, GLsizei, const GLchar* const message, const void*) {
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
        
        // Filtering useless errors
        // 131218: "Program/shader state performance warning: Vertex shader in program 3 is being recompiled based on GL state."
        if (id != 131218) {
            auto to_print = fmt::format(
                "[{}] [{}/{}, id = {}] ({}): {}\n",
                logger::get_current_timestamp(),
                stringify_severity(severity),
                stringify_source(source),
                id,
                stringify_type(type),
                message);
            (std::cout << to_print).flush();
            if (severity == GL_DEBUG_SEVERITY_HIGH ||
                severity == GL_DEBUG_SEVERITY_MEDIUM) {
                throw std::runtime_error("High severity error, aborting");
            }
        }
    }
}

#endif //NMINECRAFTPP_CALLBACKS_HPP
