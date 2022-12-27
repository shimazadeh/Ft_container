#ifndef _PAIR_HPP
# define _PAIR_HPP

namespace ft
{
	template<typename T1, typename T2>
	struct pair
	{
		// typedef	T1	first;
		// typedef	T2	second;

		pair(void):first(), second(){}
		pair(const pair<T1, T2> &other): first(other.first), second(other.second){}
		pair(const T1 t1, const T2 t2):first(t1), second(t2){}
		~pair(){}

		void	swap(pair &other)
		{
			pair	tmp = other;

			other.first = first;
			other.second = second;

			first = tmp.first;
			second = tmp.second;
		}

		pair& operator=(const pair& other)
		{
			if (this != &other)
			{
				first = other.T1;
				second = other.T2;
			}
			return (*this);
		}

		//members
		T1	first;
		T2	second;

	};

template<typename T1, typename T2>
pair<T1, T2>make_pair(T1 t1, T2 t2)
{
	pair<T1, T2>	res(t1, t2);
	return (res);
};
}
#endif
