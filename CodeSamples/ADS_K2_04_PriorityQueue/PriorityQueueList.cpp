#include "PriorityQueueList.h"
#include <iostream>


PriorityQueueList::PriorityQueueList() :
	pqhead{nullptr}
{
}

PriorityQueueList::~PriorityQueueList()
{
	while (pqhead != nullptr) {
		PQNode* node = pqhead;
		pqhead = pqhead->next;
		delete node;
	}
}

bool PriorityQueueList::empty() const
{
	return pqhead == nullptr;
}

/**
 * Einfügens eines neuen Elementes in die PriorityQueue
 * Hinweis: Beim Einfügen wird die Reihenfolge eingehalten
 *			und das neue Element immer an die richtige Position
 *			hinzugefügt -> linearer Aufwand O(n)
 *
 * \pre Je höher die Prio, desto kleiner der numerische Wert von Node.prio
 */
void PriorityQueueList::push_front(int item, int prio)
{
	PQNode* newNode = new PQNode{ item,prio,nullptr };

	if (pqhead == nullptr) {
		// Einfügen in leere Liste
		pqhead = newNode;
	}
	else {
		PQNode* node = pqhead;
		if (newNode->prio < node->prio) {
			// Einfügen am Listenanfang
			newNode->next = node;
			pqhead = newNode;
		}
		else {
			while (node->next != nullptr && newNode->prio > node->next->prio) node = node->next;
			if (node->next == nullptr) {
				// Einfügen am Ende
				node->next = newNode;
			}
			else {
				// Einfügen in der Mitte
				auto tmp = node->next;
				node->next = newNode;
				node->next->next = tmp;
			}
		}
	}
}

/**
 * Entnahme des Elementes aus der PriorityQueue
 * Hinweis: das Element mit höchster Priorität ist immer
 *			am Anfang der Liste -> Entnahme hat konstanten Aufwand O(1)
 *
 * \pre Je höher die Prio, desto kleiner der numerische Wert von PQNode.prio
 */
PQNode PriorityQueueList::pop_max()
{
	PQNode maxNode{ -1,-1,nullptr };
	if (pqhead != nullptr) {
		auto node = pqhead;
		pqhead = pqhead->next;
		maxNode = *node;
		delete node;
	}
	return maxNode;
}

void PriorityQueueList::print()
{
	if (pqhead == nullptr) {
		std::cout << "PQList ist leer" << std::endl;
	}
	else {
		std::cout << "PQList( ";
		auto node = pqhead;
		while (node->next != nullptr) {
			std::cout << "( " << node->prio << " , " << node->data << " ) ";
			node = node->next;
		}
		std::cout << std::endl;
	}
}
