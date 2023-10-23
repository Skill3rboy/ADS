#pragma once

using Item = int;			// Item als alias für integer

// Datenstruktur Warteschlange implementiert mit einem Array als Ringpuffer
class Queue {
private:
	Item*	Q;				// Daten-Array der Queue
	int		n;				// Array-Größe
	int		tail;			// Schreibposition
	int		head;			// Leseposition
	int		size;			// Anzahl der aktuellen Elemente in der Queue
public:
	Queue(int capacity=8);  // Konstruktor mit default-Argument für die Kapazität
	~Queue();				// Destruktor: gibt Speicherplatz frei
	void enqueue(Item item);// Füge Element hinzu 
	Item dequeue();			// Entfernt ein Element
	bool isEmpty();			// Abfrage, ob Queue leer
	bool isFull();			// Abfrage, ob Queue voll
	int	 getSize();			// Liefert aktuelle Anzahl Elemente in Queue
	int  calcSize();		// Berechnet aktuelle Anzahl Elemente in Queue (ohne Verwendung von dem Member size) 
};