#pragma once
#include "Node.h"

class LinkedList_Stack
{
private:
	Node* head;				// Zeiger auf oberstes Element im Stack (Listenanfang)
public:
	LinkedList_Stack();		// Konstruktor
	~LinkedList_Stack();	// Destruktor
	void push(int key);		// neues Element auf dem Stack ablegen
	bool pop(Node& popNode);// oberstes Element vom Stack entnehmen
	void print() const;		// Stack ausgeben
};

