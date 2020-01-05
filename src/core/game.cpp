#include "core/game.hpp"

namespace minecraft {
    types::i32 game::run() {
        shader chunk_shader("chunk.vert", "chunk.frag");
        //world world;
        //world.get_chunks().emplace_back();
        while (!glfwWindowShouldClose(window)) {
            double current_frame = glfwGetTime();
            delta_time = current_frame - last_frame;
            last_frame = current_frame;
            glClearColor(0.2, 0.2, 0.2, 1.0);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            chunk_shader.use();
            chunk_shader.end();
            glfwPollEvents();
            glfwSwapBuffers(window);
        }
        return logger::log<types::log_codes::INFO>(
            "main loop exited", types::error_codes::ZERO);
    }

    types::i32 game::init() {
        // glfw init
        if (!glfwInit()) {
            return logger::log<types::log_codes::ERROR>(
                "at glfwInit", types::error_codes::GLFW_INIT);
        }

        logger::log<types::log_codes::INFO>(
            "glfwInit exited", types::error_codes::ZERO);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        if (!(window = glfwCreateWindow(minecraft::WIDTH, minecraft::HEIGHT, "MinecraftPP", nullptr, nullptr))) {
            return logger::log<types::log_codes::ERROR>(
                "at glfwCreateWindow", types::error_codes::GLFW_WINDOW_CREATION);
        }

        logger::log<types::log_codes::INFO>(
            "glfwCreateWindow exited", types::error_codes::ZERO);

        glfwMakeContextCurrent(window);
        glfwSwapInterval(0);

        // glad init
        if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
            glfwTerminate();
            return logger::log<types::log_codes::ERROR>(
                "at gladLoadGLLoader", types::error_codes::GLAD_INIT);
        }

        logger::log<types::log_codes::INFO>(
            "gladLoadGLLoader exited", types::error_codes::ZERO);

        glViewport(0, 0, minecraft::WIDTH, minecraft::HEIGHT);

        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);

        // set debug callback
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(debug_callback, nullptr);

        return 0;
    }
}
