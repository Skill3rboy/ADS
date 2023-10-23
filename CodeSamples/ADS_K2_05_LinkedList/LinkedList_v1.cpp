#include "LinkedList_v1.h"
#include <iostream>

LinkedList_v1::LinkedList_v1() :
	head{ nullptr },
	tail{ nullptr}
{
}

LinkedList_v1::~LinkedList_v1()
{
	while (head != nullptr && head != tail) {
		Node* node = head;
		head = head->next;
		delete node;
	}
	delete tail;
}

void LinkedList_v1::insert(int key)
{
	if (head == nullptr && tail == nullptr) {
		Node* node = new Node();
		node->key = key;
		tail = node;
		head = node;
	}
	else if (tail != nullptr) {
		tail->next = new Node(key, nullptr);
		tail = tail->next;
	}
}

bool LinkedList_v1::remove(int key)
{
	if (head == nullptr) {
		// Löschen in leerer Liste nicht möglich
		return false;
	}
	else if (head->key == key) {
		// Löschen am Anfang
		Node* node = head;
		if (head->next != nullptr) {
			head = head->next;
		}
		delete node;
	}
	else {
		// Löschen in der Mitte
		Node* node = head;
		while (node->next != nullptr && node->next->key != key) node = node->next;
		if (node->next == nullptr) {
			// Der Key (key) ist nicht in der Liste enthalten
			return false;
		}
		else if (node->next->key == key) {
			if (node->next->next == nullptr) {
				// letztes Listenelement löschen
				delete node->next;
				node->next = nullptr;
				tail = node;
			}
			else {
				Node* tmp = node->next;
				node->next = node->next->next;
				delete tmp;
			}
		}
	}
	return true;
}

bool LinkedList_v1::search(int key) const
{
	Node* node = head;
	if (node->next == tail) return false;
	while (node->next != tail && node->next->key != key) node = node->next;
	if (node->next->key == key) return true;
	return false;
}

void LinkedList_v1::print() const
{
	if (head == nullptr) {
		std::cout << "FEHLER: Liste ist leer" << std::endl;
	}
	else {
		Node* node = head;
		std::cout << "LinkedList { ";
		while (node != nullptr) {
			std::cout << node;
			node = node->next;
		}
		std::cout << "}" << std::endl;
	}
}

