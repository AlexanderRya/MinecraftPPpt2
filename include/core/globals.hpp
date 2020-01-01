#ifndef NMINECRAFTPP_GLOBALS_HPP
#define NMINECRAFTPP_GLOBALS_HPP

#include "types.hpp"
#include "block/vertex.hpp"

#include <array>

namespace minecraft {
	constexpr auto WIDTH = 1280;
	constexpr auto HEIGHT = 720;

	inline types::f64 delta_time = 0;
	inline types::f64 last_frame = 0;

	inline std::array<vertex, 8> generate_indexed_cube_geometry() {
		return { {
			{ { 1, 1, 1 }, { 1,1 } },
			{ { 1, 0, 1 }, { 1, 0 } },
			{ { 0, 1, 1 }, { 0, 1 } },
			{ { 0, 0, 1 }, { 0, 0 } }
		} };
	}

	inline std::array<types::u32, 6> generate_indices() {
		return {
			0, 1, 3,
			0, 1, 2
		};
	}

	constexpr auto CHUNK_LAYER = 16;
	constexpr auto CHUNK_SIZE = 16 * CHUNK_LAYER;
	constexpr auto CHUNK_VOLUME = 16 * CHUNK_SIZE;
} // namespace minecraft


#endif //NMINECRAFTPP_GLOBALS_HPP
