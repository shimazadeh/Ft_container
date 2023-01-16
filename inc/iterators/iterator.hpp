#ifndef _ITERATOR_HPP
#define _ITERATOR_HPP

#include "./iterator_traits.hpp"

namespace	ft
{
	template<typename T>
	class iterator
	{
		public:
			typedef	T													value_type;
			typedef T													&reference;
			typedef const T												&const_reference;
			typedef T													*pointer;
			typedef const pointer										const_pointer;
			typedef std::ptrdiff_t										difference_type;
			typedef std::size_t											size_type;

			//===============================Constructor Destructor========================================
			iterator():_pointer(NULL){}

			iterator(const pointer	p):_pointer(p)
			{
			}

			iterator(const iterator &other)
			{
				*this = other;
			}

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
			{return (lhs._pointer == _pointer);}

			bool	operator!=(const iterator	&lhs)const
			{return (lhs._pointer != _pointer);}

			bool	operator<(iterator	&lhs)const
			{return (lhs._pointer < _pointer);}

			bool	operator<=(iterator	&lhs)const
			{return (lhs._pointer <= _pointer);}

			bool	operator>(iterator	&lhs)const
			{return (lhs._pointer > _pointer);}

			bool	operator>=(iterator	&lhs)const
			{return (lhs._pointer >= _pointer);}

		private:
			pointer	_pointer;
	};
}
#endif
