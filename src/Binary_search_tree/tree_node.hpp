#ifndef	_TREE_NODE_HPP
#define	_TREE_NODE_HPP

namespace ft
{
	template<typename Key, typename T, typename Compare = std::less<Key>, typename Allocator = std::allocator<std::pair<const Key, T>> >
	struct tree_node
	{
		typedef	T						mapped_type;
		typedef	const Key				key_type;
		typedef	ft::pair<const Key, T>	value_type;

	//======members===========
		value_type		value;
		tree_node<T>	*left;
		tree_node<T>	*right;
		tree_node<T>	*parent;

		tree_node(const T &_value, tree_node<T> *_left = nullptr, tree_node<T> *_right = nullptr, tree_node<T> *_parent = nullptr):value(_value), left(_left), right(_right), parent(_parent)
		{}

		value_type	&get_value(){return(this->value);}
		key_type	&get_key(){return(this->value.first);}
		mapped_type	&get_maptype(){return(this->value.second);}

		const value_type	&get_value()const {return(this->value);}
		const key_type	&get_key()const{return(this->value.first);}
		const mapped_type	&get_maptype()const{return(this->value.second);}
	};
}

#endif
