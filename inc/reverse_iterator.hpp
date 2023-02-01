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
			typedef	std::ptrdiff_t											difference_type;
			typedef typename ft::iterator_traits<T>::reference				reference;
			typedef typename ft::iterator_traits<T>::pointer				pointer;


			//I dont understand why this doesnt work
			// typedef typename ft::select_const<IsConst, const T&, T&>::type	reference;
			// typedef typename ft::select_const<IsConst, const T*, T*>::type	pointer;

		//=============================================Constructor==================================================
			reverse_iterator():current(){}

			explicit reverse_iterator(const iterator_type &x):current(x.base()){}

			template<typename U>//shouldnt the type be the same as T??
			reverse_iterator(const reverse_iterator<U>& other):current(other.base()){}

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
				iterator_type	tmp = current;

				return  (*--tmp);
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
			{return (reverse_iterator(it.base() + n));}

			friend difference_type operator-(const reverse_iterator &lhs, const reverse_iterator &rhs)
			{return (difference_type(lhs.base() - rhs.base()));}

			//============================================Relational Operators===================================================

			bool operator==( const reverse_iterator<T, true> &lhs)
			{return (lhs.base() == current);}

			bool operator!=( const reverse_iterator<T, true> &lhs)
			{return (lhs.base() != current);}

			bool operator<( const reverse_iterator<T, true> &lhs)
			{return (lhs.base() < current);}

			bool operator<=( const reverse_iterator<T, true> &lhs)
			{return (lhs.base() <= current);}

			bool operator>( const reverse_iterator<T, true> &lhs)
			{return (lhs.base() > current);}

			bool operator>=( const reverse_iterator<T, true> &lhs)
			{return (lhs.base() >= current);}

		protected:
			iterator_type		current;
	};
}
#endif
