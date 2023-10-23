#include "DSName.h"
#include <iostream>
#include <Windows.h>

void printFindResult(bool found, int key) {
	auto handle = GetStdHandle(STD_OUTPUT_HANDLE);
	if (found) {
		SetConsoleTextAttribute(handle, 2 /*green*/);
		std::cout << " - found" << std::endl;
		SetConsoleTextAttribute(handle, 7 /*grey*/);
	}
	else {
		SetConsoleTextAttribute(handle, 4 /*red*/);
		std::cout << " - not found" << std::endl;
		SetConsoleTextAttribute(handle, 7 /*grey*/);
	}
}

/*
	Hinweis: Programm ist nur unter Windows lauffähig.
	Für andere Betriebssysteme muss die Funktion 
	printFindResult(...) angepasst/ausgetauscht werden.
*/
int main() {

	// leere Datenstruktur anlegen		
	DSName Datastructure;

	// Elemente in die leere einfügen
	Datastructure.insertItem(Item(0, 52));
	Datastructure.insertItem(Item(1, 12));
	Datastructure.insertItem(Item(2, 34));
	Datastructure.insertItem(Item(3, 54));
	Datastructure.insertItem(Item(4, 65));
	
	// alle Elemetne der Datenstrukur ausgeben
	Datastructure.printAllItems();
	
	// Element mit key: 2 löschen
	int key = 2;
	std::cout << "Delete element with key: " << key << std::endl << std::endl;
	Datastructure.deleteItem(2);
	
	// alle Elemetne der Datenstrukur ausgeben
	Datastructure.printAllItems();
	
	// Element mit key: 4 suchen
	key = 4;
	std::cout << "Search element with key: " << key;
	bool found = Datastructure.findItem(key);
	printFindResult(found, key);

	// Element mit key: 42 suchen
	key = 42;
	std::cout << "Search element with key: " << key;
	found = Datastructure.findItem(key);
	printFindResult(found, key);
}