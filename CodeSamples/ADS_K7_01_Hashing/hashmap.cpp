#include "hashmap.h"
using namespace std;

/*
 * Konstruktor zur Erstellung einer neuen Hashmap.
 *
 * \param[in] (optional) startsize				Initiale Größe der Hashmap (default: 19)
 * \param[in] (optional) maxAllowedOccupancy	Maximaler Belegtheitsgrad her Hashmap (default: 0.6666666) 
 * \param[in] (optional) maxLengthOfInnerVector Maximale Listenlänge pro Hashwert  (default: 3)
*/
Hashmap::Hashmap(int startsize, double maxAllowedOccupancy, int maxLengthOfInnerVector)
{
    //Die maxwerte und die startsize brauchen eine minimale größe, damit, dass ganze Prinzip der Hashtable sinnvoll bleibt.
    if (maxLengthOfInnerVector < 3)
        maxLengthOfInnerVector = 3;
    if (startsize < 19)
        startsize = 19;
    if (maxAllowedOccupancy < 0.5)
        maxAllowedOccupancy = 0.5;
    if (maxAllowedOccupancy > 0.8)
        maxAllowedOccupancy = 0.8;

    this->maxAllowedOccupancy = maxAllowedOccupancy;
    this->maxLengthOfInnerVector = maxLengthOfInnerVector;
    table = vector<vector<Hashitem*>>();
    for (int i = 0; i != startsize; i++)
        table.push_back(vector<Hashitem*>());
}

/*
 *   Methode zum Hinzufügen eines neuen Hashitems.
 * 
 *   \param[in]					newItem       Pointer auf Hashitem, welches neu hinzuzufügen ist.
 *   \param[in/out] (optional)  keyOfObject   Pointer auf U-Int, falls gesetzt, wird an die referenzierte Stelle der Key des neu eingefügten Objektes geschrieben (default: nullptr).
 *   \return					Abhängig davon ob ein rehashing beim Einfügen notwendig war (true) oder nicht (false).
 *   \throws					Exception     "Object is already in table.", falls das Objekt bereits einmal ind Tabelle liegt, und keine Dopplungen von gleichen Elementen erlaubt ist (entriesMustBeUnique == true).
*/
bool Hashmap::addItem(Hashitem* newItem, unsigned int* keyOfObjekt)
{
    unsigned int key = calcKeyvalue(newItem);
    newItem->setKey(key);
    if (keyOfObjekt != nullptr)
        *keyOfObjekt = key;

    bool neededRehashing = false;

    if (entriesMustBeUnique)	
    {
        if (getItem(key) != nullptr)
        {
            throw new exception("Object is already in table.");
        }
    }

    occupied++;
    if (calcOccupancy() > maxAllowedOccupancy)
    {
        rehashing();  
        neededRehashing = true;
        occupied++;     //Bei dem Rehashing wird die occupied Variabel erst wieder auf null gesetzt; ohne dieses ++ würde die Erhöhung für das neue Objekt verloren gehen.
    }

    unsigned int pos = standardHashFunction(key);
    bool done = false;
    while (!done) //Alle Sondierungsfunktionen können ein false zurückgeben; dies bedeutet dass nicht innerhalb von x iterationen ein Platz gefunden werden konnte, sodass die Table 'gerehasht' wurde.
    {
        done = addIntoTable(pos, newItem);
        if (!done)
        {
            rehashing();
            occupied++; //Siehe oben
            neededRehashing = true;
            pos = standardHashFunction(key);
        }
    }
    return neededRehashing;
}

/*
 *   Diese Methode sucht in O(1) nach dem Eintrag zu dem gegebenen Key.
 * 
 *   \param[in]					Key             Der Key von dem zu suchenden Objekt.
 *   \param[in/out] (optional)  finalInnerPos   Pointer auf UInt; Falls gesetzt wird an die übergebene Position das echte Position des Obejektes im inneren Vector übergeben (dient der Codereduktion für Erase & Delete); Inhalt wertlos fall nullptr returned.
 *   \param[in/out] (optional)  finalOuterPos   Pointer auf UInt; Falls gesetzt wird an die übergebene Position das echte Position des Obejektes im äußerem Vector übergeben (dient der Codereduktion für Erase & Delete); Inhalt wertlos fall nullptr returned.
 *   \return                    Pointer auf das gesuchte Hashitem oder Nullptr falls kein Ergebnis gefunden werden konnte.
*/
Hashitem* Hashmap::getItem(unsigned int key, unsigned int* finalInnerPos, unsigned int* finalOuterPos)
{
    unsigned int pos = standardHashFunction(key);
    if (finalOuterPos != nullptr)
        *finalOuterPos = pos;
    vector<Hashitem*>* innerVector = getInnerVector(pos);
    for (unsigned int i = 0; i != (*innerVector).size(); i++)
    {
        if ((*innerVector)[i]->getKey() == key)
        {
            if (finalInnerPos != nullptr)
                *finalInnerPos = i;
            return (*innerVector)[i];
        }
    }
    return nullptr; //Objekt konnte nicht gefunden werden.
}

