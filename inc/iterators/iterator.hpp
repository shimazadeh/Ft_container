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
			typedef typename ft::iterator_traits<T>::difference_type	difference_type;
			typedef std::size_t											size_type;

			//===============================Constructor Destructor========================================
			iterator():_pointer(NULL){}

			iterator(const pointer	p)
			{
				_pointer = new pointer(p);
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

			pointer		getpointer(void)const {return (_pointer);}

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

			iterator	operator+(int n)//should I write this with difference_type?? similar to reverse iterator
			{
				iterator	tmp = *this;

				tmp->_pointer += n;
				return (tmp);
			}

			iterator	operator-(int n)
			{
				iterator	tmp = *this;

				tmp->_pointer -= n;
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
				return (vector_iterator(rhs._pointer + n));
			}

			friend difference_type	operator+(const iterator	&lhs, const iterator	&rhs)
			{
				return (vector_iterator(rhs._pointer + lhs._pointer));
			}

			friend iterator	operator-(int n, const iterator	&rhs)
			{
				return (vector_iterator(rhs._pointer - n));
			}

			friend difference_type	operator-(const iterator	&lhs, const iterator	&rhs)
			{
				return (vector_iterator(lhs._pointer - rhs._pointer));
			}
			//============================================Relational Operators===================================================
			friend bool	operator==(const iterator	&lhs, const iterator	&rhs)
			{
				return (lhs._pointer == rhs._pointer);
			}

			friend bool	operator!=(const iterator	&lhs, iterator	&rhs)
			{
				return (lhs._pointer != rhs._pointer);
			}

			friend bool	operator<(iterator	&lhs, iterator	&rhs)
			{
				return (lhs._pointer < rhs._pointer);
			}

			friend bool	operator<=(iterator	&lhs, iterator	&rhs)
			{
				return (lhs._pointer <= rhs._pointer);
			}

			friend bool	operator>(iterator	&lhs, iterator	&rhs)
			{
				return (lhs._pointer > rhs._pointer);
			}

			friend bool	operator>=(iterator	&lhs, iterator	&rhs)
			{
				return (lhs._pointer >= rhs._pointer);
			}

		private:
			pointer	_pointer;
	};

}
#endif
