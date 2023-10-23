#include <iostream>
#include <random>
#include "hashtable.h"
#include "hashmap.h"
#include <limits>

using namespace std;

bool testHashmap(vector<int>* testvalues)
{
    Hashmap map = Hashmap();
    bool returnValue = true;
    Hashitem* rsl;

	//------------------------------------------------------------------------
	// Test 1
	//------------------------------------------------------------------------
    cout << "Test 1: Erzeuge aus den Tastvalues eine Hashmap und gebe diese aus." << endl;
    std::cout << "Press ENTER to continue... " << flush;
    std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
    cout << endl;
    for (int i = 0; i != (*testvalues).size(); i++)
        map.addItem(new Hashitem((*testvalues)[i]));
    map.printTable();
    map.printOccupancy();
    cout << endl << endl;

	//------------------------------------------------------------------------
	// Test 2
	//------------------------------------------------------------------------
    cout << "Test 2: Suche nach dem Keys 12 (sollten nicht drin sein) & 71 (Key zu Wert 10) in der Hashmap:" << endl;
    std::cout << "Press ENTER to continue... " << flush;
    std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
    cout << endl;
    rsl = nullptr;
    unsigned int posI = 0;
    unsigned int posO = 0;
    rsl = map.getItem(12, &posI, &posO);
    if (rsl != nullptr)
    {
        cout << "Die Map hat folgendes Ergebnis geliefert: " << rsl << " am Index: ([" << posO << "][" << posI << ']' << ')' << endl;
        returnValue = false;
    }
    else
        cout << "Es konnte kein Eintrag zu dem gegeben Key in der Map gefunden werden." << endl;

    rsl = map.getItem(71, &posI, &posO);
    if (rsl != nullptr)
        cout << "Die Map hat folgendes Ergebnis geliefert: " << rsl << " am Index: ([" << posO << "][" << posI << ']' << ')' << endl;
    else
    {
        cout << "Es konnte kein Eintrag zu dem gegeben Key in der Map gefunden werden." << endl;
        returnValue = false;
    }
    cout << endl << endl;

	//------------------------------------------------------------------------
	// Test 3
	//------------------------------------------------------------------------
    cout << "Test 3: Entferne die Einträge zu den Keys 12 & 71 (falls vorhanden) und wiederhole dies im Erfolgsfalle.." << endl;
    std::cout << "Press ENTER to continue... " << flush;
    std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
    cout << endl;
    if (map.deleteItem(12))
    {
        cout << "Eintrag zum Key 12 wurde aus der Map entfernt." << endl;
        returnValue = false;
        if (map.deleteItem(12))
            cout << "Eintrag zum Key 12 wurde aus der Map entfernt." << endl;
        else
            cout << "Eintrag zum Key 12 existiert nicht und konnte somit nicht entfernt werden." << endl;
    }
    else
        cout << "Eintrag zum Key 12 existiert nicht und konnte somit nicht entfernt werden." << endl;

    if (map.deleteItem(71))
    {
        cout << "Eintrag zum Key 71 wurde aus der Map entfernt." << endl;
        if (map.deleteItem(71))
        {
            cout << "Eintrag zum Key 71 wurde aus der Map entfernt." << endl;
            returnValue = false;
        }
        else
            cout << "Eintrag zum Key 71 existiert nicht und konnte somit nicht entfernt werden." << endl;
    }
    else
    {
        cout << "Eintrag zum Key 71 existiert nicht und konnte somit nicht entfernt werden." << endl;
        returnValue = false;
    }
    cout << endl << endl;

    return returnValue;
}

