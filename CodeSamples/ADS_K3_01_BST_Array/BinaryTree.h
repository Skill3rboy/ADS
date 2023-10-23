#pragma once
#include <vector>
#include "Entry.h"

class BinaryTree
{
private:
	std::vector<Entry> BST;
public:
	BinaryTree(int n);
	~BinaryTree();
	void put(int key, int val);
	int get(int key);
};

