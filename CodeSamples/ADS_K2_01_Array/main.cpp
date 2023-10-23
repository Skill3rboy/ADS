#include <array>
#include <iostream>
#include <array>
#include <vector>

int main() {

	// Allokiere und initialisiere 8 int-Objekte
	int myArray[] = { 12, 15, 17, 35, 39, 47, 78, 83 };

	/*
	Alternativen für die Erstellung von Arrays in C++:

	Der Vorteil bei der Verwendung von Containern aus der
	C++ Standard Template Library (STL) besteht in der 
	Vielzahl zusätzlicher Funktionaliäten:
	* Iteratoren
	* Funktionen wie bswp. size()
	* Algorithmen aus der STL Libary können einfacher angewendet werden

	Einige dieser Funktionalitäten werden Sie erst innerhalb des 
	Kureses ADS erlernen und im Praktikum dürfen sich nicht immer 
	alles verwenden. Behalten Sie die Existenz der STL-Bibliothek
	aber im Hinterkopf.

	https://en.cppreference.com/w/cpp/container
	*/
	std::array<int, 8> myStlArray { 12, 15, 17, 35, 39, 47, 78, 83 }; //Nachteil: Die Größe ist wie bei einem Array fest.
	std::vector<int> myVector { 12, 15, 17, 35, 39, 47, 78, 83 };     //Vorteil: Größe kann dynamisch angepasst werden.


	// Feldlaenge bestimmen
	const int myArrayLength = (int) sizeof(myArray) / sizeof(myArray[0]);
	// Zugriff auf 3. Element
	int drittesElement = myArray[2];
	// Zugriff mit Zeigern bzw. ueber Adressen
	int *p1 = myArray;
	int *p2 = &myArray[0];	// Zeiger auf 1. Feldelement = p1
	int *p5 = p1 + 4;		// Zeiger auf das 5. Feldelement
	int feldElement = *p5;	// Inhalt vom Zeiger p5, hier 39

	// Ausgabe von allen Feldelementen
	for (int i = 0; i < myArrayLength; i++) {
		std::cout << "myArray-Element " << i << ": " << *p1 << std::endl;;
		p1++;
	}

	// Zeiger in C++
	int v = 5;
	int *p = &v; // p enthaelt Adresse von v
	int v2 = *p; // v2 enthaelt den Inhalt von der Adresse p,
				 // hier v2 == 5

	int a[4] = { 0, 1, 2, 3 }; 
	int *ip;
	int i;
	for (i = 0; i < 4; i++) std::cout << a[i] << " ";
	std::cout << std::endl;
	ip = a;
	for (i = 0; i < 4; i++) std::cout << *ip++ << " ";
	std::cout << std::endl;
	for (i = 0, ip = a; i < 4; i++, ip++) std::cout << *ip << " ";
	std::cout << std::endl;
	ip = &a[0]; /* entspricht ip = a; */
	for (i = 0; i < 4; i++) std::cout << ip[i] << " ";
	std::cout << std::endl;

}