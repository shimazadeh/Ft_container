#ifndef _MAP_HPP
# define _MAP_HPP

#include <iostream>
#include <memory>
#include "./RedBlackTree/RBtree_iterator.hpp"
#include "./RedBlackTree/RBtree_node.hpp"
#include "./RedBlackTree/RBtree.hpp"
#include "./utils/pair.hpp"

namespace ft
{
	template<typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<ft::pair<const Key, T>> >
	class map
	{
		public:
		//===========================================Class Types===================================================
		typedef	Key											key_type;
		typedef T											mapped_type;
		typedef pair<Key, T>								value_type;
		typedef std::size_t									size_type;
		typedef std::ptrdiff_t								difference_type;
		typedef std::less<Key>								key_compare;
		typedef std::allocator<value_type>					allocator_type;

		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;

		typedef	tree_iterator<Key, T, Compare>				iterator;
		typedef	const iterator								const_iterator;
		typedef	const_iterator								reverse_iterator;
		typedef	const_iterator								const_reverse_iterator;

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
		{}

		template< typename InputIt >
		map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator() ): _bstree(bstree<Key, T, Compare, Allocator>()), _cmp(comp), _alloc(alloc)
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
			ft::pair<iterator, bool>	tmp = insert(ft::make_pair(key, mapped_type()));
			iterator					tmp2 = tmp.first;
			mapped_type					*res = new mapped_type((tmp2.node)->get_maptype());

			return *res;
		}

		//=========================================== Iterator ===================================================
		iterator		begin(){return (iterator(_bstree.min_element(_bstree.get_root())));}
		iterator		end(){return (iterator(_bstree.max_element(_bstree.get_root())));}

		const_iterator	begin() const {return (const_iterator(_bstree.min_element(_bstree.get_root())));}
		const_iterator	end()const {return (const_iterator(_bstree.max_element(_bstree.get_root())));}

		iterator		rbegin(){return (iterator(_bstree.max_element(_bstree.get_root())));}
		iterator		rend() {return (iterator(_bstree.min_element(_bstree.get_root())));}

		const_iterator	rbegin() const{return (const_iterator(_bstree.max_element(_bstree.get_root())));}
		const_iterator	rend() const{return (const_iterator(_bstree.min_element(_bstree.get_root())));}

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

			tmp = _bstree.find_node(value.first, _bstree.get_root());
			if (tmp == nullptr)//if the key doesn't exist
			{
				dprintf(2, "value is %c\n", value.first);//empty!!!
				_bstree.insert(value);
				was_inserted = true;
				result = iterator(tmp);
			}
			else
				result = this->end();
			return (ft::make_pair(result, was_inserted));
		}

		iterator insert( iterator pos, const value_type& value )
		{
			//????
		}

		template< typename InputIt >
		void insert( InputIt first, InputIt last )
		{
			while (first != last)
			{
				_bstree.insert(first->node->get_value());//insert as a pair
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
			return (_bstree.erase(key));
		}

		//================================================================
		void	swap(map &other)
		{
			map		tmp = *this;

			this->_bstree = other._bstree;
			this->_cmp = other._cmp;
			this->_alloc = other._alloc;

			other._bstree = tmp._bstree;
			other._cmp = tmp._cmp;
			other._alloc = tmp._alloc;
		}

		//=========================================== LookUps ===================================================
		size_type count( const Key& key ) const
		{
			if (_bstree.find_node(key, _bstree.get_root()))
				return (1);
			return (0);
		}

		iterator find( const Key& key )
		{
			node_type *res = _bstree.find_node(key, _bstree.get_root());

			if (res != nullptr)
				return (iterator(res));
			return (this->end());
		}

		const_iterator find( const Key& key ) const
		{
			node_type *res = _bstree.find_node(key, _bstree.get_root());

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
			node_type	*res = _bstree.lower_bound(key, _bstree.get_root());

			if (res == nullptr)
				return (this->end());
			return (iterator(res));
		}

		const_iterator lower_bound( const Key& key ) const
		{
			node_type	*res = _bstree.lower_bound(key, _bstree.get_root());

			if (res == nullptr)
				return (this->end());
			return (const_iterator(res));
		}

		iterator upper_bound( const Key& key )
		{
			node_type	*res = _bstree.upper_bound(key, _bstree.get_root());

			if (res == nullptr)
				return (this->end());
			return (const_iterator(res));
		}

		const_iterator upper_bound( const Key& key ) const
		{
			node_type	*res = _bstree.upper_bound(key, _bstree.get_root());

			if (res == nullptr)
				return (this->end());
			return (const_iterator(res));
		}

		//=========================================== Observers ===================================================

		key_compare key_comp() const {return (_cmp);}
		value_compare value_comp() const {return (value_compare(key_comp()));};

		//===========================================Non-Member functions===================================================
		friend bool operator==( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs )
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

		friend bool operator!=( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs )
		{
			return (!(lhs == rhs));
		}

		friend bool operator<( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs )
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
					return (lhs_start < rhs_start);//???double check this
				lhs_start++;
				rhs_start++;
			}
			if (rhs_start == rhs_end)
				return false;
			return true;
		}

		friend bool operator<=( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs )
		{
			return(!(rhs < lhs));
		}

		friend bool operator>( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs )
		{
			return (!(lhs < rhs));
		}

		friend bool operator>=( const ft::map<Key,T,Compare,Allocator>& lhs, const ft::map<Key,T,Compare,Allocator>& rhs )
		{
			return(!(lhs < rhs));
		}

		void swap (map<Key,T,Compare,Allocator>& x, map<Key,T,Compare,Allocator>& y)
		{
			map<Key, T, Compare, Allocator> tmp = x;

			x = y;
			y = tmp;
		}
		//================================================= DEBUGGING TOOLS ==============================================================

		void	print_tree(void)
		{
			_bstree.print(_bstree.get_root());
		}
		//=================================================================================================================
		private:
			bstree<Key, T, Compare, Allocator>			_bstree;
			key_compare		_cmp;
			allocator_type	_alloc;
	};
}
#endif
