#ifndef _REVERSE_ITERATOR_HPP
#define _REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace	ft
{
	template<typename T>
	class reverse_iterator
	{
		public:
			typedef	ft::iterator<T>		iterator_type;
			typedef	std::ptrdiff_t		difference_type;
			typedef T					&reference;
			typedef	const T				&const_reference;
			typedef	T					*pointer;
			typedef	const T				*const_pointer;

		//=============================================Constructor==================================================
			reverse_iterator():current(){}

			explicit reverse_iterator(ft::iterator<T> &x):current(x._pointer - 1){}

			template<typename U>//shouldnt the type be the same as T??
			reverse_iterator(const reverse_iterator<U>& other):current(other.current){}

			//why no destructor is given in CPP reference page
			~reverse_iterator()
			{}
		//=========================================== Operator equal =======================================================

			template<typename U>
			reverse_iterator& operator=(const reverse_iterator<U>& other)
			{
				if (this != other)
					current = other.current;
				return (*this);
			}

			iterator_type	base()const {return (current);}

		//=========================================== Operator * -> =======================================================

			reference operator*()const
			{
				iterator_type	tmp(current);

				return  (*(--tmp));//doesnt find this function
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
				++current;

				return (tmp);
			}

			reverse_iterator operator--(int)
			{
				reverse_iterator	tmp = *this;
				--current;

				return (tmp);
			}

			reverse_iterator operator+(difference_type n) const
			{
				reverse_iterator	tmp = *this;

				tmp->current -= n;
				return (tmp);
			}

			reverse_iterator operator-(difference_type n) const
			{
				reverse_iterator	tmp = *this;

				tmp->current += n;
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

			//=========================================Arithmetic Operators==================================================================================
			friend reverse_iterator	operator+(difference_type n, const reverse_iterator &it )
			{return (reverse_iterator(it.base() + n));}

			friend difference_type operator-(const reverse_iterator &lhs, const reverse_iterator &rhs)
			{return (difference_type(lhs.base() - rhs.base()));}

			//============================================Relational Operators===================================================

			bool operator==( const reverse_iterator &lhs)const
			{return (lhs.current == current);}

			bool operator!=( const reverse_iterator &lhs)const
			{return (lhs.current != current);}

			bool operator<( const reverse_iterator &lhs)const
			{return (lhs.current < current);}

			bool operator<=( const reverse_iterator &lhs)const
			{return (lhs.current <= current);}

			bool operator>( const reverse_iterator &lhs)const
			{return (lhs.current > current);}

			bool operator>=( const reverse_iterator &lhs)const
			{return (lhs.current >= current);}

		protected:
			pointer	current;
	};
}
#endif
