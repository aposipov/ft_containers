
#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include "Iterator.hpp"

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
		typedef random_access_iterator<T>					iterator;
		typedef	random_access_iterator<const T>				const_iterator;
		typedef reverse_iterator<iterator>					reverse_iterator;
		typedef reverse_iterator<const_iterator>			const_reverse_iterator;

		/* ------------------------- constructors ------------------------- */
		explicit vector(const allocator_type &alloc = Allocator()) : _alloc(alloc), _size(0), _capacity(0), _array(NULL)
		{
			std::cout << "Default constructor called" << std::endl;
		}

		// try ?
		explicit vector(size_type n, const T &val = T(), const Allocator &alloc = Allocator()) :
				_alloc(alloc), _size(n), _capacity(n), _array(_alloc.allocate(n))
		{
			std::cout << "Parametric constructor called" << std::endl;
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_array + i, val);
		}

//		it
		template<class InputIt>
		vector(InputIt first, InputIt last, const Allocator &alloc = Allocator())
		{
			std::cout << "Iterator constructor called" << std::endl;
		}

		vector(const vector& other) : _alloc(other._alloc), _size(other._size), _capacity(other._capacity), _array
		(_alloc.allocate(_capacity))
		{
			std::cout << "Copy constructor called" << std::endl;
//			for (size_type i = 0; i < _size; i++)
//				_alloc.construct(_array + i, other[i]);
			*this = other;
		}

		/* ------------------------- destructors ------------------------- */
		~vector()
		{
			std::cout << "Destructor called" << std::endl;
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_array + i);
			if (_capacity)
				_alloc.deallocate(_array, _capacity);
		}

		/* ------------------------- member functions ------------------------- */
//		operator=
		vector &operator=(const vector &other)
		{
			std::cout << "Copy assignment operator called" << std::endl;
			if (this == &other)
				return *this;
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_array + i);
			_size = other._size;
			if (_capacity < _size)
			{
				if (capacity() != 0)
					_alloc.deallocate(_array, _capacity);
				_capacity = _size;
				_array = _alloc.allocate(_capacity);
			}
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(_array + i, other[i]);
			return *this;
		}

//		assign
		void assign(size_type count, const T& value)
		{
			clear();
			if (count > _capacity)
			{
				_alloc.deallocate(_array, _capacity);
				_array = _alloc.allocate(count);
				_capacity = count;
			}
			for (size_type i = 0; i < count; i++)
				_alloc.construct(_array + i, value);
			_size = count;
		}

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
		reference back() { return _array[_size - 1]; }
		const_reference back() const { return _array[_size - 1]; }

//		data
		pointer data() { return _array; }
		const_pointer data() const { return _array; }

		/* ------------------------- iterators m ------------------------- */
//		iterators
//		rever iterators

		/* ------------------------- capacity ------------------------- */
//		empty
		bool empty() const { return _size == 0; }

//		size
		size_type size() const { return _size; }

//		max_size
		size_type max_size() const { return _alloc.max_size(); }

//		reserve
		void reserve(size_type new_cap)
		{
			if (new_cap > max_size())
				throw std::length_error("Error: Vector reserve");
			if (new_cap <= _capacity)
				return ;
			pointer p = _alloc.allocate(new_cap);
			for (size_type i = 0; i < _size; i++)
				_alloc.construct(p + i, (*this)[i]);
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_array + i);
			_capacity = new_cap;
			_array = p;
		}

//		capacity
		size_type capacity() const { return _capacity; }

		/* ------------------------- modifiers ------------------------- */
//		clear
		void clear()
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_array + i);
			_size = 0;
		}

//		insert it

//		erase it

//		push_back
		void push_back(const T& value)
		{
			if (_capacity < _size + 1)
				reserve(_capacity * 2);
			_alloc.construct(_array + _size, value);
			_size++;
		}

//		pop_back
		void pop_back()
		{
			_alloc.destroy(_array + _size);
			_size--;
		}

//		resize
		void resize(size_type count, T value = T())
		{
			if (count < _size)
			{
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_array + i);
				_size = count;
			}
			else if (count > _size)
			{
				if (_capacity < count)
					reserve(_capacity * 2 > count ? _capacity * 2 : count);
				for (size_type i = _size; i < count; i++)
				{
					_alloc.construct(_array + i, value);
					_size++;
				}
			}
		}

//		swap
		void swap(vector& other)
		{
			if (this == &other)
				return ;
			allocator_type a = _alloc;
			pointer p = _array;
			size_type s = _size;
			size_type c = _capacity;
			_alloc = other._alloc;
			_array = other._array;
			_size = other._size;
			_capacity = other._capacity;
			other._alloc = a;
			other._array = p;
			other._size = s;
			other._capacity = c;
		}

		/* ------------------------- non-member functions ------------------------- */
//		friend bool operator==( const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs );
//		friend bool operator!=( const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs );
//		friend bool operator<( const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs );
//		friend bool operator<=( const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs );
//		friend bool operator>( const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs );
//		friend bool operator>=( const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs );

	private:
		allocator_type _alloc;
		size_type _size;
		size_type _capacity;
		pointer _array;
	};

	/* ------------------------- non-member functions ------------------------- */
	template< class T, class Allocator >
	bool operator==( const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs )
	{
		if (lhs.size() != rhs.size())
			return false;
		for (size_t i = 0; i < rhs.size(); i++)
			if (lhs[i] != rhs[i])
				return false;
		return true;
	}

	template< class T, class Allocator >
	bool operator!=( const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs )
	{
		return !(lhs == rhs);
	}

//	it
//	std::lexicographical_compare
//	bool operator<( const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs );

//	bool operator<=( const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs );
//	bool operator>( const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs );
//	bool operator>=( const std::vector<T, Allocator>& lhs, const std::vector<T, Allocator>& rhs );

	template< class T, class Alloc >
	void swap( ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs ) { lhs.swap(rhs); }
}

#endif