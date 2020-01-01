#ifndef NMINECRAFTPP_BLOCK_HPP
#define NMINECRAFTPP_BLOCK_HPP

#include "vertex.hpp"

namespace minecraft {
	struct block {
		glm::ivec3 pos;
		enum class type {
			air,
			dirt
		} t;
	};
}

#endif //NMINECRAFTPP_BLOCK_HPP
