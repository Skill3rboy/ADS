#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "hashitem.h"
using namespace std;

enum class ProbingMethod : int { Linear = 1, Quadratic = 2, DoubleHashing = 3 };

class Hashtable
{
private:
	// Attribute
	vector<Hashitem*> table;
	unsigned occupied{ 0 };
	double maxAllowedOccupancy;
	ProbingMethod method;
	bool entriesMustBeUnique{ false };
	int maxCoalitionAllowed;
	
	// Hashfunktion
	void rehashing();	
	unsigned int standardHashFunction(unsigned int key) const;
	unsigned int secondHashFunction(unsigned int iteration, unsigned int key, unsigned int nextSmaller = 0);

	// Kollisionsbeseitigungsfunktionen (Add)
	bool linearProbing(Hashitem* newItem, unsigned int key, unsigned int iteration = 0);
	bool squareProbing(Hashitem* newItem, unsigned int key, unsigned int iteration = 0);
	bool doubleHasing(Hashitem* newItem, unsigned int key, unsigned int iteration = 0, unsigned int nextSmaller = 0);

	// Kollisionsbeseitigungsfunktionen (Get/Erase/Delete)
	Hashitem* linearProbingGetMode(unsigned int key, unsigned int pos, unsigned int iteration = 0, unsigned int* finalPos = nullptr);
	Hashitem* squareProbingGetMode(unsigned int key, unsigned int pos, unsigned int iteration = 0, unsigned int* finalPos = nullptr);
	Hashitem* doubleHasingGetMode(unsigned int key, unsigned int pos, unsigned int iteration = 0, unsigned int nextSmaller = 0, unsigned int* finalPos = nullptr);

	// Berechnungsfunktionen
	unsigned int calcKeyvalue(Hashitem* hi) const;
	double calcOccupancy() const;
	unsigned int calcNextPrimeNumber(unsigned int startingPos, bool countDown = false) const;

public:
	// Konstruktor
	Hashtable(ProbingMethod probingMethod, int startsize = 19, double maxAllowedOccupancy = 0.66666667, int maxCoalitionAloowed = 3);
	
	// Zugriffsfunktionen
	bool addItem(Hashitem* newItem, unsigned int* keyOfObjekt = nullptr);
	Hashitem* getItem(unsigned int key, unsigned int* posLocation = nullptr);
	Hashitem* eraseItem(unsigned int key);
	bool deleteItem(unsigned int key);
	
	// Hilfsmethoden zur Ausgabe
	void printOccupancy();
	void printTable();
};

