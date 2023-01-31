#ifndef	_RBTREE_NODE_HPP
#define	_RBTREE_NODE_HPP


#include "./pair.hpp"
#include <memory>
#include <iostream>
#include <string>
#define nullptr NULL

namespace ft
{
	template<typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<ft::pair<const Key, T> > >
	struct tree_node
	{
		typedef	T																	mapped_type;
		typedef	Key																	key_type;
		typedef	ft::pair<Key, T>													value_type;
		typedef std::less<Key>														key_compare;
		typedef std::allocator<value_type>											allocator_type;
		typedef ft::tree_node<key_type, mapped_type, key_compare, allocator_type>	node_type;

		//============================================ Members ================================================================

		value_type		value;
		node_type		*left;
		node_type		*right;
		node_type		*parent;
		std::string		color;

		//============================================= Constructor & Destroctur=========================================================

		tree_node(void):left(nullptr), right(nullptr), parent(nullptr), color("b")
		{
			value = ft::make_pair(Key(), mapped_type());
		}

		tree_node(const value_type &_value, std::string _color): value(_value),  left(nullptr), right(nullptr), parent(nullptr), color(_color)
		{}

		tree_node(const node_type &other)
		{
			*this = other;
		}

		~tree_node()
		{}

		tree_node &operator=(const tree_node &other)
		{
			if (this != &other)
			{
				value = other.value;
				left = other.left;
				right = other.right;
				parent = other.parent;
				color = other.color;
			}
			return (*this);
		}
		//==========================Member functions=================================================================

		value_type&		get_value() {return(value);}
		key_type&		get_key() {return(value.first);}
		mapped_type&	 get_maptype() {return(value.second);}
		node_type		*get_rightnode() const {return(right);}
		node_type		*get_leftnode() const {return (left);}
		node_type		*get_parent() const {return (parent);}
		std::string&	get_color() {return (color);}

		value_type		get_value() const {return(value);}
		key_type		get_key() const {return(value.first);}
		mapped_type		get_maptype() const {return(value.second);}
		std::string		get_color() const {return (color);}

		bool			isNil()const
		{
			value_type	is_empty = ft::make_pair(Key(), mapped_type());

			if (value == is_empty && right == nullptr && left == nullptr)
				return true;
			return false;
		}

		bool	operator==(const tree_node	&rhs)
		{
			if (get_key() == rhs.get_key())
			{
				if (get_maptype() == rhs.get_maptype())
					return true;
			}
			return false;
		}

		bool	operator!=(const tree_node	&rhs)
		{
			return (!(*this == rhs));
		}

		bool	operator<(const tree_node	&rhs)
		{
			if (get_key() == rhs.get_key())
			{
				if (std::less<mapped_type>()(get_maptype(), rhs.get_maptype()))
					return true;
				return false;
			}
			else if (std::less<key_type>()(get_key(), rhs.get_key()))
				return true;
			return false;
		}

		bool	operator<=(const tree_node	&rhs)
		{
			return (!(*this > rhs));
		}

		bool	operator>(const tree_node	&rhs)
		{
			if (*this == rhs)
				return false;
			if (*this < rhs)
				return false;
			return true;
		}

		bool	operator>=(const tree_node	&rhs)
		{
			return (!(*this < rhs));
		}

	};
}

#endif
