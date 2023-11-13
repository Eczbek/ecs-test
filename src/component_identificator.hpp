#ifndef ECS_HEADER_COMPONENT_IDENTIFICATOR
#	define ECS_HEADER_COMPONENT_IDENTIFICATOR

#	include <concepts>
#	include <cstddef>
#	include <limits>
#	include <stdexcept>
#	include "component.hpp"
#	include "mask.hpp"

namespace ecs {
	class ComponentIdentificator {
	public:
		template<std::derived_from<ecs::Component>>
		static std::size_t get() {
			return ecs::ComponentIdentificator::getNextIdentifier();
		}

	private:
		static std::size_t getNextIdentifier() {
			static std::size_t nextIdentifier = 0;
			if (nextIdentifier >= std::numeric_limits<ecs::Mask>::digits) {
				throw std::domain_error("Component identifiers exhausted");
			}
			return nextIdentifier++;
		}
	};
}

#endif
