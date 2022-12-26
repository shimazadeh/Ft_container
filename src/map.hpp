#ifndef _MAP_HPP
# define _MAP_HPP

#include <iostream>
#include <memory>
#include <iterator>
#include "./Binary_search_tree/tree.hpp"
#include "./Binary_search_tree/tree_iterator.hpp"


namespace ft
{
	template<typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<std::pair<const Key, T>> >
	class map
	{
		public:
		//===========================================Class Types===================================================
		typedef	Key											key_type;
		typedef T											mapped_type;
		typedef std::pair<const Key, T>						value_type;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
		typedef std::less<Key>								key_compare;
		typedef std::allocator<value_type>					allocator_type;

		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

		typedef	const	tree_iterator<T>					const_iterator;
		typedef	const_iterator								iterator;
		typedef	const_iterator								reverse_iterator;
		typedef	const_iterator								const_reverse_iterator;

		//=========================================== Constructor ===================================================
		explicit map( const Compare& comp, const Allocator& alloc = Allocator()):_bstree(bstree()), _cmp(comp), _alloc(alloc)
		{}

		explicit map( const Allocator& alloc ):_bstree(bstree()), _cmp(0), _alloc(alloc)
		{}

		template< class InputIt >
		map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ): _bstree(bstree()), _cmp(comp), _alloc(alloc)
		{
			this->insert(first, last);
		}

		template< class InputIt >
		map( InputIt first, InputIt last, const Allocator& alloc ):_bstree(bstree()), _cmp(0), _alloc(alloc)
		{
			this->insert(first, last);
		}

		map( const map& other ):_bstree(other._bstree), _cmp(other._cmp), _alloc(other._alloc)
		{}

		map( const map& other, const Allocator& alloc ):_bstree(other._bstree), _cmp(other._cmp), _alloc(alloc)
		{}

		//next two constructor use move semantic: I used two methods
		map( map&& other ):_bstree(std::move(other._bstree)),_cmp(std::move(other._cmp)), _alloc(std::move(other._alloc))
		{}

		map( map&& other, const Allocator& alloc ):_bstree(std::move(other._bstree)), _cmp(other._cmp), _alloc(alloc)
		{
			other._cmp = 0;
			other._alloc = 0;
		}

		map( std::initializer_list<value_type> init, const Compare& comp = Compare(), const Allocator& alloc = Allocator() )
		{}

		map( std::initializer_list<value_type> init, const Allocator&)
		{}

		//=========================================== Destructor ===================================================
		~map(){this->clear();}
		//=========================================== Operator ===================================================
		map& operator=( const map& other )
		{
			if (this != &other)
			{
				this->clear();
				this->insert(other.begin(), other.end());
				_alloc = other._alloc;
				_cmp = other._cmp;
			}
			return (*this);
		}

		map& operator=( map&& other )
		{
			if (this != other)
			{
				this->clear();
				this->insert(other.begin(), other.end());
				_alloc = other._alloc;
				_cmp = other._cmp;
				other._alloc = 0;
				other._cmp = 0;
			}
			return (*this);
		}

		map& operator=( map&& other ) noexcept()
		{
			if (this != other)
			{
				this->clear();
				this->insert(other.begin(), other.end());
				_alloc = other._alloc;
				_cmp = other._cmp;
				other._alloc = 0;
				other._cmp = 0;
			}
			return (*this);
		}

		map& operator=( std::initializer_list<value_type> ilist );

		allocator_type get_allocator() const {return (_alloc);}

		allocator_type get_allocator() const noexcept {return (_alloc);}

		//=========================================== Access ===================================================
		T& at( const Key& key );

		const T& at( const Key& key ) const;

		T& operator[]( const Key& key );

		T& operator[]( Key&& key );
		//=========================================== Iterator ===================================================
		iterator		begin(){return (iterator(_bstree.min_element(_bstree.root)));}
		iterator		end(){return (iterator(_bstree.max_element(_bstree.root)));}

		const_iterator	begin() const {return (const_iterator(_bstree.min_element(_bstree.root)));}
		const_iterator	end()const {return (const_iterator(_bstree.max_element(_bstree.root)));}

		iterator		rbegin(){return (iterator(_bstree.max_element(_bstree.root)));}
		iterator		rend() {return (iterator(_bstree.min_element(_bstree.root)));}

		const_iterator	rbegin(){return (const_iterator(_bstree.max_element(_bstree.root)));}
		const_iterator	rend(){return (const_iterator(_bstree.min_element(_bstree.root)));}

		//=========================================== Capacity ===================================================
		bool	empty()const;

		size_type	size()const;

