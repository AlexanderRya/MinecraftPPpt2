#ifndef NMINECRAFTPP_SHADER_HPP
#define NMINECRAFTPP_SHADER_HPP

#include "glad/glad.h"
#include "glm/matrix.hpp"

#include "types.hpp"

#include <string>

namespace minecraft {
	class shader {
		types::i32 id;
		types::u32 pv_location, model_location;

		bool get_compile_status(const types::u32) const;
		bool get_link_status(const types::u32) const;
		std::string get_compile_log(const types::u32) const;
		std::string get_link_log(const types::u32) const;
	public:
		shader(const std::string&, const std::string&);
		void use() const;
		void set_mat4(const glm::mat4&);
	};
}

#endif //NMINECRAFTPP_SHADER_HPP
