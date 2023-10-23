#include "LinkedList_v2.h"
#include <iostream>

LinkedList_v2::LinkedList_v2()
{
	head = new Node;
	tail = new Node;
	head->next = tail;
}

LinkedList_v2::~LinkedList_v2()
{
	while (head != tail) {
		auto delNode = head;
		head = head->next;
		delete delNode;
	}
	delete tail;
}

void LinkedList_v2::insert(int key)
{
	tail->key = key;
	tail->next = new Node();
	tail = tail->next;
}

bool LinkedList_v2::remove(int key)
{
	auto node = head;
	while (node->next != tail && node->next->key != key) node = node->next;
	if (node->next == tail) {
		// Liste wurde durch vollständig durchlaufen 
		// und kein Element mit dem Wert 'key' gefunden
		return false;
	}
	auto delNode = node->next;
	node->next = node->next->next;
	delete delNode;
	return true;
}

bool LinkedList_v2::search(int key) const
{
	Node* node = head;
	if (node->next == tail) return false;
	while (node->next != tail && node->next->key != key) node = node->next;
	if (node->next->key == key) return true;
	return false;
}

void LinkedList_v2::print() const
{
	if (head->next == tail) {
		std::cout << "FEHLER: Liste ist leer." << std::endl;
	}
	else {
		std::cout << "List( ";
		auto node = head;
		while (node->next != tail) {
			node = node->next;
			std::cout << node->key << " ";
		}
		std::cout << " )" << std::endl;
	}
}
