#include "Queue.h"
#include <iostream>

//Queue::Queue(int capacity) {
//	n = capacity+1;		// Anzahl der Elemetne
//	Q = new Item[n];	// Array für Daten
//	head = n - 1;		// Leseindex
//	tail = 0;			// Schreibindex
//	size = 0;			// Anzal der Elemente
//  Elemente gehen von (head+1)%n bis tail, wobei tail selbst nicht belegt ist
//}

// alternative/modern constructor
Queue::Queue(int capacity) :
	n{capacity+1}, 
	tail{0},
	head{n-1},
	size{0}
{
	Q = new Item[n];
}

Queue::~Queue() {
	delete[] Q;
}

void Queue::enqueue(Item item) {
	if (!isFull()) {
		Q[tail] = item;
		tail = (tail + 1) % n;
		size++;
	} else {
		std::cerr << "ERROR: function call Queue::enqueue(Item item) causes overflow" << std::endl;
	}
}

Item Queue::dequeue() {
	if (!isEmpty()) {
		head = (head + 1) % n;
		size--;
		return Q[head];
	} else {
		std::cerr << "ERROR: function call Queue::dequeue() causes underflow" << std::endl;
		return Item();
	}
}

bool Queue::isEmpty() {
	if ((head + 1) % n == tail) return true;
	else return false;
}

bool Queue::isFull()
{
	if (head == tail)	 return true;
	else return false;
}

/*
	Liefert die Länge der Queue mittels 
	Member Variable size
*/
int Queue::getSize() {
	return size;
}

/*
	Berechnet die Länge der Queue
*/
int Queue::calcSize()
{
	int size;
	if (tail <= head) 
		size = n - head + tail - 1;
	else
		size = tail - head - 1;
	return size;
}
