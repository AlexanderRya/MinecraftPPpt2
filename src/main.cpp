#include "core/game.hpp"

int main() {
    minecraft::game g{};

    if (auto code = g.init(); code != 0) {
        return code;
    }

    return g.run();
}
