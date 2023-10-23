#pragma once

#include <vector>
#include <iostream>

class PQHeapItem {
public:
	int prio;
	int data;
	bool operator <(const PQHeapItem& item) const {
		return prio < item.prio;
	}
};

std::ostream& operator<<(std::ostream& os, const PQHeapItem& item)
{
	os << "( " << item.prio << ", " << item.data << " )";
	return os;
}


// Implementierung des Heaps nach Vorlage von
// Mark Allen Weis - Data Structures and Algorithm Analysis in C++
 
template <typename T>
class PriorityQueueHeap
{
private: 
	std::vector<T>	array;			// Daten Array
	size_t			currentSize;	// aktuelle Größe es Heaps
	void buildHeap();				// Heap erstellen (wenn dem Konstruktor Daten übergeben werden)
	void percolateDown(int hole);	// Durchsickern den entstandenen Lochs (nach entnahme des Minimums)

public:
	explicit PriorityQueueHeap(int capacity = 100);			// Konstruktor
	explicit PriorityQueueHeap(std::vector<T> const& items);// Konstruktor für bereits existierende Daten
	~PriorityQueueHeap();									// Destruktor
	bool isEmpty() const;			// Abfrage ob der Heap leer ist
	const T& findMin() const;		// Minimum im Heap finden
	void insert(const T& x);		// neues Element im Heap einfügen
	void deleteMin();				// Minimum im Heap löschen
	void deleteMin(T& minElement);	// Minimum im Heap löschen und das Element zurückgeben (per Referenz)
	void print();					// einfache Ausgabe als Array
};



template<typename T>
PriorityQueueHeap<T>::PriorityQueueHeap(int capacity) :
	currentSize{ 0 }
{
	array.resize(capacity);
}

template<typename T>
PriorityQueueHeap<T>::PriorityQueueHeap(std::vector<T> const& items) :
	array{ items.size() + 10 },
	currentSize{ items.size() }
{
	for (int i = 0; i < items.size(); i++) {
		array[i + 1] = items[i];
	}
	buildHeap();
}

template<typename T>
PriorityQueueHeap<T>::~PriorityQueueHeap()
{
}

template<typename T>
void PriorityQueueHeap<T>::buildHeap()
{
	for (int i = currentSize / 2; i > 0; i--) {
		percolateDown(i);
	}
}

template<typename T>
void PriorityQueueHeap<T>::percolateDown(int hole)
{
	int child;
	T tmp = array[hole];

	for (; hole * 2 <= currentSize; hole = child) {
		child = hole * 2;
		if (child != currentSize && array[child + 1] < array[child])
			child++;
		if (array[child] < tmp)
			array[hole] = array[child];
		else
			break;
	}
	array[hole] = tmp;
}

template<typename T>
bool PriorityQueueHeap<T>::isEmpty() const
{
	return currentSize == 0;
}

template<typename T>
const T& PriorityQueueHeap<T>::findMin() const
{
	return array[0];
}

template<typename T>
void PriorityQueueHeap<T>::insert(const T& x)
{
	if (currentSize == array.size() - 1) {
		array.resize(array.size() * 2);
	}
	// Percolate up
	int hole = ++currentSize;
	for (; hole > 1 && x < array[hole / 2]; hole /= 2) {
		array[hole] = array[hole / 2];
	}
	array[hole] = x;
}

template<typename T>
void PriorityQueueHeap<T>::deleteMin()
{
	if (isEmpty()) {
		// underflow
	}
	else {
		array[0] = array[currentSize--];
		percolateDown(0);
	}
}

template<typename T>
void PriorityQueueHeap<T>::deleteMin(T& minElement)
{
	if (isEmpty()) {
		// underflow
	}
	else {
		minElement = array[0];
		array[0] = array[currentSize--];
		percolateDown(0);
	}
}

template<typename T>
void PriorityQueueHeap<T>::print()
{
	std::cout << "\nPQHeap( ";
	for (auto it = array.begin() + 1; it != array.begin() + currentSize+1; it++) {
		std::cout << *it << " ";
	}
	std::cout << " )" << std::endl;
}