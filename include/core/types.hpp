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
        info,
        warn,
        error
    };

    enum class error_codes {
        zero = 0,
        glfw_init,
        glfw_window_creation,
        glad_init,
        file_not_found,
        shader_compilation,
        shader_linking
    };
}

#endif //NMINECRAFTPP_TYPES_HPP
