#pragma once
// API Queue 

// Datenstruktur Queue als Ringpuffer
// siehe Kapitel 2, Folie 29
class Queue
{
private:
	int* Q;
	int n; // Array-Groesse
	int head; // Leseposition
	int tail; // Schreibposition
	void resizeQueue(); // Verändere die Größe der Queue
public:
	Queue(); // Konstruktur: erzeugt leere Warteschlange
	Queue(int capacity); // Konstruktor, der n Elemente in einer Warteschlange aufnehmen kann
	~Queue(); // Destruktor: gibt Speicherplatz frei
	bool enqueue(int item); // Fuegt Element hinzu
	int dequeue(); // Entfernt ein Element
	bool isEmpty(); // Abfrage, ob Queue leer
	bool isFull();  // Abfrage, ob Queue voll ist
	int size(); // Aktuelle Anzahl Elemente in der Queue
	void printAll(); // schreibt alle Queueelemente nach dem FIFO-Prinzip heraus
};


