#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "hashitem.h"

class Hashmap
{
private:
	//Attribute
	std::vector<std::vector<Hashitem*>> table;
	unsigned occupied = 0;
	double maxAllowedOccupancy;
	bool entriesMustBeUnique = false;
	int maxLengthOfInnerVector;

	// Berechnungs Funktionen
	unsigned int calcKeyvalue(Hashitem* hi);
	double calcOccupancy();
	unsigned int calcNextPrimeNumber(unsigned int startingPos, bool countDown = false);

	//Sonnstige Methoden
	void rehashing();
	unsigned int standardHashFunction(unsigned int key);
	bool addIntoTable(unsigned int pos, Hashitem* hitem);
	std::vector<Hashitem*>* getInnerVector(unsigned at);	

public:
	// Konstruktur
	Hashmap(int startsize = 19, double maxAllowedOccupancy = 0.66666667, int maxLengthOfInnerVector = 3);
	
	//Zugriffsfunktionen
	bool addItem(Hashitem* newItem, unsigned int* keyOfObjekt = nullptr);
	Hashitem* getItem(unsigned int key, unsigned int * finalInnerPos = nullptr, unsigned int* finalOuterPos = nullptr);
	Hashitem* eraseItem(unsigned int key);
	bool deleteItem(unsigned int key);
	
	// Hilfsmethoden zur Ausgabe
	void printOccupancy();
	void printTable();
};

