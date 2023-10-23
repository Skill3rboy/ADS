#include "BST.h"
#include <iostream>
using namespace std;

int main()
{
	// Instanz vom BST erzeugen 
	BST* mytree = new BST();

	mytree->printBST();

	// BST aufbauen 
	mytree->insert(5);
	mytree->insert(3);
	mytree->insert(7);
	mytree->insert(1);
	mytree->insert(4);
	mytree->insert(2);
	mytree->insert(6);
	mytree->insert(10);
	mytree->insert(8);
	mytree->insert(11);
	mytree->insert(9);

	// BST in Levelorder ausgeben 
	mytree->printBST();

	// Abfrage nach Höhe des Baumes
	int maxHeight = mytree->getBSTHeight();

	// BST nach Niveau ausgeben
	cout << endl;
	for (int i = 0; i <= maxHeight; i++) {
		std::cout << "Knoten von Niveau " << i << ": ";
		mytree->printNiveau(i);
		std::cout << std::endl;
	}
	//mytree->setBSTHeight();
	mytree->printBST();

	// Speicherplatz freigeben 
	delete mytree; // Destruktor explizit aufrufen

	// neuen BST Baum instanzieren
	BST b;
	b.insert(6);
	b.insert(2);
	b.insert(9);
	b.insert(1);
	b.insert(4);
	b.insert(7);
	b.insert(3);
	b.insert(5);
	b.insert(8);

	maxHeight = b.getBSTHeight();

	// BST nach Niveau ausgeben
	cout << endl;
	for (int i = 0; i <= maxHeight; i++) {
		std::cout << "Knoten von Niveau " << i << ": ";
		b.printNiveau(i);
		std::cout << std::endl;
	}

	// BST nach Hoehe ausgeben
	cout << endl;
	for (int i = 0; i <= maxHeight; i++) {
		std::cout << "Knoten von Hoehe " << i << ": ";
		b.printHeight(i);
		std::cout << std::endl;
	}

	return 0; 

}