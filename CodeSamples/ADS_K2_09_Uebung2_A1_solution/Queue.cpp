#include <iostream>
#include "Queue.h"
using namespace std;

// Implementierung der Methoden aus der API Queue
// Umsetzung von Pseudocode aus Kapitel 2, Folien 26-29

Queue::Queue() {
		Q = new int[8];
		n = 8; // max. Anzahl
		head = 7; // Leseindex
		tail = 0; // Schreibindex
}

Queue::Queue(int capacity) {
	n = capacity + 1; // max. Anzahl, ACHTUNG: 1 Speicherplatz mehr wegen Unterscheidung von head und tail
	Q = new int[n];
	head = capacity; // Leseindex
	tail = 0; // Schreibindex
}

Queue::~Queue() {
	delete[] Q;
}

bool Queue::isEmpty() {
	if ((head + 1) % n == tail)
		return true;
	else
		return false;
}

bool Queue::isFull() {
	if (head == tail)
		return true;
	else
		return false;
}

bool Queue::enqueue(int item) {
	if (!isFull()) {
		Q[tail] = item;
		tail = (tail + 1) % n;
	}
	else {
		cout << "Queue ist voll und wird vergroessert" << endl;
		resizeQueue();
		Q[tail] = item;
		tail = (tail + 1) % n;
	}
	return true;
}

int Queue::dequeue() {
	if (!isEmpty()) {
		head = (head + 1) % n;
		return Q[head];
	}
	else {
		cout << "underflow error" << endl;
		return 0;
	}
}

int Queue::size() {
	// Die Elemente liegen im Ringpuffer zwischen dem Index (head+1)%n bis tail,
	// Diese Methode hat derzeit im Worst Case O(N) Aufwand. Kann immer konstant sein O(1), wenn eine
	// zusätzliche private Variable genutzt wird, die die aktuelle Anzahl der Queue-
	// Elemente beim enqueue und dequeue updatet.
	int currentNumber = 0;
	for (int i = (head + 1) % n; i < tail; i = (i + 1) % n) {
		currentNumber++;
	}
	return currentNumber;
}

void Queue::printAll() {
	// ältestes Element hat Index (head+1)%n, jüngstes Element hat Index tail
	cout << "Ausgabe der Queue nach FIFO-Prinzip:" << endl;
	for (int i = (head + 1) % n; i != tail; i = (i + 1) % n) {
		cout << "Q[" << i << "] = " << Q[i] << endl;
	}
	cout << endl;
}

void Queue::resizeQueue() {
	// TODO: Programmierung von Uebung 2 - Aufgabe 1

	// Bitte testen Sie diese Methode: Falls beim enqueue die Queue voll wird, soll die Queue
	// doppelt so viele Elemente aufnehmen können (s. Bsp. FixedCapacityStackOfStrings), dh.
	// testen bei der enqueue-Methode
	if (isFull()) {
		// neuen Speicher reservieren
		int* newQueue = new int[n*2];
		// Werte aus der Queue in neues Array übertragen und dabei das neue Array
		// von Anfang an befüllen.
		int idx = 0;
		for (int i = (head + 1) % n; i != tail; i = (i+1) % n) {
			newQueue[idx] = Q[i];
			idx++;
		}
		// Größe anpassen
		n = n * 2;
		// "altes" Array der Queue löschen
		delete[] Q;
		Q = newQueue;
		// head und tail neu setzen
		head = n - 1;
		tail = idx;
	}
	}