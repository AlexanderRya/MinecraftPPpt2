#ifndef NMINECRAFTPP_LOGGER_HPP
#define NMINECRAFTPP_LOGGER_HPP

#include "fmt/format.h"

#include "types.hpp"

#include <string>
#include <iostream>
#include <fstream>

namespace minecraft {
	struct logger {
		static types::i32 log_error(const std::pair<std::string, types::log_codes>& e);
		static void log_success(const std::string&);
	private:
		static std::string stringify_error_enum(const types::log_codes&);
		static types::i32 get_enum_code(const types::log_codes&);
	};
}

#endif //NMINECRAFTPP_LOGGER_HPP
