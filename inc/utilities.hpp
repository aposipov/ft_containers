
#ifndef FT_CONTAINERS_UTILITIES_HPP
#define FT_CONTAINERS_UTILITIES_HPP

#include <iostream>

namespace ft {

	template <class T>
	struct is_iterator
	{
	private:
		template <class C>
		static typename C::iterator_category f(int a) { return C::iterator_category(); };

		template <class C>
		static double f(...) { return 0; };

	public:
		static const bool value = sizeof(f<T>(1)) != sizeof(double);
	};

	template <class T>
	struct is_iterator<T *>
	{
		static const bool value = true;
	};

	template <bool B, typename T = void>
	struct enable_if { };

	template <typename T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

	template <class T>
	void swap(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

	template <class InputIt1, class InputIt2>
	bool equal(InputIt1 first1, InputIt1 last1,
			   InputIt2 first2)
	{
		for (; first1 != last1; ++first1, ++first2)
		{
			if (!(*first1 == *first2))
			{
				return false;
			}
		}
		return true;
	}

	template <class T>
	struct less {
		bool operator()( const T& lhs, const T& rhs ) const
		{
			return lhs < rhs;
		}
	};

	template < class InputIt1, class InputIt2 >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2 )
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (*first1 < *first2)
				return true;
			if (*first2 < *first1)
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}

	template < class InputIt1, class InputIt2, class Compare >
	bool lexicographical_compare( InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, Compare comp )
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, (void) ++first2)
		{
			if (comp(*first1, *first2))
				return true;
			if (comp(*first2, *first1))
				return false;
		}
		return (first1 == last1) && (first2 != last2);
	}
}

#endif
