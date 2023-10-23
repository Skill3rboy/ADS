/*************************************************
 * ADS Praktikum 2.1
 * main.cpp
 *
 *************************************************/
#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <string>
#include "Ring.h"
#include "catch.h"

using namespace std;

void print_menu()
{
    cout << "====================================" << endl
         << " SuperBackUp-Organizer over 9000, by. Son Goku" << endl
         << "====================================" << endl
         << "1) Backup anlegen" << endl
         << "2) Backup suchen" << endl
         << "3) Alle Backups ausgeben" << endl
         << "4) Beenden" << endl
         << "?> ";
}

int main()
{
    int result = Catch::Session().run();
    // Ihr Code hier:
    int x;
    std::string beschreibung, daten;
    Ring *ring = new Ring();
    for (int i = 1; i < 5; i++)
    {
        ring->addNewNode("beschreibung" + to_string(i), "data" + to_string(i));
    }
    while (true)
    {
        print_menu();
        std::cin >> x;
        switch (x)
        {
        case 1:
            std::cout << "+Neuen Datensatz anlegen" << std::endl
                      << "Beschreibung ?> ";
            std::cin >> beschreibung;
            std::cout << "Daten ?>";
            std::cin >> daten;
            ring->addNewNode(beschreibung, daten);
            std::cout << "Ihr Datensatz wurde hinzugefuegt. " << std::endl;
            break;
        case 2:
            std::cout << "+Nach welchen Daten soll gesucht werden?" << std::endl
                      << "?> ";
            std::cin >> daten;
            if (ring->search(daten))
            {
                RingNode *ptr = ring->searchPtr(daten);
                std::cout << "+ Gefunden in Backup: ";
                ptr->print();
            }
            else
            {
                std::cout << "Datensatz konnte nicht gefunden werden. " << std::endl;
            }
            break;
        case 3:
            ring->print();
            break;
        case 4:
            return result;
            break;
        }
    }
    //
    ///////////////////////////////////////
    system("Pause");
    return result;
}