bool testHashtableLinearProbing(vector<int>* testvalues)
{
    bool returnValue = true;
    Hashtable linearHTable = Hashtable(ProbingMethod::Linear);

	//------------------------------------------------------------------------
	// Test 1
	//------------------------------------------------------------------------
    cout << "Test 1: Hashtable mit linearen sondieren erstellen." << endl;
    std::cout << "Press ENTER to continue... " << flush;
    std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
    cout << endl;
    for (int i = 0; i != (*testvalues).size(); i++)
        linearHTable.addItem(new Hashitem((*testvalues)[i]));
    linearHTable.printTable();
    linearHTable.printOccupancy();
    cout << endl << endl;

    //------------------------------------------------------------------------
	// Test 2
	//------------------------------------------------------------------------
    cout << "Test 2: Suche nach dem Keys 12 & 71 (Key zu Wert 10):" << endl;
    std::cout << "Press ENTER to continue... " << flush;
    std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
    cout << endl;
    Hashitem* rsl;
    unsigned int pos = 0;

    rsl = linearHTable.getItem(12, &pos);
    if (rsl != nullptr)
    {
        cout << "Tabelle hat folgendes Ergebnis geliefert: " << rsl << " am Index: " << pos << endl;
        returnValue = false;
    }
    else
        cout << "Tabelle hat nichts mit dem Key 12 abgespeichert." << endl;

    rsl = linearHTable.getItem(71, &pos);
    if (rsl != nullptr)
        cout << "Tabelle hat folgendes Ergebnis geliefert: " << rsl << " am Index: " << pos << endl;
    else
    {
        cout << "Tabelle hat nichts mit dem Key 71 abgespeichert." << endl;
        returnValue = false;
    }

	//------------------------------------------------------------------------
	// Test 3
	//------------------------------------------------------------------------
    cout << "Test 3: Entferne aus der Tabelle den Wert zu dem Key '12364' (Das zugehörige Item sollte '-12345678' sein)." << endl;
    std::cout << "Press ENTER to continue... " << flush;
    std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
    cout << endl;

    if (linearHTable.deleteItem(12364))
        cout << "Das zum Key '12364' zugehörige Obejkt wurde entfernt." << endl;
    else
    {
        cout << "Es konnte kein Objekt zu dem Key '12364' gefunden werden, sodass nichts entfernt wurde." << endl;
        returnValue = false;
    }
    cout << endl << endl;


	//------------------------------------------------------------------------
	// Test 4
	//------------------------------------------------------------------------
    cout << "Test 4: Entferne aus allen Tabellen den Wert zu dem Key '12364' (da sollte nun nichts mehr existieren)." << endl;
    std::cout << "Press ENTER to continue... " << flush;
    std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
    cout << endl;

    if (linearHTable.deleteItem(12364))
    {
        returnValue = false;
        cout << "Das zum Key '12364' zugehörige Obejkt wurde entfernt." << endl;
    }
    else
        cout << "Es konnte kein Objekt zu dem Key '12364' gefunden werden, sodass nichts entfernt wurde." << endl;
    cout << endl << endl;

    return returnValue;
}

bool testHashtableSquareProbing(vector<int>* testvalues)
{
    Hashtable squareHTable = Hashtable(ProbingMethod::Quadratic);
    bool returnValue = true;

	//------------------------------------------------------------------------
	// Test 1
	//------------------------------------------------------------------------
    cout << "Test 1: Hashtable mit quadartischen sondieren erstellen." << endl;
    std::cout << "Press ENTER to continue... " << flush;
    std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
    cout << endl;
    for (int i = 0; i != (*testvalues).size(); i++)
        squareHTable.addItem(new Hashitem((*testvalues)[i]));
    squareHTable.printTable();
    squareHTable.printOccupancy();
    cout << endl << endl;

	//------------------------------------------------------------------------
	// Test 2
	//------------------------------------------------------------------------
    cout << "Test 2: Suche nach dem Keys 12 & 71 (Key zu Wert 10):" << endl;
    std::cout << "Press ENTER to continue... " << flush;
    std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
    cout << endl;
    Hashitem* rsl;
    unsigned int pos = 0;

    rsl = squareHTable.getItem(12, &pos);
    if (rsl != nullptr)
    {
        cout << "Tabelle 2 hat folgendes Ergebnis geliefert: " << rsl << " am Index: " << pos << endl;
        returnValue = false;
    }
    else
        cout << "Tabelle 2 hat nichts mit dem Key 12 abgespeichert." << endl;
    rsl = squareHTable.getItem(71, &pos);
    if (rsl != nullptr)
        cout << "Tabelle 2 hat folgendes Ergebnis geliefert: " << rsl << " am Index: " << pos << endl;
    else
    {
        cout << "Tabelle 2 hat nichts mit dem Key 71 abgespeichert." << endl;
        returnValue = false;
    }

	//------------------------------------------------------------------------
	// Test 3
	//------------------------------------------------------------------------
    cout << "Test 3: Entferne aus der Tabelle den Wert zu dem Key '12364' (Das zugehörige Item sollte '-12345678' sein)." << endl;
    std::cout << "Press ENTER to continue... " << flush;
    std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
    cout << endl;

    if (squareHTable.deleteItem(12364))
        cout << "Das zum Key '12364' zugehörige Obejkt wurde entfernt." << endl;
    else
    {
        cout << "Es konnte kein Objekt zu dem Key '12364' gefunden werden, sodass nichts entfernt wurde." << endl;
        returnValue = false;
    }
    cout << endl << endl;

	//------------------------------------------------------------------------
	// Test 4
	//------------------------------------------------------------------------
    cout << "Test 4: Entferne der Tabelle den Wert zu dem Key '12364' (da sollte nun nichts mehr existieren)." << endl;
    std::cout << "Press ENTER to continue... " << flush;
    std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
    cout << endl;

    if (squareHTable.deleteItem(12364))
    {
        cout << "Das zum Key '12364' zugehörige Obejkt wurde entfernt." << endl;
        returnValue = false;
    }
    else
        cout << "Es konnte kein Objekt zu dem Key '12364' gefunden werden, sodass nichts entfernt wurde." << endl;
    cout << endl << endl;

    return returnValue;
}

