
#ifndef FT_CONTAINERS_ITERATOR_HPP
#define FT_CONTAINERS_ITERATOR_HPP

#include "Iterator_traits.hpp"

namespace ft {
	template <typename T>
class random_access_iterator : public ft::iterator<random_access_iterator_tag, T> {

	public:
		typedef typename ft::iterator<random_access_iterator_tag, T>::value_type		value_type;
		typedef typename ft::iterator<random_access_iterator_tag, T>::difference_type	difference_type;
		typedef typename ft::iterator<random_access_iterator_tag, T>::pointer			pointer;
		typedef typename ft::iterator<random_access_iterator_tag, T>::reference			reference;
		typedef typename ft::iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;

	protected:
		pointer _it;

	public:
		random_access_iterator() : _it(NULL) {}
		random_access_iterator(pointer it) : _it(it) {}
		random_access_iterator(const random_access_iterator& ref) { *this = ref; }
		random_access_iterator& operator=(const random_access_iterator& other)
		{
			if (this != &other)
				_it = other._it;
			return *this;
		}
		~random_access_iterator() {}

		/* ------------------------- *a a->m ------------------------- */
		reference operator*() const { return *_it; }
		pointer operator->() const { return _it; }

		/* ------------------------- *a = t ------------------------- */

		/* ------------------------- ++a a++ *a++ ------------------------- */
		random_access_iterator& operator++()
		{
			++_it;
			return *this;
		}



		/* ------------------------- --a a-- *a-- ------------------------- */
		random_access_iterator& operator--()
		{
			--_it;
			return *this;
		}

		/* ------------------------- a+n n+a a-n a-b ------------------------- */
		random_access_iterator& operator+(difference_type n) const
		{
			random_access_iterator tmp(_it + n);
			return tmp;
		}

//		difference_type operator+()

		/* ------------------------- a+=n a-=n ------------------------- */
		random_access_iterator& operator+=(difference_type n) { return _it = _it + n; }
		random_access_iterator& operator-=(difference_type n) { return _it = _it - n; }

		/* ------------------------- a[n] ------------------------- */
		reference operator[](difference_type n) { return *(n + _it); }

		/* ------------------------- == != a<b a>b a<=b a>=b ------------------------- */
		bool operator==(const random_access_iterator& it) const { return _it == it._it; }
		bool operator!=(const random_access_iterator& it) const { return _it != it._it; }
		bool operator<(const random_access_iterator& it) const { return _it < it._it; }
		bool operator>(const random_access_iterator& it) const { return _it > it._it; }
		bool operator<=(const random_access_iterator& it) const { return _it <= it._it; }
		bool operator>=(const random_access_iterator& it) const { return _it >= it._it; }
	};
}

#endif
