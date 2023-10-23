#include <iostream>
#include "AVLTree.h"

int main() {
	AVLTree<int> avl_tree;
	avl_tree.insert(42);
	avl_tree.insert(1);
	avl_tree.insert(32);
	avl_tree.print();
	avl_tree.insert(23);
	avl_tree.insert(100);
	avl_tree.insert(101);
	avl_tree.print();
	avl_tree.insert(3);
	avl_tree.print();
	avl_tree.insert(2);
	avl_tree.print();
	avl_tree.insert(4);
	avl_tree.print();
	avl_tree.print();

	AVLTree<int> avl_tree_2;
	avl_tree_2.insert(1);
	avl_tree_2.insert(2);
	avl_tree_2.insert(3);
	avl_tree_2.insert(4);
	avl_tree_2.insert(5);
	avl_tree_2.insert(6);
	avl_tree_2.insert(7);
	avl_tree_2.insert(8);
	avl_tree_2.insert(9);
	avl_tree_2.insert(10);
	avl_tree_2.insert(11);
	avl_tree_2.insert(12);
	avl_tree_2.insert(13);
	avl_tree_2.insert(14);
	avl_tree_2.insert(15);
	avl_tree_2.insert(16);
	avl_tree_2.print();

	AVLTree<int> avl_tree_3;
	avl_tree_3.insert(15);
	avl_tree_3.insert(14);
	avl_tree_3.insert(13);
	avl_tree_3.insert(12);
	avl_tree_3.insert(11);
	avl_tree_3.insert(10);
	avl_tree_3.insert(9);
	avl_tree_3.insert(8);
	avl_tree_3.insert(7);
	avl_tree_3.insert(6);
	avl_tree_3.insert(5);
	avl_tree_3.insert(4);
	avl_tree_3.insert(3);
	avl_tree_3.insert(2);
	avl_tree_3.insert(1);
	avl_tree_3.print();
}