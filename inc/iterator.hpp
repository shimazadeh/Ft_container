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
			typedef	T														value_type;
			typedef typename ft::select_const<IsConst, const T&, T&>::type	reference;
			typedef typename ft::select_const<IsConst, const T*, T*>::type	pointer;
			typedef std::ptrdiff_t											difference_type;
			typedef std::size_t												size_type;
			typedef std::random_access_iterator_tag							iterator_category;

			//===============================Constructor Destructor========================================
			iterator():_pointer(NULL){}

			iterator(pointer p):_pointer(p)
			{}

			iterator(const iterator<T> &other):_pointer(other.base())
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
			reference	operator[](int n) const {return *(this + n);}

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

			iterator	operator+(int n)
			{
				iterator	tmp = *this;

				tmp._pointer += n;
				return (tmp);
			}

			iterator	operator-(int n)
			{
				iterator	tmp = *this;

				tmp._pointer -= n;
				return (tmp);
			}

			iterator&	operator+=(int n)
			{
				_pointer += n;
				return (*this);
			}

			iterator&	operator-=(int n)
			{
				_pointer -= n;
				return (*this);
			}

			//=========================================Arithmetic Operators==================================================================================

			friend iterator	operator+(int n, const iterator	&rhs)
			{
				return (iterator(rhs._pointer + n));
			}

			friend iterator	operator-(int n, const iterator	&rhs)
			{
				return (iterator(rhs._pointer - n));
			}

			friend difference_type	operator-(const iterator &rhs, const iterator	&lhs)
			{
				return (rhs.base() - lhs.base());
			}

			friend iterator	operator+(difference_type n, const iterator	&lhs)
			{
				return (iterator(lhs.base() + n));
			}

			//============================================Relational Operators===================================================
			bool	operator==(const iterator	&lhs)const
			{return (_pointer == lhs._pointer);}

			bool	operator!=(const iterator	&lhs)const
			{return (_pointer != lhs._pointer);}

			bool	operator<(const iterator	&lhs)const
			{return (_pointer < lhs._pointer);}

			bool	operator<=(const iterator	&lhs)const
			{return (_pointer <= lhs._pointer);}

			bool	operator>(const iterator	&lhs)const
			{return (_pointer > lhs._pointer);}

			bool	operator>=(const iterator	&lhs)const
			{return (_pointer >= lhs._pointer);}

		private:
			pointer	_pointer;
	};
}
#endif
