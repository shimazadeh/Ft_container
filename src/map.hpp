#ifndef _MAP_HPP
# define _MAP_HPP

#include <iostream>
#include <memory>
#include <iterator>

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

		typedef std::bidirectional_iterator_tag				iterator;//not sure
		typedef const typename iterator						const_iterator;//not sure
		typedef	std::reverse_iterator<iterator>				reverse_iterator;
		typedef	std::reverse_iterator<const_iterator>		const_reverse_iterator;

		//=========================================== Constructor ===================================================
		explicit map( const Compare& comp, const Allocator& alloc = Allocator() );

		explicit map( const Allocator& alloc );

		template< class InputIt >
		map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );

		template< class InputIt >
		map( InputIt first, InputIt last, const Allocator& alloc );

		map( const map& other );

		map( const map& other, const Allocator& alloc );

		map( map&& other );

		map( map&& other, const Allocator& alloc );

		map( std::initializer_list<value_type> init, const Compare& comp = Compare(), const Allocator& alloc = Allocator() );

		map( std::initializer_list<value_type> init, const Allocator&);

		//=========================================== Destructor ===================================================
		~map()
		{

		}
		//=========================================== Operator ===================================================
		map& operator=( const map& other );

		map& operator=( map&& other );

		map& operator=( map&& other ) noexcept();

		map& operator=( std::initializer_list<value_type> ilist );

		allocator_type get_allocator() const;

		allocator_type get_allocator() const noexcept;

		//=========================================== Access ===================================================
		T& at( const Key& key );

		const T& at( const Key& key ) const;

		T& operator[]( const Key& key );

		T& operator[]( Key&& key );
		//=========================================== Iterator ===================================================
		iterator		begin();
		iterator		end();

		const_iterator	begin();
		const_iterator	end();

		iterator		cbegin();
		iterator		cend();

		const_iterator	cbegin();
		cons_iterator	cend();

		iterator		rbegin();
		iterator		rend();

		const_iterator	rbegin();
		const_iterator	rend();

		iterator		crbegin();
		iterator		crend();

		const_iterator	crbegin();
		const_iterator	crend();
		//=========================================== Capacity ===================================================
		bool	empty()const;

		size_type	size()const;

		size_type	max_size()const;
		//=========================================== Modifiers ===================================================
		void clear();

		std::pair<iterator, bool> insert( const value_type& value );
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
			// key_type		*keys;//idk whats up here
			// T				*members;//idk whats up here
			key_compare		_cmp;
			allocator_type	_alloc;
	};
}
#endif
