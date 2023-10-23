#pragma once

class Node {
public:
	int key;	// Daten für Listenknoten
	Node* next;	// Pointer auf das vorherige Listenelement
	Node* prev;	// Pointer auf das nachfolgende Listenelement
	Node() :	// Konstruktor
		key{ 0 },
		next{ nullptr },
		prev{ nullptr }
	{}
	Node(int key_, Node* prev_ = nullptr, Node* next_ = nullptr) :
		key{ key_ },
		prev{ prev_ },
		next{ next_ }
	{}
};