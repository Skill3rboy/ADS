/*************************************************
 * ADS Praktikum 2.1
 * Ring.h
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
// Ring .h
#pragma once
#include <string>
#include "catch.h"
#include "RingNode.h"

class Ring
{

private:
	// Ihr Code hier:
	int countNodes = 0;
	RingNode *anker = nullptr;
	void printR(RingNode *ptr);
	//
	////////////////////////////////////
public:
	// Ihr Code hier:
	// Konstruktor
	Ring();
	// getter
	// Methoden
	void addNewNode(std::string beschreibung, std::string data);
	bool search(std::string data);
	void print();

	// Zusatz Methoden
	RingNode *searchPtr(std::string data);
	//
	////////////////////////////////////
	// friend Funktionen müssen unangetastet bleiben!
	friend RingNode *get_anker(Ring &r);
	friend int get_countNodes(Ring &r);
};
