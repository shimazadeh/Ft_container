#ifndef _REVERSE_ITERATOR_HPP
#define _REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include "./SelectConst.hpp"

namespace	ft
{
	template<typename T, bool IsConst = false>
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

			// reverse_iterator(iterator_type<T, IsConst> &other):current(other){}

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

			//=========================================Arithmetic Operators==================================================================================
			friend reverse_iterator	operator+(difference_type n, const reverse_iterator &it )
			{return (it + n);}

			friend difference_type operator-(const reverse_iterator &lhs, const reverse_iterator &rhs)
			{return (difference_type(rhs.base() - lhs.base()));}

			//============================================Relational Operators===================================================

			bool operator==( const reverse_iterator<T, IsConst> &lhs)const
			{return (lhs.base() == current);}

			bool operator!=( const reverse_iterator<T, IsConst> &lhs)const
			{return (lhs.base() != current);}

			bool operator<( const reverse_iterator<T, IsConst> &lhs)const
			{return (lhs.base() < current);}

			bool operator<=( const reverse_iterator<T, IsConst> &lhs)const
			{return (lhs.base() <= current);}

			bool operator>( const reverse_iterator<T, IsConst> &lhs)const
			{return (lhs.base() > current);}

			bool operator>=( const reverse_iterator<T, IsConst> &lhs)const
			{return (lhs.base() >= current);}

		protected:
			iterator_type		current;
	};
}
#endif
