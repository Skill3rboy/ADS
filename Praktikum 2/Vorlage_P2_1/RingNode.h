/*************************************************
 * ADS Praktikum 2.1
 * RingNode.h
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#pragma once
#include <string>
#include <iostream>
class RingNode
{

private:
	// Ihr Code hier:
	int oldAge = 0;
	std::string beschreibung;
	std::string symbolicData;
	RingNode *next = nullptr;
	//
public:
	// Ihr Code hier:
	// Konstruktor
	RingNode();
	RingNode(int age, std::string beschreibung, std::string data) : oldAge(age), beschreibung(beschreibung), symbolicData(data) {}
	// getter
	int getOldAge();
	std::string getDescription();
	std::string getSymbolicData();
	RingNode *getNext();

	// setter
	void setAge(int age);
	void setDescription(std::string beschreibung);
	void setSymbolicData(std::string data);
	void setNext(RingNode *next);
	// Zusatz methoden
	void print();
	//
};