#ifndef _EQUAL_HPP
# define _EQUAL_HPP

#include <iterator>

//maybe I need to use my own iterator???

namespace ft
{
	template<typename InputIt1, typename InputIt2>
	bool	equal(InputIt1 first1, InputIt2 last1, InputIt2 first2)
	{
		for (std::iterator<iterator> i = first1; i != last1; i++)
		{
			if (*i != *(first2 + (i - first1)))
				return false;
		}
		return true;
	};

	template<typename InputIt1, typename InputIt2>
	bool	equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
	{
		if (last1 - first1 != last2 - first2)
			return false;
		for (std::iterator<iterator> i = first1, j = first2; i != last1 && j != last2; i++, j++)
		{
			if (*first1 != *first2)
				return false;
		}
		return true;
	};

	template<bool B, typename T = void >
	struct	enable_if{};

	template<typename T>
	struct	enable_if<true, T>
	{
		typedef T type;
	};
}
#endif
