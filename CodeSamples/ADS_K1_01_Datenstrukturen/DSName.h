#ifndef DSNAME_H
#define DSNAME_H
#include <map>


/*
	WICHTIGER HINWEIS:
	Die Klasse DSName repräsentiert in diesem Beispiel eine allgemeine 
	Datenstruktur und soll die folgenden Eigenschaften einer Datensturktur
	verdeutlichen:
	* Einfügen von Daten
	* Zugriff auf Daten
	* Suchen von Elementen
	* Löschen von Elementen
	
	Die Implementierung ist für Sie in diesem Beispiel NICHT relevant.

	Lassen Sie sich bitte nicht durch die folgenden beiden Zeilen 
	Programmcode verwirren:
		class Item;							
		using Data = std::map<int, Item>;

	Ignorieren Sie die Implementierung und konzentrieren sich bitte nur
	auf die Verwendung der Datenstruktur in der Datei main.cpp
*/
class Item;							// Vorwärtsdeklaration (forward declaration)
using Data = std::map<int, Item>;	// moderne Version eines typedef's 

class Item {
public:
	int key;	// Eindeutige ID für die Datenstruktur
	int Data;	// Daten
	Item(int key = 0, int Data = 0) { // Konstruktor
		this->key = key;
		this->Data = Data;
	}
	~Item() {}; // Destruktor
};


class DSName {
private:
	// ... (nicht für User sichtbare Attribute und Methoden)
	Data Data; // eigentliche Daten der Datenstruktur

public:
	// ... (für den User sichtbare Attribute und Methoden)
	DSName();					 // default Konstruktor
	~DSName();					 // default Destruktor
	void insertItem(Item value); // Daten einfügen
	Item getItem(int key);		 // Daten auslesen
	bool findItem(int key);		 // Daten suchen
	bool deleteItem(int key);	 // Daten löschen
	// ...
	void printAllItems(); // Hilfsmethode: alle Elemente ausgeben

};

#endif