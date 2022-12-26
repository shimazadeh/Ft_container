#ifndef	_TREE_NODE_HPP
#define	_TREE_NODE_HPP

namespace ft
{
	template<typename T>
	struct tree_node
	{
		T				value;
		tree_node<T>	*left;
		tree_node<T>	*right;
		tree_node<T>	*parent;

		tree_node(const T &_value, tree_node<T> *_left = nullptr, tree_node<T> *_right = nullptr, tree_node<T> *_parent = nullptr):value(_value), left(_left), right(_right), parent(_parent)
		{}
	};
}

#endif
