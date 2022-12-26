#ifndef	_TREE_HPP
#define	_TREE_HPP

#include "tree_node.hpp"
#include "tree_iterator.hpp"

namespace ft
{
	template<typename T>
	class bstree
	{
		public:

		bstree():root(nullptr)
		{}

		explicit	bstree(const T &value)
		{
			root = new ft::tree_node<T>(value, nullptr, nullptr, nullptr);
		}
		//==========================================copy constructor===============================
		bstree(const bstree &other):root(other.root)
		{}

		bstree& operator=(const bstree &other)
		{
			if (*this != other)
			{
				root = other.root;
			}
			return (*this);
		}

		//============================================Move constructor============================
		bstree(const bstree &&other):root(other.root)
		{
			other.root = nullptr;
		}

		bstree&	operator=(const bstree &&other):root(other.root)
		{
			if (this != other)
			{
				root = other.root;
				other.root = nullptr;
			}
			return (*this);
		}
		//==================================================member functions================================

		//this function finds the node with minimum value of the element

		template<typename T>
		ft::tree_node<T>	*min_element(ft::tree_node<T>*	node)
		{
			if (node == nullptr || node->left == nullptr)
				return node;
			return (min_element(node->left);)
		}

		template<typename T>
		ft::tree_node<T>	*max_element(ft::tree_node<T>*	node)
		{
			if (node == nullptr || node->right == nullptr)
				return node;
			return (max_element(node->right);)
		}

		//this function inset the value into the tree starting the search from node

		ft::tree_node<T>	*insert(const T &value, ft::tree_node<T>*& node, ft::tree_node<T>* parent)
		{
			if (node == nullptr)
			{
				node = new ft::tree_node<T>(value, nullptr, nullptr, parent);
				return (node);
			}
			if (value < node->value)
				return (insert(value, node->left, node));
			else if (value > node->value)
				return (insert(value, node->right, node));
			// else the value already exist
			node->value = value;
			return node;
		}

		//erasing elements
		template<typename T>
		void	erase(const T &value, tree_node<T>*& node)
		{
			if (node == nullptr)
				return ;
			if (value < node->value)//we need to go to the left side
			{
				return (erase(value, node->left));
			}
			else if (value > node->value)//we need to go to the right side
			{
				return (erase(value, node->right));
			}
			else if (node->left != nullptr && node->right != nullptr)//a node with two childs
			{
				node->value = min_element(node->right)->value;
				return (erase(node->value, node->right));
			}
			else (node->left == nullptr && node->right == nullptr) //a leaf
			{
				tree_node<T>	*tmp = node;

				if (node->left != nullptr)
					node = node->left
				else if (node->right != nullptr)
					node = node->right;
				delete tmp;
			}
		}

		private:
			ft::tree_node<T>*	root = nullptr;
	};
}

#endif
