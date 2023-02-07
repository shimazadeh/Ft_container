#ifndef _REVERSE_ITERATOR_HPP
#define _REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "./SelectConst.hpp"

namespace	ft
{
	template<typename T>
	class reverse_iterator
	{
		public:
			typedef	T														iterator_type;
			typedef typename ft::iterator_traits<T>::difference_type		difference_type;
			typedef typename ft::iterator_traits<T>::reference				reference;
			typedef typename ft::iterator_traits<T>::pointer				pointer;
			typedef	typename ft::iterator_traits<T>::value_type				value_type;

		//=============================================Constructor==================================================
			reverse_iterator():current(){}

			explicit reverse_iterator(iterator_type x):current(x){}

			template<typename U>
			reverse_iterator(const reverse_iterator<U>& other):current(other.base()){}

			~reverse_iterator()
			{}
		//=========================================== Operator equal =======================================================
			reverse_iterator& operator=(const reverse_iterator& other)
			{
				if (this != &other)
					current = other.current;
				return (*this);
			}

			iterator_type	base()const {return (current);}

		//=========================================== Operator * -> =======================================================

			reference operator*()const
			{
				iterator_type	tmp = current;

				return  (*(--tmp));
			}

			pointer	operator->()const
			{
				return(&(operator*()));
			}

			reference operator[](difference_type	n)const
			{
				return (base()[-n-1]);
			}

		//========================================== other member operators ====================================================
			reverse_iterator& operator++()
			{
				current--;
				return (*this);
			}

			reverse_iterator& operator--()
			{
				current++;
				return (*this);
			}

			reverse_iterator operator++(int)
			{
				reverse_iterator	tmp = *this;
				--current;

				return (tmp);
			}

			reverse_iterator operator--(int)
			{
				reverse_iterator	tmp = *this;
				++current;

				return (tmp);
			}

			reverse_iterator operator+(difference_type n) const
			{
				reverse_iterator	tmp = *this;

				tmp.current -= n;
				return (tmp);
			}

			reverse_iterator operator-(difference_type n) const
			{
				reverse_iterator	tmp = *this;

				tmp.current += n;
				return (tmp);
			}

			reverse_iterator& operator+=(difference_type n)
			{
				current -= n;
				return (*this);
			}

			reverse_iterator& operator-=( difference_type n )
			{
				current += n;
				return (*this);
			}

		protected:
			iterator_type		current;
	};

	template <class T1, class T2>
	bool operator==( const reverse_iterator<T1> &lhs, const reverse_iterator<T2> &rhs)
		{return (rhs.base() == lhs.base());}

	template <class T1, class T2>
	bool operator!=( const reverse_iterator<T1> &lhs, const reverse_iterator<T2> &rhs)
		{return (rhs.base() != lhs.base());}

	template <class T1, class T2>
	bool operator<( const reverse_iterator<T1> &lhs, const reverse_iterator<T2> &rhs)
		{return (rhs.base() < lhs.base());}

	template <class T1, class T2>
	bool operator>( const reverse_iterator<T1> &lhs, const reverse_iterator<T2> &rhs)
		{return (rhs.base() > lhs.base());}

	template <class T1, class T2>
	bool operator>=( const reverse_iterator<T1> &lhs, const reverse_iterator<T2> &rhs)
		{return (rhs.base() >= lhs.base());}

	template <class T1, class T2>
	bool operator<=( const reverse_iterator<T1> &lhs, const reverse_iterator<T2> &rhs)
		{return (rhs.base() <= lhs.base());}

	template<class T, class T2>
	typename reverse_iterator<T>::difference_type	operator-(const reverse_iterator<T> &rhs, const reverse_iterator<T2> &lhs)
	{
		return (lhs.base() - rhs.base());
	}

	template<class T>
	reverse_iterator<T>	operator+(typename reverse_iterator<T>::difference_type n, const reverse_iterator<T> &it )
	{return (it + n);}

}
#endif
