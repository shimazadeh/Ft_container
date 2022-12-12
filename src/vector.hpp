#ifndef _VECTOR_HPP
# define _VECTOR_HPP

#include <iostream>
#include <iterator>

template<typename T, class Allocator = allocator<T> >

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
		Vector(void):arr(NULL), current(1), capacity(1), _alloc(NULL)
		{
		};

		explicit	Vector(const allocator_type &alloc):arr(NULL), capacity(0), current(0), _alloc(alloc)
		{
		};

		Vector(size_type count, const T& value, const allocator_type &alloc):arr(NULL), capacity(0), current(0), _alloc(alloc)
		{
			//EXPAND THE SIZE TO COUNT
		};

		explicit	Vector(size_type count, const T& value, const allocator_type &alloc = allocator_type()):arr(NULL), capacity(0), current(0), _alloc(alloc)
		{
			//EXPAND THE SIZE TO COUNT
		};

		explicit	Vector(size_type count):arr(NULL), capacity(0), current(0), _alloc(NULL)
		{
			//expand the size to count
		};

		explicit	Vector(size_type count, const allocator_type &alloc = allocator_type()):arr(NULL), capacity(0), current(0), _alloc(alloc)
		{
			//resize with count
		};

		template<class InputIt>
		Vector(InputIt first, InputIt last, const allocator_type &alloc = allocator_type()):arr(NULL), capacity(0), current(0), _alloc(alloc)
		{

		};

		Vector(const Vector &other):arr(NULL), capacity(0), current(0), _alloc(other._alloc)
		{
			*this = other;
			return (*this);
		};

		Vector(Vector &&other, const allocator_type &alloc):arr(other.arr), capacity(other.capacity), current(other.current), _alloc(alloc)
		{
		};

	//=======================================Destructor==============================================================
		~Vector(void)
		{
			_alloc.deallocate(arr, current);
			delete [] arr;
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
			for (size_type i = 0; i < count; i++)
				arr[i] = *value;
		};

		template<class InputIt>
		void	assign(InputIt first, InputIt last)
		{
			int j = 0;
			for (iterator i = first; i != last; i++)
			{
				arr[j] = *i;
				j++
			}
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
			current = 0;
		};




		iterator		insert(const_iterator pos, const T& value);//insert elements at a specific location

		void			insert(const_iterator pos, size_type count, const T &value);

		template<class InputIt>
		iterator		insert(const_iterator pos, InputIt first, InputIt last);

		// template<class... Args>
		// iterator		emplace(const_iterator pos, Args&&...args);//Inserts a new element into the container directly before pos

		// iterator		erase(iterator pos);
		// iterator		erase(iterator first, iterator last);

		void			push_back(const T& value)
		{
			try
			{

			}
			catch ()
			{

			}
		};
		void			push_back(T && value)
		{
		};

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
				for (size_type i = 0; i < current; i++)
					new_arr[i] = arr[i];
				new_arr.insert(new_arr.end(), count - current, 0); //filling the rest with 0

			}
			_alloc.destroy(arr);
			arr = new_arr;
			capacity = count;
			current = count;
		};
		// void			resize(size_type count, T value = T());
		// void			resize(size_type count, const value_type &value);

		void			swap(vector &other);

	//========================================Capacity================================================================
		void	shrinks_to_fit(void);//reduces the capacity of the container to fit its size and destroys all elements beyon the capacity
		void	reserve(size_type new_cap);//requests that the vector capacity be at least enough to contain n elements

		bool	empty(void)const //returns whether the container is empty
		{
			return ((this->current == 0));
		};
		size_type		size(void)const//returns number of elements in the elements
		{
			return (this->current);
		};
		size_type		max_size(void)const //returns max elements the vector can hold
		{
			return (std::numeric_limits<size_type>::max());
		};
		size_type		capacity(void)const //returns the size of the storage sppace allocated currently
		{
			return (this->capacity)
		};

	//========================================Iterators================================================================
		iterator				begin(void)const{return (iterator(&arr[0]))};
		iterator				end(void)const{return (iterator(&arr[current]))};

		const_iterator			begin(void)const{return (const_iterator(&arr[0]))};
		const_iterator			end(void)const{return (const_iterator(&arr[current]))};

		reverse_iterator		rbegin(void)const{return (reverse_iterator(&arr[0]))};
		reverse_iterator		rend(void)const{return (reverse_iterator(&arr[current]))};

		const_reverse_iterator	rbegin(void)const{return (const_reverse_iterator(&arr[0]))};
		const_reverse_iterator	rend(void)const{return (const_reverse_iterator(&arr[current]))};
	//=================================================================================================================

	private:
		T*						arr;
		size_type				capacity;
		size_type				current;
		const allocator_type	_alloc;

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
};


#endif
