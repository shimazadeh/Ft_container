#ifndef _PAIR_HPP
# define _PAIR_HPP

namespace ft
{
	template<typename T1, typename T2>
	struct pair
	{
		typedef	T1	first_element;
		typedef	T2	second_element;

		pair(void):first_element(), second_element(){}
		pair(const pair<T1, T2> &other): first_element(other.first_element), second_element(other.second_element){}
		pair(const T1 t1, const T2 t2):first_element(t1), second_element(t2){}
		~pair(){}

		void	swap(pair &other){}
		pair& operator=(const pair& other)
		{
			if (this != &other)
			{
				this->T1 = other.T1;
				this->T2 = other.T2;
			}
			return (*this);
		}

		//members
		T1	first_element;
		T2	second_element;

	};

template<typename T1, typename T2>
pair<T1, T2>make_pair(T1 t1, T2 t2)
{
	pair<T1, T2>	res(t1, t2);
	return (res);
};
}
#endif
