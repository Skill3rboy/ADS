#pragma once
#include <iostream>

class Node {
public:
	int	  key;	// Daten 
	Node* next; // Pointer auf das nächste Listenelement
	Node() :	// Konstruktor
		key{ 0 },
		next{ nullptr }
	{}
	Node(int _key, Node* _next=nullptr) : // Konstruktor 
		key{ _key },
		next{ _next }
	{}
};

/*
	Ausgabe Operator für eine angenehmere Verwendung 
	der Konsolenausgabe innerhalb, bswp. innerhalb
	von Schleifen
*/
static std::ostream& operator<<(std::ostream& os, const Node& node)
{
	os << " " << node.key << " ";
	return os;
}