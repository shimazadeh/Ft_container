#ifndef _MAP_HPP
# define _MAP_HPP

#include <iostream>
#include <memory>
#include <iterator>
#include "./Binary_search_tree/tree.hpp"
#include "./Binary_search_tree/tree_iterator.hpp"
#include "./Binary_search_tree/tree_node.hpp"
#include "./utils/pair.hpp"

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

		typedef	const	tree_iterator<Key, T, Compare>		const_iterator;
		typedef	const_iterator								iterator;
		typedef	const_iterator								reverse_iterator;
		typedef	const_iterator								const_reverse_iterator;


		class	value_compare
		{
			protected:
				Compare	comp;
				value_compare(Compare c): comp(c){}

			public:
				typedef	bool		result;
				typedef	value_type	first;
				typedef	value_type	second;

				bool	operator()(const value_type& x, const value_type& y) const
				{
					return (comp(x.first, y.first));
				}
		}
		//=========================================== Constructor ===================================================
		explicit map( const Compare& comp, const Allocator& alloc = Allocator()):_bstree(bstree()), _cmp(comp), _alloc(alloc)
		{}

		template< class InputIt >
		map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ): _bstree(bstree()), _cmp(comp), _alloc(alloc)
		{
			this->insert(first, last);
		}

		map( const map& other ):_bstree(other._bstree), _cmp(other._cmp), _alloc(other._alloc)
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

		allocator_type get_allocator() const {return (_alloc);}

		//=========================================== Access ===================================================
		mapped_type& at(const key_type& key)
		{
			if (!_bstree.find_node(key, _bstree.get_root()))
				throw std::out_of_range("key is out of range");
			else
				return ((*this)[key]);
		}

		const mapped_type& at( const key_type& key ) const
		{
			if (!_bstree.find_node(key, _bstree.get_root()))
				throw std::out_of_range("key is out of range");
			else
				return ((*this)[key]);
		}

		mapped_type& operator[]( const key_type& key )
		{
			return (*(this->insert(ft::make_pair(key, mapped_type())).first)).second;
		}

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
		bool	empty()const {return (if (_bstree.size() == 0));}

		size_type	size()const { return (_bstree.size());}

		size_type	max_size()const{ return(_bstree.max_size());}
		//=========================================== Modifiers ===================================================
		void clear()
		{
			_bstree.clear();
		}

		std::pair<iterator, bool> insert( const value_type& value )
		{
			bool	wasinserted = false;
			iterator	result;

			result = iterator(_bstree.insert(value, _bstree.get_root(), _bstree.get_root()->parent, &wasinserted));
			return (ft::makepair(result, wasinserted););
		}

		iterator insert( iterator pos, const value_type& value )
		{
			//????
		}

		template< class InputIt >
		void insert( InputIt first, InputIt last )
		{
			bool	whatever = false;

			while (first != last)
			{
				_bstree.insert(*first, _bstree.get_root(), _bstree.get_root()->parent, &whatever);
				first++;
			}
		}

		//=======================================================================
		void erase( iterator pos )
		{
			_bstree.erase(pos.node->get_value(), _bstree.get_root())
		}

		void erase( iterator first, iterator last )
		{
			while (first != last)
			{
				erase(first);
				first++;
			}
		}

		size_type erase( const Key& key )
		{
			return (_bstree.erase_key(key));
		}

		//================================================================
		void	swap(map &other);


		//=========================================== LookUps ===================================================
		size_type count( const Key& key ) const
		{
			if (_bstree.find_node(key, _bstree.get_root()))
				return (1);
			return (0);
		}

		iterator find( const Key& key )
		{
			ft::tree_node<const Key, T, Compare, Allocator> *res = _bstree.find_node(key, _bstree.get_root());

			if (res != nullptr)
				return (iterator(res));
			return (this->end());
		}

		const_iterator find( const Key& key ) const
		{
			ft::tree_node<const Key, T, Compare, Allocator> *res = _bstree.find_node(key, _bstree.get_root());

			if (res != nullptr)
				return (const_iterator(res));
			return (this->end());
		}

		ft::pair<iterator,iterator> equal_range(const Key& key)
		{
			ft::pair<iterator, iterator>	res;

			res.first = lower_bound(key);
			res.second = upper_bound(key);
			return (res);
		}

		ft::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
		{
			ft::pair<const_iterator, const_iterator>	res;

			res.first = lower_bound(key);
			res.second = upper_bound(key);
			return (res);
		}

		iterator lower_bound( const Key& key )
		{
			ft::tree_node	*res = _bstree.lower_bound(key, _bstree.get_root());

			if (res == nullptr)
				return (this->end())
			return (iterator(res));
		}

		const_iterator lower_bound( const Key& key ) const
		{
			ft::tree_node	*res = _bstree.lower_bound(key, _bstree.get_root());

			if (res == nullptr)
				return (this->end());
			return (const_iterator(res));
		}

		iterator upper_bound( const Key& key )
		{
			ft::tree_node	*res = _bstree.upper_bound(key, _bstree.get_root());

			if (res == nullptr)
				return (this->end());
			return (const_iterator(res));
		}

		const_iterator upper_bound( const Key& key ) const
		{
			ft::tree_node	*res = _bstree.upper_bound(key, _bstree.get_root());

			if (res == nullptr)
				return (this->end());
			return (const_iterator(res));
		}

		//=========================================== Observers ===================================================

		key_compare key_comp() const {return (_comp);}
		value_compare value_comp() const {return (value_compare(key_comp());)};

		//===========================================Non-Member functions===================================================
		template< class Key, class T, class Compare, class Alloc >
		friend bool operator==( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs )
		{
			iterator	lhs_start = lhs.begin();
			iterator	lhs_end = lhs.end();
			iterator	rhs_start = rhs.begin();
			iterator	rhs_end = rhs.end();

			while (lhs_start != lhs_end && rhs_start != rhs_end)
			{
				if (lhs_start != rhs_start)
					return false;
				lhs_start++;
				rhs_start++;
			}
			if (lhs_start != lhs_end || rhs_start != rhs_end)
				return false;
			return true;
		}

		template< class Key, class T, class Compare, class Alloc >
		friend bool operator!=( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs )
		{
			return (!(lhs == rhs));
		}
		template< class Key, class T, class Compare, class Alloc >
		friend bool operator<( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs )
		{
			iterator	lhs_start = lhs.begin();
			iterator	lhs_end = lhs.end();
			iterator	rhs_start = rhs.begin();
			iterator	rhs_end = rhs.end();

			if (lhs == rhs)
				return false;
			while (lhs_start != lhs_end && rhs_start != rhs_end)
			{
				if (lhs_start != rhs_start)
					return (lhs_start < rhs_start)
				lhs_start++;
				rhs_start++;
			}
			if (rhs_start == rhs_end)
				return false;
			return true;
		}

		template< class Key, class T, class Compare, class Alloc >
		friend bool operator<=( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs )
		{
			return(!(rhs < lhs));
		}

		template< class Key, class T, class Compare, class Alloc >
		friend bool operator>( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs )
		{
			return (!(lhs < rhs));
		}

		template< class Key, class T, class Compare, class Alloc >
		friend bool operator>=( const std::map<Key,T,Compare,Alloc>& lhs, const std::map<Key,T,Compare,Alloc>& rhs )
		{
			return(!(lhs < rhs));
		}

		template <class Key, class T, class Compare, class Alloc>  void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y);

		//=================================================================================================================
		private:
			bstree			_bstree;
			key_compare		_cmp;
			allocator_type	_alloc;
	};
}
#endif
