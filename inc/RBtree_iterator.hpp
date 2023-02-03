#ifndef	_RBTREE_ITERATOR_HPP
#define _RBTREE_ITERATOR_HPP

#include "RBtree.hpp"
#include "./SelectConst.hpp"

namespace	ft
{
	template<typename Key, typename T, typename Compare = std::less<Key> , bool IsConst = false>
	class tree_iterator
	{
		public:
			typedef	Key																						key_type;
			typedef	T																						mapped_type;
			typedef ft::pair<key_type, mapped_type>															value_type;
			typedef std::less<Key>																			key_compare;
			typedef std::allocator<value_type>																allocator_type;

			typedef ft::tree_node<key_type, mapped_type, key_compare, allocator_type>						node_type;
			typedef typename ft::select_const<IsConst, const value_type&, value_type&>::type				reference;
			typedef typename ft::select_const<IsConst, const value_type*, value_type*>::type				pointer;
			typedef std::random_access_iterator_tag															iterator_category;

		private:
			node_type	*node;

		public:
		tree_iterator():node(nullptr)
		{}

		tree_iterator(node_type	*n): node(n)
		{}

		tree_iterator(const tree_iterator<Key, T, Compare> &other):node(other.get_node())
		{}

		~tree_iterator()
		{}

		//===============================================================================================================

		pointer		operator->()const {return (&node->get_value());}
		reference	operator*()const {return (node->get_value());}

		tree_iterator &operator=(const tree_iterator &other)
		{
			if (this != &other)
				node = other.node;
			return (*this);
		}
		node_type	*get_node()const { return (node);}

		//===============================================================================================================

		tree_iterator&	operator++()
		{
			if (node == nullptr)
				return (*this);
			if (!node->right->isNil())
			{
				node = node->right;
				while(node->left && !node->left->isNil())
					node = node->left;
			}
			else
			{
				node_type	*node_up = node->parent;
				while(!node->parent->isNil() && node == node_up->right)
				{
					node = node_up;
					node_up = node_up->parent;
				}
				node = node_up;
			}
			return (*this);
		}

		tree_iterator	operator++(int)
		{
			tree_iterator	tmp(*this);
			++(*this);

			return(tmp);
		}

		tree_iterator&	operator--()
		{
			if (node == nullptr)
				return (*this);
			if (!node->isNil() && !node->left->isNil())
			{
				node = node->left;
				while (!node->right->isNil())
					node = node->right;
			}
			else if (!node->isNil())
			{
				node_type	*node_up = node->parent;
				while(!node->parent->isNil() && node == node_up->left)
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

		tree_iterator	operator--(int)
		{
			tree_iterator	tmp(*this);
			--(*this);

			return (tmp);
		}

		bool operator==(const tree_iterator &rhs)
		{
			if (node->isNil() && rhs.node->isNil())
				return true;
			if (node->isNil() || rhs.node->isNil())
				return false;
			return (node == rhs.node);
		}

		bool operator!=(const tree_iterator& rhs)
		{
			if (node->isNil() && rhs.node->isNil())
				return false;
			if (node->isNil() || rhs.node->isNil())
				return true;
			return (node != rhs.node);
		}

		bool operator<(const tree_iterator& rhs)
		{
			return (*(node) < *(rhs.node));
		}


		bool operator>(const tree_iterator& rhs)
		{
			return (*(node) > *(rhs.node));
		}
	};
}
#endif
