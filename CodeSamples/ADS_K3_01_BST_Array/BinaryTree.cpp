#include "BinaryTree.h"



BinaryTree::BinaryTree(int n)
{
	// Größe des BST festlegen
	BST.resize(n);
	// Alle key - Werte -1 setzen -> bedeutet, dass noch kein key eingetragen ist 
	//-> es sind im BST nur positive key Werte erlaubt
	for (auto it = std::begin(BST); it != std::end(BST); ++it) (*it).key = -1;
}


BinaryTree::~BinaryTree()
{
	// Die Klasse vector räumt selber auf.
}

void BinaryTree::put(int key, int val) {
	// Einfügen
	// Zuerst Einfügestelle suchen.
	int i = 0;
	while (i < BST.size() && BST[i].key != -1) {
		if (BST[i].key > key) i = i * 2 + 1;
		else i = i * 2 + 2;
	}
	// Eintragen von key und val
	if (i < BST.size()) {
		BST[i].key = key;
		BST[i].val = val;
	}
}

int BinaryTree::get(int key) {
	int i = 0;
	// key in BST suchen
	while (i < BST.size() && BST[i].key != key) {
		if (BST[i].key > key) i = i * 2 + 1;
		else i = i * 2 + 2;
	}
	// Wert von val zurückgeben
	if (i < BST.size()) {
		return BST[i].val;
	}
	return -1;
}