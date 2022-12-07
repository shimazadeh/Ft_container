#ifndef _VECTOR_HPP
# define _VECTOR_HPP

template<typename T>
class Vector
{
	public:
	//member functions
		Vector<T>(void){
			arr = new T[1];
			capacity = 1;
			current = 0;
		};
		~Vector<T>(void){
			delete [] arr;
		};

		Vector<T> &operator=(const Vector<T> &other){
			if (this != &src)
				//set the members equal to each other
			return (*this);
		};
		void	assign(size_type count, const T& value);

		template<class InputIt>
		void	assign(InputIt first, InputIt last);
		allocator_type	get_allocator()const;

	//modifiers
		void			clear();//erases all elements, after this call size returns 0

		iterator		insert(const_iterator pos, const T& value);//insert elements at a specific location
		void			insert(const_iterator pos, size_type count, const T &value);
		template<class InputIt>
		iterator		insert(const_iterator pos, InputIt first, InputIt last);

		template< class... Args >
		iterator		emplace(const_iterator pos, Args&&...args);//Inserts a new element into the container directly before pos

		iterator		erase(iterator pos);
		iterator		erase(iterator first, iterator last);

		void			push_back(const T& value);
		void			push_back(T && value);

		template< class... Args>
		void			emplace_back(Args&&...args);

		template< class... Args>
		reference		emplace_back(Argc&&...args);

		void			pop_back();
		const	void	pop_back();

		void			resize(size_type count);
		void			resize(size_type count, T value = T());
		void			resize(size_type count, const value_type &value);

		void			swap(vector &other);

	//capacity
		void	shrinks_to_fit(void);//reduces the capacity of the container to fit its size and destroys all elements beyon the capacity
		void	reserve(void);//requests that the vector capacity be at least enough to contain n elements
		bool	empty(void); //returns whether the container is empty
		int		size(void);//returns number of elements in the elements
		int		max_size(void);//returns max elements the vector can hold
		int		capacity(void);//returns the size of the storage sppace allocated currently

	//iterators
		iterator				begin(void) {};
		iterator				end(void){};

		const_iterator			begin(void)const {};
		const_iterator			end(void)const{};

		reverse_iterator		rbegin(void) {};
		reverse_iterator		rend(void){};

		const_reverse_iterator	rbegin(void)const{};
		const_reverse_iterator	rend(void)const{};

	private:
		T*	arr;
		int	capacity;
		int	current;
};

//operator
template<typename T>
bool	operator==(const Vector<T> &other, const Vector<T> &src)const{
	return ();
};
template<typename T>
bool	operator!=(const Vector<T> &other, const Vector<T> &src)const{
	return ();
};
template<typename T>
bool	operator<(const Vector<T> &other, const Vector<T> &src)const{
	return ();
};
template<typename T>
bool	operator<=(const Vector<T> &other, const Vector<T> &src)const{
	return ();
};
template<typename T>
bool	operator>(const Vector<T> &other, const Vector<T> &src)const{
	return ();
};
template<typename T>
bool	operator<=>(const Vector<T> &other, const Vector<T> &src)const{
	return ();
};
#endif
