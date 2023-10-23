#pragma once

#include "Node.h"

/**
 * class LinkedList_v2
 *
 * Verkettete Liste MIT expliziten bzw. zusätzlichen Head- und Tail-Knoten
 * d.h. in den Knoten head und tail werden keine Daten gehalten, die leere
 * Liste besteht dann aus den zwei Knoten head und tail
 */
class LinkedList_v2 {
private:
	Node* head;	// Pointer auf den Anfang der Liste
	Node* tail;	// Pointer auf das Listenende
public:
	LinkedList_v2();			// Konstruktor
	~LinkedList_v2();			// Destruktor
	void insert(int key);		// Einfügen von Elementen in die Liste
	bool remove(int key);		// Löschen von Elementen aus der Liste
	bool search(int key) const;	// Suche nach Listenelement
	void print() const;			// Ausgeben der Liste
};