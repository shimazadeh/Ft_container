#ifndef _VECTOR_HPP
# define _VECTOR_HPP

#include <iostream>
#include <memory>
#include "./iterators/iterator.hpp"
#include "./iterators/reverse_iterator.hpp"

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
			typedef ft::iterator_traits<T>::reference				reference;
			typedef	const reference									const_reference;
			typedef	ft::iterator_traits<T>::pointer					pointer;
			typedef	const pointer									const_pointer;

			typedef	ft::iterator<T>									iterator;
			typedef	ft::iterator<T>									const_iterator;
			typedef	ft::reverse_iterator<typename iterator>			reverse_iterator;
			typedef	ft::reverse_iterator<typename const_iterator>	const_reverse_iterator;

		//========================================Constructors==========================================================

			explicit	vector(const allocator_type &alloc):arr(NULL), size_allocated(0), size_filled(0), _alloc(alloc)
			{
			}

			explicit	vector(size_type count, const T& value, const allocator_type &alloc = allocator_type()):arr(NULL), size_allocated(0), size_filled(0), _alloc(alloc)
			{
				size_allocated = count * 2;
				size_filled = count;
				_alloc.allocate(count * 2);
				for (size_type i = 0; i < size_filled; i++)
					_alloc.construct(arr + i, value);
			}

			template<class InputIt , class = typename ft::enable_if<ft::is_integral<InputIt>::value>:: type>
			vector(InputIt first, InputIt last, const allocator_type &alloc = allocator_type()):arr(NULL), size_allocated(0), size_filled(0), _alloc(alloc)
			{
				size_filled = last - first;
				size_allocated = size_filled * 2;
				_alloc.allocate(size_allocated);
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}

			vector(const vector &other):arr(NULL), size_allocated(0), size_filled(0), _alloc(other._alloc)
			{
				*this = other;
				return (*this);
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
				this->_alloc = other->_alloc;
				this->assign(other.begin(), other.end());
				return (*this);
			}

			void assign (size_type n, const value_type& val)
			{
				this->clear();
				for (size_type i = 0; i < count; i++)
					push_back(*value);
			}

			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{
				this->clear();
				for(iterator i = first; i != last; i++)
					push_back(*i);
			}

			allocator_type	get_allocator()const
			{
				return (this->_alloc);
			}

		//======================================Element access=============================================================
			reference back() {return (&arr[size_filled - 1]);}
			const_reference back() const {return (&arr[size_filled - 1]);}

			reference	front() {return (&arr[0]);}
			const_reference front() const {return (&arr[0]);}

			reference at (size_type n)
			{
				if (n >= size_filled)
					throw std::out_of_range();
				else
					return (arr[n]);
			}

			const_reference at (size_type n) const
			{
				if (n >= size_filled)
					throw std::out_of_range();
				else
					return (const arr[n]);
			}

		//========================================Iterators================================================================
			iterator				begin(void)const{return (iterator(&arr[0]));}
			iterator				end(void)const{return (iterator(&arr[size_filled]));}

			const_iterator			begin(void)const{return (const_iterator(&arr[0]));}
			const_iterator			end(void)const{return (const_iterator(&arr[size_filled]));}

			reverse_iterator		rbegin(void)const{return (reverse_iterator(&arr[0]));}
			reverse_iterator		rend(void)const{return (reverse_iterator(&arr[size_filled]));}

			const_reverse_iterator	rbegin(void)const{return (const_reverse_iterator(&arr[0]));}
			const_reverse_iterator	rend(void)const{return (const_reverse_iterator(&arr[size_filled]));}

		//========================================Capacity================================================================
			void	shrinks_to_fit(void)
			{
				T	*new_arr;

				if (size_filled == size_allocated)
					return ;
				new_arr = _alloc.allocate(size_filled);
				for (int i = 0; i < size_filled ; i++)
				{
					_alloc.constructr(new_arr + i, arr[i]);
				}
				_alloc.destroy(arr);
				arr = new_arr;
			}//reduces the size_allocated of the container to fit its size and destroys all elements beyon the size_allocated

			void	reserve(size_type new_cap)
			{
				T	*new_arr;

				if (new_cap <= size_allocated)
					return ;
				new_arr = _alloc.allocate(new_cap);
				for (size_type i = 0; i < size_filled; i++)
				{
					_alloc.construct(new_arr + i, arr[i]);
				}
				_alloc.destroy(arr);
				arr = new_arr;
				size_allocated = new_cap;
			}//requests that the vector size_allocated be at least enough to contain n elements

			bool	empty(void)const //returns whether the container is empty
			{
				return ((this->size_filled == 0));
			}

			size_type		size(void)const//returns number of elements in the elements
			{
				return (this->size_filled);
			}

			size_type		max_size(void)const //returns max elements the vector can hold
			{
				return (std::numeric_limits<size_type>::max());
			}

			size_type		size_allocated(void)const //returns the size of the storage sppace allocated size_filledly
			{
				return (this->size_allocated)
			}

		//=======================================Modifiers================================================================
			void			clear()//erases all elements, after this call size returns 0
			{
				for (iterator i = 0; i != arr.end(); i++)
					_alloc.destroy(&(*i));
				size_filled = 0;
			}

			iterator		insert(const_iterator pos, const T& value)
			{
				vector				new_vec(arr.begin() + pos, arr.end());

				if (size_filled == size_allocated)
					extend(size_filled * 2);
				size_filled++;

				for (int i = 0; i < new_vec.size(); i++)
					this->pop_back();
				this->push_back(value);

				for (iterator tmp = new_vec.begin(); tmp != new_vec.end(); tmp++)
					this->push_back(*tmp);

				return (arr.begin() + pos);
			}//insert elements at a specific location

			void			insert(const_iterator pos, size_type count, const T& value)
			{
				vector				new_vec(arr.begin() + pos, arr.end());

				if (size_filled + count > size_allocated)
					extend((size_filled * 2) + count);
				size_filled++;

				for (int i = 0; i < new_vec.size(); i++)
					this->pop_back();

				for (size_type i = 0; i < count; i++)
					this->push_back(value);

				for (iterator tmp = new_vec.begin(); tmp != new_vec.end(); tmp++)
					this->push_back(*tmp);

				return (arr.begin()+ pos);
			}

			template<class InputIt>
			iterator		insert(const_iterator pos, InputIt first, InputIt last)
			{
				vector				new_vec(arr.begin() + pos, arr.end());
				size_type			diff = 0;

				for (iterator i = first; i != last; i++)
					diff++;
				if (size_filled + diff > size_allocated)
					extend((size_filled * 2) + diff);
				size_filled++;

				for (int i = 0; i < new_vec.size(); i++)
					this->pop_back();

				for (iterator i = first; i != last; i++)
					this->push_back(*i);

				for (iterator tmp = new_vec.begin(); tmp != new_vec.end(); tmp++)
					this->push_back(*tmp);

				return (arr.begin() + pos);
			}

			iterator		erase(iterator pos)
			{
				T			*new_arr;
				iterator	j = 0;

				new_arr = _alloc.allocate(size_allocated);
				for (iterator i = 0; i != arr.end() ; i++)
				{
					if (i != pos)
						_alloc.construct(new_arr + i , *(arr + j));
					_alloc.destroy(arr[j]);
					j++;
				}
				_alloc.deallocate(arr);
				arr = new_arr;
				return ((arr + pos));
			}

			iterator		erase(iterator first, iterator last)
			{
				T			*new_arr;
				iterator	i = 0;
				iterator	j = 0;

				new_arr = _alloc.allocate(size_allocated);
				while (i != arr.end())
				{
					if (i < first && i >= last)
						_alloc.construct(new_arr + i , *(arr + j));
					_alloc.destroy(arr + j);
					j++;
					i++;
				}
				_alloc.deallocate(arr);
				arr = new_arr;
				return (arr + first);
			}

			void			push_back(const T& value)
			{
				if (size_allocated == 0)
				{
					arr = _alloc.allocate(1);
					size_allocated++
				}
				if (size_filled == size_allocated)
				{
					new_arr = _alloc.allocate(size_filled + 1);
					for (int i = 0; i < size_filled; i++)
					{
						_alloc.construct(new_arr + i, arr[i]);
						_alloc.destroy(arr + i);
					}
					_alloc.deallocate(arr);
					arr = new_arr;
					size_allocated++;
				}
				_alloc.construct(arr + size_filled, value);
				size_filled++;
			}

			void			pop_back()
			{
				if (size_filled > 0)
					_alloc.destroy(arr + (size_filled - 1));
				size_filled--;
			}//removes the last element in the vector

			void			resize(size_type count, value_type val = value_type())
			{
				value_type	*new_arr;

				new_arr = _alloc.allocate(count);
				if (this.size() > count)//delete the last elements (this.size() - count)
				{
					for (size_type i = 0; i < count; i++)
						new_arr[i] = arr[i];

				}
				else if (this.size() < count)//insert empty elements at the end
				{
					for (size_type i = 0; i < size_filled; i++)
						new_arr[i] = arr[i];
					new_arr.insert(new_arr.end(), count - size_filled, 0); //filling the rest with 0

				}
				_alloc.deallocate(arr);
				arr = new_arr;
				size_allocated = count;
				size_filled = count;
			}

			//***there is another swap type that is a non member function???
			void			swap(vector &other)
			{
				T		*tmp_arr = arr;
				size_type	tmp_filled = size_filled;
				size_type	tmp_allocated = size_allocated;

				arr = other.arr;
				size_filled = other.size_filled;
				size_allocated = other.size_allocated;

				other.arr = tmp_arr;
				other.size_allocated = tmp_allocated;
				other.size_filled = tmp_filled;
			}

		//====================================================Non Member functions=====================================================
		friend bool	operator==(const vector &other, const vector &src)const
		{
			iterator	other_b = other.begin();
			iterator	src_b = src.begin();

			if (other.size() != src.size())
				return false;
			while (other_b != other.end() && src_b != src.end() && *src_b == *other_b)
			{
				other_b++;
				src_b++;
			}
			if (other_b == other.end() && src_b == src.end())
				return true;
			return false;
		}

		friend bool	operator!=(const vector &other, const vector &src)const
		{
			return (!(other == src));
		}

		friend bool	operator<(const vector &other, const vector &src)const
		{
			iterator	other_b = other.begin();
			iterator	src_b = src.begin();

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

		friend bool	operator<=(const vector &other, const vector &src)const
		{
			return (!(other > src));
		}

		friend bool	operator>(const vector &other, const vector &src)const
		{
			if (other == src)
				return false;
			return (!(other_b < src_b));
		}

		friend bool	operator>=(const vector &other, const vector &src)const{
			return (!(other < src));
		}

		//=================================================================================================================
		private:
			T*						arr;
			size_type				size_allocated;//size allocated
			size_type				size_filled;//size filled/saved
			const allocator_type	_alloc;

			void	expand(size_type	count)// only calls this function when count > size_filled
			{
				T*			new_arr;

				if (size_allocated == 0)
				{
					_alloc.allocate(1);
					size_allocated++;
				}
				else
				{
					new_arr = _alloc.allocate(count);
					for (size_type i = 0; i < size_filled; i++)
					{
						_alloc.construct(new_arr + i , arr[i]);
						_alloc.destroy(arr[i]);
					}
					_alloc.deallocate(arr);
					arr = new_arr;
					size_allocated = count;
				}
			}
	};//class end
}//namespace end

#endif