/*
 * 
 *   Entfernt das mittels Key gesuchte Objekt aus der Table,
 *   gibt dieses zurück und löscht es auch nicht vom Heap.
 * 
 *   \param[in]     Key         Der Key von dem zu suchenden Objekt.
 *   \return                    Pointer auf das gesuchte Hashitem oder Nullptr falls kein Ergebnis gefunden werden konnte.
*/
Hashitem* Hashmap::eraseItem(unsigned int key)
{
    unsigned int iPos = 0;
    unsigned int oPos = 0;
    Hashitem* target = getItem(key, &iPos, &oPos);
    if (target == nullptr)
        return nullptr; //Objekt konnte nicht gefunden werden
    table[oPos].erase(table[oPos].begin()+oPos);
    occupied--;
    return target;
}

/*
 *   Löscht das zum Key zugehörige Objekt.
 *
 *   \param[in]     Key       Der Key von dem zu entferneden Objekt.
 *   \return               Bool - true falls Objekt gelöscht wurde; sonst false.
*/
bool Hashmap::deleteItem(unsigned int key)
{
    unsigned int iPos = 0;
    unsigned int oPos = 0;
    Hashitem* target = getItem(key, &iPos, &oPos);
    if (target == nullptr)
        return false;
    table[oPos].erase(table[oPos].begin() + iPos);
    delete target;
    occupied--;
    return true;
}

/*
 *   Gibt die Belegungrate in Absolutenzahlen und Prozent aus.
*/
void Hashmap::printOccupancy()
{
    double value = calcOccupancy();
    value = value * 100.;
    if (value < 0.)
        value = 0.;
    if (value > 100.)
        value = 100.;
    cout << "Die Hashtable ist zu '" << occupied << '/' << table.size() << "' besetzt. Das entspricht " << value << "%." << endl;
}

/*
 *   Gibt die Tabelle aus
 *
 *   Ausgabe nach Schemata:
 *   i:-->item1:-->null:-->item2
 *   .....
*/
void Hashmap::printTable()
{
    if (calcOccupancy() >= 0.0001) //Nullüberpürfung mit double
    {
        for (int i = 0; i != table.size(); i++)
        {
            cout << i << ":-->";
            for (int j = 0; j != table[i].size(); j++)
            {
                if (j != 0)         //Sonderfall - hat nur optische Relevanz
                    cout << ", ";
                cout << (table[i][j])->getItem();
            }
            if(table[i].size()!=0)  //Sonderfall - hat nur optische Relevant
                cout << ", ";
            cout << "NULL" << endl;
        }
    }
    else
        cout << "Die Hashmap ist leer.";
}

/*
 *   Diese Funktion berechnet aus dem int-item eines Hashitems einen 
 *   pseudozufälligen Key. Damit werden auch zahlen, die eng beieinander
 *   liegen (1,2,3,0,-1...) auf die Hashtable gespreitzt.
 * 
 *   \param[in]  hi  Item zu dem der Key berechnet werden soll.
 *   \return         Key value zu gegebenem Hashitem.
*/
unsigned int Hashmap::calcKeyvalue(Hashitem* hi)
{
    unsigned int key = hi->getItem();
    srand(key);
    return rand() % 1000000;
}

/*
 *   Die Funktion berechnet zu viel Prozent die Tabelle belegt ist.
 * 
 *   \Return: double - aktueller Belegungsgrad der Tabelle im Bereich [0,1];
*/
double Hashmap::calcOccupancy()
{
    return ((double)occupied / (double)table.size());
}

