#ifndef ECS_HEADER_POSITION
#	define ECS_HEADER_POSITION

#	include <cstddef>
#	include "component.hpp"

namespace ecs {
	struct Position
	: ecs::Component {
		std::size_t x;
		std::size_t y;

		constexpr Position(const std::size_t x, const std::size_t y) noexcept
		: x(x), y(y) {}
	};
}

#endif
