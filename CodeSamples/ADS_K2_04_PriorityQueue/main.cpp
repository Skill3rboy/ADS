#include "PriorityQueueArray.h"
#include "PriorityQueueList.h"
#include "PriorityQueueHeap.h"
#include <iostream>

int main (int argc, char* argv[]) {
	std::locale::global(std::locale("German_germany"));
	const unsigned capacity = 8;

	// -----------------------------------------------------------------
	// Priority Queue auf Basis eines Arrays 
	PriorityQueueArray PQArray(capacity);
	PQArray.push_front(PQItem{ 26, 6});
	PQArray.push_front(PQItem{ 34, 99 });
	PQArray.push_front(PQItem{ 26, 4 });
	PQArray.push_front(PQItem{ 23, 2 });
	PQArray.push_front(PQItem{ 12, 1 });
	PQArray.push_front(PQItem{ 43, 7 });
	PQArray.push_front(PQItem{ 23, 9 });
	PQArray.print();

	auto maxElem = PQArray.pop_max();
	std::cout << "Element mit höchster Priorität entnehmen: PQItem( " << maxElem.prio << " , " << maxElem.data << ")" << std::endl << std::endl;
	PQArray.print();
	maxElem = PQArray.pop_max();
	std::cout << "Element mit höchster Priorität entnehmen: PQItem( " << maxElem.prio << " , " << maxElem.data << ")" << std::endl << std::endl;
	PQArray.print();
	std::cout << "\nNeues PQItem(24, 3) in PQArray einfügen" << std::endl;
	PQArray.push_front(PQItem{ 24, 3 });
	PQArray.print();
	std::cout << std::endl;

	// -----------------------------------------------------------------
	// Priority Queue auf Basis einer verketteten Liste

	PriorityQueueList PQList;
	PQList.push_front(4, 7);
	PQList.push_front(3, 8);
	PQList.push_front(1, 1); // Einfügen am Listenanfang
	PQList.push_front(3, 4);
	PQList.print();
	auto maxNode = PQList.pop_max();
	std::cout << "Element mit höchster Priorität entnehmen: PQNode( " << maxNode.prio << " , " << maxNode.data << ")" << std::endl << std::endl;
	PQList.print();


	// -----------------------------------------------------------------
	// Priority Queue auf Basis eines Min-Heaps
	PriorityQueueHeap<PQHeapItem> PQHeap;
	PQHeap.insert(PQHeapItem{ 21, 12 });
	PQHeap.insert(PQHeapItem{ 16,  0 });
	PQHeap.insert(PQHeapItem{ 13, 17 });
	PQHeap.insert(PQHeapItem{ 24, 14 });
	PQHeap.insert(PQHeapItem{ 31, 32 });
	PQHeap.insert(PQHeapItem{ 19, 32 });
	PQHeap.insert(PQHeapItem{ 68, 32 });
	PQHeap.insert(PQHeapItem{ 65, 32 });
	PQHeap.insert(PQHeapItem{ 26, 32 });
	PQHeap.insert(PQHeapItem{ 32, 38 });
	// Heap ausgeben
	PQHeap.print();
	// minimales Element suchen
	std::cout << "Element mit höchster Priorität ist: PQHeapItem" << PQHeap.findMin() << std::endl;
	// minimales Element entnehmen
	PQHeapItem item;
	PQHeap.deleteMin(item);
	std::cout << "Element mit höchster Priorität entnehmen: PQHeapItem" << item << std::endl;
	PQHeap.print();
	PQHeap.deleteMin(item);
	std::cout << "Element mit höchster Priorität entnehmen: PQHeapItem" << item << std::endl;
	PQHeap.print();
	
	system("PAUSE");
	return 0;
}