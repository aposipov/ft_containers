
#ifndef FT_CONTAINERS_NODE_HPP
#define FT_CONTAINERS_NODE_HPP

#include <iostream>

namespace ft {

	enum Color { BLACK, RED };

	template <class Key, class T>
	struct Node {

		typedef ft::pair<const Key, T>	data;
		typedef Node*	pointer_node;


		data			value;
		pointer_node	parent;
		pointer_node	left;
		pointer_node	right;
//		bool			is_red;
		Color			color;

		Node() { }

		Node(const data& v) : value(v), parent(NULL), left(NULL), right(NULL), color(RED) {}

		~Node() { }

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

//{
//enum Color {RED, BLACK};
//
//template <class Key, class T>
//struct Node
//{
//	std::pair<const Key, T> data;
//	Node* parent;
//	Node* left;
//	Node* right;
//	Color color;
//	Node();
//	Node(const std::pair<const Key, T>& data, Node* parent = NULL, Node* left = NULL, Node* right = NULL, Color color = RED);
//	~Node();
//};
//
//// Другие прототипы, которые могут быть нужны в этом файле
//}