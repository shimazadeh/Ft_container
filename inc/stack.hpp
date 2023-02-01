#ifndef _STACK_HPP
# define _STACK_HPP

#include <iostream>
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
		explicit stack(const Container &cont = container_type())
		{
			c = cont;//why do I leak when I do c(cont)??
		}

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
		value_type	&top(){return(this->c.back());}

		const value_type	&top()const{return(this->c.back());}
		//==================================Capacity===================================================================
		bool	empty()const{return(this->c.empty());}

		size_type	size()const{return(this->c.size());}

		//==================================Modifiers===================================================================
		void	push(const value_type& value){this->c.push_back(value);}

		void	pop(){this->c.pop_back();}

		friend bool operator==(const stack<T,Container>& lhs, const stack<T, Container>& rhs)
		{
			return (lhs.c == rhs.c);
		}

		friend bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
		{
			return (!(lhs == rhs));
		}

		friend bool operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
		{
			return (lhs.c < rhs.c);
		}

		friend bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
		{
			return (!(lhs > rhs));
		}

		friend bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs )
		{
			if (lhs == rhs)
				return false;
			if (lhs < rhs)
				return false;
			return (true);
		}

		friend bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
		{
			return (!(lhs < rhs));
		}

		private:
			Container	c;

	};//class end
	//==================================Non-Member functions========================================================
}//namespace end
#endif
