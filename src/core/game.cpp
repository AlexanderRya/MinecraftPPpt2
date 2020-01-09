#include "core/game.hpp"

namespace minecraft {
    types::i32 game::run() {
        shader chunk_shader("chunk.vert", "chunk.frag");

        chunk_shader.use();
        chunk_shader.set_mat4("model", glm::mat4(1.0f));
        chunk_shader.end();

        world THE_WORLD;
        THE_WORLD.generate_chunk({ 0, 0, 0 });

        renderer rend(THE_WORLD.get_chunks());

        while (!glfwWindowShouldClose(window)) {
            double current_frame = glfwGetTime();
            delta_time = current_frame - last_frame;
            last_frame = current_frame;

            glClearColor(0.2, 0.2, 0.2, 1.0);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            chunk_shader.use();

            chunk_shader.set_mat4("pv_mat", camera::proj_mat * cam.get_view_mat());
            rend.render();

            chunk_shader.end();

            process_input();
            glfwPollEvents();
            glfwSwapBuffers(window);
        }
        return logger::log<types::log_codes::info>(
            "main loop exited with code:", types::error_codes::zero);
    }

    types::i32 game::init() {
        // glfw init
        if (!glfwInit()) {
            return logger::log<types::log_codes::error>(
                "at glfwInit with code:", types::error_codes::glfw_init);
        }

        logger::log<types::log_codes::info>(
            "glfwInit exited with code:", types::error_codes::zero);

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        if (!(window = glfwCreateWindow(minecraft::WIDTH, minecraft::HEIGHT, "MinecraftPP", nullptr, nullptr))) {
            return logger::log<types::log_codes::error>(
                "at glfwCreateWindow with code:", types::error_codes::glfw_window_creation);
        }

        logger::log<types::log_codes::info>(
            "glfwCreateWindow exited with code:", types::error_codes::zero);

        glfwMakeContextCurrent(window);
        glfwSwapInterval(0);

        // glad init
        if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
            glfwTerminate();
            return logger::log<types::log_codes::error>(
                "at gladLoadGLLoader with code:", types::error_codes::glad_init);
        }

        logger::log<types::log_codes::info>(
            "gladLoadGLLoader exited with code:", types::error_codes::zero);

        glViewport(0, 0, minecraft::WIDTH, minecraft::HEIGHT);

        glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
        glfwSetCursorPosCallback(window, mouse_callback);
        glfwSetKeyCallback(window, key_callback);
        glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);

        // set debug callback
        glEnable(GL_DEBUG_OUTPUT);
        glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        glDebugMessageCallback(debug_callback, nullptr);

        return 0;
    }

    void game::process_input() const {
        cam.move(window);
    }
}
