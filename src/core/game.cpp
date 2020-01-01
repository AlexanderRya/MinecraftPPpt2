#include "core/game.hpp"

namespace minecraft {
	types::i32 game::run() {
		shader chunk_shader("chunk.vert", "chunk.frag");
		while (!glfwWindowShouldClose(w)) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(0.2, 0.2, 0.2, 1.0);
			glfwPollEvents();
			glfwSwapBuffers(w);
		}
		return logger::log_success("MINECRAFT::MAIN"), 0;
	}

	types::i32 game::init() {
		if (!glfwInit()) {
			return logger::log_error({ "GLFW", types::log_codes::ERROR_GLFW_FAILED_INIT });
		}

		logger::log_success("GLFW_INIT");

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		if (!(w = glfwCreateWindow(minecraft::WIDTH, minecraft::HEIGHT, "MinecraftPP", nullptr, nullptr))) {
			return logger::log_error({ "GLFW",types::log_codes::ERROR_GLFW_FAILED_WINDOW_CREATION });
		}

		logger::log_success("CREATE_WINDOW");

		glfwMakeContextCurrent(w);
		glfwSwapInterval(0);

		if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
			glfwTerminate();
			return logger::log_error({ "GLAD", types::log_codes::ERROR_GLAD_FAILED_INIT });
		}

		logger::log_success("GLAD_INIT");

		glViewport(0, 0, minecraft::WIDTH, minecraft::HEIGHT);

		glfwSetFramebufferSizeCallback(w, [](GLFWwindow*, const int vwidth, const int vheight) {
			glViewport(0, 0, vwidth, vheight);
		});

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);

		return 0;
	}
}
