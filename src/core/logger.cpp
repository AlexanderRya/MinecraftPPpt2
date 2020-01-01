#include "core/logger.hpp"

namespace minecraft {
	types::i32 logger::log_error(const std::pair<std::string, types::log_codes>& e) {
		std::cout << fmt::format("[{}]: {} | CODE: {}\n", e.first, stringify_error_enum(e.second), get_enum_code(e.second));
		return get_enum_code(e.second);
	}

	std::string logger::stringify_error_enum(const types::log_codes& e) {
		switch (e) {
			case types::log_codes::ERROR_GLFW_FAILED_INIT:
				return "ERROR_GLFW_FAILED_INIT";
			case types::log_codes::ERROR_GLFW_FAILED_WINDOW_CREATION:
				return "ERROR_GLFW_FAILED_WINDOW_CREATION";
			case types::log_codes::ERROR_GLAD_FAILED_INIT:
				return "ERROR_GLAD_FAILED_INIT";
			case types::log_codes::ERROR_FILE_NOT_FOUND:
				return "ERROR_FILE_NOT_FOUND";
			case types::log_codes::ERROR_SHADER_COMPILE_FAILED:
				return "ERROR_SHADER_COMPILE_FAILED";
			case types::log_codes::ERROR_PROGRAM_LINK_FAILED:
				return "ERROR_PROGRAM_LINK_FAILED";
			default:
				return "??";
		}
	}

	types::i32 logger::get_enum_code(const types::log_codes& e) {
		switch (e) {
			case types::log_codes::ERROR_GLFW_FAILED_INIT:
				return 1;
			case types::log_codes::ERROR_GLFW_FAILED_WINDOW_CREATION:
				return 2;
			case types::log_codes::ERROR_GLAD_FAILED_INIT:
				return 3;
			case types::log_codes::ERROR_FILE_NOT_FOUND:
				return 4;
			case types::log_codes::ERROR_SHADER_COMPILE_FAILED:
				return 5;
			case types::log_codes::ERROR_PROGRAM_LINK_FAILED:
				return 6;
			default:
				return -1;
		}
	}

	void logger::log_success(const std::string& str) {
		std::cout << fmt::format("[{}]: {} | CODE: {}\n", str, "SUCCESS", 0);
	}
} // namespace minecraft
