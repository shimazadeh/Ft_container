#ifndef	_RB_REVERSEITERATOR_HPP
#define _RB_REVERSEITERATOR_HPP

#include "RBtree.hpp"

namespace	ft
{
	template<typename Key, typename T, typename Compare = std::less<Key> , bool IsConst = false >
	struct tree_reverse_iterator
	{
		typedef	Key																	key_type;
		typedef	T																	mapped_type;
		typedef ft::pair<Key, T>													value_type;
		typedef std::less<Key>														key_compare;
		typedef std::allocator<value_type>											allocator_type;
		typedef ft::tree_node<key_type, mapped_type, key_compare, allocator_type>	node_type;///should be private??
		typedef value_type															*pointer;
		typedef value_type															&reference;

		//member
		node_type	*node;
		bool		is_end;

		tree_reverse_iterator():node(nullptr), is_end(false)
		{}

		tree_reverse_iterator(node_type	*n, bool	if_end): node(n), is_end(if_end)
		{
		}
		~tree_reverse_iterator()
		{
		}

		//=============================================================================================================================

		reference	operator*()const{return (node->get_value());}
		pointer		operator->()const{return (&node->get_value());}

		tree_reverse_iterator&	operator=(const tree_reverse_iterator &other)
		{
			if (this != &other)
			{
				is_end = other.is_end;
				node = other.node;
			}
			return (*this);
		}

		tree_reverse_iterator	operator++(int)//i++
		{
			tree_reverse_iterator	tmp(this);
			++(*this);

			return(tmp);
		}

		tree_reverse_iterator&	operator++()//++i
		{
			if (node == nullptr)
				return (*this);
			is_end = false;
			if (node->left && !node->left->isNil())//If the current node has a non-null right child,
			{
				node = node->left;
				while(!node->right->isNil())
					node = node->right;//Take a step down to the right Then run down to the left as far as possible
			}
			else//If the current node has a null right child Move up the tree until we have moved over a left child link
			{
				node_type	*node_up = node->parent;
				while(!node->parent->isNil() && node == node_up->left)
				{
					node = node_up;
					node_up = node_up->parent;
				}
				node = node_up;
			}
			if (node->isNil())
				is_end = true;
			return (*this);
		}

		tree_reverse_iterator	operator--(int)//i--
		{
			tree_reverse_iterator	tmp(*this);
			--(*this);

			return (tmp);
		}

		tree_reverse_iterator&	operator--()//--i
		{
			if (node == nullptr)
				return (*this);
			is_end = false;
			if (!node->right->isNil())//If the current node has a non-null left child,
			{
				node = node->right;
				while (!node->left->isNil())
					node = node->left;// Take a step down to the left and run down to the right
			}
			else// If the current node has a null left child, Move up the tree until we have moved over a right child link
			{
				node_type	*node_up = node->parent;
				while(!node->parent->isNil() && node == node_up->right)
				{
					node = node_up;
					node_up = node_up->parent;
				}
				node = node_up;
			}
			if (node->isNil())
				is_end = true;
			return (*this);
		}
	};

	template<typename Key, typename T, typename Compare>
	bool operator==(const ft::tree_reverse_iterator<Key, T, Compare> &lhs, const ft::tree_reverse_iterator<Key, T, Compare> &rhs)
	{
		if (lhs.is_end && rhs.is_end)
			return true;
		if (lhs.is_end || rhs.is_end)
			return false;
		return (*(lhs.node) == *(rhs.node));
	}

	template<typename Key, typename T, typename Compare>
	bool operator!=(const ft::tree_reverse_iterator<Key, T, Compare>& lhs, const ft::tree_reverse_iterator<Key, T, Compare>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<typename Key, typename T, typename Compare>
	bool operator<(const ft::tree_reverse_iterator<Key, T, Compare>& lhs, const ft::tree_reverse_iterator<Key, T, Compare>& rhs)
	{
		return (*(lhs.node) < *(rhs.node));
	}

}
#endif
