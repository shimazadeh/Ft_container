#ifndef _VECTOR_HPP
# define _VECTOR_HPP

#include <iostream>
#include <memory>
#include <stdexcept>
#include <limits>
#include "./iterators/iterator.hpp"
#include "./iterators/reverse_iterator.hpp"
#include "./utils/equal.hpp"
#include "./utils/Is_Integral.hpp"
#include "./utils/pair.hpp"
#include <cstdio>

namespace	ft
{
	template<typename T, typename Allocator = std::allocator<T> >

	class	vector
	{
		public:
		//==================================Member Types=================================================================
			typedef	T												value_type;
			typedef	Allocator										allocator_type;
			typedef	std::size_t										size_type;
			typedef	std::ptrdiff_t									difference_type;
			typedef value_type										&reference;
			typedef	const value_type								&const_reference;
			typedef	value_type										*pointer;
			typedef	const pointer									const_pointer;
			typedef	ft::iterator<T>									iterator;
			typedef	ft::iterator<T>									const_iterator;
			typedef	ft::reverse_iterator<iterator>					reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>			const_reverse_iterator;

		//========================================Constructors==========================================================

			explicit	vector(const allocator_type &alloc = allocator_type()):arr(NULL), size_allocated(0), size_filled(0), _alloc(alloc)
			{}

			explicit	vector(size_type count, const value_type& value = value_type(), const allocator_type &alloc = allocator_type()):arr(NULL), size_filled(0), _alloc(alloc)
			{
				size_allocated = count * 2;
				size_filled = count;
				arr = _alloc.allocate(size_allocated);
				for (size_type i = 0; i < size_filled; i++)
					_alloc.construct(arr + i, value);
			}

			template<class InputIterator>
			vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>:: type* = 0):
			arr(NULL), size_filled(0), _alloc(alloc)
			{
				size_allocated = (last - first) * 2;
				arr = _alloc.allocate(size_allocated);
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}

			vector(const vector &other):arr(NULL), size_allocated(0), size_filled(0), _alloc(other._alloc)
			{
				*this = other;
			}

		//=======================================Destructor==============================================================
			~vector(void)
			{
				this->clear();
				// if (size_allocated > 0)// I had to remove this to fix a memory leak but see why size allocate is 0 at line 204
				// {
					_alloc.deallocate(arr, size_allocated);
					size_allocated = 0;
				// }
			}

		//======================================= Operator ========================================================
			vector &operator=(const vector &other)
			{
				if (this != &other)
				{
					_alloc = other._alloc;
					assign(other.begin(), other.end());
					size_filled = other.size_filled;
					size_allocated = other.size_allocated;
				}
				return (*this);
			}

			void assign(size_type n, const value_type& val)
			{
				if (n > size_allocated)
					expand(n);
				this->clear();
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}

