#include <iostream>
#include "FixedCapacityStackOfStrings.h"
using namespace std;

FixedCapacityStackOfStrings::FixedCapacityStackOfStrings(int capacity)
{
	s = new string[capacity];
	stack_capacity = capacity;
	N = 0;
}

FixedCapacityStackOfStrings::~FixedCapacityStackOfStrings()
{

	delete[] s;
}

bool FixedCapacityStackOfStrings::isEmpty()
{
	return N == 0;
}

bool FixedCapacityStackOfStrings::isFull()
{
	return N == stack_capacity;
}

void FixedCapacityStackOfStrings::push(string item)
{
	// vor 1f: s[N++] = item;
	// nach 1f:
	if (isFull()) {
		cout << "Stack wird vergroessert!" << endl;
		resize(2 * stack_capacity);
	}
	cout << "s[" << N << "]=" << item << " eingefuegt." << endl;
	s[N++] = item;

}

string FixedCapacityStackOfStrings::pop()
{
	// vor 1f: return s[--N];
	// nach 1f:
	if (!isEmpty()) return s[--N];
	else {
		cout << "Stapel ist leer! Es kann kein Element entnommen werden";
		return "error";
	}
}

void FixedCapacityStackOfStrings::print() {
	// Stapelinhalt ausgeben
	// Array-Index vom obersten Element? N-1
	// Array-Index vom �ltesten Element? 0
	// gebe alle Arrayelemente von s[n-1] bis s[0] aus (von top nach bottom)
	// Ausgabe nach dem LIFO-Prinzip von top nach bottom
	for (int i = N - 1; i >= 0; i--) {
		cout << "s[" << i << "]=" << s[i] << endl;
	}
}

// private Methode
void FixedCapacityStackOfStrings::resize(int length) {
	// wenn das Array voll belegt ist
	// 1. neues erzeugen mit der L�nge length, wobei length >> N
	string* s2 = new string[length];

	// 2. kopieren der Werte vom alten Array in das neue Array
	for (int i = 0; i < N; i++)
	{
		s2[i] = s[i];
	}
	// 3. altes Array l�schen
	delete[] s;
	
	// 4. neue Array der DS verf�gbar machen
	s = s2;

	// 5. neue Gr��e merken
	stack_capacity = length;
}
// Aufgabe 1e: Wie kann es zu einem Array-�berlauf und Array-Unterlauf kommen?
// Ein Array-�berlauf kann passieren, wenn ein neues Element bei einem vollen Stapel eingef�gt wird.
// Das wird nun innerhalb der Methode push durch dynamische Vergr��erung des Arrays erreicht durch die Methode resize. 
// Das geht theoretisch soweit wie Speicher vorhanden ist. Der Client bekommt dies nicht mit.
// Ein Array-Unterlauf kann passieren, wenn die pop-Methode dies nicht abf�ngt und auf einen negativen Feldindex zugegriffen wird.

// Aufgabe 1g
string FixedCapacityStackOfStrings::peek() {
	if (!isEmpty()) return s[N-1];
	else {
		cout << "Stapel ist leer! Kein Element ist im Stapel enthalten." << endl;
		return "error";
	}
}