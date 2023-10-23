#pragma once

#include "Node.h"

/**
 * class LinkedList_v1
 *
 * Verkettete Liste OHNE expliziten Head- und Tail-Knoten
 * d.h. in jedem Knoten der Liste werden Daten gespeichert
 */
class LinkedList_v1 {
private:
	Node* head;	// Pointer auf den Anfang der Liste
	Node* tail; // Pointer aud das Listenende
public:
	LinkedList_v1();			// Konstruktor
	~LinkedList_v1();			// Destruktor
	void insert(int key);		// Einfügen von Elementen in die Liste
	bool remove(int key);		// Löschen von Elementen aus der Liste
	bool search(int key) const; // Suche nach Listenelement
	void print() const;			// Ausgeben der Liste
};