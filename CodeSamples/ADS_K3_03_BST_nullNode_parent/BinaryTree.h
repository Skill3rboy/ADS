#include "TreeNode.h"
#include <iostream>
#include <queue>

class BinaryTree {
private:
	TreeNode *head;						// Ankerknoten des Binäraums
	TreeNode *nullNode;					// Pseudoknoten für die Blätter
	void printInorder(TreeNode *k);		// Ausgabe in Inorder
	void printPreorder(TreeNode *k);	// Ausgabe in Preorder
	void printPostorder(TreeNode *k);	// Ausgabe in Postorder
	void printLevelorder(TreeNode *k);	// Ausgabe in Levelorder
	void deleteTreeNode(TreeNode * k);	// Löscht alle Knoten im BST
	TreeNode * TreeSearch(TreeNode * x, int k); // Rekursive Suche im BST
	TreeNode * IterativeTreeSearch(TreeNode * x, int k); // Iterative Suche im BST
	TreeNode * MinimumTreeSearch(TreeNode * x); // Minimum Suche im BST
	TreeNode * MaximumTreeSearch(TreeNode * x); // Minimum Suche im BST
	void TreeInsert(TreeNode * z);		// Einfügen eines neuen Knoten z, vorab Erzeugen

public:
	BinaryTree();						// Konstruktor
	~BinaryTree();						// Destruktor : Löscht alle Knoten
	void put(int key, int val);			// neues Element einfügen
	int get(int key);					// Knoten suchen
	bool remove(int key);				// Knoten entfernen
	// Traversierungsmethoden
	void printInorder();				// Ausgabe in Inorder
	void printPreorder();				// Ausgabe in Preorder
	void printPostorder();				// Ausgabe in Postorder
	void printLevelorder();				// Ausgabe in Levelorder
};