#include <type_traits>

template <typename E>
constexpr auto getUnderlyingEnumValue(E e) noexcept
{
	return static_cast<std::underlying_type_t<E>>(e);
}