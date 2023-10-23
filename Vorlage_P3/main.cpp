/*************************************************
 * ADS Praktikum 3
 * main.cpp
 *
 *************************************************/
#define CATCH_CONFIG_RUNNER
#include <iostream>
#include "Tree.h"
#include "catch.h"

using namespace std;

void printMenue()
{
	std::cout
		<< "=========================================" << std::endl
		<< " ADS - ELK - Stack v1.9, by 25th Bam " << std::endl
		<< "=========================================" << std::endl
		<< "1) Datensatz einfuegen, manuell" << std::endl
		<< "2) Datensatz einfuegen, CSV Datei" << std::endl
		<< "3) Suchen" << std::endl
		<< "4) Ausgabe in Preoder" << std::endl
		<< "5) Ausgabe in Levelorder" << std::endl
		<< "6) Ausgabe in Levelorder (mit Niveauauswahl)" << std::endl
		<< "7) Beenden" << std::endl;
}
void mainscreen_addTreeCSV(Tree *&ref)
{
	char j;
	std::cout << "+ Moechten Sie die Daten aus der Datei ExportZielanalyse.csv "
				 "importieren(j / n) ? >";
	std::cin >> j;
	if (j == 'j')
	{
		std::ifstream csvread;
		csvread.open("ExportZielanalyse.csv", std::ios::in);
		if (!csvread.is_open())
		{
			std::cout << "Fehler beim Lesen!" << std::endl;
			return;
		}
		else
		{
			std::string name, age, postcode, income;

			while (!csvread.eof())
			{
				getline(csvread, name, ';');
				getline(csvread, age, ';');
				getline(csvread, income, ';');
				getline(csvread, postcode, '\n');
				ref->addNode(name, stoi(age), stod(income), stoi(postcode));
			}
			csvread.close();
		}
		std::cout << "+ Daten wurden dem Baum hinzugefuegt." << std::endl;
	}
}
int main()
{

	int result = Catch::Session().run();

	///////////////////////////////////////
	// Ihr Code hier:
	Tree *tree = new Tree();
	printMenue();
	while (true)
	{
		int x = 0;
		std::string nameN;
		int ageN;
		double incomeN;
		int plz;
		std::cout << "?>";
		std::cin >> x;
		if (x == 1)
		{
			std::cout << "+ Bitte geben Sie den Datensatz ein: " << std::endl
					  << "Name ?> ";
			std::cin >> nameN;
			std::cout << "Alter ?> ";
			std::cin >> ageN;
			std::cout << "Einkommen ?> ";
			std::cin >> incomeN;
			std::cout << "PLZ ?> ";
			std::cin >> plz;
			std::cout << "+ Ihr Datensatz wurde eingefuegt" << std::endl;
			tree->addNode(nameN, ageN, incomeN, plz);
		}
		else if (x == 2)
		{
			mainscreen_addTreeCSV(tree);
		}
		else if (x == 3)
		{
			std::cout
				<< "+ Bitte geben Sie den zu suchenden Datensatz an " << std::endl
				<< "Name ?> ";
			std::cin >> nameN;
			std::cout << "+ Fundstellen: " << std::endl;
			if (tree->searchNode(nameN))
			{
				TreeNode *ptr = tree->searchNodePtr(nameN);
				ptr->print();
			}
			else
			{
				std::cout << "Fehler, keine passender Datensatz gefunden!" << std::endl;
			}
		}
		else if (x == 4)
		{
			std::cout << "ID | Name | Alter | Einkommen | PLZ | Pos | Red " << std::endl
					  << "---+------------+-------+-----------+-------+-------+-------" << std::endl;
			tree->printAll();
		}
		else if (x == 5)
		{
			std::cout << "ID | Name | Alter | Einkommen | PLZ | Pos | Red" << std::endl
					  << "---+------------+-------+-----------+-------+-------+-------" << std::endl;
			tree->printLevelOrder();
		}
		else if (x == 6)
		{
			int y = 0;
			std::cout << "Bitte Niveauauswählen: ";
			std::cin >> y;
			std::cout << "ID | Name | Alter | Einkommen | PLZ | Pos | Red" << std::endl
					  << "---+------------+-------+-----------+-------+-------+-------" << std::endl;
			tree->printLevelOrder(y);
		}
		else if (x == 7)
			return result;
		printMenue();
	}

	//
	///////////////////////////////////////
	system("PAUSE");

	return result;
}
