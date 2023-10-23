#pragma once
#include <string>
using namespace std;

class FixedCapacityStackOfStrings
{
private: 
	string* s; // Array von Strings als Stapel
	int N;     // Anzahl Elemente im Stapel
	int stack_capacity;  // maximale Anzahl Strings im Array s
	void resize(int length); // (Aufgabe 1d)
public: 
	FixedCapacityStackOfStrings(int capacity); // Konstruktor
	~FixedCapacityStackOfStrings();			   // Destruktor
	bool isEmpty(); // Abfragemethode, ob der Stapel leer ist
	bool isFull(); // Abfragemethode, ob der Stapel voll ist (Aufgabe 1b)
	void push(string item); // ein String auf den Stapel legen
	string pop();           // Entnahme eines Strings vom Stapel
	void print(); // Ausgabe des gesamten Stapelinhalts (Aufgabe 1c)
	string peek(); // liefert das oberste Stapelelement ohne Löschen (Aufgabe 1g)
};

