#include <iostream>
#include "Queue.h"
using namespace std;

// Übungsblatt 2 Aufgabe 1

// Client-Programm
int main() {

	int item;
	Queue q(5); // erzeugt Array mit 6 Feldelementen
	q.enqueue(4); q.printAll();
	q.enqueue(1); q.printAll();
	q.enqueue(3); q.printAll();
	item = q.dequeue(); q.printAll();
	q.enqueue(8); q.printAll();
	q.dequeue(); q.printAll();

	cout << "Aktuelle Anzahl Elemente in der Queue: " << q.size() << endl;
	q.printAll();

	// Queue solange mit Werten füllen, bis diese voll ist
	item = 20;
	while (!q.isFull()) {
		q.enqueue(item); q.printAll();
		item++;
	}
	cout << "Queue ist voll. Folgende Elemente sind drin enthalten:" << endl;
	q.printAll();
	cout << "Ein weiteres Element (4) wird hinzugefuegt und die Queue wird mittels der resize-Methode vergroessert." << endl;
	q.enqueue(4);
	q.printAll();
	// Entnehme alle Elemente aus der Queue, bis diese leer ist
	cout << "Entnehme folgende Elemente bis Queue leer ist: ";
	while (!q.isEmpty()) {
		cout << q.dequeue() << " ";
	}
	cout << endl << "Queue ist nun leer: " <<std::boolalpha << q.isEmpty() << endl;

	cout <<endl <<"Hinzufuegen von Elementen bis Queue wieder voll ist" << endl;
	while (!q.isFull()) {
		q.enqueue(rand() % 100);
	}
 	q.printAll();

	cout << endl << "Entfernen von 5 Elementen und Einfuegen von zwei Elementen" << endl;
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.enqueue(rand() % 100);
	q.enqueue(rand() % 100);
	q.printAll();

	return 0;
}