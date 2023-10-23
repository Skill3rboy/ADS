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
	// TODO:


}

Queue::~Queue() {
	delete[] Q;
}

bool Queue::isEmpty() {
	// TODO

}

bool Queue::isFull() {
	// TODO
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
	// TODO
}

void Queue::resizeQueue() {
	// TODO: optional
	// Bitte testen Sie diese Methode: Falls beim enqueue die Queue voll wird, soll die Queue
	// doppelt so viele Elemente aufnehmen können, dh. testen bei der enqueue-Methode
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