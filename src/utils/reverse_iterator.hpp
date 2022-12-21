#ifndef _REVERSE_ITERATOR_HPP
#define _REVERSE_ITERATOR_HPP

#include "iterator.hpp"

namespace	ft
{
	template<typename Iter>
	class reverse_iterator
	{
		protected:
			Iter	current;

		public:
			typedef	Iter												iterator_type;
			typedef	typename iterator_traits<Iter>::difference_type		difference_type;
			typedef	typename iterator_traits<Iter>::value_type			value_type;
			typedef	typename iterator_traits<Iter>::pointer				pointer;
			typedef	typename iterator_traits<Iter>::reference			reference;
			typedef	typename iterator_traits<Iter>::iterator_category	iterator_category;

		//=============================================Constructor==================================================
			reverse_iterator():current(){}

			reverse_iterator(iterator_type x):current(x){}

			template<typename U>
			reverse_iterator(const reverse_iterator<U>& other):current(other.current){}

		//=========================================== Operator equal =======================================================

			template<typename U>
			reverse_iterator& operator=(const reverse_iterator<U>& other):current(other.current){}
		//=========================================== Operator * -> =======================================================

			reference operator*()const
			{
				Iter	tmp = current;
				return  (*--tmp);
			}

			pointer	operator->()const {return(std::addressof(operator*()));}

		//=========================================== Operator [] =======================================================

			operator[](difference_type	n)const {return ();} //???Not sure about this one

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
				current++;

				return (tmp);
			}

			reverse_iterator operator--( int )
			{
				reverse_iterator	tmp = *this;
				current--;

				return (tmp);
			}

			reverse_iterator operator+( difference_type n ) const
			{
				return reverse_iterator(base() - n);
			}

			reverse_iterator operator-( difference_type n ) const
			{
				return reverse_iterator(base() + n);

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

		//====================================================== base =============================================================
			iterator_type	base()const {return (current);}

	};
//======================================None member function==========================================================================

template< typename Iterator1, typename Iterator2 >
bool operator==( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs )
{return (lhs.current == rhs.current);}

template< typename Iterator1, typename Iterator2 >
bool operator!=( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs )
{return (lhs.current != rhs.current);}

template< typename Iterator1, typename Iterator2 >
bool operator<( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs )
{return (lhs.current < rhs.current);}

template< typename Iterator1, typename Iterator2 >
bool operator<=( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs )
{return (lhs.current <= rhs.current);}

template< typename Iterator1, typename Iterator2 >
bool operator>( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs )
{return (lhs.current > rhs.current);}

template< typename Iterator1, typename Iterator2 >
bool operator>=( const std::reverse_iterator<Iterator1>& lhs, const std::reverse_iterator<Iterator2>& rhs )
{return (lhs.current >= rhs.current);}

template< typename Iter >
reverse_iterator<Iter>	operator+( typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it )
{return (reverse_iterator<Iter>(it.base() - n));}

template< typename Iterator1, typename Iterator2 >
typename reverse_iterator<Iterator1>::difference_type operator-( const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs )
{return (reverse_iterator<Iter>(it.base() + n));}

}
#endif
