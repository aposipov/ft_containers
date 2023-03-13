
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

			/* ------------------------- member functions ------------------------- */
			map& operator=(const map& other);

			allocator_type get_allocator() const;

			/* ------------------------- element access ------------------------- */
			T& at( const Key& key );

			const T& at( const Key& key ) const;

			T& operator[]( const Key& key );

			/* ------------------------- iterators ------------------------- */
			iterator begin();

			const_iterator begin() const;

			iterator end();

			const_iterator end() const;

			reverse_iterator rbegin();

			const_reverse_iterator rbegin() const;

			reverse_iterator rend();

			const_reverse_iterator rend() const;

			/* ------------------------- capacity ------------------------- */
			bool empty() const;

			size_type size() const;

			size_type max_size() const;

			/* ------------------------- modifiers ------------------------- */
			void clear();

			ft::pair<iterator, bool> insert( const value_type& value );

			iterator insert( iterator pos, const value_type& value );

			iterator erase( iterator pos );

			iterator erase( iterator first, iterator last );

//			size_type erase( const Key& key );

			void swap( map& other );

			/* ------------------------- lookup ------------------------- */
			size_type count( const Key& key ) const;

			iterator find( const Key& key );

			const_iterator find( const Key& key ) const;

			ft::pair<iterator,iterator> equal_range( const Key& key );

			ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;

			iterator lower_bound( const Key& key );

			const_iterator lower_bound( const Key& key ) const;

			iterator upper_bound( const Key& key );

			const_iterator upper_bound( const Key& key ) const;

			/* ------------------------- observers ------------------------- */
			key_compare key_comp() const;

			ft::map::value_compare value_comp() const;

	};

	/* ------------------------- non-member functions ------------------------- */

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const std::map<Key, T, Compare, Alloc>& lhs,
					 const std::map<Key, T, Compare, Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const std::map<Key, T, Compare, Alloc>& lhs,
					 const std::map<Key, T, Compare, Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const std::map<Key, T, Compare, Alloc>& lhs,
					const std::map<Key, T, Compare, Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const std::map<Key, T, Compare, Alloc>& lhs,
					 const std::map<Key, T, Compare, Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const std::map<Key, T, Compare, Alloc>& lhs,
					const std::map<Key, T, Compare, Alloc>& rhs );

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const std::map<Key, T, Compare, Alloc>& lhs,
					 const std::map<Key, T, Compare, Alloc>& rhs );

}

#endif
