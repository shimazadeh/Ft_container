#ifndef	_RBTREE_HPP
#define	_RBTREE_HPP

#include "RBtree_node.hpp"
#include "RBtree_iterator.hpp"
#include <memory>
#include <iostream>

namespace ft
{
	template<typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<ft::pair<Key, T> > >
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
		{
			initialize_nil();
			root = nil;
		}

		~bstree()
		{
			std::cout << "tree desctructor is called" << std::endl;
			this->clear_all();
			delete nil;
		}
		//==========================================copy constructor===============================
		bstree(const bstree &other):root(other.root), _size(other._size), _nodeAlloc(other._nodeAlloc)
		{
			initialize_nil();
		}

		bstree& operator=(const bstree &other)
		{
			if (this != &other)
			{
				root = new node_type(*other.root);
				initialize_nil();
				_size = other._size;
				_nodeAlloc = other._nodeAlloc;
			}
			return (*this);
		}
		//==================================================member functions====================================================
		void		initialize_nil()
		{
			value_type	nil_value = ft::make_pair(Key(), mapped_type());
			nil = new node_type(nil_value , "b");
			nil->parent = nil;//I think this shoud be a nullptr??
			nil->left = nil;
			nil->right = nil;
		}

		node_type	*min_element(node_type *node, bool	&if_end) const
		{
			if (node == nil || node->left == nil)
			{
				if (node == nil)
					if_end = true;
				return node;
			}
			return (min_element(node->left, if_end));
		}

		node_type	*max_element(node_type	*node, bool	&if_end) const
		{
			if (node == nil || node->right == nil)
			{
				if (node == nil)
					if_end = true;
				return node;
			}
			return (max_element(node->right, if_end));
		}

		node_type	*lower_bound(const key_type&	key, node_type	*node)
		{
			if (node == nil || key == node->get_key())
				return (node);
			if (_cmp(node->get_key(), key)) //if current key is less than the KEY
				return (lower_bound(key, node->right));
			node_type	*tmp = lower_bound(key, node->left);
			if (tmp == nil)
				return (node);
			return (tmp);
		}

		node_type	*upper_bound(const key_type&	key, node_type	*node)
		{
			if (node == nil)
				return (node);
			if (_cmp(node->get_key(), key) || key == node->get_key())
				return (upper_bound(key, node->right));
			node_type	*tmp = upper_bound(key, node->left);
			if (tmp == nil)
				return (node);
			return (tmp);
		}

		//finds the node from mapped value
		node_type	*find_node_map(const mapped_type&	map, node_type	*to_search)const
		{
			if (to_search == nil || to_search->get_maptype() == map)
				return (to_search);
			if(_cmp(map, to_search->get_maptype()))//if its less we go to the left branch
				return (find_node_map(map, to_search->left));
			return (find_node_map(map, to_search->right));
		}

		//find the node form the key value
		node_type	*find_node_key(const key_type&	key, node_type	*to_search) const
		{
			if (to_search == nil || to_search->get_key() == key)
				return (to_search);
			if(_cmp(key, to_search->get_key()))//if its less we go to the left branch
				return (find_node_key(key, to_search->left));
			return (find_node_key(key, to_search->right));
		}

		//make insert works with pair or key or mapped value????

		void	insert_by_key(const Key 	&key, node_type	*hint = nullptr)
		{
			node_type	*new_node = new node_type(ft::make_pair(key, mapped_type()), "r");

			new_node->right = nil;
			new_node->left = nil;
			new_node->parent = nil;

			insert(new_node , hint);
		}

		void	insert_by_value(const value_type &value, node_type	*hint = nullptr)
		{
			node_type	*new_node = new node_type(value, "r");

			new_node->right = nil;
			new_node->left = nil;
			new_node->parent = nil;

			insert(new_node, hint);
		}

