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

    enum class log_codes {
        INFO,
        WARN,
        ERROR
    };

    enum class error_codes {
        ZERO = 0,
        GLFW_INIT,
        GLFW_WINDOW_CREATION,
        GLAD_INIT,
        FILE_NOT_FOUND,
        SHADER_COMPILATION,
        SHADER_LINKING
    };
}

#endif //NMINECRAFTPP_TYPES_HPP
