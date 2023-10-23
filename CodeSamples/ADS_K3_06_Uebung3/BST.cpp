#include "BST.h"
#include <queue>        //std::queue
#include <iostream>     // std::cout
#include <algorithm>    // std::max
using namespace std;

void BST::printNiveau(int niveau) {
	// verwende Levelorder um die Knoten von einem spezifischen Niveau auszugeben
	int currentNiveau = -1;
	queue<Treenode*> nodeQueue;
	queue<int> niveauQueue;

	// lege Wurzelknoten in die nodeQueue und das Niveau von der Wurzel in die niveauQueue
	if (head->right != nullptr) {
		// Baum ist nicht leer
		nodeQueue.push(head->right);
		niveauQueue.push(0);
	}

	//cout << "Knoten von Niveau " << niveau << ": ";
	while (!nodeQueue.empty() && currentNiveau != niveau + 1) {
		Treenode* currentNode = nodeQueue.front();
		nodeQueue.pop();
		int currentNodeNiveau = niveauQueue.front();
		niveauQueue.pop();
		if (currentNodeNiveau == niveau) {
			cout << "(" << currentNode->item << ") ";
		}
		// Nachfolger in die Queue
		if (currentNode->left != nullptr) {
			nodeQueue.push(currentNode->left);
			niveauQueue.push(currentNodeNiveau + 1);
		}
		if (currentNode->right != nullptr) {
			nodeQueue.push(currentNode->right);
			niveauQueue.push(currentNodeNiveau + 1);
		}
	}
}

int BST::getBSTHeight() {
	if (head->right != nullptr) {
		computeHeight(head->right);
		return head->right->height;
	}
	else
	{
		return -1;
	}
}
void BST::printHeight(int height) {
	if (head->right != nullptr) {
		printHeight(head->right, height);
	}
}

int BST::printHeight(Treenode* node, int height) {
	// traversiere den Baum Bottom-Up => in Postorder
	int hLeft = -1;
	int hRight = -1;
	if (node->left) {
		hLeft = printHeight(node->left, height);
	}
	if (node->right) {
		hRight = printHeight(node->right, height);
	}
	int nodeHeight = max(hLeft, hRight) + 1;
	if (nodeHeight == height) {
		cout << "(" << node->item << ") ";
	}

	return nodeHeight;
}

BST::BST() {
	// constructor
	head = new Treenode();
	head->left = nullptr;
	head->right = nullptr;
}

BST::~BST() {
	// destructor: löesche alle Knoten vom BST
	if (head->right) deleteBST(head->right);  // 1 Punkt für den Aufruf der rekursiven Methode
}

void BST::deleteBST(Treenode* p) {
	// Erkennen, dass p ein Blattknoten ist und gelöscht werden kann (2 Punkte)
	// 1 Punkt für die richtige Traversierung (möglichst Postorder) 
	if (p->left) {
		deleteBST(p->left); // 1 Punkt
		p->left = nullptr;
	}
	if (p->right) {
		deleteBST(p->right); // 1 Punkt
		p->right = nullptr;
	}
	if (p->left == nullptr && p->right == nullptr)
	{
		delete p;
		return;
	}

	return;
}

int BST::computeHeight(Treenode* p) {
	// traversiere den Baum in Postorder
	if (p == nullptr) {
		return -1; // nicht existierende Knoten haben die Höhe -1 (= ein Niveau unter dem Blattknoten)
	}

	int leftHeight = computeHeight(p->left);
	int rightHeight = computeHeight(p->right);

	// Höhe des Knotens bestimmen
	p->height = leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;

	return p->height;
}

void BST::insert(int key) {

	// neuen Knoten erzeugen und initialisieren
	Treenode* p = new Treenode();
	p->item = key;
	p->height = 0;
	p->left = nullptr;
	p->right = nullptr;

	Treenode* tmp = head->right;
	if (tmp == nullptr) {
		head->right = p;
		return;
	}

	Treenode* prev = head;
	while (tmp != nullptr) {
		prev = tmp;
		if (tmp->item > key) {
			tmp = tmp->left;
		}
		else {
			tmp = tmp->right;
		}
	}
	if (prev->item > key)
	{
		prev->left = p;
	}
	else
	{
		prev->right = p;
	}

	return;

}

void BST::printBST() {

	// BST wird in Levelorder mit Hilfe einer Queue ausgegeben

	Treenode* root = head->right;

	// 2 Queues instanzieren (1 Punkt)
	std::queue<Treenode*> q;
	std::queue<int> nq;
	if (root == nullptr) {
		std::cout << "BST ist leer" << std::endl;
		return;
	}
	// Wurzelknoten und Startniveau in die Queues pushen (1 Punkt)
	q.push(root);
	nq.push(0);

	// vorheriges Niveau merken bzw. den Niveauwechsel irgendwie mitbekommen (1 Punkt)
	int prev_niveau = -1;
	int niveau;

	// Schleife 6 Punkte
	while (!q.empty()) {
		// Entnahme aus den Queues und löschen (2 Punkte)
		Treenode* curr = q.front();
		q.pop();
		niveau = nq.front(); nq.pop();

		// Ausgabe Niveauwechsel (1 Punkt)
		if (prev_niveau != niveau) {
			std::cout << std::endl << "Niveau " << niveau << ": ";
			prev_niveau = niveau;
		}
		// Ausgabe des Knotens (1 Punkt)
		std::cout << "(" << curr->item << ") ";

		// Linker Nachfolgeknoten in die Queues (1 Punkt)
		if (curr->left != nullptr)
		{
			q.push(curr->left);
			nq.push(niveau + 1);
		}
		// Rechter Nachfolgeknoten in die Queues (1 Punkt)
		if (curr->right != nullptr)
		{
			q.push(curr->right);
			nq.push(niveau + 1);
		}
	}
	return;
}
