#ifndef _VECTOR_HPP
# define _VECTOR_HPP

#include <iostream>
#include <iterator>

template<typename T, class Allocator = allocator<T> >

namespace	ft
{
	class	Vector
	{
		public:
		//==================================Class Types=================================================================
			typedef	T						value_type;
			typedef	std::Allocator			allocator_type;
			typedef	std::size_t				size_type;
			typedef	std::ptrdiff_t			difference_type;
			typedef	value_type				&reference;
			typedef	const value_type		&const_reference;
			typedef	value_type				*pointer;
			typedef	const value_type		*const_pointer;
			typedef	std::iterator<iterator>					iterator;
			typedef	std::iterator<const_iterator>			const_iterator;
			typedef	std::reverse_iterator<iterator>			reverse_iterator;
			typedef	std::reverse_iterator<const_iterator>	const_reverse_iterator;

		//========================================Constructors==========================================================
			Vector(void):arr(NULL), size_filled(0), size_allocated(0), _alloc(NULL)
			{
			};

			explicit	Vector(const allocator_type &alloc):arr(NULL), size_allocated(0), size_filled(0), _alloc(alloc)
			{
			};

			Vector(size_type count, const T& value, const allocator_type &alloc):arr(NULL), size_allocated(0), size_filled(0), _alloc(alloc)
			{
				size_filled = count;
				size_allocated = count * 2;
				_alloc.allocate(count * 2);
				for (size_type i = 0; i < size_filled; i++)
					_alloc.construct(arr + i, value);
			};

			explicit	Vector(size_type count, const T& value, const allocator_type &alloc = allocator_type()):arr(NULL), size_allocated(0), size_filled(0), _alloc(alloc)
			{
				size_allocated = count * 2;
				size_filled = count;
				_alloc.allocate(count * 2);
				for (size_type i = 0; i < size_filled; i++)
					_alloc.construct(arr + i, value);
			};

			explicit	Vector(size_type count):arr(NULL), size_allocated(0), size_filled(0), _alloc(NULL)
			{
				size_allocated = count * 2;
				size_filled = count;
				_alloc.allocate(count * 2);
			};

			explicit	Vector(size_type count, const allocator_type &alloc = allocator_type()):arr(NULL), size_allocated(0), size_filled(0), _alloc(alloc)
			{
				size_allocated = count * 2;
				size_filled = count;
				_alloc.allocate(count * 2);
			};

			template<class InputIt>
			Vector(InputIt first, InputIt last, const allocator_type &alloc = allocator_type()):arr(NULL), size_allocated(0), size_filled(0), _alloc(alloc)
			{
				size_filled = last - first;
				size_allocated = size_filled * 2;
				_alloc.allocate(size_allocated);
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			};

			Vector(const Vector &other):arr(NULL), size_allocated(0), size_filled(0), _alloc(other._alloc)
			{
				*this = other;
				return (*this);
			};

			Vector(Vector &&other, const allocator_type &alloc):arr(NULL), size_allocated(0), size_filled(0), _alloc(alloc)
			{
				*this = &other;
				return (*this);
			};

		//=======================================Destructor==============================================================
			~Vector(void)
			{
				this->clear();
				if (size_allocated > 0)
				{
					_alloc.deallocate(arr, size_allocated);
					size_allocated = 0;
				}
			};

		//=======================================Member Functions========================================================
			Vector &operator=(const Vector &other)
			{
				this->_alloc = other->_alloc;
				this->assign(other.begin(), other.end());
				return (*this);
			};

			void	assign(size_type count, const T& value)
			{
				this->clear();
				for (size_type i = 0; i < count; i++)
					push_back(*value);
			};

			template<class InputIt>
			void	assign(InputIt first, InputIt last)
			{
				this->clear();
				for(iterator i = first; i != last; i++)
					push_back(*i);
			};

			allocator_type	get_allocator()const
			{
				return (this->_alloc);
			};

		//=======================================Modifiers================================================================
			void			clear()//erases all elements, after this call size returns 0
			{
				for (iterator i = 0; i != arr.end(); i++)
					_alloc.destroy(&(*i));
				size_filled = 0;
			};

			iterator		insert(const_iterator pos, const T& value)
			{
				T					*new_arr;
				iterator			j = 0;

				if (size_filled == size_allocated)
					extend(size_filled * 2);
				size_filled++;
				new_arr = _alloc.allocate(size_filled);
				for (iterator i = 0; i != arr.end() + 1; i++)
				{
					////????
				}
				return (new_arr.begin());
			};//insert elements at a specific location

			void			insert(const_iterator pos, size_type count, const T &value);

			template<class InputIt>
			iterator		insert(const_iterator pos, InputIt first, InputIt last);

			// template<class... Args>
			// iterator		emplace(const_iterator pos, Args&&...args);//Inserts a new element into the container directly before pos

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
			};

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
			};

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
			};

			// void			push_back(T && value)
			// {
			// };

			// template<class... Args>
			// void			emplace_back(Args&&...args);

			// template<class... Args>
			// reference		emplace_back(Argc&&...args);

			// void			pop_back();
			// const	void	pop_back();

			void			resize(size_type count)
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
			};
			// void			resize(size_type count, T value = T());
			// void			resize(size_type count, const value_type &value);

			void			swap(vector &other)
			{

			};

		//========================================size_allocated================================================================
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
			};//reduces the size_allocated of the container to fit its size and destroys all elements beyon the size_allocated

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
			};//requests that the vector size_allocated be at least enough to contain n elements

			bool	empty(void)const //returns whether the container is empty
			{
				return ((this->size_filled == 0));
			};

			size_type		size(void)const//returns number of elements in the elements
			{
				return (this->size_filled);
			};

			size_type		max_size(void)const //returns max elements the vector can hold
			{
				return (std::numeric_limits<size_type>::max());
			};

			size_type		size_allocated(void)const //returns the size of the storage sppace allocated size_filledly
			{
				return (this->size_allocated)
			};

		//========================================Iterators================================================================
			iterator				begin(void)const{return (iterator(&arr[0]))};
			iterator				end(void)const{return (iterator(&arr[size_filled]))};

			const_iterator			begin(void)const{return (const_iterator(&arr[0]))};
			const_iterator			end(void)const{return (const_iterator(&arr[size_filled]))};

			reverse_iterator		rbegin(void)const{return (reverse_iterator(&arr[0]))};
			reverse_iterator		rend(void)const{return (reverse_iterator(&arr[size_filled]))};

			const_reverse_iterator	rbegin(void)const{return (const_reverse_iterator(&arr[0]))};
			const_reverse_iterator	rend(void)const{return (const_reverse_iterator(&arr[size_filled]))};

		//====================================================operator=====================================================
		friend bool	operator==(const Vector &other, const Vector &src)const
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
		};

		friend bool	operator!=(const Vector &other, const Vector &src)const
		{
			return (!(other == src));
		};

		friend bool	operator<(const Vector &other, const Vector &src)const
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
		};

		friend bool	operator<=(const Vector &other, const Vector &src)const
		{
			return (!(other > src));
		};

		friend bool	operator>(const Vector &other, const Vector &src)const
		{
			if (other == src)
				return false;
			return (!(other_b < src_b));
		};

		friend bool	operator>=(const Vector &other, const Vector &src)const{
			return (!(other < src));
		};

		friend bool	operator<=>(const Vector &other, const Vector &src)const{
			return ();
		};
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
			};
	};//class end
}//namespace end

#endif