		size_type	max_size()const;
		//=========================================== Modifiers ===================================================
		void clear()
		{}

		std::pair<iterator, bool> insert( const value_type& value )
		{
			_bstree.insert(value, _bstree.root, _bstree.root->parent);
		}

		template< class P >
		std::pair<iterator, bool> insert( P&& value );

		std::pair<iterator, bool> insert( value_type&& value );


		iterator insert( iterator pos, const value_type& value );

		iterator insert( const_iterator pos, const value_type& value );

		template< class P >
		iterator insert( const_iterator pos, P&& value );

		iterator insert( const_iterator pos, value_type&& value );

		template< class InputIt >
		void insert( InputIt first, InputIt last );

		void insert( std::initializer_list<value_type> ilist );

		insert_return_type insert( node_type&& nh );

		iterator insert( const_iterator pos, node_type&& nh );

		template <class M>
		std::pair<iterator, bool> insert_or_assign( const Key& k, M&& obj );

		template <class M>
		std::pair<iterator, bool> insert_or_assign( Key&& k, M&& obj );

		template <class M>
		iterator insert_or_assign( const_iterator hint, const Key& k, M&& obj );

		template <class M>
		iterator insert_or_assign( const_iterator hint, Key&& k, M&& obj );

		template< class... Args >
		std::pair<iterator,bool> emplace( Args&&... args );

		template <class... Args>
		iterator emplace_hint( const_iterator hint, Args&&... args );


		template< class... Args >
		pair<iterator, bool> try_emplace( const Key& k, Args&&... args );

		template< class... Args >
		pair<iterator, bool> try_emplace( Key&& k, Args&&... args );

		template< class... Args >
		iterator try_emplace( const_iterator hint, const Key& k, Args&&... args );

		template< class... Args >
		iterator try_emplace( const_iterator hint, Key&& k, Args&&... args );


		iterator erase( iterator pos );

		iterator erase( const_iterator pos );

		iterator erase( iterator first, iterator last );

		iterator erase( const_iterator first, const_iterator last );

		size_type erase( const Key& key );

		template< class K >
		size_type erase( K&& x );

		void	swap(map &other);

		node_type extract( const_iterator position );

		node_type extract( const Key& k );

		template< class K >
		node_type extract( K&& x );


		template<class C2>
		void merge( std::map<Key, T, C2, Allocator>& source );

		template<class C2>
		void merge( std::map<Key, T, C2, Allocator>&& source );

		template<class C2>
		void merge( std::multimap<Key, T, C2, Allocator>& source );

		template<class C2>
		void merge( std::multimap<Key, T, C2, Allocator>&& source );

		//=========================================== LookUps ===================================================
		size_type count( const Key& key ) const;

		template< class K >
		size_type count( const K& x ) const;

		iterator find( const Key& key );

		const_iterator find( const Key& key ) const;

		template< class K >
		iterator find( const K& x );

		template< class K >
		const_iterator find( const K& x ) const;

		bool contains( const Key& key ) const;

		template< class K >
		bool contains( const K& x ) const;

		std::pair<iterator,iterator> equal_range( const Key& key );
		std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const;

		template< class K >
		std::pair<iterator,iterator> equal_range( const K& x );

		template< class K >
		std::pair<const_iterator,const_iterator> equal_range( const K& x ) const;

		iterator lower_bound( const Key& key );

		const_iterator lower_bound( const Key& key ) const;

		template< class K >
		iterator lower_bound( const K& x );

		template< class K >
		const_iterator lower_bound( const K& x ) const;

		iterator upper_bound( const Key& key );

		const_iterator upper_bound( const Key& key ) const;

		template< class K >
		iterator upper_bound( const K& x );

		template< class K >
		const_iterator upper_bound( const K& x ) const;

		//=========================================== Observers ===================================================

		key_compare key_comp() const;
		std::map::value_compare value_comp() const;

		//===========================================Non-Member functions===================================================
		template< class Key, class T, class Compare, class Alloc >
		friend bool operator==( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );

		template< class Key, class T, class Compare, class Alloc >
		friend bool operator!=( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );

		template< class Key, class T, class Compare, class Alloc >
		friend bool operator<( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );

		template< class Key, class T, class Compare, class Alloc >
		friend bool operator<=( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );

		template< class Key, class T, class Compare, class Alloc >
		friend bool operator>( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );

		template< class Key, class T, class Compare, class Alloc >
		friend bool operator>=( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );

		template< class Key, class T, class Compare, class Alloc >
		friend operator<=>( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs );

		//=================================================================================================================
		private:
			bstree			_bstree;
			key_compare		_cmp;
			allocator_type	_alloc;
	};
}
#endif
