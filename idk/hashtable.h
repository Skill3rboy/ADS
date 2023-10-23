#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include <vector>
#include <math.h>

using namespace std;

class HashTable
{
public:
	HashTable(int size, double threshold = 0.6); // Konstruktor
	~HashTable();								 // Destruktor
	int insert(int item);						 // f�gt ein Element der Hashtabelle hinzu
	int at(int i);								 // Liefert das i-te Element der Hashtabelle zur�ck
	int getCollisionCount();					 // Liefert die Anzahl der Kollisionen zur�ck
	int getSize();								 // Liefert die Gr��e der Hashtabelle zur�ck
	int getElements();							 // Liefert die Anzahl der Elemente der Hashtabelle zur�ck
	void print();								 // Ausgabe der Hashtable ind er Form:
												 // [0] -> 1
												 //  .....
private:
	int size;					// Gr��e der HashTable
	int elements;				// Anz. d. Elemente in HashTable
	int collisionCount;			// Anz. d. Kollisionen beim Einf�gen
	double threshold_rehashing; // Schwellwert f�rs rehashing (size/elements)
	vector<int> *hashTable;		// HashTable
	int hashValue(int item);	// calculate hash value
	void rehashing();			// rehashing
};

// Helper Funktion:
int get_next_Prime(int a); // Gibt zu einer natuerlichen Zahl a, die n�chstgr��ere Primzahl zur�ck

#endif