/*
 *   Methode zur Überprüfung ob die gegebene Zahl eine Primzahl ist.
 *   Source:         https://www.geeksforgeeks.org/c-program-to-check-prime-number/
 * 
 *   \param[in]     n   Eingabe auf die die Primeigenschaft getestet werden soll.
 *   \return            True falls Eingabe eine Primzahl war; sonst false.
*/
bool isAPrimeNumber(unsigned int n)
{
    // Corner case
    if (n <= 1)
        return false;

    // Check from 2 to n-1
    for (unsigned int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}

/*
 *   Diese Funktion berechnet die nächste Primzahl aus gehen von einer Startposition,
 *   welche selbst nicht geprüft wird. Es kann auf-/ und absteigend gesucht werden.
 * 
 *   \param[in]				startingPos     Ausgehend von dieser Position wird die nächste Primzahl gesucht; die Startposition selbst wird nicht getestet.
 *   \param[in] (optional)	countDown       Default (false); Falls false wird in positiver (aufsteigend) Richtung nach der nächsten Primzahl gesucht; sonst in negative (absteigend).
 *   \return						            Nächte gefundene Primzahl; 0 Falls keine gefunden oder Fehler.
*/
unsigned int Hashmap::calcNextPrimeNumber(unsigned int startingPos, bool countDown)
{
    unsigned int counter = startingPos;
    while (true)
    {
        if (countDown)
            counter--;
        else
            counter++;
        if (isAPrimeNumber(counter))
            return counter;
        if (counter < 2)
            return 0;
    }
}

/*
 * Lieftert den inneren Vektor zu einem Eintrag in der Hashmap zurück.
 *
 *   \param[in]     at          Die Position in der Äußeren Tabelle von wo dieser Pointer geholt werden muss
 *   \return                    Pointer auf inneren Hashitem Vector. Wegen der Pointer auf Pointer Struktur sollte unbedingt diese Methode statt direkt zugriffen genutzt werden um Fehler zuvermeiden.
 *   \throws        Exception   "Vector out of bounds." - 'at' war größer gleich table size.
*/
vector<Hashitem*>* Hashmap::getInnerVector(unsigned at)
{
    if (at >= table.size())
        throw new exception("Vector out of bounds.");
    return &table[at];
}


/*
 *  Vergrößerte die Tabelle auf die Größe der nächsten höheren Primzahl.
 *
 *  ACHTUNG: Sollte vor dem rehashing das Attribut 'occupied' erhöht worden sein,
 *	so geht diese Information verloren!
*/
void Hashmap::rehashing()
{
    //Alte Table sichern:
    vector<vector<Hashitem*>> oldTable = table;

    //Neue initalisieren
    unsigned int newSize = calcNextPrimeNumber(oldTable.size());
    table = vector<vector<Hashitem*>>();
    occupied = 0;
    for (int i = 0; i != newSize; i++)
        table.push_back(vector<Hashitem*>());

    //Alte Werte neu einfügen:
    for (int i = 0; i != oldTable.size(); i++)
    {
        vector<Hashitem*>* innerVector = &oldTable[i];  //Pointer nutzen! Kein unnötiges Kopieren von Tabellen - egal wie klein sie auch sein mögen.
        for (int j = 0; j != (*innerVector).size(); j++)
            addItem((*innerVector)[j]);
    }
}

/*
 *   Berechnet aus Key und Tablesize die Initialsuchposition. 
 * 
 *   \param[in]  key     Key des Wertes zu dem die Hashfunktion berechnet wird.
 *   \return             Position im Vektor für den gegebenen Key.
*/
unsigned int Hashmap::standardHashFunction(unsigned int key)
{
    return key % table.size();
}

/*
 *   Diese Methode fügt ein neues Element in den inneren Vektor ein, 
 *	soferne dieser nicht zu voll werden würde.
 * 
 *   \param[in]     pos     Position des Äußeren Vectors wo eingefügt werden soll.
 *   \param[in]     hitem   Item was einzufügen ist.
 *   \return		   true falls eingefügt werden konnte; sonst false.
*/
bool Hashmap::addIntoTable(unsigned int pos, Hashitem* hitem)
{
    vector<Hashitem*>* innerVector = getInnerVector(pos);
    if ((*innerVector).size() != maxLengthOfInnerVector)
        (*innerVector).push_back(hitem);
    else
        return false;
    return true;
}