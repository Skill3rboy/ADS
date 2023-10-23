#include "Queue.h"

#include <iostream>

int main() {
	
	// Übungsaufgaben: Warteschlangen
	Queue Q(9);
	Q.enqueue(4);
	Q.enqueue(1);
	Q.enqueue(3);
	Q.enqueue(3);
	Q.enqueue(3);
	Q.enqueue(3);
	Q.enqueue(3);
	Q.enqueue(3);
	Q.enqueue(3);

	Q.dequeue();
	Q.enqueue(8);
	Q.dequeue(); 
	std::cout << "Anzahl Elemente in der Queue\n";
	std::cout << "\tQueue.getSize() : " << Q.getSize() << std::endl;
	std::cout << "\tQueue.calcSize() : "<< Q.calcSize();

}