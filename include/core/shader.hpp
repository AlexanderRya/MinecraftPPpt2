#ifndef NMINECRAFTPP_SHADER_HPP
#define NMINECRAFTPP_SHADER_HPP

#include <renderer/glad.hpp>
#include "glm/matrix.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "types.hpp"

#include <filesystem>

namespace minecraft {
    class shader {
        types::i32 id;

        bool get_compile_status(const types::u32) const;
        bool get_link_status(const types::u32) const;
        std::string get_compile_log(const types::u32) const;
        std::string get_link_log(const types::u32) const;
    public:
        shader(const std::filesystem::path&, const std::filesystem::path&);

        void use() const;
        void end() const;
        void set_mat4(const char*, const glm::mat4&) const;
    };
}

#endif //NMINECRAFTPP_SHADER_HPP
