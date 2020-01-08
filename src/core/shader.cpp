#include "core/shader.hpp"
#include "core/logger.hpp"

namespace minecraft {
    shader::shader(const std::filesystem::path& vertex, const std::filesystem::path& fragment) {
        std::ifstream
            vin("../assets/shaders/" + vertex.generic_string()),
            fin("../assets/shaders/" + fragment.generic_string());

        if (!vin.is_open()) {
            logger::log<types::log_codes::ERROR>(
                "file not found error at: " + vertex.generic_string() + ", code:",
                types::error_codes::FILE_NOT_FOUND);

            throw std::runtime_error(
                fmt::format("can't find shader at: {}", vertex.generic_string() + ", code:"));
        }
        if (!fin.is_open()) {
            logger::log<types::log_codes::ERROR>(
                "file not found error at: " + fragment.generic_string() + ", code:",
                types::error_codes::FILE_NOT_FOUND);

            throw std::runtime_error(
                fmt::format("can't find shader at: {}", fragment.generic_string() + ", code:"));
        }

        std::string
            temp_vsource{ std::istreambuf_iterator{ vin }, {}},
            temp_fsource{ std::istreambuf_iterator{ fin }, {}};

        auto vertex_source = temp_vsource.c_str();
        auto fragment_source = temp_fsource.c_str();

        types::u32
            vshader = glCreateShader(GL_VERTEX_SHADER),
            fshader = glCreateShader(GL_FRAGMENT_SHADER);

        glShaderSource(vshader, 1, &vertex_source, nullptr);
        glCompileShader(vshader);
        if (!get_compile_status(vshader)) {
            throw std::runtime_error(
                fmt::format("vertex shader compilation failed, log:\n{}",
                    get_compile_log(vshader)));
        }

        glShaderSource(fshader, 1, &fragment_source, nullptr);
        glCompileShader(fshader);
        if (!get_compile_status(fshader)) {
            throw std::runtime_error(
                fmt::format("fragment shader compilation failed, log:\n {}",
                    get_compile_log(fshader)));
        }

        id = glCreateProgram();

        glAttachShader(id, vshader);
        glAttachShader(id, fshader);

        glLinkProgram(id);
        if (!get_link_status(id)) {
            throw std::runtime_error(
                fmt::format("shader program linking failed, log:\n {}",
                    get_link_log(id)));
        }

        glDeleteShader(vshader);
        glDeleteShader(fshader);

        logger::log<types::log_codes::INFO>(
            fmt::format("shader creation for: {} and {} exited with code:",
                vertex.generic_string(), fragment.generic_string()),
            types::error_codes::ZERO);
    }

    std::string shader::get_compile_log(const types::u32 shader) const {
        types::i32 log_length = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_length);
        std::string log(log_length, '\0');
        glGetShaderInfoLog(shader, log_length, &log_length, &log[0]);
        logger::log<types::log_codes::ERROR>(
            "at glCompileShader with code:", types::error_codes::SHADER_COMPILATION);
        return log;
    }

    std::string shader::get_link_log(const types::u32 program) const {
        types::i32 log_length = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &log_length);
        std::string log(log_length, '\0');
        glGetProgramInfoLog(program, log_length, &log_length, &log[0]);
        logger::log<types::log_codes::ERROR>(
            "at glLinkProgram with code:", types::error_codes::SHADER_LINKING);
        return log;
    }

    bool shader::get_compile_status(const types::u32 shader) const {
        types::i32 success = 0;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        return static_cast<bool>(success);
    }

    bool shader::get_link_status(const types::u32 program) const {
        types::i32 success;
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        return static_cast<bool>(success);
    }

    void shader::use() const {
        glUseProgram(id);
    }

    void shader::end() const {
        glUseProgram(0);
    }

    void shader::set_mat4(const char* name, const glm::mat4& mat) const {
        glUniformMatrix4fv(glGetUniformLocation(id, name), 1, false, glm::value_ptr(mat));
    }
}
