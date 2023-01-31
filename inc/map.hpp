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
			typedef	tree_iterator<Key,T, Compare, true>									const_iterator;
			typedef	tree_reverse_iterator<Key, T, Compare>								reverse_iterator;
			typedef	tree_reverse_iterator<Key, T, Compare, true>						const_reverse_iterator;
			typedef ft::tree_node<key_type, mapped_type, key_compare, allocator_type>	node_type;

			class	value_compare
			{
				public:

					Compare	comp;
					value_compare(Compare c): comp(c){}

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
				clear();
				insert(other.begin(), other.end());
				_alloc = other._alloc;
				_cmp = other._cmp;
				_allocNode = other._allocNode;
				_lastelem->parent =  _bstree.max_element(_bstree.get_root());
				_rev_lastelem->parent = _bstree.min_element(_bstree.get_root());
			}
			return (*this);
		}

		allocator_type get_allocator() const {return (_alloc);}

		//=========================================== Access ===================================================

		mapped_type& operator[]( const key_type& key )
		{
			insert(ft::make_pair(key, mapped_type()));
			node_type	*tmp = _bstree.find_node_key(key, _bstree.get_root());

			return ((tmp->value).second);
		}

		//=========================================== Iterator ===================================================
		iterator		begin()
		{
			return (iterator(_bstree.min_element(_bstree.get_root())));
		}

		iterator		end()
		{
			node_type	*end_element = _bstree.max_element(_bstree.get_root());

			_lastelem->parent = end_element;
			return (iterator(_lastelem));
		}

		const_iterator	begin()const
		{
			return (const_iterator(_bstree.min_element(_bstree.get_root())));
		}

		const_iterator	end()const
		{
			node_type	*end_element = _bstree.max_element(_bstree.get_root());

			_lastelem->parent = end_element;
			return (const_iterator(_lastelem));
		}

		reverse_iterator		rbegin()
		{
			return (reverse_iterator(_bstree.max_element(_bstree.get_root())));
		}

		reverse_iterator		rend()
		{
			node_type	*end_element = _bstree.min_element(_bstree.get_root());

			_rev_lastelem->parent = end_element;
			return (reverse_iterator(_rev_lastelem));
		}

		const_reverse_iterator	rbegin() const
		{
			return (const_reverse_iterator(_bstree.max_element(_bstree.get_root())));
		}

		const_reverse_iterator	rend() const
		{
			node_type	*end_element = _bstree.min_element(_bstree.get_root());

			_rev_lastelem->parent = end_element;
			return (const_reverse_iterator(_rev_lastelem));
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
			}
			result = iterator(tmp);
			return (ft::make_pair(result, was_inserted));
		}

		iterator insert( iterator pos, const value_type& value )
		{
			node_type	*res;

			res = _bstree.find_node_key(value.first, _bstree.get_root());
			if (res->isNil())
			{
				if (!pos.get_node()->isNil() && (++pos)->first == value.first)
					_bstree.insert_by_value(value, pos.get_node());
				else
					_bstree.insert_by_value(value);
				res = _bstree.find_node_key(value.first, _bstree.get_root());
			}
			return (iterator(res));
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
			_bstree.erase_by_key((pos.get_node())->get_key());
		}

		void erase( iterator first, iterator last )
		{
			map<Key, T>		tmp(first, last);

			for (iterator i = tmp.begin(); i != tmp.end(); i++)
				erase(i->first);
		}

		size_type erase( const Key& key )
		{
			if (!_bstree.find_node_key(key, _bstree.get_root())->isNil())
			{
				_bstree.erase_by_key(key);
				return (1);
			}
			return (0);
		}

		//=============================================================================================================
		void	swap(map &other)
		{
			_bstree.swap(other._bstree);
			swap(_cmp, other._cmp);
			swap(_alloc, other._alloc);
			swap(_allocNode, other._allocNode);
			swap(_lastelem, other._lastelem);
			swap(_rev_lastelem, other._rev_lastelem);
		}

		//=========================================== LookUps ===================================================
		size_type count( const Key& key ) const
		{
			if (!_bstree.find_node_key(key, _bstree.get_root())->isNil())
				return (1);
			return (0);
		}

		iterator find( const Key& key )
		{
			node_type *res = _bstree.find_node_key(key, _bstree.get_root());

			if (!res->isNil())
				return (iterator(res));
			return (this->end());
		}

		const_iterator find( const Key& key ) const
		{
			node_type *res = _bstree.find_node_key(key, _bstree.get_root());

			if (!res->isNil())
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
			node_type	*res = _bstree.lower_bound(key, _bstree.get_root());

			if (res->isNil())
				return (end());
			return (iterator(res));
		}

		const_iterator lower_bound( const Key& key ) const
		{
			node_type	*res = _bstree.lower_bound(key, _bstree.get_root());

			if (res->isNil())
				return (end());
			return (const_iterator(res));
		}

		iterator upper_bound( const Key& key )
		{
			node_type	*res = _bstree.upper_bound(key, _bstree.get_root());

			if (res->isNil())
				return (end());
			return (iterator(res));
		}

		const_iterator upper_bound( const Key& key ) const
		{
			node_type	*res = _bstree.upper_bound(key, _bstree.get_root());

			if (res->isNil())
				return (end());
			return (const_iterator(res));
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

			template <typename U>
			void	swap(U	a, U	b)
			{
				U	tmp = a;

				a = b;
				b = tmp;
			}

	};
	//===========================================Non-Member functions===================================================
	template <class Key, class T, class Compare, class Allocator>
	bool operator==( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs )
	{
		typename map<Key,T,Compare,Allocator>::const_iterator			lhs_start = lhs.begin();
		typename map<Key,T,Compare,Allocator>::const_iterator			lhs_end = lhs.end();
		typename map<Key,T,Compare,Allocator>::const_iterator			rhs_start = rhs.begin();
		typename map<Key,T,Compare,Allocator>::const_iterator			rhs_end = rhs.end();

		return (ft::equal(lhs_start, lhs_end, rhs_start, rhs_end));
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator!=( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs )
	{
		return (!(lhs == rhs));
	}

	template <class Key, class T, class Compare, class Allocator>
	bool operator<( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs )
	{
		typename ft::map<Key,T,Compare,Allocator>::const_iterator		lhs_start = lhs.begin();
		typename ft::map<Key,T,Compare,Allocator>::const_iterator		lhs_end = lhs.end();
		typename ft::map<Key,T,Compare,Allocator>::const_iterator		rhs_start = rhs.begin();
		typename ft::map<Key,T,Compare,Allocator>::const_iterator		rhs_end = rhs.end();

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
		x.swap(y);
	}
}
#endif
