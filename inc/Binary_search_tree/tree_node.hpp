#ifndef	_TREE_NODE_HPP
#define	_TREE_NODE_HPP

#include "./utils/pair.hpp"
#include <memory>

namespace ft
{
	template<typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<std::pair<const Key, T>> >
	struct tree_node
	{
		typedef	T																	mapped_type;
		typedef	const Key															key_type;
		typedef	ft::pair<const Key, T>												value_type;
		typedef std::less<Key>														key_compare;
		typedef std::allocator<value_type>											allocator_type;
		typedef ft::tree_node<key_type, mapped_type, key_compare, allocator_type>	node_type;

		//======members===========
		value_type		value;
		node_type		*left;
		node_type		*right;
		node_type		*parent;
		char			color;

		//========Constructor & Destroctur=============================================================================

		tree_node(void): left(nullptr), right(nullptr), parent(nullptr), color('b')
		{
			value.first = Key();
			value.second = mapped_type();
		}

		tree_node(const mapped_type &_value, node_type *_left = nullptr, node_type *_right = nullptr, tree_node<T> *_parent = nullptr):value(ft::makepair(Key(), _value)), left(_left), right(_right), parent(_parent), color('b')
		{}

		tree_node(const node_type &other): value(other.value), left(other.left), right(other.right), parent(other.parent), color(other.color)
		{}

		~tree_node()//Im not sure if I need to delete the pointers
		{
		}

		//==========================Member functions=================================================================
		value_type	&get_value() const {return(this->value);}
		key_type	&get_key() const {return(this->value.first);}
		mapped_type	&get_maptype() const {return(this->value.second);}
		node_type	*get_rightnode() const {return(this->right);}
		node_type	*get_leftnode() const {return (this->left);}
		node_type	*get_parent() const {return (this->parent);}
		char		get_color() const {return (this->color);}

		// const value_type	&get_value()const {return(this->value);}
		// const key_type	&get_key()const{return(this->value.first);}
		// const mapped_type	&get_maptype()const{return(this->value.second);}
	};
}

#endif
