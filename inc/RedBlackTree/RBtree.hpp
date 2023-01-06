#ifndef	_RBTREE_HPP
#define	_RBTREE_HPP

#include "RBtree_node.hpp"
#include "RBtree_iterator.hpp"
#include <memory>
#include <iostream>

namespace ft
{
	template<typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<ft::pair<const Key, T>> >
	class bstree
	{
		public:
		typedef	Key																	key_type;
		typedef T																	mapped_type;
		typedef ft::pair<Key, T>													value_type;
		typedef std::size_t															size_type;
		typedef std::allocator<value_type>											allocator_type;
		typedef std::less<Key>														key_compare;
		typedef ft::tree_node<key_type, mapped_type, key_compare, allocator_type>	node_type;

		//================================= constructor =======================================================
		bstree():root(nullptr), _size(0), _nodeAlloc(Allocator())
		{}

		explicit	bstree(const mapped_type &value)
		{
			root = new node_type(value, nullptr, nullptr, nullptr);
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
			if (this != &other)
			{
				root = other.root;
				_size = other._size;
				_nodeAlloc = other._nodeAlloc;
			}
			return (*this);
		}
		//==================================================member functions====================================================
		//this function finds the node with minimum value of the element

		node_type	*min_element(node_type *node, bool	&if_end) const
		{
			if (node == nullptr || node->left == nullptr)
			{
				if (node == nullptr)
					if_end = true;
				return node;
			}
			return (min_element(node->left, if_end));
		}

		node_type	*max_element(node_type	*node, bool	&if_end) const
		{
			if (node == nullptr || node->right == nullptr)
			{
				if (node == nullptr)
					if_end = true;
				return node;
			}
			return (max_element(node->right, if_end));
		}

		node_type	*lower_bound(const key_type&	key, node_type	*node)
		{
			if (node == nullptr || key == node->get_key())
				return (node);
			if (_cmp(node->get_key(), key)) //if current key is less than the KEY
				return (lower_bound(key, node->right));
			node_type	*tmp = lower_bound(key, node->left);
			if (tmp == nullptr)
				return (node);
			return (tmp);
		}

		node_type	*upper_bound(const key_type&	key, node_type	*node)
		{
			if (node == nullptr)
				return (node);
			if (_cmp(node->get_key(), key) || key == node->get_key())
				return (upper_bound(key, node->right));
			node_type	*tmp = upper_bound(key, node->left);
			if (tmp == nullptr)
				return (node);
			return (tmp);
		}

		//finds the node from mapped value
		node_type	*find_node(const mapped_type&	key, node_type	*to_search)
		{
			if (to_search == nullptr || to_search->get_maptype() == key)
				return (to_search);
			if(_cmp(key, to_search->get_maptype()))//if its less we go to the left branch
				return (find_node(key, to_search->left));
			return (find_node(key, to_search->right));
		}

		//find the node form the key value
		node_type	*find_node(const key_type&	key, node_type	*to_search)
		{
			if (to_search == nullptr || to_search->get_key() == key)
				return (to_search);
			if(_cmp(key, to_search->get_key()))//if its less we go to the left branch
				return (find_node(key, to_search->left));
			return (find_node(key, to_search->right));
		}

		//make insert works with pair or key or mapped value????

		template <typename any>
		void	insert(const any &key)
		{
			node_type	*new_node = new node_type(key, nullptr, nullptr, nullptr, "r");
			node_type	*tmp = root;
			node_type	*tmp1 = nullptr;

			if (root == nullptr)//if the tree is empty set the new node to root
			{
				root = new_node;
				new_node->parent = nullptr;
			}
			else//we create a new node as a leaf
			{
				while(tmp != nullptr)//search to find the right position
				{
					tmp1 = tmp;
					if (tmp->value.first < new_node->value.first)
						tmp = tmp->right;
					else
						tmp = tmp->left;
				}
				new_node->parent = tmp1;
				if (tmp1->value.first < new_node->value.first)
					tmp1->right = new_node;
				else
					tmp1->left = new_node;
			}
			insertion_fix(new_node);
			_size++;
		}

