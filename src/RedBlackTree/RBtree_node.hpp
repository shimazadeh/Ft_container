#ifndef	_TREE_NODE_HPP
#define	_TREE_NODE_HPP


#include "../utils/pair.hpp"
#include <memory>
#include <string>

namespace ft
{
	template<typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<ft::pair<const Key, T>> >
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

		tree_node(void): left(nullptr), right(nullptr), parent(nullptr), color("b")
		{
			value.first = Key();
			value.second = mapped_type();
		}

		tree_node(const mapped_type &_value, node_type *_left, node_type *_right, node_type *_parent, std::string _color):value(ft::make_pair(Key(), _value)), color(_color)
		{
			left = new node_type(*_left);
			right = new node_type(*_right);
			parent = new node_type(*_parent);
		}

		tree_node(const key_type &_value, node_type *_left, node_type *_right, node_type *_parent, std::string _color):value(ft::make_pair(_value, mapped_type())), color(_color)
		{
			left = new node_type(*_left);
			right = new node_type(*_right);
			parent = new node_type(*_parent);
		}

		tree_node(const value_type &_value, node_type *_left, node_type *_right, node_type *_parent, std::string _color): value(_value), color(_color)
		{
			left = new node_type(*_left);
			right = new node_type(*_right);
			parent = new node_type(*_parent);
		}

		tree_node(const node_type &other)
		{
			*this = other;
		}

		~tree_node()//Im not sure if I need to delete the pointers??
		{
		}

		tree_node &operator=(const tree_node &other)
		{
			if (this != &other)
			{
				value = other.value;
				left = new node_type(*(other.left));
				right = new node_type(*(other.right));
				parent = new node_type(*(other.parent));
				color = other.color;
			}
			return (*this);
		}
		//==========================Member functions=================================================================

		value_type	 get_value() const {return(this->value);}
		key_type	 get_key() const {return(this->value.first);}
		mapped_type	 get_maptype() const {return(this->value.second);}
		node_type	*get_rightnode() const {return(this->right);}
		node_type	*get_leftnode() const {return (this->left);}
		node_type	*get_parent() const {return (this->parent);}
		char		get_color() const {return (this->color);}

	};
	//=======================================Non-Member functions===============================================================
	template<typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<ft::pair<const Key, T>> >
	bool	operator==(const tree_node<Key, T, Compare, Allocator>	&lhs, const tree_node<Key, T, Compare, Allocator>	&rhs)
	{
		if (lhs->get_key() == rhs->get_key())
		{
			if (lhs->get_maptype() == lhs->get_maptype())
				return true;
		}
		return false;
	}

	template<typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<ft::pair<const Key, T>> >
	bool	operator!=(const tree_node<Key, T, Compare, Allocator>	&lhs, const tree_node<Key, T, Compare, Allocator>	&rhs)
	{
		return (!(lhs == rhs));
	}

	template<typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<ft::pair<const Key, T>> >
	bool	operator<(const tree_node<Key, T, Compare, Allocator>	&lhs, const tree_node<Key, T, Compare, Allocator>	&rhs)
	{
		Compare	_cmp;

		if (lhs->get_key() == rhs->get_key())
		{
			if (_cmp(lhs->get_maptype(), rhs->get_maptype()))
				return true;
			return false;
		}
		else if (_cmp(lhs->get_key(), rhs->get_key()))
			return true;
		return false;
	}

	template<typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<ft::pair<const Key, T>> >
	bool	operator<=(const tree_node<Key, T, Compare, Allocator>	&lhs, const tree_node<Key, T, Compare, Allocator>	&rhs)
	{
		return (!(lhs > rhs));
	}

	template<typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<ft::pair<const Key, T>> >
	bool	operator>(const tree_node<Key, T, Compare, Allocator>	&lhs, const tree_node<Key, T, Compare, Allocator>	&rhs)
	{
		if (lhs == rhs)
			return false;
		if (lhs < rhs)
			return false;
		return true;
	}

	template<typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<ft::pair<const Key, T>> >
	bool	operator>=(const tree_node<Key, T, Compare, Allocator>	&lhs, const tree_node<Key, T, Compare, Allocator>	&rhs)
	{
		return (!(lhs < rhs));
	}
}

#endif
