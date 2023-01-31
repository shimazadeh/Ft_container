#ifndef	_RB_REVERSEITERATOR_HPP
#define _RB_REVERSEITERATOR_HPP

#include "RBtree.hpp"

namespace	ft
{
	template<typename Key, typename T, typename Compare = std::less<Key> , bool IsConst = false >
	class tree_reverse_iterator
	{
		public:
			typedef	Key																	key_type;
			typedef	T																	mapped_type;
			typedef ft::pair<Key, T>													value_type;
			typedef std::less<Key>														key_compare;
			typedef std::allocator<value_type>											allocator_type;
			typedef ft::tree_node<key_type, mapped_type, key_compare, allocator_type>	node_type;
			typedef value_type															*pointer;
			typedef value_type															&reference;
			typedef std::random_access_iterator_tag										iterator_category;

		private:
			node_type	*node;

		public:
		tree_reverse_iterator():node(nullptr)
		{}

		tree_reverse_iterator(node_type	*n): node(n)
		{}

		tree_reverse_iterator(const tree_reverse_iterator<Key, T, Compare> &other):node(other.get_node())
		{}
		~tree_reverse_iterator()
		{}

		//=============================================================================================================================

		reference	operator*()const{return (node->get_value());}
		pointer		operator->()const{return (&node->get_value());}

		node_type	*get_node()const { return (node);}

		tree_reverse_iterator&	operator=(const tree_reverse_iterator &other)
		{
			if (this != &other)
				node = other.node;
			return (*this);
		}

		tree_reverse_iterator	operator++(int)
		{
			tree_reverse_iterator	tmp(*this);
			++(*this);

			return(tmp);
		}

		tree_reverse_iterator&	operator++()
		{
			if (node == nullptr)
				return (*this);
			if (!node->left->isNil())
			{
				node = node->left;
				while(!node->right->isNil())
					node = node->right;
			}
			else
			{
				node_type	*node_up = node->parent;
				while(!node->parent->isNil() && node == node_up->left)
				{
					node = node_up;
					node_up = node_up->parent;
				}
				node = node_up;
			}
			return (*this);
		}

		tree_reverse_iterator	operator--(int)
		{
			tree_reverse_iterator	tmp(*this);
			--(*this);

			return (tmp);
		}

		tree_reverse_iterator&	operator--()
		{
			if (node == nullptr)
				return (*this);
			if (!node->isNil() && !node->right->isNil())
			{
				node = node->right;
				while (node->left && !node->left->isNil())
					node = node->left;
			}
			else if (!node->isNil())
			{
				node_type	*node_up = node->parent;
				while(!node->parent->isNil() && node == node_up->right)
				{
					node = node_up;
					node_up = node_up->parent;
				}
				node = node_up;
			}
			else if (node->isNil())
				node = node->parent;
			return (*this);
		}

		bool operator==(const tree_reverse_iterator& rhs)
		{
			if (node->isNil() && rhs.node->isNil())
				return true;
			if (node->isNil() || rhs.node->isNil())
				return false;
			return (node == rhs.node);
		}

		bool operator!=(const tree_reverse_iterator& rhs)
		{
			if (node->isNil() && rhs.node->isNil())
				return false;
			if (node->isNil() || rhs.node->isNil())
				return true;
			return !(node == rhs.node);
		}
		bool operator<(const tree_reverse_iterator& rhs)
		{
			return (*(node) < *(rhs.node));
		}
	};

}
#endif
