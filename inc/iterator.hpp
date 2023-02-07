#ifndef _ITERATOR_HPP
#define _ITERATOR_HPP

#include "./iterator_traits.hpp"
#include "./SelectConst.hpp"

namespace	ft
{
	template<typename T, bool IsConst = false>
	class iterator
	{
		public:
			typedef typename ft::select_const<IsConst, T const , T>::type	value_type;
			typedef value_type&												reference;
			typedef value_type*												pointer;
			typedef std::ptrdiff_t											difference_type;
			typedef std::size_t												size_type;
			typedef std::bidirectional_iterator_tag							iterator_category;

			//===============================Constructor Destructor========================================
			iterator():_pointer(NULL){}

			iterator(pointer p):_pointer(p)
			{}

			template <typename U, bool IfConst>
			iterator(const iterator<U, IfConst> &other):_pointer(other.base())
			{}

			~iterator()
			{}
			//============================================================================
			iterator	&operator=(const iterator &other)
			{
				if (this != &other)
					_pointer = other._pointer;
				return (*this);
			}

			pointer		base(void)const {return (_pointer);}

			reference	operator*()const {return (*_pointer);}
			pointer		operator->()const {return (_pointer);}
			reference	operator[](int n) const {return _pointer[n];}

			//====================================================================================
			iterator&	operator++()
			{
				_pointer++;
				return (*this);
			}

			iterator	operator++(int)
			{
				iterator	tmp = *this;

				++(*this);
				return (tmp);
			}

			iterator&	operator--()
			{
				_pointer--;
				return (*this);
			}

			iterator	operator--(int)
			{
				iterator	tmp = *this;

				--(*this);
				return (tmp);
			}

			iterator	operator+(difference_type n)
			{
				iterator	tmp = *this;

				tmp._pointer += n;
				return (tmp);
			}

			iterator	operator-(difference_type n)
			{
				iterator	tmp = *this;

				tmp._pointer -= n;
				return (tmp);
			}

			iterator&	operator+=(difference_type n)
			{
				_pointer += n;
				return (*this);
			}

			iterator&	operator-=(difference_type n)
			{
				_pointer -= n;
				return (*this);
			}

		protected:
			pointer	_pointer;
	};

	template<class T, bool IsConst1, bool IsConst2>
	typename iterator<T, IsConst1>::difference_type	operator-(const iterator<T, IsConst1> &rhs, const iterator<T, IsConst2> &lhs)
	{
		return (rhs.base() - lhs.base());
	}

	template<class T, bool IsConst >
	iterator<T, IsConst>	operator+(typename iterator<T, IsConst>::difference_type n, const iterator<T,IsConst>	&rhs)
	{
		return (iterator<T, IsConst>(rhs.base() + n));
	}

	template<class T, bool IsConst1, bool IsConst2>
	bool	operator==(const iterator<T, IsConst1>	&lhs, const iterator<T, IsConst2> &rhs)
	{return (lhs.base() == rhs.base());}

	template<class T, bool IsConst1, bool IsConst2>
	bool	operator!=(const iterator<T, IsConst1>	&lhs, const iterator<T, IsConst2> &rhs)
	{return (lhs.base() != rhs.base());}

	template<class T, bool IsConst1, bool IsConst2>
	bool	operator<(const iterator<T, IsConst1>	&lhs, const iterator<T, IsConst2> &rhs)
	{return (lhs.base() < rhs.base());}

	template<class T, bool IsConst1, bool IsConst2>
	bool	operator<=(const iterator<T, IsConst1>	&lhs, const iterator<T, IsConst2> &rhs)
	{return (lhs.base() <= rhs.base());}

	template<class T, bool IsConst1, bool IsConst2>
	bool	operator>(const iterator<T, IsConst1>	&lhs, const iterator<T, IsConst2> &rhs)
	{return (lhs.base() > rhs.base());}

	template<class T, bool IsConst1, bool IsConst2>
	bool	operator>=(const iterator<T, IsConst1>	&lhs, const iterator<T, IsConst2> &rhs)
	{return (lhs.base() >= rhs.base());}

}
#endif
