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
	std::cout << "Ausdruck in Infix-Notation: " << infixExpression << std::endl;
	std::cout << "Ausdruck in Postfix-Notation: ";
	Stack stack;
	for (auto const& c : infixExpression) {
		// linke Klammern und Leerzeichen ignorieren
		if (c == '(' || c == '{' || c == '[' || c == ' ') continue;
		// Operatoren auf dem Stack ablegen
		else if (c == '+' || c == '*' || c == '-' || c == '/') {
			stack.push(c);
		}
		// letzten Operanden Ausgeben
		else if (c == ')' || c == '}' || c == ']') {
			// Annahme: Ausdruck ist gültig und somit der Stack nicht leer
			std::cout << char(stack.pop());
		}
		else {
			std::cout << c;
		}
	}
	std::cout << std::endl;
}

/**
 * Funktion zum Auswerten von arithmetischen Ausdrücken
 *
 * \param[in] expression Der arithmetische Ausdruck der ausgewertet werden soll
 * 
 * \pre Der arithmetische Ausdruck muss gültig sein, d.h.
 *		- richtige Klammerung
 *		- nur Zahlen < 10
 */
int evaluateArithmeticExpressions(std::string expression) {
	//GenericStack<int>  OperandStack;	// Stack für Operanden  (Zahl1, Zahl2, ... , ZahlN)
	//GenericStack<char> OperatorStack;	// Stack für Operatoren ( +, -, *, /)

	Stack OperandStack;		// Stack für Operanden  (Zahl1, Zahl2, ... , ZahlN)
	Stack OperatorStack;	// Stack für Operatoren ( +, -, *, /)

	for (auto const& c: expression) {
		// linke Klammern ignorieren
		if (c == '(' || c == '{' || c == '[' || c == ' ') continue;
		// Element ist ein Operand
		if (isdigit(c)) {
			OperandStack.push(atoi(&c));
		}
		// Element ist ein Operator
		else if (c == '+' || c == '-' || c == '*' || c == '/') {
			OperatorStack.push(c);
		}
		// Element ist eine schließende Klammer --> Teilausdruck berechnen
		else if (c == ')' || c == '}' || c == ']') {
			int	 operand2  = OperandStack.pop();
			int	 operand1  = OperandStack.pop();
			char operator_ = OperatorStack.pop();
			int result = 0;
			if      (operator_ == '+') result = operand1 + operand2;
			else if (operator_ == '-') result = operand1 - operand2;
			else if (operator_ == '*') result = operand1 * operand2;
			else if (operator_ == '/') result = operand1 / operand2;
			// Ergebnis der Rechnung wieder auf dem Stack ablegen
			OperandStack.push(result);
		}
	}
	int finalResult = OperandStack.pop();
	return finalResult;
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
	// Stack Übungsaufgabe Kapitel 2, Folie 22
	// Auswertung arithmetischer Ausdrücke
	std::string expression = "(1 + ((2+3)*(4*5)))";
	std::cout << "\nAuswertung arithmetischer Ausdrücke: " << std::endl;
	std::cout << "Austruck: " << expression << std::endl;
	std::cout << "Ergebnis: " << evaluateArithmeticExpressions(expression) << std::endl;

	std::string expression2 = "((4/2)+ ((3 * 4 )-((2 *9)*(7*9))))";
	std::cout << "\nAuswertung arithmetischer Ausdrücke: " << std::endl;
	std::cout << "Austruck: " << expression2 << std::endl;
	std::cout << "Ergebnis: " << evaluateArithmeticExpressions(expression2) << std::endl << std::endl;;

	// Stack Übrungsaufgaben Kapitel 2, Folie 24
	/*	1. Stapel S sei als Array mit 6 Feldelementen
		implementiert.Zeigen Sie den Arrayinhalt, wenn nach
		der Reihe die folgenden Operationen ausgeführt
		werden : PUSH(S, 4), PUSH(S, 1), PUSH(S, 3), POP(S),
		PUSH(S, 8), POP(S).
	*/
	Stack S;
	S.push(4);
	S.printAll();
	S.push(1);
	S.printAll();
	S.push(3);
	S.printAll();
	S.pop();
	S.printAll();
	S.push(8);
	S.printAll();
	S.pop();
	S.printAll();

	/*  2. Erläutere, wie man 2 Stapel mit 1 Array A[0.. n-1]
		implementieren kann, so daß weder ein Stack overflow
		noch die Gesamtanzahl der Elemente in beiden Stapeln
		n ergibt. PUSH - und POP - Operationen sollen in O(1)
		laufen.
	*/
	// Aufgabe zum Nachdenken


	/*	3. Wandeln Sie arithmetische Ausdrücke mit einem Stapel
		von der Infix - zur Postfix - Notation um.Operatoren auf
		den Stapel, (überlesen, ) Operator vom Stapel,
		Operanden direkt ausgeben.Bsp: 
		(a + (b + c))  -->	abc++
		(a + ((b * c) * (d - e))) --> abc * de-*+
	*/
	std::cout << "\nUmwandlung von Ausdrücken von der Infix- in die Postfix-Notation" << std::endl;
	convertInfixToPostfixExpression("(a + (b + c))");
	convertInfixToPostfixExpression("(a + ((b * c) * (d - e)))");

	return 0;
}