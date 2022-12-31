#ifndef	_MAP_ITERATOR_HPP
#define _MAP_ITERATOR_HPP

#include "RBtree.hpp"

namespace	ft
{
	template<typename Key, typename T, typename Compare = std::less<Key>>
	struct tree_iterator
	{
		typedef	Key																	key_type;
		typedef	T																	mapped_type;
		typedef	T*																	pointer;
		typedef	T&																	reference;
		typedef	std::ptrdiff_t														difference_type;
		typedef	std::bidirectional_iterator_tag										iterator_category;
		typedef ft::pair<Key, T>													value_type;
		typedef std::less<Key>														key_compare;
		typedef std::allocator<value_type>											allocator_type;
		typedef ft::tree_node<key_type, mapped_type, key_compare, allocator_type>	node_type;

		//member
		node_type	*node;

		tree_iterator():node(nullptr)
		{}

		tree_iterator(const node_type	*n)
		{
			node = new node_type(*n);
		}

		tree_iterator &operator=(const tree_iterator &other)
		{
			if (this != &other)
				node = other.node;
			return (*this);
		}

		const	T&	operator*()const noexcept;

		tree_iterator&	operator++()
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
				auto	node_up = node->parent;
				while(node->parent != nullptr && node == node_up->right)
				{
					node = node_up;
					node_up = node_up->parent;
				}
				node = node_up;
			}
			return (*this);
		}

		tree_iterator&	operator++(int)
		{
			tree_iterator	*tmp = new tree_iterator(*this);
			node++;

			return(*tmp);
		}

		tree_iterator&	operator--()
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
			return (*this);
		}

		tree_iterator&	operator--(int)
		{
			tree_iterator	tmp = *this;
			node--;

			return (*this);
		}
	};

	//IM not sure about these functions:
	template<typename Key, typename T, typename Compare = std::less<Key>>
	bool operator==(tree_iterator<Key, T, Compare> &lhs, tree_iterator<Key, T, Compare> &rhs)
	{
		return (lhs.node == rhs.node);
	}

	template<typename Key, typename T, typename Compare = std::less<Key>>
	bool operator!=(tree_iterator<Key, T, Compare>& lhs, tree_iterator<Key, T, Compare>& rhs)
	{
		return (!(lhs == rhs));
	}

	template<typename Key, typename T, typename Compare = std::less<Key>>
	bool operator<(tree_iterator<Key, T, Compare>& lhs, tree_iterator<Key, T, Compare>& rhs)
	{
		return (lhs.node < rhs.node);
	}

}
#endif
