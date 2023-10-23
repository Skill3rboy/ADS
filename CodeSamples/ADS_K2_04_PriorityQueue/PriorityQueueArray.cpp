#include "PriorityQueueArray.h"
#include <iostream>

PriorityQueueArray::PriorityQueueArray(unsigned maxN) :
	capacity{maxN},
	size{0}
{
	PQueue = new PQItem[capacity];
}

PriorityQueueArray::~PriorityQueueArray()
{
	delete[] PQueue;
}

bool PriorityQueueArray::empty() const
{
	return size == 0;
}

bool PriorityQueueArray::isfull() const
{
	return size == capacity;
}

/**
 * Einfügens eines neuen Elementes in die PriorityQueue
 * Hinweis: es wird an einer beliebigen Position eingefügt O(1),
 *			die Priorisierung erfolgt bei der Entnahme O(n)
 *
 * \pre Je höher die Prio, desto kleiner der numerische Wert von PQItem.prio
 */
void PriorityQueueArray::push_front(PQItem newItem)
{
	if (!isfull()) {
		PQueue[size] = newItem;
		size++;
	}
	else {
		std::cerr << "ERROR: Priority Queue ist voll." << std::endl;
	}
}

/**
 * Entnahme des Elementes aus der PriorityQueue
 * Hinweis: jede Entnahem des Elementes mit höchster Priotität erfolgt
			durch eine lineare Suche in O(n). 
			Allerdings ist der Aufwand für das Einfügen konstant O(1)
 *
 * \pre Je höher die Prio, desto kleiner der numerische Wert von PQItem.prio  
 */
PQItem PriorityQueueArray::pop_max()
{
	PQItem maxItem{-1,-1};
	int	maxPrio = std::numeric_limits<int>::max();
	unsigned maxIdx = 0;
	for (unsigned i = 0; i < size; i++) {
		if (PQueue[i].prio < maxPrio) {
			maxItem = PQueue[i];
			maxPrio = maxItem.prio;
			maxIdx = i;
		}
	}
	// Elemente im Array aufrücken + O(n)
	for (unsigned i = maxIdx; i < size-1; i++) {
		PQueue[i] = PQueue[i + 1];
	}
	size--;
	return maxItem;
}

void PriorityQueueArray::print()
{
	std::cout << "PQArray( ";
	for (unsigned i = 0; i < size; i++) {
		std::cout << "( " << PQueue[i].prio << " , " << PQueue[i].data << " ) ";
	}
	std::cout << " )" << std::endl;
}
