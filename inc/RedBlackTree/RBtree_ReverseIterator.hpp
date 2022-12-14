#ifndef	_RB_REVERSEITERATOR_HPP
#define _RB_REVERSEITERATOR_HPP

#include "RBtree.hpp"

namespace	ft
{
	template<typename Key, typename T, typename Compare = std::less<Key> >
	struct tree_reverse_iterator
	{
		typedef	Key																	key_type;
		typedef	T																	mapped_type;
		typedef ft::pair<Key, T>													value_type;
		typedef std::less<Key>														key_compare;
		typedef std::allocator<value_type>											allocator_type;
		typedef ft::tree_node<key_type, mapped_type, key_compare, allocator_type>	node_type;

		//member
		node_type	*node;
		bool		is_end;

		tree_reverse_iterator():node(nullptr), is_end(false)
		{}

		tree_reverse_iterator(const node_type	*n, bool	if_end): is_end(if_end)
		{
			if (n != nullptr)
				node = new node_type(*n);
			else
				node = nullptr;
		}
		~tree_reverse_iterator()
		{}

		node_type &operator*()
		{
			return (*node);
		}

		tree_reverse_iterator&	operator=(const tree_reverse_iterator &other)
		{
			if (this != &other)
			{
				is_end = other.is_end;
				node = other.node;
			}
			return (*this);
		}

		// const	T&	operator*()const noexcept
		// {}

		tree_reverse_iterator&	operator++(int)//i++
		{
			tree_reverse_iterator	*tmp = new tree_reverse_iterator(*this);
			++(*this);

			return(*tmp);
		}

		tree_reverse_iterator&	operator++()//++i
		{
			if (node == nullptr)
				return (*this);
			if (node->right)//If the current node has a non-null right child,
			{
				node = node->right;
				while(node->left != nullptr)
					node = node->left;//Take a step down to the right Then run down to the left as far as possible
			}
			else//If the current node has a null right child Move up the tree until we have moved over a left child link
			{
				node_type	*node_up = node->parent;
				while(node->parent != nullptr && node == node_up->right)
				{
					// std::cout << "current parent" << *node_up << std::endl;
					node = node_up;
					node_up = node_up->parent;
					// std::cout << "next parent " << *node_up << std::endl;
				}
				node = node_up;
			}
			if (node == nullptr)
				is_end = true;
			return (*this);
		}

		tree_reverse_iterator&	operator--(int)//i--
		{
			tree_reverse_iterator	tmp = *this;
			--(*this);

			return (*this);
		}

		tree_reverse_iterator&	operator--()//--i
		{
			if (node == nullptr)
				return (*this);
			if (node->left != nullptr)//If the current node has a non-null left child,
			{
				node = node->left;
				while (node->right != nullptr)
					node = node->right;// Take a step down to the left and run down to the right
			}
			else// If the current node has a null left child, Move up the tree until we have moved over a right child link
			{
				node_type	*node_up = node->parent;
				while(node->parent != nullptr && node == node_up->left)
				{
					node = node_up;
					node_up = node_up->parent;
				}
				node = node_up;
			}
			if (node == nullptr)
				is_end = true;
			return (*this);
		}
	};

	//IM not sure about these functions:
	template<typename Key, typename T, typename Compare>
	bool operator==(ft::tree_reverse_iterator<Key, T, Compare> &lhs, ft::tree_reverse_iterator<Key, T, Compare> &rhs)
	{
		if (lhs.is_end && rhs.is_end)
			return true;
		if (lhs.is_end || rhs.is_end)
			return false;
		return (*(lhs.node) == *(rhs.node));
	}

	template<typename Key, typename T, typename Compare>
	bool operator!=(ft::tree_reverse_iterator<Key, T, Compare>& lhs, ft::tree_reverse_iterator<Key, T, Compare>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<typename Key, typename T, typename Compare>
	bool operator<(ft::tree_reverse_iterator<Key, T, Compare>& lhs, ft::tree_reverse_iterator<Key, T, Compare>& rhs)
	{
		return (*(lhs.node) < *(rhs.node));
	}

}
#endif
