#ifndef _STACK_HPP
# define _STACK_HPP

#include <iostream>
#include <iterator>
#include "vector.hpp"

namespace ft
{
	template<typename T, class Container = ft::vector<T> >

	class stack
	{
		public:
		//==================================Member Types=================================================================
		typedef	T									value_type;
		typedef	Container							container_type;
		typedef std::size_t							size_type;

		//==================================Constructors================================================================
		explicit stack(const Container &cont = container_type()):c(cont){}

		//==================================Destructor==================================================================

		~stack(){}

		//==================================operator====================================================================

		stack& operator=(const stack& other)//this is not listed in the cpp ref page
		{
			if (this != &other)
				this->c = other.c;
			return (*this);
		}
		//==================================Element Access============================================================
		value_type	&top(){return(c.back());}

		const value_type	&top()const{return(c.back());}
		//==================================Capacity===================================================================
		bool	empty()const{return(c.empty());}

		size_type	size()const{return(c.size());}

		//==================================Modifiers===================================================================
		void	push(const value_type& value){return(c.push_back(value));}

		void	pop(){c.pop_back();}

		void	swap(stack& other) noexcept
		{
			Container	temp = c;

			c = other.c;
			other.c = temp;
		}

		private:
			Container	c;

			friend bool operator==(const ft::stack<T,Container>& lhs, const ft::stack<T, Container>& rhs);
			friend bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs );

	};//class end
	//==================================Non-Member functions========================================================
	template< class T, class Container >
	bool operator==(const ft::stack<T,Container>& lhs, const ft::stack<T, Container>& rhs)
	{
		return (lhs.c == rhs.c);
	}

	template< class T, class Container >
	bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (!(lhs == rhs));
	}

	template< class T, class Container >
	bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (lhs.c < rhs.c);
	}

	template< class T, class Container >
	bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (!(lhs > rhs));
	}

	template< class T, class Container >
	bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		if (lhs == rhs)
			return false;
		if (lhs < rhs)
			return false;
		return (true);
	}

	template< class T, class Container >
	bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
	{
		return (!(lhs < rhs));
	}

	template <class T, class Container>
	void swap (ft::stack<T,Container>& x, ft::stack<T,Container>& y) noexcept
	{
		x.swap(y);
	}
}//namespace end
#endif
