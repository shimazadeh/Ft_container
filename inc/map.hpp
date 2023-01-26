#ifndef _MAP_HPP
# define _MAP_HPP

#include <iostream>
#include <memory>
#include "./RBtree_iterator.hpp"
#include "./RBtree_ReverseIterator.hpp"
#include "./RBtree_node.hpp"
#include "./RBtree.hpp"
#include "./equal.hpp"
#include "./Is_Integral.hpp"
#include "./pair.hpp"
#include <cstdio>

namespace ft
{
	template<typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
		//===========================================Class Types===================================================
		typedef	Key																	key_type;
		typedef T																	mapped_type;
		typedef pair<Key, T>														value_type;
		typedef std::size_t															size_type;
		typedef std::ptrdiff_t														difference_type;
		typedef std::less<Key>														key_compare;
		typedef std::allocator<value_type>											allocator_type;

		typedef typename allocator_type::reference									reference;
		typedef typename allocator_type::const_reference							const_reference;
		typedef typename allocator_type::pointer									pointer;
		typedef typename allocator_type::const_pointer								const_pointer;

		typedef	tree_iterator<Key, T, Compare>										iterator;
		typedef	const iterator														const_iterator;
		typedef	tree_reverse_iterator<Key, T, Compare>								reverse_iterator;
		typedef	const reverse_iterator												const_reverse_iterator;
		typedef ft::tree_node<key_type, mapped_type, key_compare, allocator_type>	node_type;

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
		};
		//=========================================== Constructor ===================================================
		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_bstree(bstree<Key, T, Compare, Allocator>()), _cmp(comp), _alloc(alloc)
		{
			_lastelem = new node_type();
			_rev_lastelem = new node_type();
		}

		template< typename InputIterator >
		map(InputIterator first, InputIterator last, const Compare& comp = Compare(),
		const Allocator& alloc = Allocator(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>:: type* = 0):
		_bstree(bstree<Key, T, Compare, Allocator>()), _cmp(comp), _alloc(alloc)
		{
			_lastelem = new node_type();
			_rev_lastelem = new node_type();
			this->insert(first, last);
		}

		map(const map& other)
		{
			_lastelem = new node_type();
			_rev_lastelem = new node_type();
			*this = other;
		}

		//=========================================== Destructor ===================================================
		~map()
		{
			delete _lastelem;
			delete _rev_lastelem;
		}
		//=========================================== Operator ===================================================
		map& operator=( const map& other )
		{
			if (this != &other)
			{
				this->clear();
				this->insert(other.begin(), other.end());
				_alloc = other._alloc;
				_cmp = other._cmp;
				_allocNode = other._allocNode;
				*_lastelem = *other._lastelem;
				*_rev_lastelem = *other._rev_lastelem;
			}
			return (*this);
		}

		allocator_type get_allocator() const {return (_alloc);}

		//=========================================== Access ===================================================
		mapped_type& at(const key_type& key)//ref page says since c++11!!!!!???
		{
			if (!_bstree.find_node_key(key, _bstree.get_root()))
				throw std::out_of_range("key is out of range");
			else
				return ((*this)[key]);
		}

		const mapped_type& at( const key_type& key ) const
		{
			if (!_bstree.find_node_key(key, _bstree.get_root()))
				throw std::out_of_range("key is out of range");
			else
				return ((*this)[key]);
		}

		mapped_type& operator[]( const key_type& key )
		{
			_bstree.insert_by_key(key);
			node_type	*tmp = _bstree.find_node_key(key, _bstree.get_root());

			//think about this: why this method didnt work???
			// ft::pair<iterator, bool>	tmp = insert(ft::make_pair(key, mapped_type()));
			// iterator					tmp2 = tmp.first;
			// return ((*tmp2).value.second);
			return (tmp->value.second);
		}

		//=========================================== Iterator ===================================================
		iterator		begin()
		{
			bool	if_end = false;

			return (iterator(_bstree.min_element(_bstree.get_root(), if_end), if_end));
		}
		iterator		end()
		{
			bool		whatever = false;
			node_type	*end_element = _bstree.max_element(_bstree.get_root(), whatever);

			_lastelem->parent = end_element;
			return (iterator(_lastelem, true));
		}

		const_iterator	begin() const
		{
			bool	if_end = false;

			return (const_iterator(_bstree.min_element(_bstree.get_root(), if_end), if_end));
		}
		const_iterator	end()const
		{
			bool		whatever = false;
			node_type	*end_element = _bstree.max_element(_bstree.get_root(), whatever);

			_lastelem->parent = end_element;
			return (const_iterator(_lastelem, true));
		}

		reverse_iterator		rbegin()
		{
			bool	if_end = false;

			return (reverse_iterator(_bstree.max_element(_bstree.get_root(), if_end), if_end));
		}

		reverse_iterator		rend()
		{
			bool		whatever = false;
			node_type	*end_element = _bstree.min_element(_bstree.get_root(), whatever);

			_rev_lastelem->parent = end_element;
			return (reverse_iterator(_rev_lastelem, true));
		}

		const_reverse_iterator	rbegin() const
		{
			bool	if_end = false;

			return (const_reverse_iterator(_bstree.max_element(_bstree.get_root(), if_end), if_end));
		}

		const_reverse_iterator	rend() const
		{
			bool		whatever = false;
			node_type	*end_element = _bstree.min_element(_bstree.get_root(), whatever);

			_rev_lastelem->parent = end_element;
			return (const_reverse_iterator(_rev_lastelem, true));
		}

		//=========================================== Capacity ===================================================
		bool	empty()const {return (_bstree.size() == 0);}

		size_type	size()const { return (_bstree.size());}

		size_type	max_size()const{ return(_bstree.max_size());}
		//=========================================== Modifiers ===================================================
		void clear()
		{
			_bstree.clear_all();
		}

		ft::pair<iterator, bool> insert(const value_type& value)
		{
			bool		was_inserted = false;
			iterator	result;
			node_type	*tmp;

			tmp = _bstree.find_node_key(value.first, _bstree.get_root());
			if (tmp->isNil())
			{
				_bstree.insert_by_value(value);
				was_inserted = true;
				tmp = _bstree.find_node_key(value.first, _bstree.get_root());
				result = iterator(tmp, tmp->isNil());
			}
			else
				result = this->end();
			return (ft::make_pair(result, was_inserted));
		}

		iterator insert( iterator pos, const value_type& value )
		{
			node_type	*res;

			res = _bstree.find_node_key(value.first, _bstree.get_root());
			if (res->isNil())
			{
				if ((*pos).first + 1 == value.first)
					_bstree.insert_by_value(value, pos.get_node());
				else
					_bstree.insert_by_value(value);
				res = _bstree.find_node_key(value.first, _bstree.get_root());
			}
			return (iterator(res, res->isNil()));
		}

		template< typename InputIterator >
		void insert( InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>:: type* = 0)
		{
			while (first != last)
			{
				_bstree.insert_by_value(*first);
				first++;
			}
		}

		//=======================================================================
		void erase( iterator pos )
		{
			_bstree.erase(pos.get_value());
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
			if (_bstree.find_node_key(key, _bstree.get_root()))
			{
				_bstree.erase_by_key(key);
				return (1);
			}
			return (0);
		}

		//=============================================================================================================
		void	swap(map &other)
		{
			map			tmp(*this);

			_bstree.swap(other._bstree);
			_cmp = other._cmp;
			_alloc = other._alloc;
			_allocNode = other._allocNode;
			*_lastelem = *other._lastelem;
			*_rev_lastelem = *other._rev_lastelem;

			other._bstree.swap(tmp._bstree);
			other._cmp = tmp._cmp;
			other._alloc = tmp._alloc;
			other._allocNode = tmp._allocNode;
			*other._lastelem = *tmp._lastelem;
			*other._rev_lastelem = *tmp._rev_lastelem;
		}

		//=========================================== LookUps ===================================================
		size_type count( const Key& key ) const
		{
			if (_bstree.find_node_key(key, _bstree.get_root()))
				return (1);
			return (0);
		}

		iterator find( const Key& key )
		{
			node_type *res = _bstree.find_node_key(key, _bstree.get_root());

			if (!res->isNil())
				return (iterator(res, res->isNil()));
			return (this->end());
		}

		const_iterator find( const Key& key ) const
		{
			node_type *res = _bstree.find_node_key(key, _bstree.get_root());

			if (!res->isNil())
				return (const_iterator(res, res->isNil()));
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
			node_type	*res = _bstree.lower_bound(key, _bstree.get_root());

			if (res->isNil())
				return (this->end());
			return (iterator(res, res->isNil()));
		}

		const_iterator lower_bound( const Key& key ) const
		{
			node_type	*res = _bstree.lower_bound(key, _bstree.get_root());

			if (res->isNil())
				return (this->end());
			return (const_iterator(res, res->isNil()));
		}

		iterator upper_bound( const Key& key )
		{
			node_type	*res = _bstree.upper_bound(key, _bstree.get_root());

			if (res->isNil())
				return (this->end());
			return (const_iterator(res, res->isNil()));
		}

		const_iterator upper_bound( const Key& key ) const
		{
			node_type	*res = _bstree.upper_bound(key, _bstree.get_root());

			if (res->isNil())
				return (this->end());
			return (const_iterator(res, res->isNil()));
		}

		//=========================================== Observers ===================================================

		key_compare key_comp() const {return (_cmp);}
		value_compare value_comp() const {return (value_compare(key_comp()));};

		//================================================= DEBUGGING TOOLS ==============================================================

		void	print_tree(std::string str)
		{
			std::cout << "printing tree:" << str << std::endl;
			_bstree.print(_bstree.get_root());
		}
		//=================================================================================================================
		private:
			bstree<Key, T, Compare, Allocator>			_bstree;
			key_compare									_cmp;
			allocator_type								_alloc;
			std::allocator<node_type>					_allocNode;
			node_type									*_lastelem;
			node_type									*_rev_lastelem;

			template <typename U>
			void	swap(U	*a, U	*b)
			{
				U	*tmp = a;

				a = b;
				b = tmp;
			}
	};
	//===========================================Non-Member functions===================================================
	template <class Key, class T, class Compare, class Allocator>
	bool operator==( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs )
	{
		typename map<Key,T,Compare,Allocator>::iterator	lhs_start = lhs.begin();
		typename map<Key,T,Compare,Allocator>::iterator	lhs_end = lhs.end();
		typename map<Key,T,Compare,Allocator>::iterator	rhs_start = rhs.begin();
		typename map<Key,T,Compare,Allocator>::iterator	rhs_end = rhs.end();

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

	template <class Key, class T, class Compare, class Allocator>
	bool operator!=( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs )
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator<( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs )
	{
		typename ft::map<Key,T,Compare,Allocator>::iterator	lhs_start = lhs.begin();
		typename ft::map<Key,T,Compare,Allocator>::iterator	lhs_end = lhs.end();
		typename ft::map<Key,T,Compare,Allocator>::iterator	rhs_start = rhs.begin();
		typename ft::map<Key,T,Compare,Allocator>::iterator	rhs_end = rhs.end();

		if (lhs == rhs)
			return false;
		while (lhs_start != lhs_end && rhs_start != rhs_end)
		{
			if (lhs_start != rhs_start)
				return (lhs_start < rhs_start);
			lhs_start++;
			rhs_start++;
		}
		if (rhs_start == rhs_end)
			return false;
		return true;
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator<=( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs )
	{
		return(!(lhs > rhs));
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator>( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs )
	{
		if (lhs == rhs)
			return false;
		if (lhs < rhs)
			return false;
		return (true);
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator>=( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs )
	{
		return(!(lhs < rhs));
	}

	template <class Key, class T, class Compare, class Allocator>
	void swap (map<Key,T,Compare,Allocator>& x, map<Key,T,Compare,Allocator>& y)
	{
		map<Key, T, Compare, Allocator> tmp = x;

		x = y;
		y = tmp;
	}
}
#endif
