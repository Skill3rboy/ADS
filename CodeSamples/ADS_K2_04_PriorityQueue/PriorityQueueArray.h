#pragma once

#include <vector>

class PQItem {
public:
	int data;
	int prio;
};

class PriorityQueueArray
{
private:
	PQItem*  PQueue;
	unsigned capacity;
	unsigned size;
public:
	PriorityQueueArray(unsigned maxN);	// Konstruktor
	~PriorityQueueArray();				// Destruktor
	bool	empty() const;				// Test, ob Array leer
	bool	isfull() const;				// Test, ob Array voll
	void	push_front(PQItem newItem);	// Hinzufuegen eines neuen Elementes
	PQItem	pop_max();					// Holen und Entfernen des Elementes mit maximaler Prioritaet
	void	print();					// Ausgeben der Elemente auf der Konsole
};

