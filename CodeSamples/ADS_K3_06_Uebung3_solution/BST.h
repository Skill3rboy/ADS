#pragma once
#include "Treenode.h"

class BST {
private:
	Treenode* head;
	int computeHeight(Treenode* p); // rekursive Methode, 
								// berechnet die Höhe zum       
								// Knoten p und gibt diese 
								// zurück 
	void deleteBST(Treenode* p); // löscht den Teilbaum ab p

	// rekursive Methode zur Ausgabe aller Knoten zu einer Höhe
	int printHeight(Treenode* node, int height); 

public:
	BST();
	~BST();
	void insert(int key);
	int getBSTHeight();  // Starterfunktion für die rekursive 
						  // Methode und liefert die Höhe des  
						  // Baumes zurück 
	void printBST();      // Ausgabe des BST in Levelorder
	void printNiveau(int niveau); // Ausgabe aller Knoten zu einem Niveau
	void printHeight(int height); // Ausgabe aller Knoten zu einer Höhe
};
