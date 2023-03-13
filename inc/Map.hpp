
#ifndef FT_CONTAINERS_MAP_HPP
#define FT_CONTAINERS_MAP_HPP

//#include <iostream>
#include "Pair.hpp"
#include "Iterator.hpp"
#include "utilities.hpp"

namespace ft {

	template<class Key, class T,
			class Compare = ft::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map {

		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef ft::pair<const Key, T>					value_type;
			typedef std::size_t								size_type;
			typedef std::ptrdiff_t							difference_type;
			typedef Compare									key_compare;
			typedef Allocator								allocator_type;
			typedef value_type&								reference;
			typedef const value_type&						const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;
			typedef value_type								iterator;
			typedef const value_type						const_iterator;
			typedef ft::reverse_iterator<iterator>			reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

			class value_compare {
				friend class map;
			protected:
				Compare comp;
				value_compare(Compare c) : comp(c) {}
			public:
				bool operator()(const value_type& x, const value_type& y) const
				{
					return comp(x.first, y.first);
				}
			};

			/* ------------------------- constructors ------------------------- */
//			map() {}

			explicit map(const Compare& comp, const Allocator& alloc = Allocator()) {}

			template < class InputIt >
			map(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()) {}

			map(const map& x) {}
			/* ------------------------- destructor ------------------------- */

			~map();


	};
}

#endif
