#ifndef _REVERSE_ITERATOR_HPP
#define _REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace	ft
{
	template<typename T>
	class reverse_iterator
	{
		protected:
			T	current;

		public:
			typedef	T					iterator_type;
			typedef	std::ptrdiff_t		difference_type;
			typedef T					&reference;
			typedef	const T				&const_reference;
			typedef	T					*pointer;
			typedef	const T				*const_pointer;

		//=============================================Constructor==================================================
			reverse_iterator():current(){}

			explicit reverse_iterator(iterator_type x):current(x){}

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
				iterator_type	tmp = current;
				return  (*--tmp);
			}

			pointer	operator->()const
			{
				return(&(operator*()));
			}

			reference operator[](difference_type	n)const
			{
				return (base()[-n-1]);//from CPP page
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

			reverse_iterator operator++( int )
			{
				reverse_iterator	tmp = *this;
				++current;

				return (tmp);
			}

			reverse_iterator operator--( int )
			{
				reverse_iterator	tmp = *this;
				--current;

				return (tmp);
			}

			reverse_iterator operator+( difference_type n ) const
			{
				iterator_type	tmp = *this;

				tmp->current -= n;
				return (tmp);
			}

			reverse_iterator operator-( difference_type n ) const
			{
				reverse_iterator	tmp = *this;

				tmp->current += n;
				return (tmp);
			}

			reverse_iterator& operator+=( difference_type n )
			{
				current -= n;
				return (*this);
			}

			reverse_iterator& operator-=( difference_type n )
			{
				current += n;
				return (*this);
			}
	};
//======================================None member function==========================================================================

template< typename Iterator1, typename Iterator2 >
bool operator==( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
{return (lhs.current == rhs.current);}

template< typename Iterator1, typename Iterator2 >
bool operator!=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
{return (lhs.current != rhs.current);}

template< typename Iterator1, typename Iterator2 >
bool operator<( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
{return (lhs.current < rhs.current);}

template< typename Iterator1, typename Iterator2 >
bool operator<=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
{return (lhs.current <= rhs.current);}

template< typename Iterator1, typename Iterator2 >
bool operator>( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
{return (lhs.current > rhs.current);}

template< typename Iterator1, typename Iterator2 >
bool operator>=( const ft::reverse_iterator<Iterator1>& lhs, const ft::reverse_iterator<Iterator2>& rhs )
{return (lhs.current >= rhs.current);}

template< typename Iter >
reverse_iterator<Iter>	operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it )
{return (reverse_iterator<Iter>(it.base() - n));}

template< typename Iter>
typename reverse_iterator<Iter>::difference_type operator-(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter> &rhs)
{return (reverse_iterator<Iter>::difference_type(lhs.base() - rhs.base()));}

}
#endif
