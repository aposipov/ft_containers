
#ifndef FT_CONTAINERS_ITERATOR_HPP
#define FT_CONTAINERS_ITERATOR_HPP

#include "Iterator_traits.hpp"

namespace ft {
	template <typename T>
	class random_access_iterator : iterator<std::random_access_iterator_tag> {
		pointer _it;
	};
}

#endif
