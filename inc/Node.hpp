
#ifndef FT_CONTAINERS_NODE_HPP
#define FT_CONTAINERS_NODE_HPP

namespace ft {
	template <class T>
	struct Node {

		typedef T		value_type;
		typedef Node*	pointer_node;

		value_type		value;
		pointer_node	parent;
		pointer_node	left;
		pointer_node	right;
		bool			is_red;

		Node() {}

		~Node() {}



		Node &operator=(const Node& other)
		{
			if (this != &other)
			{
				this->value = other.value;
				this->parent = other.parent;
				this->left = other.left;
				this->right = other.right;
				this->is_red = other.is_red;
			}
			return *this;
		}


	};
}

#endif
