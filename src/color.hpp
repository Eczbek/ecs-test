#ifndef ECS_HEADER_COLOR
#	define ECS_HEADER_COLOR

#	include <cstdint>
#	include "component.hpp"

namespace ecs {
	struct Color
	: ecs::Component {
		std::uint8_t red;
		std::uint8_t green;
		std::uint8_t blue;

		constexpr Color(const std::uint8_t red, const std::uint8_t green, const std::uint8_t blue) noexcept
		: red(red), green(green), blue(blue) {}
	};
}

#endif
