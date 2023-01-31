#ifndef _EQUAL_HPP
# define _EQUAL_HPP

#include "./iterator.hpp"
#include "./Is_Integral.hpp"

namespace ft
{
	template<bool B, typename T = void >
	struct	enable_if{};

	template<typename T>
	struct	enable_if<true, T>
	{
		typedef T type;
	};
}

namespace ft
{
	template<typename InputIt1, typename InputIt2>
	bool	equal(InputIt1 first1, InputIt2 last1, InputIt2 first2, typename ft::enable_if<!ft::is_integral<InputIt1>::value>:: type* = 0, typename ft::enable_if<!ft::is_integral<InputIt2>::value>:: type* = 0)
	{
		while(first1 != last1)
		{
			if (*first1 != *first2)
				return false;
			first1++;
			first2++;
		}
		return true;
	};

	template<typename InputIt1, typename InputIt2>
	bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2, typename ft::enable_if<!ft::is_integral<InputIt1>::value>:: type* = 0, typename ft::enable_if<!ft::is_integral<InputIt2>::value>:: type* = 0)
	{
		InputIt1 i = first1;
		InputIt2 j = first2;

		while (i != last1 && j != last2 && *i == *j)
		{
			i++;
			j++;
		}
		if (i == last1 && j == last2)
			return true;
		return false;
	};
}
#endif