		void	insertion_fix(node_type	*to_insert)
		{
			node_type	*tmp;//this becomes parent sibiling

			if (root == to_insert)//this means the tree was empty before so we set the color to black
			{
				to_insert->color = "b";
				return ;
			}
			while(to_insert->parent != nullptr && to_insert->parent->color == "r")//if the parent of the node is red we need to compare the parent sibiling color
			{
				node_type	*g = to_insert->parent->parent;//this is the grandparent

				if (g->left == to_insert->parent)//if the inseted node is the left child
				{
					if (g->right != nullptr)//check the color of the sibiling
					{
						tmp = g->right;
						if (tmp->color == "r")
						{
							to_insert->parent->color = "b";
							tmp->color = "b";
							g->color = "r";
							to_insert = g;
						}
					}
					else//there is no sibiling
					{
						if (to_insert->parent->right == to_insert)
						{
							to_insert = to_insert->parent;
							left_rotate(to_insert);
						}
						to_insert->parent->color = "b";
						g->color = "r";
						right_rotate(g);
					}
				}
				else//if the inserted node is the right child
				{
					if (g->left != nullptr)
					{
						tmp = g->left;
						if (tmp->color == "r")
						{
							to_insert->parent->color = "r";
							tmp->color = "b";
							g->color = "r";
							to_insert = g;
						}
					}
					else
					{
						if (to_insert->parent->left == to_insert)
						{
							to_insert = to_insert->parent;
							right_rotate(to_insert);
						}
						to_insert->parent->color = "b";
						g->color = "r";
						left_rotate(g);
					}
				}
				root->color = "b";
			}
		}

		template <typename any>
		void	erase(const any &key)
		{
			node_type	*tmp = nullptr;//to iterate over root
			node_type	*y = nullptr;//used to save the successor of to_delete
			node_type	*tmp1 = nullptr;//used if to_delete has two childs

			if (root == nullptr)
				return ;
			tmp = find_node(key);
			if (tmp != nullptr)
			{
				if (tmp->left == nullptr || tmp->right == nullptr)//a leaf or one child
					y = tmp;
				else
					y = successor(tmp);
				if (y->left != nullptr)
					tmp1 = y->left;
				else
				{
					if (y->right != nullptr)
						tmp1 = y->right;
					else
						tmp1 = nullptr;
				}
				if (tmp1 != nullptr)
					tmp1->parent = y->parent;
				if (y->parent == NULL)
					root = tmp1;
				else
				{
					if (y == y->parent->left)
						y->parent->left = tmp1;
					else
						y->parent->right = tmp1;
				}
				if (y != tmp)
				{
					tmp->color = y->color;
					tmp->value = y->value;
				}
				if (y->color == "b")
					erase_fix(tmp1);
				_size--;
			}
		}

		void	erase_fix(node_type	*to_fix)
		{
			node_type	*tmp;//set as the parent sibiling

			while(to_fix != root && to_fix->color == "b")
			{
				if (to_fix->parent->left == to_fix)
				{
					tmp = to_fix->parent->right;
					if (tmp->color == "r")
					{
						tmp->color == "b";
						to_fix->parent->color = "r";
						left_rotate(to_fix->parent);
						tmp = to_fix->parent->right;
					}
					if (tmp->right->color == "b" && tmp->left->color == "b")
					{
						tmp->color = "r";
						to_fix = to_fix->parent;
					}
					else
					{
						if (tmp->right->color == "b")
						{
							tmp->left->color == "b";
							right_rotate(tmp);
							tmp = to_fix->parent->right;
						}
						tmp->color = to_fix->parent->color;
						to_fix->parent->color = "b";
						tmp->right->color = "b";
						left_rotate(to_fix->parent);
						to_fix = root;
					}
				}
				else
				{
					tmp = to_fix->parent->left;
					if (tmp->color == "r")
					{
						tmp->color = "b";
						to_fix->parent->color = "r";
						right_rotate(to_fix->parent);
						tmp = to_fix->parent->left;
					}
					if (tmp->left->color == "b" && tmp->right->color == "b")
					{
						tmp->color = "r";
						to_fix = to_fix ->parent;
					}
					else
					{
						if (tmp->left->color == "b")
						{
							tmp->right->color = "b";
							tmp->color = "r";
							left_rotate(tmp);
							tmp = to_fix->parent->left;
						}
						tmp->color = to_fix->parent->color;
						to_fix->parent->color = "b";
						tmp->left->color = "b";
						right_rotate(to_fix->parent);
						to_fix = root;
					}
				}
				to_fix->color = "b";
				root->color = "b";
			}
		}

		node_type	*successor(node_type	*node)//returns node--
		{
			node_type	*successor = nullptr;

			if (node->left != nullptr)
			{
				successor = node->left;
				if (successor->right != nullptr)
					successor = successor->right;
			}
			else
			{
				successor = node->right;
				while(successor->left != nullptr)
					successor = successor->left;
			}
			return (successor);
		}

