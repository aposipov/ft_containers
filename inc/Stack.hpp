
#ifndef FT_CONTAINERS_STACK_HPP
#define FT_CONTAINERS_STACK_HPP

#include "Vector.hpp"

namespace ft {

	template < class T, class Container = ft::vector<T> >
	class stack {

	public:
		typedef Container								container_type;
		typedef typename Container::value_type			value_type;
		typedef typename Container::size_type			size_type;
		typedef typename Container::reference			reference;
		typedef typename Container::const_reference		const_reference;

	protected:

		Container _ctnr;

	public:

		explicit stack(const container_type& ctnr = container_type()) : _ctnr(ctnr) {}

		~stack() {}

//		operator=
		stack& operator=(const stack& other)
		{
			_ctnr = other._ctnr;
			return *this;
		}

//		top
		value_type& top() { return _ctnr.back(); }
		const value_type& top() const {return  _ctnr.back(); }

//		empty
		bool empty() const { return _ctnr.empty(); }

//		size
		size_type size() const { return _ctnr.size(); }

//		push
		void push(const value_type& val) { return _ctnr.push_back(val); }

//		pop
		void pop() { return _ctnr.pop_back(); }

	};

	/* ------------------------- non-member functions ------------------------- */
	template <class T, class Container>
	bool operator==(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs == rhs; }

	template <class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs != rhs; }

	template <class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs < rhs; }

	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs <= rhs; }

	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs > rhs; }

	template <class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs >= rhs; }
}

#endif
