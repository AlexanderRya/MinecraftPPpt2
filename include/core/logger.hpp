#ifndef NMINECRAFTPP_LOGGER_HPP
#define NMINECRAFTPP_LOGGER_HPP

#include "fmt/format.h"

#include "types.hpp"
#include "util/enum.hpp"
#include "util/rang.hpp"

#include <string>
#include <iostream>
#include <type_traits>
#include <fstream>
#include <chrono>
#include <ctime>

namespace minecraft {
    struct logger {
        template <auto Vx>
        static types::i32 log(std::string msg, const types::error_codes code) {
            rang::fgB color;
            auto to_print = fmt::format(
                "[{}] [{}] {} {}\n",
                get_current_timestamp(),
                stringify_error_level<Vx>(),
                msg, to_underlying_type(code));
            if constexpr (Vx == types::log_codes::INFO) {
                color = rang::fgB::green;
            } else if constexpr (Vx == types::log_codes::WARN) {
                color = rang::fgB::yellow;
            } else {
                color = rang::fgB::red;
            }
            std::cout << color << to_print << rang::fgB::green;
            return to_underlying_type(code);
        }

        static std::string get_current_timestamp() {
            namespace ch = std::chrono;

            auto time = ch::duration_cast<ch::seconds>(ch::high_resolution_clock::now().time_since_epoch()).count();

            std::string buf(128, '\0');
            buf.resize(std::strftime(buf.data(), buf.size(), "%Y-%m-%d %X", std::localtime(&time)));

            return buf;
        }
    private:
        template <auto Vx>
        constexpr static std::string_view stringify_error_level() {
            return util::enum_name<Vx>();
        }

        static std::underlying_type_t<types::error_codes> to_underlying_type(const types::error_codes& e) {
            return static_cast<std::underlying_type_t<types::error_codes>>(e);
        }
    };
}

#endif //NMINECRAFTPP_LOGGER_HPP
