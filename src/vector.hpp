#ifndef _VECTOR_HPP
# define _VECTOR_HPP

#include <iostream>
#include <iterator>

template<typename T, class Allocator = allocator<T> >

class	Vector
{
	// private:
	// 	T*				arr;
	// 	size_type		capacity;
	// 	size_type		current;
	// 	const allocator_type	_alloc;
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

		explicit	Vector(const allocator_type &alloc):arr(?), capacity(0), current(0), _alloc(alloc)
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

		explicit	Vector(size_type count):arr(NULL), capacity(0), current(0), _alloc(??)
		{
			//expand the size to count
		};

		explicit	Vector(size_type count, const allocator_type &alloc = allocator_type()):arr(NULL), capacity(0), current(0), _alloc(alloc)
		{
			//resize with count
		};

		template<class InputIt>
		Vector(InputIt first, InputIt last, const allocator_type &alloc = allocator_type()):arr(NULL), capacity(0), current(0), _alloc(alloc)
		{};

		Vector(const Vector &other):arr(NULL), capacity(0), current(0), _alloc(other._alloc)
		{
			*this = other;
			return (*this);
		};

		Vector(Vector &&other, const allocator_type &alloc):arr(other.arr), count()
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
		void	assign(size_type count, const T& value);

		template<class InputIt>
		void	assign(InputIt first, InputIt last);
		allocator_type	get_allocator()const;

	//=======================================Modifiers================================================================
		void			clear();//erases all elements, after this call size returns 0

		iterator		insert(const_iterator pos, const T& value);//insert elements at a specific location
		void			insert(const_iterator pos, size_type count, const T &value);
		template<class InputIt>
		iterator		insert(const_iterator pos, InputIt first, InputIt last);

		template<class... Args>
		iterator		emplace(const_iterator pos, Args&&...args);//Inserts a new element into the container directly before pos

		iterator		erase(iterator pos);
		iterator		erase(iterator first, iterator last);

		void			push_back(const T& value);
		void			push_back(T && value);

		template<class... Args>
		void			emplace_back(Args&&...args);

		template<class... Args>
		reference		emplace_back(Argc&&...args);

		void			pop_back();
		const	void	pop_back();

		void			resize(size_type count);
		void			resize(size_type count, T value = T());
		void			resize(size_type count, const value_type &value);

		void			swap(vector &other);

	//========================================Capacity================================================================
		void	shrinks_to_fit(void);//reduces the capacity of the container to fit its size and destroys all elements beyon the capacity
		void	reserve(size_type new_cap);//requests that the vector capacity be at least enough to contain n elements
		bool	empty(void); //returns whether the container is empty
		int		size(void);//returns number of elements in the elements
		int		max_size(void);//returns max elements the vector can hold
		int		capacity(void);//returns the size of the storage sppace allocated currently

	//========================================Iterators================================================================
		iterator				begin(void) {};
		iterator				end(void){};

		const_iterator			begin(void)const {};
		const_iterator			end(void)const{};

		reverse_iterator		rbegin(void) {};
		reverse_iterator		rend(void){};

		const_reverse_iterator	rbegin(void)const{};
		const_reverse_iterator	rend(void)const{};

	private:
		T*				arr;
		size_type		capacity;
		size_type		current;
		const allocator_type	_alloc;

	//operator
	friend bool	operator==(const Vector &other, const Vector &src)const{
		return ();
	};
	friend bool	operator!=(const Vector &other, const Vector &src)const{
		return ();
	};
	friend bool	operator<(const Vector &other, const Vector &src)const{
		return ();
	};
	friend bool	operator<=(const Vector &other, const Vector &src)const{
		return ();
	};
	friend bool	operator>(const Vector &other, const Vector &src)const{
		return ();
	};
	friend bool	operator<=>(const Vector &other, const Vector &src)const{
		return ();
	};
};


#endif
