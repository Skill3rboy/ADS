#include <iostream> // für cin und cout
#include <sstream>  // für istringstream
#include <string>   
#include <stack>

// Musterloesung zum Uebungsblatt 1 - Aufgabe 4
// ============================================
// Implementierung eines Stapel Clients:
// Schreiben Sie ein Programm, das einen Ausdruck mit fehlenden öffnenden Klammern von der Befehlszeile entgegennimmt und den äquivalenten Infix-Ausdruck mit den ergänzten Klammern ausgibt. Lautet zum Beispiel die Eingabe
// 1 + 2 ) * 3 + 4 ) * 56 ) )
// so sollte ihr Programm Folgendes ausgeben :
// ((1 + 2)* ((3 + 4) * 56))

int main()
{
	std::string line = "1 + 2 ) * 3 + 4 ) * 56 ) )";
	std::istringstream iss(line);
	std::string word;
	std::stack<std::string> s1; // Stapel für Operanden
	std::stack<std::string> s2; // Stapel für Operatoren
	unsigned i = 0;
	while (iss >> word)
	{
		if (word.compare("(") == 0) {
			// Klammer auf gelesen
			std::cout << "( ueberlesen" << std::endl;
		}
		else if (word.compare(")") == 0) {
			// Klammer zu gelesen
			std::cout << ") gelesen" << std::endl;
			std::string op2 = s1.top(); // Entnahme des 2. Operanden
			s1.pop();
			std::string op1 = s1.top(); // Entnahme des 1. Operanden
			s1.pop();
			std::string sign = s2.top(); // Entnahme des Operators
			s2.pop();
			// Zusammensetzen der wohl geklammerten Operation
			std::string opnew = "(";
			opnew.append(op1);
			opnew.append(sign);
			opnew.append(op2);
			opnew.append(")");
			std::cout << "push auf Operandenstapel: " << opnew << std::endl;
			s1.push(opnew);
		}
		else if ((word.compare("-") != 0) && (word.compare("+") != 0) && (word.compare("*") != 0) ) {
			// Operand gelesen
			std::cout << "push auf Operandenstapel: " << word << std::endl;
			s1.push(word);
		}
		else if ((word.compare("-") == 0) || (word.compare("+") == 0) || (word.compare("*") == 0)) {
			// Operator gelesen
			std::cout << "push Operator auf Operatorstapel: " << word << std::endl;
			s2.push(word);
		}		
	}
	return 0;
}