		node_type	*predecessor(node_type	*node)//returns max of the branch
		{
			node_type	*predecessor = nullptr;

			if (node->left != nullptr)
				return (max_element(node->left));
			else
			{
				predecessor = node->parent;
				while (predecessor != nullptr && node == predecessor->left)
				{
					node = predecessor;
					predecessor = predecessor->parent;
				}
			}
			return (predecessor);
		}
		//rotating function
		void	left_rotate(node_type	*node)
		{
			if (node->right == nullptr)
				return ;

			node_type	*tmp = node->right;

			if (tmp->left != nullptr)
			{
				node->right = tmp->left;
				tmp->left->parent = node;
			}
			else
				node->right = nullptr;

			if (node->parent != nullptr)
				tmp->parent = node->parent;
			if (node->parent == nullptr)
			{
				root = tmp;
				root->parent = nullptr;//I added this but not sure for corner cases
			}
			else if (node->parent->right == node)//if node is the right child
				node->parent->right = tmp;
			else
				node->parent->left = tmp;

			tmp->left = node;
			node->parent = tmp;
		}

		void	right_rotate(node_type	*node)
		{
			if (node->left == nullptr)
				return ;
			node_type	*tmp = node->left;

			if (tmp->right != nullptr)
			{
				node->left = tmp->right;
				tmp->right->parent = node;//i dont get this
			}
			else
				node->left = nullptr;

			if (node->parent != nullptr)
				tmp->parent = node->parent;
			else if (node->parent == nullptr)
			{
				root = tmp;
				root->parent = nullptr;
			}
			else if (node->parent->right == node)
				node->parent->right = tmp;
			else
				node->parent->left = tmp;

			tmp->right = node;
			node->parent = tmp;
		}

		size_type	size(){return (_size);}

		size_type	max_size(){return (_nodeAlloc.max_size());}

		node_type	*get_root()const{return(root);}

		void	clear_all()
		{
			// if (root->right)
			// 	to_delete(root->right);
			// if (root->left)
			// 	to_delete(root->left);
			// to_delete(root);
			// _size--;
		}

		// void	to_delete(node_type	*node)
		// {
		// 	_nodeAlloc.destroy(node->value);
		// 	_nodeAlloc.deallocate(node, 1);
		// }

		//=================================================== Debugging tools =================================================================================
		void	print(node_type	*node)
		{
			if (node != nullptr)
			{
				if (node == root)
				{
					if (node->color == "r")
					{
						std:: cout << "\033[1;31mRoot-----";
						std:: cout << node->value.first;
						std::cout << ":" << node->value.second <<"\033[0m\n";
					}
					else
					{
						std:: cout << "\033[1;32mRoot-----";
						std:: cout << node->value.first;
						std::cout << ":" << node->value.second <<"\033[0m\n";
					}
				}
				if (node->right != nullptr)
				{
					if (node->right->color == "r")
					{
						std:: cout << "\033[1;31mright-----";
						std:: cout << node->right->value.first;
						std::cout << ":" << node->right->value.second <<"\033[0m\n";
					}
					else
					{
						std:: cout << "\033[1;32mright-----";
						std:: cout << node->right->value.first;
						std::cout << ":" << node->right->value.second <<"\033[0m\n";
					}
				}
				else
					std::cout << "right; nill" << std::endl;
				if (node->left != nullptr)
				{
					if (node->left->color == "r")
					{
						std:: cout << "\033[1;31mleft-----";
						std:: cout << node->left->value.first;
						std::cout << ":" << node->left->value.second <<"\033[0m\n";
					}
					else
					{
						std:: cout << "\033[1;32mleft-----";
						std:: cout << node->left->value.first;
						std::cout << ":" << node->left->value.second <<"\033[0m\n";
					}
				}
				else
					std::cout << "left; nill" << std::endl;
				if (node->parent != nullptr)
				{
					if (node->parent->color == "r")
					{
						std:: cout << "\033[1;31mparent-----";
						std:: cout << node->parent->value.first;
						std::cout << ":" << node->parent->value.second <<"\033[0m\n";
					}
					else
					{
						std:: cout << "\033[1;32mparent-----";
						std:: cout << node->parent->value.first;
						std::cout << ":" << node->parent->value.second <<"\033[0m\n";
					}
				}
				else
					std::cout << "parent; nill" << std::endl;
				print(node->right);
				print(node->left);
			}
		}

		private:
			node_type					*root = nullptr;
			size_type					_size;
			key_compare					_cmp;
			allocator_type				_nodeAlloc;
	};
}

#endif
