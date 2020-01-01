#ifndef NMINECRAFTPP_TYPES_HPP
#define NMINECRAFTPP_TYPES_HPP

namespace minecraft::types {
	using i8 = signed char;
	using i16 = signed short;
	using i32 = signed int;
	using i64 = signed long long;

	using u8 = unsigned char;
	using u16 = unsigned short;
	using u32 = unsigned int;
	using u64 = unsigned long long;

	using f32 = float;
	using f64 = double;

	using isize = i64;
	using usize = u64;

	enum class log_codes : i32 {
		ERROR_GLFW_FAILED_INIT = 1,
		ERROR_GLFW_FAILED_WINDOW_CREATION,
		ERROR_GLAD_FAILED_INIT,
		ERROR_FILE_NOT_FOUND,
		ERROR_SHADER_COMPILE_FAILED,
		ERROR_PROGRAM_LINK_FAILED
	};
}

#endif //NMINECRAFTPP_TYPES_HPP
