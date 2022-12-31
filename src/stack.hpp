#ifndef _STACK_HPP
# define _STACK_HPP

#include <iostream>
#include <iterator>
#include "vector.hpp"

namespace ft
{
	template<typename T, class Container = ft::vector<T> >

	class stack : public vector
	{
		public:
		//==================================Member Types=================================================================
		typedef	Container							container_type:
		typedef	typename Container::value_type		T;
		typedef typename Container::value_type		value_type;
		typedef typename Container::size_t			size_type;
		typedef typename Container::reference		reference;
		typedef typename Container::const_reference	const_reference;

		//==================================Constructors================================================================
		explicit stack(const Container &cont = container_type()):c(cont){}

		//==================================Destructor==================================================================

		~stack(){}//does it need to be virtual??

		//==================================operator====================================================================

		stack& operator=(const stack& other)
		{
			if (this != &other)
				this->c = other.c;
			return (*this);
		}

		stack& operator=(stack&& other)//not sure
		{
			if (this != &&other)
				this->c = &other.c;
		}
		//==================================Element Access============================================================
		value_type	&top(){return(c.back())}

		const value_type	&top()const{return(c.back())}
		//==================================Capacity===================================================================
		bool	empty()const{return(c.empty())}

		size_type	size()const{return(c.size())}

		//==================================Modifiers===================================================================
		void	push(const value_type& value){return(c.push_back(value));}

		template< class... Args >
		void emplace(Args&&... args){return(c.emplace_back(std::forward<Args>(args)...));}

		template< class... Args >
		decltype(auto) emplace(Args&&... args){return(c.emplace_back(std::forward<Args>(args)...));}

		void	pop(){c.pop_back();}

		void swap( stack& other ) noexcept{swap(c, other.c);}

		//==================================Non-Member functions========================================================
		template< class T, class Container >
		friend	bool operator==(const ft::stack<T,Container>& lhs, const ft::stack<T, Container>& rhs)
		{
			return (lhs.c == rhs.c);
		}

		template< class T, class Container >
		friend bool operator!=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
		{
			return (lhs.c != rhs.c);
		}

		template< class T, class Container >
		friend bool operator<( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
		{
			return (lhs.c < rhs.c);
		}

		template< class T, class Container >
		friend bool operator<=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
		{
			return (lhs.c <= rhs.c);
		}

		template< class T, class Container >
		friend bool operator>( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
		{
			return (lhs.c > rhs.c);
		}

		template< class T, class Container >
		friend bool operator>=( const ft::stack<T,Container>& lhs, const ft::stack<T,Container>& rhs )
		{
			return (lhs.c >= rhs.c);
		}

		template <class T, class Container>
		void swap (stack<T,Container>& x, stack<T,Container>& y) noexcept(noexcept(x.swap(y)))
		{

		}
		private:
			Container	c;

	};//class end
}//namespace end
#endif
