#ifndef	_MAP_ITERATOR_HPP
#define _MAP_ITERATOR_HPP

#include "tree.hpp"

namespace	ft
{
	template<typename Key, typename T, typename Compare = std::less<Key>>
	struct tree_iterator
	{
		typedef	const Key											key_type;
		typedef	T													mapped_type;
		typedef	T*													pointer;
		typedef	T&													reference;
		typedef	std::ptrdiff_t										difference_type;
		typedef	std::bidirectional_iterator_tag						iterator_category;
		typedef std::less<Key>										key_compare;
		typedef ft::tree_node<key_type, mapped_type, key_compare>	tree_node;

		//member
		const	tree_node	*node;

		tree_iterator():node(nullptr)
		{}

		tree_iterator(const ft::tree_node<T>* n):node(n)
		{}

		const	T&	operator*()const noexcept;

		tree_iterator&	operator++()
		{
			if (node == nullptr)
				return (*this);
			if (node->right)//If the current node has a non-null right child,
			{
				node = ft::tree::min_element(node->right);// Take a step down to the right Then run down to the left as far as possible
			}
			else// If the current node has a null right child Move up the tree until we have moved over a left child link
			{
				auto	node_up = node->parent;
				while(parent != nullptr && node == node_up->right)
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
			tree_iterator	tmp = *this;
			node++;

			return(tmp);
		}

		tree_iterator&	operator--()
		{
			if (node == nullptr)
				return (*this);
			if (node->left)//If the current node has a non-null left child,
			{
				node = ft::tree::max_element(node->left);// Take a step down to the left and run down to the right
			}
			else// If the current node has a null left child, Move ?? the tree until we have moved over a right child link
			{
				auto	node_up = node->parent;
				while(parent != nullptr && node == node_up->left)
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

		template< class Key, class T, class Compare, class Alloc >
		friend bool operator==(tree_iterator &lhs, tree_iterator &rhs)
		{
			if (lhs->node->first == rhs->node->first)
			{
				if (lhs->node->second == rhs->node->second)
					return  true;
			}
			return false;
		}

		template< class Key, class T, class Compare, class Alloc >
		friend bool operator!=(tree_iterator& lhs, tree_iterator& rhs)
		{
			return (!(lhs == rhs));
		}

		template< class Key, class T, class Compare, class Alloc >
		friend bool operator<(tree_iterator& lhs, tree_iterator& rhs)
		{
			if (lhs->node->first < rhs->node->first)
				return true;
			else if (lhs->node->first == rhs->node->first)
			{
				if (lhs->node->second < rhs->node->second)
					return true;
			}
			return false;
		}

	};

}
#endif
