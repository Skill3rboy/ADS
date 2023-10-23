#include <iostream>
#include <string>
#include "FixedCapacityStackOfStrings.h"
using namespace std;

// Musterloesung zum Uebungsblatt 1 - Aufgabe 1
// ============================================
// a) Schreiben Sie eine main - Methode, die einen Stapel instanziert, der maximal 5 Strings aufnehmen kann.
//    Fragen Sie zunächst ab, ob der Stapel leer ist und geben eine entsprechende Fehlermeldung aus.
//    Versuchen Sie, 6 Strings in den Stapel zu pushen und anschliessend den Stapel wieder 6 mal zu leeren.
// b) Schreiben Sie eine Methode isFull(), die überprüft, ob der Stapel voll ist.
// c) Schreiben Sie eine Methode print(), die den gesamten Inhalt des Stapels ausgibt.
// d) Fügen Sie auch eine Methode resize(int length) hinzu, die für den Stapel ein neues Array mit length Elementen anlegt, 
//    die Werte des Stapel - Arrays in das neue kopiert und die Referenz des neuen Arrays nun als Stapel - Array nutzt.
// e) Wie kann es hier zu einem Array - Überlauf und Array - Unterlauf kommen ?
// f) Modifizieren Sie die Methoden push und pop, so dass kein Überlauf oder Unterlauf auftreten kann.
// g) Schreiben Sie eine Methode peek(), die das zuletzt auf den Stapel gelegte Element zurückliefert, 
//    ohne es explizit zu löschen.

int main() {

	// Uebung 1 - Aufgabe 1a
	// Stapel erzeugen - Instanz mit maximal 5 Elemente soll der Stapel aufnehmen können
	FixedCapacityStackOfStrings myStack(5);

	if (myStack.isEmpty()) {
		cout << "Stapel ist leer!" << endl;
	}

	// 6 Strings in den Stapel legen
	if (!myStack.isFull()) myStack.push("1");
	if (!myStack.isFull()) myStack.push("2");
	if (!myStack.isFull()) myStack.push("3");
	if (!myStack.isFull()) myStack.push("4");
	if (!myStack.isFull()) myStack.push("5");
	if (!myStack.isFull()) myStack.push("6");
	else cout << "Stapel ist voll!" << endl;

	// Testen von Aufgabe 1d:
	// Methode resize testen (wird als private-Methode innerhalb von der Methode push aufgerufen)
	myStack.push("7");
	myStack.push("8");

	// Testen von Aufgabe 1c:
	cout << "Ausgabe des gesamten Stapels:" << endl;
	myStack.print();
	cout << endl;

	// Testen von Aufgabe 1g:
	cout << "Oberste Element vom Stapel ist: " << myStack.peek() << endl;

	// 6 Strings vom Stapel entnehmen
	string top;
	for (int i = 0; i < 6; i++) {
		if (!myStack.isEmpty()) {
			top = myStack.pop();
			cout << "Element " << top << " vom Stapel entnommen!" << endl;
		}
		else {
			cout << "Stapel ist leer - Entnahme nicht moeglich!" << endl;
		}
	}
	return 0;
	// Ende Aufgabe 1a

}