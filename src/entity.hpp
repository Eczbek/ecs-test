#ifndef ECS_HEADER_ENTITY
#	define ECS_HEADER_ENTITY

#	include <concepts>
#	include <cstddef>
#	include <cstdint>
#	include "component.hpp"
#	include "component_identificator.hpp"
#	include "mask.hpp"

namespace ecs {
	class Entity {
	public:
		const std::size_t identifier;

		template<std::derived_from<ecs::Component> Component>
		bool has() const noexcept {
			return (this->mask >> ecs::ComponentIdentificator::get<Component>) & 1;
		}

		template<std::derived_from<ecs::Component>... Components>
		Entity() noexcept
		: mask((... | (1 << ecs::ComponentIdentificator::get<Components>))) {
			static std::size_t nextIdentifier = 0;
			this->identifier = nextIdentifier++;
		}

	private:
		const ecs::Mask mask;
	};
}

#endif
