#ifndef _VECTOR_HPP
# define _VECTOR_HPP

#include <iostream>
#include <memory>
#include <stdexcept>
#include <limits>
#include "./iterator.hpp"
#include "./reverse_iterator.hpp"
#include "./equal.hpp"
#include "./Is_Integral.hpp"
#include "./pair.hpp"
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
			typedef	ft::iterator<T, true>							const_iterator;
			typedef	ft::reverse_iterator<iterator>					reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator, true>		const_reverse_iterator;

		//========================================Constructors==========================================================

			explicit	vector(const allocator_type &alloc = allocator_type()):arr(NULL), size_allocated(0), size_filled(0), _alloc(alloc)
			{}

			explicit	vector(size_type count, const value_type& value = value_type(), const allocator_type &alloc = allocator_type()):arr(NULL), size_filled(0), _alloc(alloc)
			{
				size_allocated = count;//removed * 2
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
				// size_allocated = (last - first);//removed * 2
				size_allocated = input_iter_diff(first, last);

				if (size_allocated > 0)
					arr = _alloc.allocate(size_allocated);
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}

			vector(const vector &other):arr(NULL), size_allocated(other.size()), size_filled(other.size()), _alloc(other._alloc)
			{
				arr = _alloc.allocate(size_allocated);
				for (size_type i = 0; i < size(); i++)
					_alloc.construct(&arr[i], other.arr[i]);
			}

		//=======================================Destructor==============================================================
			~vector(void)
			{
				this->clear();
				if (size_allocated > 0)
				{
					_alloc.deallocate(arr, size_allocated);
					size_allocated = 0;
				}
			}

		//======================================= Operator ========================================================
			vector &operator=(const vector &other)
			{
				if (this != &other)
				{
					_alloc = other._alloc;
					if (arr == NULL)
						expand(1);
					assign(other.begin(), other.end());
				}
				return (*this);
			}

			void assign(size_type n, const value_type& val)
			{
				if ( n > size_allocated)
				{
					if (n > size_filled * 2)
						expand(n);
					else
						expand(size_filled * 2);
				}
				clear();
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}

			template<class InputIterator>
			void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>:: type* = 0)
			{
				// size_type	size = last - first;
				size_type 	size = input_iter_diff(first, last);

				if (size > size_allocated)
				{
					if (size > size_filled * 2)
						expand(size);
					else
						expand(size_filled * 2);
				}
				clear();
				for (InputIterator i = first; i != last; i++)
					push_back(*i);
			}

			allocator_type	get_allocator()const{return (_alloc);}

			size_type capacity() const{return (size_allocated);}

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
					return ((*this)[n]);
			}

			const_reference at (size_type n) const
			{
				if (n >= size_filled)
					throw std::out_of_range("INDEX OUT OF RANGE");
				else
					return ((*this)[n]);
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
				if (new_cap > max_size())
					throw std::length_error("vector::reserve");
				if (new_cap <= size_allocated)
					return ;
				if (size_allocated == 0)
					expand(1);
				expand(new_cap);
			}

			bool	empty(void)const
			{
				return ((this->size_filled == 0));
			}

			size_type		size(void)const
			{
				return (size_filled);
			}

			size_type		max_size(void)const
			{
				return (_alloc.max_size());
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
				vector		new_vec(pos, end());
				size_type	index = pos - begin();

				for (size_type i = 0; i < new_vec.size(); i++)
					pop_back();
				push_back(value);

				for (iterator tmp = new_vec.begin(); tmp != new_vec.end(); tmp++)
					push_back(*tmp);

				return (iterator(&arr[index]));
			}

			void	insert(iterator pos, size_type count, const value_type& value)
			{
				vector	new_vec(pos , end());

				if (size_filled + count > size_allocated)
				{
					if (size_filled + count > size_filled * 2)
						expand(size_filled + count);
					else
						expand(size_filled * 2);
				}

				for (size_type i = 0; i < new_vec.size(); i++)
					pop_back();

				for (size_type i = 0; i < count; i++)
					push_back(value);

				for (iterator tmp = new_vec.begin(); tmp != new_vec.end(); tmp++)
					push_back(*tmp);
			}

			template<class InputIterator>
			void	insert(iterator pos, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>:: type* = 0)
			{
				vector		new_vec(pos, end());

				if (size_filled + input_iter_diff(first, last) > size_allocated)
				{
					if (size_filled + input_iter_diff(first, last) > size_filled * 2)
						expand(size_filled + input_iter_diff(first, last));
					else
						expand(size_filled * 2);
				}

				for (size_type i = 0; i < new_vec.size(); i++)
					pop_back();

				for (InputIterator i = first; i != last; i++)
					push_back(*i);

				for (iterator tmp = new_vec.begin(); tmp != new_vec.end(); tmp++)
					push_back(*tmp);
			}

			iterator		erase(iterator pos)
			{
				vector		new_arr(pos + 1, end());
				size_t		dist = end() - pos;
				size_t		index = pos - begin();

				for (size_t i = 0; i < dist; i++)
					pop_back();

				for(iterator i = new_arr.begin(); i != new_arr.end(); i++)
					insert(end(), *i);
				return (iterator(&arr[index]));
			}

			iterator		erase(iterator first, iterator last)
			{
				size_type	pos = end() - last;
				pointer		tmp = first.base();
				size_type	index = first - begin();

				while(first != last)
				{
					_alloc.destroy(first.base());
					first++;
					size_filled--;
				}

				for (size_type i = 0; i < pos; i++)
				{
					_alloc.construct(tmp + i, *(last.base() + i));
					_alloc.destroy(last.base() + i);
				}

				return (iterator(&arr[index]));

			}

			void			push_back(const value_type& value)
			{
				if (size_allocated == 0)
					expand(1);
				if (size_filled == size_allocated)
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
				if (count < size())
				{
					for (int i = (int)size_filled - 1; i >= (int)count; i--)
						_alloc.destroy(&arr[i]);
					size_filled = count;
				}
				else if (count > size())
				{
					size_type	old_size = size();
					if (count > size_allocated)
					{
						if (count > size_filled * 2)
							expand(count);
						else
							expand(size_filled * 2);
					}

					for (size_type i = old_size; i < count; i++)
						_alloc.construct(&arr[i], val);
					size_filled = count;
				}
			}

			void			swap(vector &other)
			{
				T				*tmp_arr = arr;
				size_type		tmp_filled = size_filled;
				size_type		tmp_allocated = size_allocated;
				allocator_type	tmp_alloc = _alloc;

				arr = other.arr;
				size_filled = other.size_filled;
				size_allocated = other.size_allocated;
				_alloc = other._alloc;

				other.arr = tmp_arr;
				other.size_allocated = tmp_allocated;
				other.size_filled = tmp_filled;
				other._alloc = tmp_alloc;
			}
		//=================================================================================================================
		private:
			T						*arr;
			size_type				size_allocated;
			size_type				size_filled;
			allocator_type			_alloc;

			void	expand(size_type	count)
			{
				if (size_allocated == 0)
				{
					arr = _alloc.allocate(1);
					size_allocated++;
				}
				else
				{
					T*			new_arr = _alloc.allocate(count);

					for (size_type i = 0; i < size_filled; i++)
					{
						_alloc.construct(&new_arr[i] , arr[i]);
						_alloc.destroy(&arr[i]);
					}
					_alloc.deallocate(arr, size_allocated);
					arr = new_arr;
					size_allocated = count;
				}
			}

			template<class InputIterator>
			size_type	input_iter_diff(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>:: type* = 0)
			{
				size_type	count = 0;

				while(first != last)
				{
					count++;
					first++;
				}
				return(count);
			}


	};//class end
	//====================================================Non Member functions=====================================================
	template <class T, class Alloc>
	bool	operator==(const vector<T, Alloc> &other, const vector<T, Alloc> &src)
	{
		if (other.size() != src.size())
			return false;
		return (ft::equal<ft::iterator<T, true>, ft::iterator<T, true> >(other.begin(), other.end(), src.begin(), src.end()));
	}

	template <class T, class Alloc>
	bool	operator!=(const vector<T, Alloc> &other, const vector<T, Alloc> &src)
	{
		return (!(other == src));
	}

	template <class T, class Alloc>
	bool	operator<(const vector<T, Alloc> &other, const vector<T, Alloc> &src)
	{
		typename ft::vector<T, Alloc>::const_iterator	other_b = other.begin();
		typename ft::vector<T, Alloc>::const_iterator	src_b = src.begin();
		typename ft::vector<T, Alloc>::const_iterator	other_e = other.end();
		typename ft::vector<T, Alloc>::const_iterator	src_e = src.end();

		if (other == src)
			return false;
		while (other_b != other_e && src_b != src_e)
		{
			if (*other_b != *src_b)
				return (*other_b < *src_b);
			other_b++;
			src_b++;
		}
		if (other_b == other_e)
			return true;
		return (false);
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
		if (other < src)
			return false;
		return (true);
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
