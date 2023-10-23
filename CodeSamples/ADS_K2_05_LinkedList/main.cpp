#include "LinkedList_v1.h"
#include "LinkedList_v2.h"
#include "LinkedList_Queue.h"
#include "LinkedList_Stack.h"
#include <iostream>

void dequeueAndPrint(LinkedList_Queue& queue) {
	Node dequeueElem;
	bool valid = queue.dequeue(dequeueElem);
	std::cout << "Element aus Queue entnehmen (queue.dequeue()) - ";
	if (valid)	std::cout << dequeueElem << std::endl;
	else		std::cout << "FEHLER: Queue ist leer" << std::endl;
	queue.print();
}

void popAndPrint(LinkedList_Stack& stack) {
	Node popElem;
	bool valid = stack.pop(popElem);
	std::cout << "Oberstes Element aus dem Stack entnehmen (stack.pop(..)) - ";
	if (valid)	std::cout << popElem.key << std::endl;
	else		std::cout << "FEHLER: Stack ist leer" << std::endl;
	stack.print();
}

void main(int argc, char* argv[]) {
	std::locale::global(std::locale("German_germany"));
	// Verkettete Liste anlegen
	//LinkedList_v1 list;
	LinkedList_v2 list;

	// Elemente in die Liste hinzufügen
	list.insert(5);
	list.insert(1);
	list.insert(4);
	list.insert(6);
	list.insert(7);
	// Liste ausgeben und Elemente Löschen
	list.print();
	std::cout << std::boolalpha << "Listenanfang löschen (list.remove(5)): " << list.remove(5) << std::endl;
	list.print();
	std::cout << "Element in der Mitte löschen (list.remove(4)): " << list.remove(4) << std::endl;
	list.print();
	std::cout << "Listenende löschen (list.remove(7)): " << list.remove(7) << std::endl;
	list.print();
	std::cout << "Nicht vorhandenes Element löschen (list.remove(42)): " << list.remove(42) << std::endl;
	list.print();
	std::cout << "Listenelement suchen (list.search(4)): " << list.search(4) << std::endl;

	std::cout << "\nAnwendungsbeispiel: verkettete Liste als Queue" << std::endl;
	std::cout << "Einreihen von: 4, 6, 0, 1, 2 " << std::endl;
	LinkedList_Queue queue;
	queue.enqueue(4);
	queue.enqueue(6);
	queue.enqueue(0);
	queue.enqueue(1);
	queue.enqueue(2);
	dequeueAndPrint(queue);
	dequeueAndPrint(queue);
	dequeueAndPrint(queue);
	dequeueAndPrint(queue);
	dequeueAndPrint(queue);
	dequeueAndPrint(queue);

	std::cout << "\nAnwendungsbeispiel: verkettete Liste als Stack" << std::endl;
	std::cout << "Elemente auf dem Stack ablegen: 4, 5, 1, 0" << std::endl;
	LinkedList_Stack stack;
	stack.push(4);
	stack.push(5);
	stack.push(1);
	stack.push(0);
	stack.print();
	popAndPrint(stack);
	popAndPrint(stack);
	popAndPrint(stack);
	popAndPrint(stack);
	popAndPrint(stack);

	system("PAUSE");
}