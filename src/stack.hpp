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
		stack():stack(Container()){}

		explicit stack(const Container &cont = Container()):c(cont){}

		explicit stack(const Container &cont):c(cont){}

		explicit stack(Container && cont):c(std::move(cont)){}

		stack(const stack &other){*this = other;}

		stack(stack &&other):c(std::move(other.c)){}

		template<class InputIt>
		stack(InputIt first, InputIt last)
		{
			c(Container(first, last));
		}

		template<class Alloc>
		explicit stack (const Alloc& alloc)
		{
			c(Container(alloc));
		}

		template<class Alloc>
		stack(const Container& cont, const Alloc& alloc)
		{
			c(Container(cont, alloc));
		}

		///** not sure
		template<class Alloc>
		stack(Container &&cont, const Alloc &alloc):c(std::move(cont), alloc){}

		template<class Alloc>
		stack(const stack &other, const Alloc& alloc)
		{
			c = Container(other.c, alloc);
		}

		///** not sure
		template< class Alloc >
		stack (stack&& other, const Alloc& alloc):c(std::move(other.c), alloc){}

		template< class InputIt, class Alloc >
		stack( InputIt first, InputIt last, const Alloc& alloc )
		{
			c = Container(first, last, alloc);
		}

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
		reference	top(){return(c.back())}

		const_reference	top()const{return(c.back())}
		//==================================Capacity===================================================================
		bool	empty()const{return(c.empty())}

		size_type	size()const{return(c.size())}

		//==================================Modifiers===================================================================
		void	push(const value_type& value){return(c.push_back(value));}

		void	push(value_type&& value){return(c.push_back(std::move(value)));}

		template< class... Args >
		void emplace(Args&&... args){return(c.emplace_back(std::forward<Args>(args)...));}

		template< class... Args >
		decltype(auto) emplace(Args&&... args){return(c.emplace_back(std::forward<Args>(args)...));}

		void	pop(){c.pop_back();}

		void swap( stack& other ) noexcept{swap(c, other.c);}

		//==================================Non-Member functions========================================================
		template< class T, class Container >
		friend	bool operator==(const std::stack<T,Container>& lhs, const std::stack<T, Container>& rhs)
		{
			return (lhs.c == rhs.c);
		}

		template< class T, class Container >
		friend bool operator!=( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs )
		{
			return (lhs.c != rhs.c);
		}

		template< class T, class Container >
		friend bool operator<( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs )
		{
			return (lhs.c < rhs.c);
		}

		template< class T, class Container >
		friend bool operator<=( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs )
		{
			return (lhs.c <= rhs.c);
		}

		template< class T, class Container >
		friend bool operator>( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs )
		{
			return (lhs.c > rhs.c);
		}

		template< class T, class Container >
		friend bool operator>=( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs )
		{
			return (lhs.c >= rhs.c);
		}

		template< class T, std::three_way_comparable Container >
		std::compare_three_way_result_t<Container>
			friend operator<=>( const std::stack<T,Container>& lhs, const std::stack<T,Container>& rhs )
			{

			}

		private:
			Container	c;

	};//class end
}//namespace end
#endif