bool testHashtableUsingDoubleHashing(vector<int>* testvalues)
{
    bool returnValue = true;
    Hashtable doubleHTable = Hashtable(ProbingMethod::DoubleHashing);

	//------------------------------------------------------------------------
	// Test 1
	//------------------------------------------------------------------------
    cout << "Test 1: Hashtable mit doppelem Hashing zum Sondieren erstellen." << endl;
    std::cout << "Press ENTER to continue... " << flush;
    std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
    cout << endl;
    for (int i = 0; i != (*testvalues).size(); i++)
        doubleHTable.addItem(new Hashitem((*testvalues)[i]));
    doubleHTable.printTable();
    doubleHTable.printOccupancy();
    cout << endl << endl;

	//------------------------------------------------------------------------
	// Test 2
	//------------------------------------------------------------------------
    cout << "Test 2: Suche nach dem Keys 12 & 71 (Key zu Wert 10):" << endl;
    std::cout << "Press ENTER to continue... " << flush;
    std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
    cout << endl;
    Hashitem* rsl;
    unsigned int pos = 0;

    rsl = doubleHTable.getItem(12, &pos);
    if (rsl != nullptr)
    {
        cout << "Tabelle hat folgendes Ergebnis geliefert: " << rsl << " am Index: " << pos << endl;
        returnValue = false;
    }
    else
        cout << "Tabelle hat nichts mit dem Key 12 abgespeichert." << endl;

    rsl = doubleHTable.getItem(71, &pos);
    if (rsl != nullptr)
        cout << "Tabelle hat folgendes Ergebnis geliefert: " << rsl << " am Index: " << pos << endl;
    else
    {
        cout << "Tabelle hat nichts mit dem Key 71 abgespeichert." << endl;
        returnValue = false;
    }
    cout << endl << endl;

	//------------------------------------------------------------------------
	// Test 3
	//------------------------------------------------------------------------
    cout << "Test 3: Entferne aus der Tabelle den Wert zu dem Key '12364' (Das zugehörige Item sollte '-12345678' sein)." << endl;
    std::cout << "Press ENTER to continue... " << flush;
    std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
    cout << endl;

    if (doubleHTable.deleteItem(12364))
        cout << "Das zum Key '12364' zugehörige Obejkt wurde entfernt." << endl;
    else
    {
        cout << "Es konnte kein Objekt zu dem Key '12364' gefunden werden, sodass nichts entfernt wurde." << endl;
        returnValue = false;
    }
    cout << endl << endl;

	//------------------------------------------------------------------------
	// Test 4
	//------------------------------------------------------------------------
    cout << "Test 4: Entferne aus der Tabelle den Wert zu dem Key '12364' (da sollte nun nicht mehr existieren)." << endl;
    std::cout << "Press ENTER to continue... " << flush;
    std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
    cout << endl;

    if (doubleHTable.deleteItem(12364))
    {
        cout << "Das zum Key '12364' zugehörige Obejkt wurde entfernt." << endl;
        returnValue = false;
    }
    else
        cout << "Es konnte kein Objekt zu dem Key '12364' gefunden werden, sodass nichts entfernt wurde." << endl;
    cout << endl << endl;

    return returnValue;
}

/*
    Kontrollsteuermethode für alle Tests. Über die Parameter können die Tests auch geskippt werden.

    \Return:
    \Param[in]: (opt.)  testXYZ     Falls gesetzt wird die Testmethode "XYZ" getestet. Default ist für alle true.
*/
bool testHashingDatastructures(bool testLinearPhobing = true, bool testSquarePhobing = true, bool testDoubbleHashing = true, bool testMap = true)
{
    bool rsl = true;
    vector<int> testvalues = { 10, 3, 4, -10, 0, 34, 1, 12, -2, 2412021, -12345678, -9, 9 };

    if (testLinearPhobing)
        rsl = rsl && testHashtableLinearProbing(&testvalues);
    if (testSquarePhobing)
        rsl = rsl && testHashtableSquareProbing(&testvalues);
    if(testDoubbleHashing)
        rsl = rsl && testHashtableUsingDoubleHashing(&testvalues);
    if(testMap)
        rsl = rsl && testHashmap(&testvalues);

    if (rsl)
        cout << "Alle Tests wurden bestanden." << endl;
    else
        cout << "Nicht alle Tests wurden besstanden!!!" << endl;
    return rsl;
}

int main()
{
    locale::global(locale("German_germany"));
    testHashingDatastructures();  

    /*
        Hier neuen Code einfügen....
    */
   
    std::cout << "Press ENTER to exit... " << flush;
    std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n');
    return 0;
}