			template<class InputIterator>
			void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>:: type* = 0)
			{
				size_type	size = last - first;

				if (size > size_allocated)
					expand(size + size_allocated);
				this->clear();
				for(iterator i = first; i != last; i++)
					push_back(*i);
			}

			allocator_type	get_allocator()const
			{
				return (_alloc);
			}

			size_type capacity() const
			{
				return (size_allocated);
			}

		//======================================Element access=============================================================
			reference back() {return (arr[size_filled - 1]);}
			const_reference back() const {return (arr[size_filled - 1]);}

			reference	front() {return (arr[0]);}
			const_reference front() const {return (arr[0]);}

			reference at (size_type n)
			{
				if (n >= size_filled)
					throw std::out_of_range("INDEX OUT OF RANGE");
				else
					return (arr[n]);
			}

			const_reference at (size_type n) const
			{
				if (n >= size_filled)
					throw std::out_of_range("INDEX OUT OF RANGE");
				else
					return (arr[n]);
			}

			reference	operator[](size_type n)
			{
				return (arr[n]);
			}

			const_reference	operator[](size_type n)const
			{
				return (arr[n]);
			}
		//========================================Iterators================================================================
			iterator				begin(void){return (iterator(&arr[0]));}
			iterator				end(void){return (iterator(&arr[size_filled]));}

			const_iterator			begin(void)const{return (const_iterator(&arr[0]));}
			const_iterator			end(void)const{return (const_iterator(&arr[size_filled]));}

			reverse_iterator		rbegin(void){return (reverse_iterator(&arr[size_filled]));}
			reverse_iterator		rend(void){return (reverse_iterator(&arr[0]));}

			const_reverse_iterator	rbegin(void)const{return (const_reverse_iterator(&arr[size_filled]));}
			const_reverse_iterator	rend(void)const{return (const_reverse_iterator(&arr[0]));}

		//========================================Capacity================================================================
			void	reserve(size_type new_cap)
			{
				T	*new_arr;

				if (new_cap <= size_allocated)
					return ;
				expand(new_cap);
			}

			bool	empty(void)const
			{
				return ((this->size_filled == 0));
			}

			size_type		size(void)const
			{
				return (this->size_filled);
			}

			size_type		max_size(void)const
			{
				return (std::numeric_limits<size_type>::max());
			}

		//=======================================Modifiers================================================================
			void			clear()
			{
				for (size_t i = 0; i < size_filled; i++)
					_alloc.destroy(&arr[i]);
				size_filled = 0;
			}

			iterator	insert(iterator pos, const value_type& value)
			{
				vector	new_vec(pos, end());//should be begin() + pos!!??
				std::cout << "new vec size allocated : %lu" << new_vec.size_allocated << "****************************************************************" << std::endl;
				if (size_filled == size_allocated)
					expand(size_filled * 2);

				for (size_type i = 0; i < new_vec.size(); i++)
					pop_back();
				push_back(value);

				for (iterator tmp = new_vec.begin(); tmp != new_vec.end(); tmp++)
					push_back(*tmp);

				return (iterator(&arr[pos - begin()]));
			}

			void	insert(iterator pos, size_type count, const value_type& value)
			{
				vector	new_vec(pos, end());//should be begin() + pos!!??

				if (size_filled + count > size_allocated)
					expand((size_filled * 2) + count);
				size_filled += count;

				for (int i = 0; i < new_vec.size(); i++)
					pop_back();

				for (size_type i = 0; i < count; i++)
					push_back(value);

				for (iterator tmp = new_vec.begin(); tmp != new_vec.end(); tmp++)
					push_back(*tmp);
			}

			template<class InputIterator>
			void	insert(iterator pos, InputIterator first, InputIterator last, typename ft::enable_if<ft::is_integral<InputIterator>::value>:: type = 0)
			{
				vector		new_vec(pos, end());//should be begin()+ pos
				size_type	diff = 0;

				for (iterator i = first; i != last; i++)
					diff++;
				if (size_filled + diff > size_allocated)
					expand((size_filled * 2) + diff);
				size_filled += diff;

				for (int i = 0; i < new_vec.size(); i++)
					pop_back();

				for (iterator i = first; i != last; i++)
					push_back(*i);

				for (iterator tmp = new_vec.begin(); tmp != new_vec.end(); tmp++)
					push_back(*tmp);
			}

			iterator		erase(iterator pos)
			{
				vector		new_arr(pos, end());
				size_t		dist = end() - pos;

				for (size_t i = 0; i < dist; i++)
					pop_back();

				for(iterator i = new_arr.begin() + 1; i != new_arr.end(); i++)
					insert(end(), *i);
				return (arr + dist);
			}

			iterator		erase(iterator first, iterator last)
			{
				size_t	pos = first - begin();

				for (iterator i = first; i != last; i++)
					erase(i);
				return (arr + pos);
			}

			void			push_back(const value_type& value)
			{
				if (size_allocated == 0 || size_filled >= size_allocated)
					expand(size_filled * 2);
				_alloc.construct(&arr[size_filled], value);
				size_filled++;
			}

			void			pop_back()
			{
				if (size_filled > 0)
				{
					_alloc.destroy(arr + (size_filled - 1));
					size_filled--;
				}
			}

			void			resize(size_type count, value_type val = value_type())
			{
				value_type	*new_arr;

				new_arr = _alloc.allocate(count);
				if (size() > count)
				{
					for (size_type i = 0; i < count; i++)
						new_arr[i] = arr[i];
				}
				else if (size() < count)
				{
					for (size_type i = 0; i < size_filled; i++)
						new_arr[i] = arr[i];
					new_arr->insert(new_arr->end(), count - size_filled, val);
				}
				_alloc.deallocate(arr, size_allocated);
				arr = new_arr;
				size_allocated = count;
				size_filled = count;
			}

			void			swap(vector &other)
			{
				T			*tmp_arr = arr;
				size_type	tmp_filled = size_filled;
				size_type	tmp_allocated = size_allocated;

				arr = other.arr;
				size_filled = other.size_filled;
				size_allocated = other.size_allocated;

				other.arr = tmp_arr;
				other.size_allocated = tmp_allocated;
				other.size_filled = tmp_filled;
			}
		//=================================================================================================================
		private:
			T						*arr;
			size_type				size_allocated;//size allocated
			size_type				size_filled;//size filled/saved
			allocator_type			_alloc;

			void	expand(size_type	count)// only calls this function when count > size_allocated
			{
				if (size_allocated == 0)
				{
					arr = _alloc.allocate(1);
					size_allocated++;
					// printf("expanding to 1\n");
				}
				else
				{
					T*			new_arr = _alloc.allocate(count);

					for (size_type i = 0; i < size_filled; i++)
					{
						// printf("size filled is %lu\n", i);
						_alloc.construct(&new_arr[i] , arr[i]);
						_alloc.destroy(&arr[i]);
					}
					_alloc.deallocate(arr, size_allocated);
					arr = new_arr;
					size_allocated = count;
				}
			}
	};//class end
	//====================================================Non Member functions=====================================================
	template <class T, class Alloc>
	bool	operator==(const vector<T, Alloc> &other, const vector<T, Alloc> &src)
	{
		if (other.size() != src.size())
			return false;
		return (ft::equal<ft::iterator<T>, ft::iterator<T> >(other.begin(), other.end(), src.begin(), src.end()));
	}

	template <class T, class Alloc>
	bool	operator!=(const vector<T, Alloc> &other, const vector<T, Alloc> &src)
	{
		return (!(other == src));
	}

	template <class T, class Alloc>
	bool	operator<(const vector<T, Alloc> &other, const vector<T, Alloc> &src)
	{
		ft::iterator<T>	other_b = other.begin();
		ft::iterator<T>	src_b = src.begin();

		if (other == src)
			return false;
		while (other_b != other.end() && src_b != src.end() && *src_b == *other_b)
		{
			other_b++;
			src_b++;
		}
		if (src_b == src.end())
			return false;
		return (*other_b < *src_b);
	}

	template <class T, class Alloc>
	bool	operator<=(const vector<T, Alloc> &other, const vector<T, Alloc> &src)
	{
		return (!(other > src));
	}

	template <class T, class Alloc>
	bool	operator>(const vector<T, Alloc> &other, const vector<T, Alloc> &src)
	{
		if (other == src)
			return false;
		return (!(other < src));
	}

	template <class T, class Alloc>
	bool	operator>=(const vector<T, Alloc> &other, const vector<T, Alloc> &src)
	{
		return (!(other < src));
	}

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}

}//namespace end

#endif
