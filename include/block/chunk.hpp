#ifndef NMINECRAFTPP_CHUNK_HPP
#define NMINECRAFTPP_CHUNK_HPP

#include "block.hpp"
#include "core/globals.hpp"

#include <vector>

namespace minecraft {
	class chunk {
		std::array<block, CHUNK_VOLUME> data{};
		std::vector<glm::ivec3> to_draw{};
	public:
		chunk(const std::array<block, CHUNK_VOLUME>&);
		void draw();
	};
}

#endif //NMINECRAFTPP_CHUNK_HPP
