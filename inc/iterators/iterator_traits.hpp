#ifndef _ITERATOR_TRAITS_HPP
#define _ITERATOR_TRAITS_HPP

#include <iterator>

namespace ft
{
	// template <class Iterator>
	// class iterator_traits;

	// template <class T>
	// class iterator_traits<T*>;

	// template <class T>
	// class iterator_traits<const T*>;

	template<typename Iter>
	struct iterator_traits
	{
		typedef	typename Iter::difference_type		difference_type;
		typedef	typename Iter::value_type			value_type;
		typedef	typename Iter::pointer				pointer;
		typedef	typename Iter::reference			reference;
		typedef	typename Iter::iterator_category	iterator_category;

	};
}

#endif
