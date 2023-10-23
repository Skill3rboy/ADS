#pragma once

class PQNode {
public:
	int data;
	int prio;
	PQNode* next;
};

class PriorityQueueList
{
private:
	// Zeiger auf 1. Listen-Element
	PQNode* pqhead;
public:
	PriorityQueueList();  // Konstruktor
	~PriorityQueueList(); // Destruktor
	bool empty() const; // Test Liste leer
	// Hinzufuegen eines neuen Elementes
	void push_front(int item, int prio);
	// Element mit max. Prioritaet holen und entfernen
	PQNode pop_max();
	// Alle Listenelemente Ausgeben
	void print();
};

