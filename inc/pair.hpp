#ifndef _PAIR_HPP
# define _PAIR_HPP

namespace ft
{
	template<typename T1, typename T2>
	struct pair
	{
		pair(void):first(), second(){}
		pair(const pair<const T1, T2> &other): first(other.first), second(other.second){}
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
				first = other.first;
				second = other.second;
			}
			return (*this);
		}

		//members
		T1	first;
		T2	second;

	};

	template <class T1, class T2>
	bool operator== (const pair< T1, T2>& lhs, const pair< T1,  T2>& rhs)
	{
		if (lhs.first == rhs.first)
		{
			if (lhs.second == rhs.second)
				return true;
		}
		return false;
	}

	template <class T1, class T2>
	bool operator< (const pair< T1, T2>& lhs, const pair< T1, const T2>& rhs)
	{
		if (lhs.first == rhs.first)
		{
			if (lhs.second < rhs.second)
				return true;
			return false;
		}
		return lhs.first < rhs.first;
	}

template<typename T1, typename T2>
pair<T1, T2>make_pair(T1 t1, T2 t2)
{
	pair<T1, T2>	res(t1, t2);
	return (res);
};
}
#endif
