#include "Stack.h"
#include <iostream>
#include <string>


/**
 *	Konvertierung und Ausgabe von arithmetischen Ausdrücken von der Infix- in die
 *  Postfix-Notation.
 *
 *	\param[in] infixExpression arithmetischer Ausdruck in Infix-Notation
 *  \pre Der übergebene Ausdruck muss eine korrekte Klammerung ausweisen
 */
void convertInfixToPostfixExpression(std::string infixExpression) {
	/*
		TODO: Übung 2 - Aufgabe 5 
	*/
}

/**
 * Funktion zum Auswerten von arithmetischen Ausdrücken
 *
 * \param[in] expression Der arithmetische Ausdruck der ausgewertet werden soll
 * 
 * \pre Der arithmetische Ausdruck muss gültig sein, d.h.
 *		- richtige Klammerung
 *		- nur Zahlen < 10 (oder Sonderbehandlung einführen)
 */
int evaluateArithmeticExpressions(std::string expression) {
	/*
		TODO: Übung 2 - Aufgabe 2
	*/
}


int main(int argc, char *argv[]) {
	// damit Umlaute in der Konsole angezeigt werden
	std::locale::global(std::locale("German_germany"));

	Stack myStack(7);
	myStack.push(15);
	myStack.push(6);
	myStack.push(2);
	myStack.printAll();
	int element = 17;
	std::cout << "Insert Element " << element << std::endl;
	myStack.push(element);
	element = 3;
	std::cout << "Insert Element " << element << std::endl;
	myStack.push(element);
	myStack.printAll();
	int x = myStack.pop();
	std::cout << "Entnommenes Element vom Stapel = " << x << std::endl;
	myStack.printAll();


	std::cout << "\nAufgaben zum Thema Stack" << std::endl;
	
	// Übung 2 - Aufgabe 2
	/* 
		Auswertung arithmetischer Ausdrücke
	*/
	std::string expression = "(1 + ((2+3)*(4*5)))";
	std::cout << "\nAuswertung arithmetischer Ausdrücke: " << std::endl;
	std::cout << "Austruck: " << expression << std::endl;
	
	// TODO: evaluateArithmeticExpressions(...) implementieren
	std::cout << "Ergebnis: " << evaluateArithmeticExpressions(expression) << std::endl;
	


	// Übung 2 - Aufgabe 3
	/*	
		Stapel S sei als Array mit 6 Feldelementen
		implementiert.Zeigen Sie den Arrayinhalt, wenn nach
		der Reihe die folgenden Operationen ausgeführt
		werden : PUSH(S, 4), PUSH(S, 1), PUSH(S, 3), POP(S),
		PUSH(S, 8), POP(S).
	*/

	// TODO


	// Übung 2 - Aufgabe 5
	/*	
		Wandeln Sie arithmetische Ausdrücke mit einem Stapel
		von der Infix - zur Postfix - Notation um.Operatoren auf
		den Stapel, (überlesen, ) Operator vom Stapel,
		Operanden direkt ausgeben.Bsp: 
		(a + (b + c))  -->	abc++
		(a + ((b * c) * (d - e))) --> abc * de-*+
	*/
	std::cout << "\nUmwandlung von Ausdrücken von der Infix- in die Postfix-Notation" << std::endl;
	//TODO: convertInfixToPostfixExpression(...) implementieren
	convertInfixToPostfixExpression("(a + (b + c))");

	return 0;
}