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
 *	Diese Funktion l�scht einen Knoten aus der doppelt verketteten Liste
 *  und passt gleichzeit die Pointer auf Vorg�nger und Nachfolger an.
 *
 */
void DoublyLinkedList::erase(Node* delNode)
{
	/*
		TODO: �bung 2 - Aufgabe 6
	*/
}

/**
 *	L�schen eines Knoten aus der doppelt verketteten Liste
 *
 *	Diese Funktion sucht den Knoten in der Liste, der gel�scht werden soll.
 *	Das eigentliche L�schen geschieht in der privaten Funktion erase(Node* ..)
 *
 */
bool DoublyLinkedList::erase(int key)
{
	/*
		TODO: �bung 2 - Aufgabe 6
	*/

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

	// iterieren �ber die gesamte Liste
	while (node->next != nullptr) {

		Node* tmp_node = node;			// Zeiger auf letztes Element des sortierten Bereichs
		Node* tmp_next = node->next;	// Zeiger auf das erste Elemente im unsortierten Bereich


		if (tmp_node->key < tmp_next->key) {
			// Sortierung bereits von tmp_node und tmp_next korrekt
			// --> weiter zum n�chsten Element
			node = node->next;
		} else {
			// tmp_next ist an der falschen Position
			// so lange um ein Element nach links verschieben, bis die Sortierung stimmt
			while (tmp_node!= nullptr && tmp_next->key < tmp_node->key) {
				// tempr�res Elemente - ben�tigt beim swappen der Elemente
				auto tmp_next_next = tmp_next->next;
				// Vertauschen der Elemente und Anpassen 
				tmp_next->prev = tmp_node->prev;
				tmp_next->next = tmp_node;
				tmp_node->prev = tmp_next;
				tmp_node->next = tmp_next_next;
				// Anpassen der Vorg�nger/Nachfolger-Referenzen
				if (tmp_next_next != nullptr) tmp_next_next->prev = tmp_node;
				if (tmp_next->prev !=nullptr) tmp_next->prev->next = tmp_next;
				// Element f�r n�chsten Schleifendurchgang w�hlen
				tmp_node = tmp_next->prev;
			}
			// Head auf das 
			if (tmp_next != nullptr && tmp_next->key < minNode->key) minNode = tmp_next;
		}
	}
	head = minNode;
}