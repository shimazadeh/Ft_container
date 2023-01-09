#ifndef	_RBTREE_NODE_HPP
#define	_RBTREE_NODE_HPP


#include "../utils/pair.hpp"
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

		tree_node(void): left(nullptr), right(nullptr), parent(nullptr), color("b")
		{
			value = ft::make_pair(Key(), mapped_type());
		}

		tree_node(const mapped_type &_value, node_type *_left, node_type *_right, node_type *_parent, std::string _color):value(ft::make_pair(Key(), _value)), color(_color)
		{
			if (_left != nullptr)
				left = new node_type(_left->value, _left->right, _left->left, _left->parent, _left->color);
			else
				left = nullptr;

			if (_right != nullptr)
				right = new node_type(_right->value, _right->right, _right->left, _right->parent, _right->color);
			else
				right = nullptr;

			if (_parent != nullptr)
				parent = new node_type(_parent->value, _parent->right, _parent->left, _parent->parent, _parent->color);
			else
				parent = nullptr;
		}

		tree_node(const key_type &_value, node_type *_left, node_type *_right, node_type *_parent, std::string _color):value(ft::make_pair(_value, mapped_type())), color(_color)
		{
			if (_left != nullptr)
				left = new node_type(_left->value, _left->right, _left->left, _left->parent, _left->color);
			else
				left = nullptr;

			if (_right != nullptr)
				right = new node_type(_right->value, _right->right, _right->left, _right->parent, _right->color);
			else
				right = nullptr;

			if (_parent != nullptr)
				parent = new node_type(_parent->value, _parent->right, _parent->left, _parent->parent, _parent->color);
			else
				parent = nullptr;
		}

		tree_node(const value_type &_value, node_type *_left, node_type *_right, node_type *_parent, std::string _color): value(_value), color(_color)
		{
			if (_left != nullptr)
				left = new node_type(_left->value, _left->right, _left->left, _left->parent, _left->color);
			else
				left = nullptr;

			if (_right != nullptr)
				right = new node_type(_right->value, _right->right, _right->left, _right->parent, _right->color);
			else
				right = nullptr;

			if (_parent != nullptr)
				parent = new node_type(_parent->value, _parent->right, _parent->left, _parent->parent, _parent->color);
			else
				parent = nullptr;
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
				left = other.left;
				right = other.right;
				parent = other.parent;
				color = other.color;
			}
			return (*this);
		}
		//==========================Member functions=================================================================

		value_type&	get_value() {return(value);}
		key_type&	get_key() {return(value.first);}
		mapped_type& get_maptype() {return(value.second);}
		node_type	*get_rightnode() const {return(right);}
		node_type	*get_leftnode() const {return (left);}
		node_type	*get_parent() const {return (parent);}
		std::string&	get_color() {return (color);}

		value_type	get_value() const {return(value);}
		key_type	get_key() const {return(value.first);}
		mapped_type get_maptype() const {return(value.second);}
		std::string	get_color() const {return (color);}
		bool		isNil()const
		{
			return (this->parent == this);//smart mf you are!
		}
	};

	//=======================================Non-Member functions===============================================================
	template<typename Key, typename T, typename Compare, typename Allocator>
	bool	operator==(const tree_node<Key, T, Compare, Allocator>	&lhs, const tree_node<Key, T, Compare, Allocator>	&rhs)
	{
		if (lhs.get_key() == rhs.get_key())
		{
			if (lhs.get_maptype() == lhs.get_maptype())
				return true;
		}
		return false;
	}

	template<typename Key, typename T, typename Compare, typename Allocator>
	bool	operator!=(const tree_node<Key, T, Compare, Allocator>	&lhs, const tree_node<Key, T, Compare, Allocator>	&rhs)
	{
		return (!(lhs == rhs));
	}

	template<typename Key, typename T, typename Compare, typename Allocator>
	bool	operator<(const tree_node<Key, T, Compare, Allocator>	&lhs, const tree_node<Key, T, Compare, Allocator>	&rhs)
	{
		Compare	_cmp;

		if (lhs.get_key() == rhs.get_key())
		{
			if (_cmp(lhs.get_maptype(), rhs.get_maptype()))
				return true;
			return false;
		}
		else if (_cmp(lhs.get_key(), rhs.get_key()))
			return true;
		return false;
	}

	template<typename Key, typename T, typename Compare, typename Allocator>
	// template<typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<ft::pair<const Key, T> > >
	bool	operator<=(const tree_node<Key, T, Compare, Allocator>	&lhs, const tree_node<Key, T, Compare, Allocator>	&rhs)
	{
		return (!(lhs > rhs));
	}

	template<typename Key, typename T, typename Compare, typename Allocator>
	bool	operator>(const tree_node<Key, T, Compare, Allocator>	&lhs, const tree_node<Key, T, Compare, Allocator>	&rhs)
	{
		if (lhs == rhs)
			return false;
		if (lhs < rhs)
			return false;
		return true;
	}

	template<typename Key, typename T, typename Compare, typename Allocator>
	bool	operator>=(const tree_node<Key, T, Compare, Allocator>	&lhs, const tree_node<Key, T, Compare, Allocator>	&rhs)
	{
		return (!(lhs < rhs));
	}

	template<typename Key, typename T, typename Compare, typename Allocator>
	std::ostream	&operator<<(std::ostream &o, const tree_node<Key, T, Compare, Allocator> &src)
	{
		if (src.isNil() == false)
			o << "Key: " << src.get_key() << " with value of:" << src.get_maptype();

		return o;
	}
}

#endif
