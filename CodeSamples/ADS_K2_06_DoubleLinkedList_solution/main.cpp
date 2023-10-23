#include "DoublyLinkedList.h"

#include <iostream>

int main() {
	std::locale::global(std::locale("German_germany"));
	
	std::cout << "Doppelt verkettete Liste anlegen und mit Elementen (4, 3, 7, 9, 8, 5) füllen:" << std::endl;
	DoublyLinkedList list;
	list.insert(4);
	list.insert(3);
	list.insert(7);
	list.insert(9);
	list.insert(8);
	list.insert(5);
	list.print();
	std::cout << std::boolalpha;
	std::cout << "Listenanfang löschen (list.erase(5)) - " << list.erase(5) << std::endl;
	list.print();
	std::cout << "mittleres Element löschen (list.erase(7)) - " << list.erase(7) << std::endl;
	list.print();
	std::cout << "Listenende löschen (list.erase(4)) - " << list.erase(4) << std::endl;
	list.print();
	std::cout << "Element (42) suchen (list.search(42)) - " << list.search(42) << std::endl;

	std::cout << std::endl << "Sortieren von doppelt verketteten Listen: " << std::endl;
	DoublyLinkedList list2;
	list2.insert(10);
	list2.insert(1);
	list2.insert(9);
	list2.insert(5);
	list2.insert(8);
	list2.insert(4);
	list2.insert(6);
	list2.insert(7);
	list2.insert(3);
	list2.insert(2);
	list2.print();
	//list2.insertionSort();
	list2.selectionSort();
	list2.print();

	std::cout << std::endl;
	DoublyLinkedList list3;
	list3.insert(1);
	list3.insert(2);
	list3.insert(3);
	list3.insert(4);
	list3.insert(5);
	list3.insert(6);
	list3.insert(7);
	list3.insert(8);
	list3.insert(9);
	list3.insert(10);
	list3.print();
	//list3.insertionSort();
	list3.selectionSort();
	list3.print();
	
	std::cout << std::endl;
	DoublyLinkedList list4;
	list4.insert(10);
	list4.insert(9);
	list4.insert(8);
	list4.insert(7);
	list4.insert(6);
	list4.insert(5);
	list4.insert(4);
	list4.insert(3);
	list4.insert(2);
	list4.insert(1);
	list4.print();
	//list4.insertionSort();
	list4.selectionSort();
	list4.print();

	system("PAUSE");
	return 0;
}
