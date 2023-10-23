#include "BST.h"
#include <iostream>
using namespace std;

int main()
{
	// Instanz vom BST erzeugen 
	BST* mytree = new BST();

	// BST aufbauen 
	// TODO: Baum nach der Abbildung aufbauen

	// BST in Levelorder ausgeben 
	// TODO

	// Abfrage nach Höhe des Baumes
	int maxHeight = mytree->getBSTHeight();

	// BST nach Niveau ausgeben
	cout << endl;
	for (int i = 0; i <= maxHeight; i++) {
       // TODO
	}
	//mytree->setBSTHeight();
	mytree->printBST();

	// Speicherplatz freigeben 
	// TODO Destruktor explizit aufrufen, da mit new allokiert wurde

	// neuen BST Baum instanzieren
	BST b;
	//TODO 2. Baum nach (d) aufbauen 

	maxHeight = b.getBSTHeight();

	// BST nach Niveau ausgeben
	cout << endl;
	for (int i = 0; i <= maxHeight; i++) {
		std::cout << "Knoten von Niveau " << i << ": ";
		b.printNiveau(i);
		std::cout << std::endl;
	}

	// BST nach Hoehe ausgeben
	// TODO

	return 0; 

}