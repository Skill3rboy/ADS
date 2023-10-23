#include "DSName.h"
#include <iostream>
#include <utility>

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

	Ignorieren Sie die Implementierung und konzentrieren sich bitte nur
	auf die Verwendung der Datenstruktur in der Datei main.cpp
*/

DSName::DSName()
{
}

DSName::~DSName()
{
}

void DSName::insertItem(Item value)
{
	Data.insert( std::pair<int,Item>(value.key, value) );
}

Item DSName::getItem(int key)
{
	auto iterator = Data.find(key);
	if (iterator != Data.end()) {
		return iterator->second;
	}
	else {
		return Item();
	}
}

bool DSName::findItem(int key)
{
	if ((Data.find(key)) != Data.end()) return true;
	return false;
}

bool DSName::deleteItem(int key)
{
	return Data.erase(key) > 0;
}

void DSName::printAllItems()
{
	std::cout << "DSname contains following items:" << std::endl;
	for (auto const& Item : Data) {
		std::cout << "key: " << Item.second.key << " value: " << Item.second.Data << std::endl;
	}
	std::cout << std::endl;
}
