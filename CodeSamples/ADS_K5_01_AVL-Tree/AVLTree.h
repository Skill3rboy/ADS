#pragma once
#include <memory>
#include <algorithm>
#include <queue>

template<typename T>
class AVLNode {
	template<typename T>
	friend class AVLTree;
private:
	T element;
	std::unique_ptr<AVLNode> left;
	std::unique_ptr<AVLNode> right;
	int height;

	inline AVLNode(const T& elem)
		: element{ elem }
		, height{ 0 }
	{}
};

template<typename T>
class AVLTree {
private:
	std::unique_ptr<AVLNode<T>> root;
	
	void balanceTree(const T& element, std::unique_ptr<AVLNode<T>>& node);
	int height(std::unique_ptr<AVLNode<T>> const& node) const;
	void remove(const T& element, std::unique_ptr<AVLNode<T>>& node); // TODO: viel Spaﬂ beim Programmieren
	void insert(const T& element, std::unique_ptr<AVLNode<T>>& node);
	void doubleLeftRightRotation(std::unique_ptr<AVLNode<T>>& node);
	void doubleRightLeftRotation(std::unique_ptr<AVLNode<T>>& node);
	void avlRightRotation(std::unique_ptr<AVLNode<T>>& node);
	void avlLeftRotation(std::unique_ptr<AVLNode<T>>& node); 
public:
	void insert(const T& element);
	void remove(const T& element); // TODO: viel Spaﬂ beim Programmieren
	void print();
};


template<typename T>
inline int AVLTree<T>::height(std::unique_ptr<AVLNode<T>> const& node) const
{
	return node ? node->height : -1;
}

template<typename T>
inline void AVLTree<T>::doubleLeftRightRotation(std::unique_ptr<AVLNode<T>>& node)
{
	avlLeftRotation(node->left);
	avlRightRotation(node);
}

template<typename T>
inline void AVLTree<T>::doubleRightLeftRotation(std::unique_ptr<AVLNode<T>>& node)
{
	avlRightRotation(node->right);
	avlLeftRotation(node);
}

template<typename T>
inline void AVLTree<T>::avlRightRotation(std::unique_ptr<AVLNode<T>>& node)
{
	auto tmpNode = std::move(node->left);
	node->left = std::move(tmpNode->right);
	tmpNode->right = std::move(node);
	tmpNode->height = std::max(height(tmpNode->left), height(tmpNode->right)) + 1;
	node = std::move(tmpNode);
	node->height = std::max(height(node->left), height(node->right)) + 1;
}

template<typename T>
inline void AVLTree<T>::avlLeftRotation(std::unique_ptr<AVLNode<T>>& node)
{
	auto tmpNode = std::move(node->right);
	node->right = std::move(tmpNode->left);
	tmpNode->left = std::move(node);
	tmpNode->height = std::max(height(tmpNode->left), height(tmpNode->right)) + 1;
	node = std::move(tmpNode);
	node->height = std::max(height(node->left), height(node->right)) + 1;
}

template<typename T>
inline void AVLTree<T>::balanceTree(const T& element, std::unique_ptr<AVLNode<T>>& node) {
	if (height(node->left) - height(node->right) == 2) {
		if (element < node->left->element) {
			avlRightRotation(node);
		}
		else {
			doubleLeftRightRotation(node);
		}
	}
	else if (height(node->left) - height(node->right) == -2) {
		if (element > node->right->element) {
			avlLeftRotation(node);
		}
		else {
			doubleRightLeftRotation(node);
		}
	}
}

template<typename T>
inline void AVLTree<T>::insert(const T& element, std::unique_ptr<AVLNode<T>>& node)
{
	if (!node) {
		node = std::unique_ptr<AVLNode<T>>{ new AVLNode<T>(element) };
 	}
	else if (element < node->element) {
		insert(element, node->left);
		balanceTree(element, node);
	}
	else if (element > node->element) {
		insert(element, node->right);
		balanceTree(element, node);
	}
	node->height = std::max(height(node->left), height(node->right)) + 1;
}

template<typename T>
inline void AVLTree<T>::insert(const T& element)
{
	this->insert(element, root);
}

template<typename T>
inline void AVLTree<T>::print()
{
	// based on: https://www.youtube.com/watch?v=o-_Gk0rBeIo
	if (!root) {
		std::cout << "Baum ist leer" << std::endl << std::endl;
	}
	else {
		std::cout << "AVL-Tree besteht aus folgenden Elementen (levelorder): " << std::endl;
		std::queue<AVLNode<T>*> queue;
		queue.push(root.get());
		queue.push(nullptr);
		while (true) {
			auto curr = queue.front();
			queue.pop();
			if (curr != nullptr) {
				std::cout << curr->element << " ";
				if (curr->left) queue.push(curr->left.get());
				if (curr->right) queue.push(curr->right.get());
			}
			else {
				std::cout << std::endl;
				if (queue.empty()) break;
				queue.push(nullptr);
			}
		}
		std::cout << std::endl;
	}
}


