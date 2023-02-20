
#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <iostream>
//#include
//#include "iterator.h"

namespace ft {

	template < class T, class Allocator = std::allocator<T> >
	class vector
	{

	public:

		/* ------------------------- member types ------------------------- */
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef value_type &reference;
		typedef const value_type &const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;

		/* ------------------------- iterators ------------------------- */
//		typedef random_access_it<T>						iterator;
//		typedef	random_access_it<const T>				const_iterator;
//		typedef reverse_it<iterator>					reverse_iterator;
//		typedef reverse_it<const_iterator>				const_reverse_iterator;

		/* ------------------------- constructors ------------------------- */
		explicit vector(const allocator_type &alloc = Allocator()) : _alloc(alloc), _size(0), _capacity(0), _array(NULL)
		{}

		// try ?
		explicit vector(size_type n, const T &val = T(), const Allocator &alloc = Allocator()) :
				_alloc(alloc), _size(n), _capacity(n), _array(_alloc.allocate(n))
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_array + i, val);
		}

		template<class InputIt>
		vector(InputIt first, InputIt last, const Allocator &alloc = Allocator())
		{}

		vector(const vector &other)
		{}

		/* ------------------------- destructors ------------------------- */
		~vector()
		{}

		/* ------------------------- member functions ------------------------- */
		vector &operator=(const vector &other)
		{}
//		assign

//		get_allocator
		allocator_type get_allcator() const
		{
			return _alloc;
		}

		/* ------------------------- element access ------------------------- */
//		at
		reference at(size_type pos)
		{
			if (!(pos < _size))
				throw std::out_of_range("Error: Vector at");
			return *(_array + pos);
		}

		const_reference at(size_type pos) const
		{
			if (!(pos < _size))
				throw std::out_of_range("Error: Vector at");
			return *(_array + pos);
		}

//		operator[]
		reference operator[](size_type pos) { return *(_array + pos); }
		const_reference operator[](size_type pos) const { return *(_array + pos); }

//		front
		reference front() { return _array[0]; }
		const_reference front() const { return _array[0]; }

//		back
		reference back() { return (_size - 1); }
		const_reference back() const { return (_size - 1); }

//		data
		pointer data() { return _array; }
		const_pointer data() const { return _array; }

		/* ------------------------- iterators m ------------------------- */
//		iterators
//		rever iterators

		/* ------------------------- capacity ------------------------- */
//		empty
//		size
//		max_size
//		reserve
//		capacity

		/* ------------------------- modifiers ------------------------- */


		/* ------------------------- non-member functions ------------------------- */

	private:
		allocator_type _alloc;
		size_type _size;
		size_type _capacity;
		pointer _array;
	};

}

#endif