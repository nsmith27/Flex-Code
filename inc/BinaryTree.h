#ifndef H_BinaryTree
#define H_BinaryTree

#include <cstddef>
#include <ostream>
using std::endl;

template <class T>
class BinaryTree;

template <typename T>
class BT_Node {
private:
	BT_Node * right;
	BT_Node* left;
	T data;
	BT_Node() {
		this->right = nullptr;
		this->left = nullptr;
	}
	BT_Node(const T& value) {
		this->data = value;
		this->right = nullptr;
		this->left = nullptr;
	}
	friend BinaryTree<T>;
};

template <class T>
class BinaryTree {
private:
	void deleteTree(BT_Node<T>* subtree);
	void printInOrder(BT_Node<T>* node, std::ostream& out);
	void printPostOrder(BT_Node<T>* node, std::ostream& out);
	void printPreOrder(BT_Node<T>* node, std::ostream& out);
	BT_Node<T>* copyTree(BT_Node<T>* node);

protected:
	BT_Node<T>* root;
	BT_Node<T>* getLeft(BT_Node<T>* L);
	BT_Node<T>* getRight(BT_Node<T>* R);
	BT_Node<T>* createNode();
	void setLeft(BT_Node<T>* node, BT_Node<T>* L);
	void setRight(BT_Node<T>* node, BT_Node<T>* R);
	void setData(BT_Node<T>* node, T value);
	void clearTree();

public:
	BinaryTree();
	BinaryTree(const T& value);
	BinaryTree(const BinaryTree<T>& original);
	~BinaryTree();
	BinaryTree& operator=(const BinaryTree& other);
	void printInOrder(std::ostream& out);
	void printPostOrder(std::ostream& out);
	void printPreOrder(std::ostream& out);

	};
#endif

template <typename T>
BinaryTree<T>::BinaryTree() {
	this->root = nullptr;
}

template <typename T>
BinaryTree<T>::BinaryTree(const T& value) {
	this->root = new BT_Node<T>(value);
}

template <typename T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& original) {
	if (&original != this) {
		this->root = copyTree(original.root);
	}
}

template <typename T>
BinaryTree<T>::~BinaryTree() {
	deleteTree(root);
	root = nullptr;
}

template <typename T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree& other) {
	if (this != other) {
		this->delete();
		this->root = copyTree(other.root);
	}
	return *this;
}

template <typename T>
BT_Node<T>* BinaryTree<T>::copyTree(BT_Node<T>* N) {
	if (N) {
		BT_Node<T>* C = new BT_Node<T>;
		C->data = N->data;
		C->left = (copyTree(N->left));
		C->right = (copyTree(N->right));
		return C;
	}
	return nullptr;
}

template <typename T>
void BinaryTree<T>::deleteTree(BT_Node<T>* subtree) {
	if (subtree == nullptr) {
		return;
	}
	deleteTree(subtree->left);
	deleteTree(subtree->right);
	delete subtree;
	subtree = nullptr;
	return;
}

template <typename T>
void BinaryTree<T>::clearTree() {
	deleteTree(root);
	root = nullptr; 
}

template <typename T>
BT_Node<T>* BinaryTree<T>::createNode() {
	BT_Node<T>* J = new BT_Node<string>;
	return J;
}

template <typename T>
void BinaryTree<T>::setData(BT_Node<T>* node, T value) {
	node->data = value;  
}

template <typename T>
void BinaryTree<T>::setLeft(BT_Node<T>* node, BT_Node<T>* L) {
	node->left = L;
}

template <typename T>
void BinaryTree<T>::setRight(BT_Node<T>* node, BT_Node<T>* R) {
	node->right = R;
}

template <typename T>
BT_Node<T>* BinaryTree<T>::getLeft(BT_Node<T>* L) {
	return L->left;
}

template <typename T>
BT_Node<T>* BinaryTree<T>::getRight(BT_Node<T>* R) {
	return R->right;
}

template <typename T>
void BinaryTree<T>::printInOrder(std::ostream& out) {
	printInOrder(this->root, out);
}

template <typename T>
void BinaryTree<T>::printInOrder(BT_Node<T>* node, std::ostream& out) {
	if (node) {
		printInOrder(node->left, out);
		out << node->data;
		printInOrder(node->right, out);
		return;
	}
	return;
}

template <typename T>
void BinaryTree<T>::printPostOrder(std::ostream& out) {
	printPostOrder(this->root, out);
	out << endl;
}

template <typename T>
void BinaryTree<T>::printPostOrder(BT_Node<T>* node, std::ostream& out) {
	if (node) {
		printPostOrder(node->left, out);
		printPostOrder(node->right, out);
		out << node->data;
		return;
	}
	return;
}

template <typename T>
void BinaryTree<T>::printPreOrder(std::ostream& out) {
	printPreOrder(this->root, out);
	out << endl;
}

template <typename T>
void BinaryTree<T>::printPreOrder(BT_Node<T>* node, std::ostream& out) {
	if (node) {
		out << node->data;
		printPreOrder(node->left, out);
		printPreOrder(node->right, out);
		return;
	}
	return;
}
