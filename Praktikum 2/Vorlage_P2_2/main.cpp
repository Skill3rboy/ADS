/*************************************************
 * ADS Praktikum 2.2
 * main.cpp
 *
 *************************************************/
#define CATCH_CONFIG_RUNNER
#include "Tree.h"
#include "catch.h"
#include <iostream>

// using namespace std;

///////////////////////////////////////
// Hilfsmethoden fürs Menü hier:

/***************************
 ** Vorgegebene  Funktion **
 ***************************
   "mainscreen_addTreeCSV"

Importiert CSV Datei in bestehenden Baum.
Bei Aufruf in der main() Methode, muss der Pointer auf den Anker des Baums, als Parameter übergeben werden.
Es wird die im gleichen Verzeichnis liegende Datei "ExportZielanalyse.csv" geladen.
****************************/
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

//
///////////////////////////////////////
int main()
{

    int result = Catch::Session().run();

    ///////////////////////////////////////
    // Ihr Code hier:
    Tree *tree = new Tree();

    std::cout
        << "=========================================" << std::endl
        << " ADS - ELK - Stack v1.9, by 25th Bam " << std::endl
        << "=========================================" << std::endl
        << "1) Datensatz einfuegen, manuell" << std::endl
        << "2) Datensatz einfuegen, CSV Datei" << std::endl
        << "3) Datensatz loeschen" << std::endl
        << "4) Suchen" << std::endl
        << "5) Datenstruktur anzeigen" << std::endl
        << "6) Level-Order Ausgabe" << std::endl
        << "7) Beenden" << std::endl;
    while (true)
    {
        int x = 0;
        std::string nameN;
        int ageN;
        double incomeN;
        int plz;
        int orderIDN;
        std::cout << "?>";
        std::cin >> x;
        switch (x)
        {
        case 1:
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
            break;
        case 2:
            mainscreen_addTreeCSV(tree);
            break;
        case 3:
            std::cout << "+ Bitte geben Sie den zu loeschenden Datensatz an: " << std::endl
                      << "OrderID ?> ";
            std::cin >> orderIDN;
            tree->deleteNode(orderIDN);
            std::cout << "+ EIntrag wurde geloescht. " << std::endl;
            break;
        case 4:
            std::cout << "+ Bitte geben Sie den zu suchenden Datensatz an " << std::endl
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
            break;
        case 5:
            std::cout << "ID | Name           | Age | Income         | PostCode | OrderID " << std::endl
                      << "----+------------------+-------+-----------+----------+-------" << std::endl;
            tree->printAll();
            break;
        case 6:
            std::cout << "ID | Name           | Age | Income         | PostCode | OrderID " << std::endl
                      << "----+------------------+-------+-----------+----------+-------" << std::endl;
            tree->levelOrder();
            break;
        case 7:
            return result;
            break;
        }
    }
    //
    ///////////////////////////////////////
    system("PAUSE");
    return result;
}