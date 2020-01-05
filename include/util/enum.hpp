#ifndef NMINECRAFTPP_ENUM_HPP
#define NMINECRAFTPP_ENUM_HPP

#include <string_view>

namespace minecraft::util {
    namespace {
        constexpr auto get_enum_name(std::string_view str) {
            return str.substr(str.find_last_of(':') + 1, str.size());
        }
    }

    template <auto Vx>
    constexpr auto enum_name() {
        return get_enum_name({ __PRETTY_FUNCTION__, sizeof(__PRETTY_FUNCTION__) - 2 });
    }
}
#endif //NMINECRAFTPP_ENUM_HPP