		void	insert(node_type	*new_node, node_type	*hint = nullptr)
		{
			node_type	*tmp = root;
			node_type	*tmp1 = nil;

			if (root == nil)//if the tree is empty set the new node to root
			{
				root = new_node;
				new_node->parent = nil;
			}
			else//we find the right place
			{
				if (hint != nullptr)
					tmp1 = hint;
				else
				{
					while(tmp != nil)//search to find the right position
					{
						tmp1 = tmp;
						if (tmp->value.first < new_node->value.first)
							tmp = tmp->right;
						else
							tmp = tmp->left;
					}
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
			while(to_insert->parent != nil && to_insert->parent->color == "r")//if the parent of the node is red we need to compare the parent sibiling color
			{
				node_type	*g = to_insert->parent->parent;//this is the grandparent

				if (g->left == to_insert->parent)//if the inseted node is the left child
				{
					if (g->right != nil)//check the color of the sibiling
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
					if (g->left != nil)
					{
						tmp = g->left;
						if (tmp->color == "r")
						{
							to_insert->parent->color = "b";
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

		void	erase_by_key(const Key 	&key)
		{
			node_type	*tmp = find_node_key(key, root);

			erase(tmp);
		}

		void	erase_by_map(const mapped_type &map)
		{
			node_type	*tmp = find_node_map(map, root);

			erase(tmp);
		}

		void	erase(node_type *tmp)
		{
			node_type	*y = nil;//used to save the successor of to_delete
			node_type	*tmp1 = nil;//used to save any children

			if (root == nil)
				return ;
			if (tmp != nil)
			{
				//to save whatever comes after to_delete in a node
				if (tmp->left == nil || tmp->right == nil)//a leaf or one child
					y = tmp;
				else
					y = successor(tmp);//tmp++

				std::cout << "y is " << y->get_key() << std::endl;
				//saving the children of to_delete to tmp1
				if (y->left != nil)
					tmp1 = y->left;
				else
				{
					if (y->right != nil)
						tmp1 = y->right;
					else
						tmp1 = nil;//we are deleting a leaf node so we need to reconnect a parent to it
				}
				// if (tmp1 != nil)
					tmp1->parent = y->parent;

				if (y->parent == nil)//reconnecting the root to tmp1
					root = tmp1;
				else if (y == y->parent->left)
					y->parent->left = tmp1;
				else
					y->parent->right = tmp1;

				if (y != tmp)
				{
					tmp->color = y->color;
					tmp->value = y->value;
				}
				if (y->color == "b")
					erase_fix(tmp1);

				_size--;
				if (y == tmp)
					to_delete(tmp);
			}
		}

		void	erase_fix(node_type	*to_fix)
		{
			node_type	*tmp;//set as the parent sibiling
			std::cout << "recoloring " << to_fix->get_key() <<std::endl;

			while(to_fix != root && to_fix->color == "b")
			{
				std::cout << "recoloring " << to_fix->get_key() <<std::endl;
				if (to_fix->parent->left == to_fix)
				{
					tmp = to_fix->parent->right;
					if (tmp->color == "r")
					{
						tmp->color = "b";
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
							tmp->left->color = "b";
							tmp->color = "r";
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
			}
			to_fix->color = "b";
			root->color = "b";
		}

		node_type	*successor(node_type	*node)//returns node--
		{
			node_type	*successor = nil;

			if (node->right != nil)
			{
				successor = node->right;
				while (successor->left != nil)
					successor = successor->left;
			}
			else
			{
				node_type	*node_up = node->parent;
				while(!node->parent->isNil() && node == node_up->left)
				{
					node = node_up;
					node_up = node_up->parent;
				}
				successor = node_up;
			}
			return (successor);
		}

		node_type	*predecessor(node_type	*node)//returns max of the branch
		{
			node_type	*predecessor = nil;

			if (node->left != nil)
				return (max_element(node->left));
			else
			{
				predecessor = node->parent;
				while (predecessor != nil && node == predecessor->left)
				{
					node = predecessor;
					predecessor = predecessor->parent;
				}
			}
			return (predecessor);
		}

		void	left_rotate(node_type	*node)
		{
			if (node->right == nil)
				return ;

			node_type	*tmp = node->right;

			if (tmp->left != nil)
			{
				node->right = tmp->left;
				tmp->left->parent = node;
			}
			else
				node->right = nil;

			if (node->parent != nil)
				tmp->parent = node->parent;
			if (node->parent == nil)
			{
				root = tmp;
				root->parent = nil;//I added this but not sure for corner cases
			}
			else
			{
				if (node->parent->right == node)
					node->parent->right = tmp;
				else
					node->parent->left = tmp;
			}
			tmp->left = node;
			node->parent = tmp;
		}

		void	right_rotate(node_type	*node)
		{
			if (node->left == nil)
				return ;
			node_type	*tmp = node->left;

			if (tmp->right != nil)
			{
				node->left = tmp->right;
				tmp->right->parent = node;
			}
			else
				node->left = nil;

			if (node->parent != nil)
				tmp->parent = node->parent;
			if (node->parent == nil)
			{
				root = tmp;
				root->parent = nil;
			}
			else
			{
				if (node->parent->right == node)
					node->parent->right = tmp;
				else
					node->parent->left = tmp;
			}

			tmp->right = node;
			node->parent = tmp;
		}

		size_type	size(){return (_size);}

		size_type	max_size(){return (_nodeAlloc.max_size());}

		node_type	*get_root()const{return(root);}

		void	clear_all()
		{
			if (root != nil)
				clear_recursive(root);
		}

		void	clear_recursive(node_type	*head)
		{
			// std::cout << "freeing: " << head->value.first << std::endl;
			if (head->right != nil)
				clear_recursive(head->right);
			if (head->left != nil)
				clear_recursive(head->left);
			to_delete(head);
			_size--;
		}

		void	to_delete(node_type	*node)
		{
			_valueAlloc.destroy(&node->value);
			_nodeAlloc.deallocate(node, 1);
		}

		void	swap(bstree &other)
		{
			node_type											*tmp_root = root;
			size_type											tmp_size = _size;
			key_compare											tmp_cmp = _cmp;
			std::allocator<ft::pair<Key, T> >					tmp_valueAlloc = _valueAlloc;
			std::allocator<node_type>							tmp_nodeAlloc = _nodeAlloc;


			root = other.root;
			_size = other._size;
			_cmp = other._cmp;
			_valueAlloc = other._valueAlloc;
			_nodeAlloc = other._nodeAlloc;

			other.root = tmp_root;
			other._size = tmp_size;
			other._cmp = tmp_cmp;
			other._valueAlloc = tmp_valueAlloc;
			other._nodeAlloc = tmp_nodeAlloc;
		}
		//=================================================== Debugging tools =================================================================================
		void	print(node_type	*node)
		{
			if (node != nil)
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
				else
				{
					if (node->parent->right == node && node->color == "r")
						std:: cout << "\033[1;31mRightNode-----:";
					else if (node->parent->right == node)
						std:: cout << "\033[1;32mRightNode-----:";
					if (node->parent->left == node && node->color == "r")
						std:: cout << "\033[1;31mLeftNode-----:";
					else if (node->parent->left == node)
						std:: cout << "\033[1;32mLeftNode-----:";
					std::cout << node->value.first;
					std::cout << ":" << node->value.second <<"\033[0m\n";
				}
				if (node->right != nil)
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
				if (node->left != nil)
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
				if (node->parent != nil)
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
					std::cout << "parent; nil" << std::endl;
				print(node->right);
				print(node->left);
			}
		}

		private:
			node_type											*root;
			node_type											*nil;
			size_type											_size;
			key_compare											_cmp;
			std::allocator<ft::pair<Key, T> >					_valueAlloc;
			std::allocator<node_type>							_nodeAlloc;
	};
}

#endif
