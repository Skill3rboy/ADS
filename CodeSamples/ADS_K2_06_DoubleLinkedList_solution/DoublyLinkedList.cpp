#include "DoublyLinkedList.h"
#include <iostream>


void DoublyLinkedList::insert(int key)
{
	Node* newNode = new Node(key);
	newNode->next = head;
	newNode->prev = nullptr;
	if (head != nullptr) head->prev = newNode;
	head = newNode;
}

/**
 *	Diese Funktion löscht einen Knoten aus der doppelt verketteten Liste
 *  und passt gleichzeit die Pointer auf Vorgänger und Nachfolger an.
 *
 */
void DoublyLinkedList::erase(Node* delNode)
{
	if (delNode->prev != nullptr) {
		delNode->prev->next = delNode->next;
	}
	else {
		head = delNode->next;
	}
	if (delNode->next != nullptr) {
		delNode->next->prev = delNode->prev;
	}
	delete delNode;
}

/**
 *	Löschen eines Knoten aus der doppelt verketteten Liste
 *
 *	Diese Funktion sucht den Knoten in der Liste, der gelöscht werden soll.
 *	Das eigentliche Löschen geschieht in der privaten Funktion erase(Node* ..)
 *
 */
bool DoublyLinkedList::erase(int key)
{
	auto delNode = head;
	// Knoten suchen der gelöscht werden soll
	while (delNode != nullptr && delNode->key != key) delNode = delNode->next;
	if (delNode != nullptr) {
		// Knoten löschen
		erase(delNode);
		return true;
	}
	return false;
}

bool DoublyLinkedList::search(int key)
{
	auto node = head;
	while (node != nullptr && node->key != key) node = node->next;
	if (node == nullptr) return false;	// Element nicht in der Liste
	return true;						// Element in Liste enthalten
}

DoublyLinkedList::DoublyLinkedList() :
	head{ nullptr }
{
}

DoublyLinkedList::~DoublyLinkedList()
{
	while (head != nullptr) {
		Node* node = head;
		head = head->next;
		delete node;
	}
}

void DoublyLinkedList::print() {
	std::cout << "List( ";
	auto node = head;
	while (node != nullptr) {
		std::cout << node->key << " ";
		node = node->next;
	}
	std::cout << ")" << std::endl;
}

void DoublyLinkedList::insertionSort() {
	Node* node = head;
	Node* minNode = head;

	// iterieren über die gesamte Liste
	while (node->next != nullptr) {

		Node* tmp_node = node;			// Zeiger auf letztes Element des sortierten Bereichs
		Node* tmp_next = node->next;	// Zeiger auf das erste Elemente im unsortierten Bereich


		if (tmp_node->key < tmp_next->key) {
			// Sortierung bereits von tmp_node und tmp_next korrekt
			// --> weiter zum nächsten Element
			node = node->next;
		} else {
			// tmp_next ist an der falschen Position
			// so lange um ein Element nach links verschieben, bis die Sortierung stimmt
			while (tmp_node!= nullptr && tmp_next->key < tmp_node->key) {
				// tempräres Elemente - benötigt beim swappen der Elemente
				auto tmp_next_next = tmp_next->next;
				// Vertauschen der Elemente und Anpassen 
				tmp_next->prev = tmp_node->prev;
				tmp_next->next = tmp_node;
				tmp_node->prev = tmp_next;
				tmp_node->next = tmp_next_next;
				// Anpassen der Vorgänger/Nachfolger-Referenzen
				if (tmp_next_next != nullptr) tmp_next_next->prev = tmp_node;
				if (tmp_next->prev !=nullptr) tmp_next->prev->next = tmp_next;
				// Element für nächsten Schleifendurchgang wählen
				tmp_node = tmp_next->prev;
			}
			// Head auf das 
			if (tmp_next != nullptr && tmp_next->key < minNode->key) minNode = tmp_next;
		}
	}
	head = minNode;
}


void DoublyLinkedList::selectionSort()
{
	if (head == nullptr || head->next == nullptr)
		return;	// Eine Liste mit weniger keinem oder einem Element ist bereits sortiert

	// Hilfspointer auf den Listenanfang
	Node* node = head;

	// iterieren über die gesamte Liste
	while (node->next != nullptr) {
		Node* minNode = node;
		int   minKey = node->key;

		// Suche nach dem Knoten mit dem kleinsten key im unsortierten Bereich
		for (auto curr = node->next; curr != nullptr; curr = curr->next) {
			if (curr->key < minKey)
				minNode = curr;
		}

		/*
		ACHTUNG: An dieser Stelle entspricht die Musterlösung
				 nicht der korrekten Vorgehensweise.

				 Es sollen NICHT nur die key's der beiden Listenknoten
				 getauscht werden, sondern es sollen die Listenknoten
				 vertauscht werden - d.h. die müssen die next- und 
				 prev-Zeiger aller beteiligten Listenknoten anpassen.
				 Dies ist allerdings eine elementare Aufgabe von
				 Praktikum 1, für die wir keine Musterlösung 
				 zur Verfügung stellen möchten.
				 Orientieren Sie sich an folgender Funktion:
				 - DoublyLinkedList::insertionSort() 
		*/
		std::swap(node->key, minNode->key);

		// Node auf den Beginn des unsortierten Bereiches setzten
		node = node->next;
		if (node == nullptr) break;
	}
}
