#include "BinaryTree.h"

BinaryTree::BinaryTree() {						// Konstruktor
	head = new TreeNode;
	nullNode = new TreeNode;
	head->Parent = nullNode;
	head->right = nullNode;						// Der BST beginnt bei head-right
	head->left = nullNode;
	nullNode->Parent = nullNode;
	nullNode->right = nullNode;
	nullNode->left = nullNode;
}

BinaryTree::~BinaryTree() {						// Destruktor : Löscht alle Knoten
	deleteTreeNode(head->right);
	delete head;
	delete nullNode;
}

void BinaryTree::printInorder(TreeNode *k) {	// Ausgabe in Inorder
	if (k != nullNode) {
		printInorder(k->left);
		std::cout << "(" << k->key << "," << k->val << ") ";
		printInorder(k->right);
	}
}

void BinaryTree::printPreorder(TreeNode *k) {	// Ausgabe in Preorder
	if (k != nullNode) {
		std::cout << "(" << k->key << "," << k->val << ") ";
		printPreorder(k->left);
		printPreorder(k->right);
	}
}	

void BinaryTree::printPostorder(TreeNode *k) {	// Ausgabe in Postorder
	if (k != nullNode) {
		printPostorder(k->left);
		printPostorder(k->right);
		std::cout << "(" << k->key << "," << k->val << ") ";
	}
}

void BinaryTree::printLevelorder(TreeNode *k) {	// Ausgabe in Levelorder
	std::queue<TreeNode *> q;
	TreeNode * node;
	if (k != nullNode) {
		q.push(k);
		while (!q.empty()) {
			node = q.front();
			q.pop();
			std::cout << "(" << node->key << "," << node->val << ") ";
			if(node->left != nullNode) q.push(node->left);
			if(node->right != nullNode) q.push(node->right);
		}
	}
}

void BinaryTree::deleteTreeNode(TreeNode *k) {	// Löscht alle Knoten im BST
	if (k != nullNode) {
		deleteTreeNode(k->left);
		deleteTreeNode(k->right);
		delete k;
	}
}

void BinaryTree::put(int key, int val) {		// neues Element einfügen
	TreeNode * z = new TreeNode;				// neues Blatt anlegen
	z->key = key;
	z->val = val;
	z->Parent = nullNode;
	z->left = nullNode;
	z->right = nullNode;
	TreeInsert(z);								// Blatt in BST einfügen
}

int BinaryTree::get(int key) {					// Knoten suchen
//	TreeNode * tmp = TreeSearch(head->right, key);
	TreeNode * tmp = IterativeTreeSearch(head->right, key);
	if (tmp == nullNode) return -1;
	else return tmp->val;
}

bool BinaryTree::remove(int key) {				// Knoten entfernen
	// Knoten suchen
	TreeNode * z = head->right;					// an der Wurzel beginnen
	TreeNode * x;								// Hilfszeiger
	while (z != nullNode && key != z->key) {	// Knoten suchen
		if (key < z->key) z = z->left;
		else z = z->right;
	}
	// z zu löschender Knoten
	if (z == nullNode) return false;			// Knoten wurde nicht gefunden

	// Fall 1: Löschen eines Blattes
	if (z->left == nullNode && z->right == nullNode) {	// Knoten ist ein Blatt und kann gelöscht werden
		x = nullNode;							// z aus Elternknoten austragen

	// Fall 2: z hat 1 Nachfolger
	} else if(!(z->left != nullNode && z->right != nullNode)) {	// Knoten hat einen Nachfolger
		if (z->left != nullNode) x = z->left;	// Elternknoten bekommt linken Nachfolger von z
		else x = z->right;						// Elternknoten bekommt rechten Nachfolger von z
	}

	// Fall 3: z hat 2 Nachfolger
	// Suche Minimum im rechten Teilbaum von z
	else {
		x = z->right;							// x ist Minimum
		while (x->left != nullNode) x = x->left;		// Minimum suchen			
		x->left = z->left;						// Minimum links übernimmt linken Teilbaum von z
		if (x->Parent != z) {					// Minimum ist nicht bereits z->left selber
			x->Parent->left = x->right;			// neues Minimum übernimmt rechten Teilbaum von alten Minimum
			if (x->right != nullNode) x->right->Parent = x->Parent;		// Korrektur des Parent im rechten Teilbaum vom Minimum
			x->right = z->right;				// Minimum rechts übernimmt rechten Teilbaum von z
		}
		z->left->Parent = x;					// Die Kinder des zu löschenden Knoten aktualisieren
		z->right->Parent = x;
	}

	// Knoten löschen und Elternknoten aktualisieren
	if (z->Parent == nullNode) head->right = x;
	else
		if (z->Parent->left == z) z->Parent->left = x;	// in Elternknoten Kindzeiger aktualisieren
		else z->Parent->right = x;
	if (x->Parent != nullNode) x->Parent = z->Parent;
	delete z;
	return true;
}

// Traversierungsmethoden

void BinaryTree::printInorder() {				// Ausgabe in Inorder
	std::cout << "Inorder: ";
	printInorder(head->right);
	std::cout << std::endl;
}

void BinaryTree::printPreorder() {				// Ausgabe in Preorder
	std::cout << "Preorder: ";
	printPreorder(head->right);
	std::cout << std::endl;
}

void BinaryTree::printPostorder() {				// Ausgabe in Postorder
	std::cout << "Postorder: ";
	printPostorder(head->right);
	std::cout << std::endl;
}

void BinaryTree::printLevelorder() {			// Ausgabe in Levelorder
	std::cout << "Levelorder: ";
	printLevelorder(head->right);
	std::cout << std::endl;
}

TreeNode * BinaryTree::TreeSearch(TreeNode * x, int k) { // Rekursive Suche im BST
	if (x == nullNode || k == x->key) return x;
	if (k < x->key) return TreeSearch(x->left, k);
	else return TreeSearch(x->right, k);

}

TreeNode * BinaryTree::IterativeTreeSearch(TreeNode * x, int k) { // Iterative Suche im BST
	while (x != nullNode && k != x->key) {
		if (k < x->key) x = x->left;
		else x = x->right;
	}
	return x;
}

TreeNode * BinaryTree::MinimumTreeSearch(TreeNode * x) { // Minimum Suche im BST
	while (x->left != nullNode) {
		x = x->left;
	}
	return x;
}

TreeNode * BinaryTree::MaximumTreeSearch(TreeNode * x) { // Minimum Suche im BST
	while (x->right != nullNode) {
		x = x->right;
	}
	return x;
}

void BinaryTree::TreeInsert(TreeNode* z) {		// Einfügen eines neuen Knoten z, vorab Erzeugen
	TreeNode* x = head->right;					// x aktueller Knoten im BST
	while (x != nullNode) {
		z->Parent = x;
		if (z->key < x->key) x = x->left;
		else x = x->right;
	}
	if (z->Parent == nullNode) head->right = z;				// noch leerer BST
	else
		if (z->key < z->Parent->key) z->Parent->left = z;	// Blatt wird links angefügt
		else z->Parent->right = z;							// Blatt wird rechts angefügt
}

