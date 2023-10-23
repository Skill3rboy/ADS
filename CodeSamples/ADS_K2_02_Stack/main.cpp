#include "Stack.h"
#include <iostream>
#include <string>


/**
 *	Konvertierung und Ausgabe von arithmetischen Ausdr�cken von der Infix- in die
 *  Postfix-Notation.
 *
 *	\param[in] infixExpression arithmetischer Ausdruck in Infix-Notation
 *  \pre Der �bergebene Ausdruck muss eine korrekte Klammerung ausweisen
 */
void convertInfixToPostfixExpression(std::string infixExpression) {
	/*
		TODO: �bung 2 - Aufgabe 5 
	*/
}

/**
 * Funktion zum Auswerten von arithmetischen Ausdr�cken
 *
 * \param[in] expression Der arithmetische Ausdruck der ausgewertet werden soll
 * 
 * \pre Der arithmetische Ausdruck muss g�ltig sein, d.h.
 *		- richtige Klammerung
 *		- nur Zahlen < 10 (oder Sonderbehandlung einf�hren)
 */
int evaluateArithmeticExpressions(std::string expression) {
	/*
		TODO: �bung 2 - Aufgabe 2
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
	
	// �bung 2 - Aufgabe 2
	/* 
		Auswertung arithmetischer Ausdr�cke
	*/
	std::string expression = "(1 + ((2+3)*(4*5)))";
	std::cout << "\nAuswertung arithmetischer Ausdr�cke: " << std::endl;
	std::cout << "Austruck: " << expression << std::endl;
	
	// TODO: evaluateArithmeticExpressions(...) implementieren
	std::cout << "Ergebnis: " << evaluateArithmeticExpressions(expression) << std::endl;
	


	// �bung 2 - Aufgabe 3
	/*	
		Stapel S sei als Array mit 6 Feldelementen
		implementiert.Zeigen Sie den Arrayinhalt, wenn nach
		der Reihe die folgenden Operationen ausgef�hrt
		werden : PUSH(S, 4), PUSH(S, 1), PUSH(S, 3), POP(S),
		PUSH(S, 8), POP(S).
	*/

	// TODO


	// �bung 2 - Aufgabe 5
	/*	
		Wandeln Sie arithmetische Ausdr�cke mit einem Stapel
		von der Infix - zur Postfix - Notation um.Operatoren auf
		den Stapel, (�berlesen, ) Operator vom Stapel,
		Operanden direkt ausgeben.Bsp: 
		(a + (b + c))  -->	abc++
		(a + ((b * c) * (d - e))) --> abc * de-*+
	*/
	std::cout << "\nUmwandlung von Ausdr�cken von der Infix- in die Postfix-Notation" << std::endl;
	//TODO: convertInfixToPostfixExpression(...) implementieren
	convertInfixToPostfixExpression("(a + (b + c))");

	return 0;
}