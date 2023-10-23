#pragma once
#include "Node.h"

class DoublyLinkedList {
private:
	Node* head;				// Pointer auf den Listenanfgang
	void  erase(Node* node);	// Listenelement löschen
public:
	void insert(int key);	// neues Listenelement einfügen
	bool erase(int key);	// Listenelement löschen
	bool search(int key);	// Listenelement suchen
	DoublyLinkedList();		// Konstruktor
	~DoublyLinkedList();	// Destruktor
	void print();			// Liste ausgeben
	void insertionSort();	// Liste sortieren (InsertionSort)
	void selectionSort();	// Liste sortieren (SelectionSort)
};