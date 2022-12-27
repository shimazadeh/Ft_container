#ifndef	_TREE_HPP
#define	_TREE_HPP

#include "tree_node.hpp"
#include "tree_iterator.hpp"
#include <memory>
#include <iostream>

namespace ft
{
	template<typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<std::pair<const Key, T>> >
	class bstree
	{
		public:
		typedef	Key											key_type;
		typedef T											mapped_type;
		typedef std::pair<const Key, T>						value_type;
		typedef std::size_t									size_type;
		typedef std::allocator<value_type>					allocator_type;
		typedef std::less<Key>								key_compare;

		//========================================================================================
		bstree():root(nullptr), _size(0), _nodeAlloc(allocator())
		{}

		explicit	bstree(const T &value)
		{
			root = new ft::tree_node<T>(value, nullptr, nullptr, nullptr);
		}

		~bstree()
		{
			this->clear_all();
		}
		//==========================================copy constructor===============================
		bstree(const bstree &other):root(other.root), _size(other._size), _nodeAlloc(other._nodeAlloc)
		{}

		bstree& operator=(const bstree &other)
		{
			if (*this != other)
			{
				root = other.root;
				_size = other._size;
				_nodeAlloc = other._nodeAlloc;
			}
			return (*this);
		}

		//============================================Move constructor============================
		bstree(const bstree &&other):root(other.root), _size(other._size), _nodeAlloc(other._nodeAlloc)
		{
			other.root = nullptr;
			other._size = 0;
			other._nodeAlloc = nullptr;
		}

		bstree&	operator=(const bstree &&other)
		{
			if (this != other)
			{
				root = other.root;
				_size = other._size;
				_nodeAlloc = other._nodeAlloc;
				other.root = nullptr;
				other._size = 0;
				other._nodeAlloc = nullptr;
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

		ft::tree_node<T>	*lower_bound(const key_type&	key, ft::tree<T>	*node)
		{
			if (node == nullptr || key == node.get_key())
				return (node);
			if (_cmp(node->get_key(), key)) //if current key is less than the KEY
				return (lower_bound(key, node->right));
			ft::tree_node<T>	*tmp = lower_bound(key, node->left);
			if (tmp == nullptr)
				return (node);
			return (tmp);
		}

		ft::tree_node<T>	*upper_bound(const key_type&	key, ft::tree<T>	*node)
		{
			if (node == nullptr)
				return (node);
			if (_cmp(node->get_key(), key) || key == node->get_key())
				return (lower_bound(key, node->right));
			ft::tree_node<T>	*tmp = lower_bound(key, node->left);
			if (tmp == nullptr)
				return (node);
			return (tmp);
		}

		//finds the node
		ft::tree_node<T>	*find_node(const key_type&	key, ft::tree_node<T>*	node)
		{
			if (node == nullptr || node->get_Key() == key)
				return (node);
			if(_cmp(key, node->get_Key()))//if its less we go to the left branch
				return (find_node(key, node->left));
			return (find_node(key, node->right))
		}

		//this function inset the value into the tree starting the search from node

		ft::tree_node<T>	*insert(const T &value, ft::tree_node<T>*& node, ft::tree_node<T>* parent, bool	&wasinserted)
		{
			if (node == nullptr)
			{
				node = new ft::tree_node<T>(value, nullptr, nullptr, parent);
				wasinserted = true;
				_size++;
				return (node);
			}
			if (value < node->value)
				return (insert(value, node->left, node, wasinserted));
			else if (value > node->value)
				return (insert(value, node->right, node, wasinserted));
			// else the value already exist
			node->value = value;
			return node;
		}

		size_type	erase_key(const key_type &key)
		{
			ft::tree_node<T>	*founded;

			founded = find_node(key, root);
			if (founded == nullptr)
				return 0;
			erase(key, founded);
			return (1);
		}

		//erasing elements: this function has a problem comparison of pairs
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
			else //a leaf or node with 1 subtree
			{
				tree_node<T>	*tmp = node;

				if (node->left != nullptr)
					node = node->left
				else if (node->right != nullptr)
					node = node->right;
				delete tmp;
				_size--;
			}
		}

		size_type	size(){return (_size);}

		size_type	max_size(){return (_nodeAlloc.max_size());}

		ft::tree_node<T>*	get_root(){return(root);}

		void	clear_all()
		{
			if (root->right)
				to_delete(root->right)
			if (root->left)
				to_delete(root->left)
			_nodeAlloc.destroy(&root->value)
			_nodeAlloc.deallocate(root, 1);
			_size--;
		}

		private:
			ft::tree_node<key_type, mapped_type, key_compare, allocator_type>*			root = nullptr;
			size_type					_size;
			key_compare					_cmp;
			allocator_type<value_type>	_nodeAlloc;
	};
}

#endif
