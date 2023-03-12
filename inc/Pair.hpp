
#ifndef FT_CONTAINERS_PAIR_HPP
#define FT_CONTAINERS_PAIR_HPP

namespace ft {

	template<class T1, class T2>
	struct pair
	{

	public:

		typedef T1 first_type;
		typedef T2 second_type;

		T1 first;
		T2 second;

		pair() : first(), second() {}

		pair(const first_type &a, const second_type &b) : first(a), second(b) {}

		template<class U, class V>
		pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}

		~pair() {}

		pair& operator=(const pair& other)
		{
			first = other.first;
			second = other.second;
			return *this;
		}
	};

	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 t, T2 u) { return pair<T1, T2>(t, u); }

	template< class T1, class T2, class U1, class U2 >
	bool operator==(const pair<T1, T2>& lhs, const pair<U1, U2>& rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template< class T1, class T2, class U1, class U2 >
	bool operator!=(const pair<T1, T2>& lhs, const pair<U1, U2>& rhs)
	{
		return !(lhs == rhs);
	}

	template< class T1, class T2, class U1, class U2 >
	bool operator<(const pair<T1, T2>& lhs, const pair<U1, U2>& rhs)
	{
		return lhs.first == rhs.first ? lhs.second < rhs.second : lhs.first < rhs.first;
	}

	template< class T1, class T2, class U1, class U2 >
	bool operator<=(const pair<T1, T2>& lhs, const pair<U1, U2>& rhs)
	{
		return !(lhs > rhs);
	}

	template< class T1, class T2, class U1, class U2 >
	bool operator>(const pair<T1, T2>& lhs, const pair<U1, U2>& rhs)
	{
		return lhs < rhs;
	}

	template< class T1, class T2, class U1, class U2 >
	bool operator>=(const pair<T1, T2>& lhs, const pair<U1, U2>& rhs)
	{
		return !(lhs < rhs);
	}
}

#endif
