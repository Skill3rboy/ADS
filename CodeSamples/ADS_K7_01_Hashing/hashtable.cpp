#include "hashtable.h"
#include <exception>
#include <random>


//Konstruktor
/*
* Konstruktor zur Erstellung einer neuen Hashmap.
*
* \Param:               probingMethod           Enum (s. "hashtable.h") zur Festlung der konkret f�r diese Tabelle genutzte Sondierungsfunktion.
* \Param[in] (optional) startsize				Initiale Gr��e der Hashmap                                              (default: 19)
* \Param[in] (optional) maxAllowedOccupancy	    Maximaler Belegtheitsgrad her Hashmap                                   (default: 0.6666666) 
* \Param[in] (optional) maxCoalitionAloowed     Gibt an nach wie vielen Kollisionen sp�testens gerehasht werden muss.   (default: 3)
*/
Hashtable::Hashtable(ProbingMethod probingMethod, int startsize, double maxAllowedOccupancy, int maxCoalitionAloowed)
{
    // �berpr�fung auf sinnvolle Werte.
    if (maxCoalitionAloowed < 3)
        maxCoalitionAloowed = 3;
    if (startsize < 19)
        startsize = 19;
    if (maxAllowedOccupancy < 0.5)
        maxAllowedOccupancy = 0.5;
    if (maxAllowedOccupancy > 0.8)
        maxAllowedOccupancy = 0.8;

    this->method = probingMethod;
    this->maxAllowedOccupancy = maxAllowedOccupancy;
    this->maxCoalitionAllowed = maxCoalitionAloowed;
    table = vector<Hashitem*>();
    for (int i = 0; i != startsize; i++)
        table.push_back(nullptr);
}

/*
*   F�gt ein gegebenes Hashitem neu in die Liste ein und kann - falls gew�nscht - den zugeh�rigen Key zur�ck geben.
*
*   \Return:                                Bool abh�ngig davon ob (mind.) ein rehashing beim Einf�gen notwendig war (true) oder nicht (false).
*   \Param[in]:             newItem:        Pointer auf Hashitem, welches neu hinzuzuf�gen ist.
*   \Param[in/out]: (opt.)  keyOfObject:    Falls gesetzt, wird an die referenzierte Stelle der Key des neu eingef�gten Objektes geschrieben. (Default: nullptr)
*   \Throws:                Exception       "Object is already in table.", falls das Objekt bereits einmal in der Tabelle liegt, und keine Dopplungen von gleichen Elementen erlaubt ist (entriesMustBeUnique == true).
*/
bool Hashtable::addItem(Hashitem* newItem, unsigned int* keyOfObject)
{
    unsigned int key = calcKeyvalue(newItem);
	newItem->setKey(key);
    if (keyOfObject != nullptr)
        *keyOfObject = key;

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
        rehashing();  // Ausf�hrung von rehashing
        neededRehashing = true;
        occupied++;
    }

    unsigned int pos = standardHashFunction(key);
    bool done = false;
    bool firstTry = true;
    unsigned int tempOcc = occupied;
    
	// Alle Sondierungsfunktionen k�nnen ein false zur�ckgeben,
	// dies bedeutet, dass nicht innerhalb von x Iterationen ein Platz gefunden werden konnte,
	// und ein rehashing ausgef�hrt werden muss.
    // ACHTUNG! Bei wirklich �blen und extrem unwahrscheinlichen Eingabefolgen und mind. einer Keydopplung - welche ebenfalls sehr, sehr unwahrscheinlich ist - kann es hier zur einer Endlosschleife kommen!
	while (!done) 
    {
        switch (method)
        {
		case ProbingMethod::Linear:
            done=linearProbing(newItem, pos);
            break;
		case ProbingMethod::Quadratic:
            done=squareProbing(newItem, pos);
            break;
		case ProbingMethod::DoubleHashing:
            done=doubleHasing(newItem, pos);
            break;
        default:
            throw new exception("Unkown probing method detected.");
        }
        if (firstTry)
            if (!done)
                neededRehashing = true;
        if(!done)
            rehashing();
        firstTry = false;
    }
    if (occupied != tempOcc)
        occupied = tempOcc;
    return neededRehashing;
}

/*
*   Diese Methode sucht in der Hashtable nach einem Hashitem ausgehend von einem Key.
* 
*   \Return:                                Pointer auf das gesuchte Hashitem oder Nullptr falls kein Ergebnis.
*   \Param[in]:             Key             Der Key von dem zu suchenden Objekt.
*   \Param[in/out]: (opt.)  posLocation     Falls gesetzt wird an die �bergebene Position das echte Position des Obejektes im Array �bergeben (dient der Codereduktion f�r Erase & Delete)
*   \Throws:                Exception       "Unkown probing method detected." falls die phobingMethod variabel nicht [1,3] ist.
*/
Hashitem* Hashtable::getItem(unsigned int key, unsigned int* posLocation)
{
	unsigned int pos = standardHashFunction(key);
	Hashitem* rsl = nullptr;
	switch (method)
	{
	case ProbingMethod::Linear:
		rsl = linearProbingGetMode(key,pos,0, posLocation);
		break;
	case ProbingMethod::Quadratic:
		rsl = squareProbingGetMode(key,pos,0, posLocation);
		break;
	case ProbingMethod::DoubleHashing:
		rsl = doubleHasingGetMode(key,pos,0,0, posLocation);
		break;
	default:
		throw new exception("Unkown probing method detected.");
	}
	return rsl;
}

/*
*   Diese Methode sucht den Wert zu dem gegeben Key. Sollte es keinen Treffer geben, wird ein nullptr zur�ck gegeben; sonst wird der gefundene Eintrag aus der Liste entfernt und and die Callmethode zur�ck gegeben.
* 
*   \Return:                Pointer auf das gesuchte Hashitem oder Nullptr falls kein Ergebnis.
*   \Param[in]: Key         Der Key von dem zu suchenden Objekt.
*   \Throws:    Exception   "Unkown probing method detected." falls die phobingMethod variabel nicht [1,3] ist.
*/
Hashitem* Hashtable::eraseItem(unsigned int key)
{
    unsigned int foundAt = 0;
	Hashitem* foundItem = getItem(key, &foundAt);
	if(foundItem==nullptr) //Objekt existiert nicht.
		return nullptr;
    table[foundAt] = nullptr;
    occupied--;
    return foundItem;
}

/*
*   Diese Methode ist praktisch identisch zur Erase; jedoch wird dass Objekt wirklich gel�scht und auch nicht zur�ck gegeben.
* 
*   \Return:                Bool - true falls Objekt gel�scht wurde; sonnst false.
*   \Param[in]: Key         Der Key von dem zu entferneden Objekt.
*   \Throws:    Exception   "Unkown probing method detected." falls die phobingMethod variabel nicht [1,3] ist.
*/
bool Hashtable::deleteItem(unsigned int key)
{
    unsigned int foundAt = 0;
    Hashitem* foundItem = getItem(key, &foundAt);
    if (foundItem == nullptr) //Objekt existiert nicht.
        return false;
    table[foundAt] = nullptr;
    occupied--;
    delete foundItem;
    return true;
}

/*
    Gibt die Belegungrate in Absolutenzahlen und Prozent aus.
*/
void Hashtable::printOccupancy()
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
    Gibt die Tabelle aus.

    Siehe Ende der Methode f�r ein Beispiel;
    Gibt jeweils 5 Eintr�ge pro geprinteter Zeile an.
*/
void Hashtable::printTable()
{
    if (calcOccupancy() < 0.0001) //Null�berp�rfung mit double
        cout << "Die Hashtable ist leer.";
    else
        for (int i = 0; i < table.size(); i=i+5)
        {
            for (int j = 0; (j != 5)&&j+i<table.size(); j++)
            {
                string number = std::to_string(i+j);
                while (number.size() < 5)
                    number =  ' ' + number;
                cout << number << '|';
            }
            cout << endl;
            for (int j = 0; j != 29; j++)
                cout << '-';
            cout << endl;
            for (int j = 0; (j != 5) && j + i < table.size(); j++)
            {
                string s;
				if (table[i + j] == nullptr)
					s = "leer";
				else
					s = std::to_string(table[i + j]->getItem());
                while (s.size() < 5)
                    s = ' ' + s;
                cout << s << '|';
            }

            cout << endl << endl;
        }
    for (int j = 0; j != 29; j++)
        cout << '-';
    cout << endl;
    /*
    Ausgabe sieht beispielsweise so aus:
        0|    1|    2|
    -----------------
     leer|   21| leer|

    -----------------
    */
}

//Hashfunktion(-en)
/*
*   Berechnet aus Key und Tablesize die Initialsuchposition.
*
*   \Return:             Position im Vector f�r den gegebenen Key.
*   \Param[in]:  key     Key des Wertes zu dem die Hashfunktion berechnet wird.
*/
unsigned int Hashtable::standardHashFunction(unsigned int key) const
{
	return key % table.size();
}

/*
*   Berechnet die innere HashFunktion beim doppelten Hashing.
* 
*   \Return:                            Position im Vector f�r den gegebenen Key nach i-ter Iteration
*   \Param[in]:          iteration       Angabe in der wievielten Iteration w�hrend des mehrfachen Hashings man sich befindet.
*   \Param[in]:          key             Key des Wertes zu dem die Hashfunktion berechnet wird.
*   \Param[in]: (opt.)   nextSmaller     Default ist 0. Wert der relativ zur Tabellengr��e betrachteten n�chst kleineren Primzahl. Falls 0, wird der Wert in dieser Methode berechnet (da die Funktion rekursiv ist, dient diese Mechanik dazu, Laufzeit einzusparen).
*/
unsigned int Hashtable::secondHashFunction(unsigned int iteration, unsigned int key, unsigned int nextSmaller)
{
	if (nextSmaller == 0)
		nextSmaller = calcNextPrimeNumber(key, true);

	unsigned int nextKeyValue = nextSmaller - (key % nextSmaller);          //Innere Hashfunktion
	nextKeyValue = (key + iteration * nextKeyValue) % table.size();         //�u�ere Hashfunktion
	return nextKeyValue;
}


//Sondierungsfunktionen
//Die Klasse bietet drei verschiedene Sondierungsfunktionen an; linear, quadartisch und doppeltes Hashing
//Bei linear wird einfach linear weiter durch das Array gegangen bis die enditeration oder ein freierplatz gefunden wird.
//Bei Quadartisch wird auf die Key position das iterations quadrath drauf addiert (k+i�)
//Bei dem doppelten Hashing wird eine zweite Hashfunktion hinzugenommen, die mit der n�chst kleineren Primzahl (imvergleich zur Tabellengr��e) arbeitet.
//Es gibt Sondierungsfunktionen f�r das Adden und das Getten; letzteres wird auch bei delete und erase benutzt.

//Sondierungsfunktion AddMode
/*
*   Diese Methode versucht nach dem Verfahren des "linearen Sondierens" einen Platz f�r das einzuf�gende Objekt unter rekursivem Selbstaufruf zu finden.
* 
*   \Return:                        Bool; True falls ein Einf�gen m�glich war; false falls nicht (in diesem Fall wird gerehasht). Die Funktion ruft sich rekursiv maxCoalitionAllowed-Mal auf.
*   \Param[in]:         newItem     Pointer auf Hashitem - Das neu einzuf�gende Objekt.
*   \Param[in]:         key         Position an welcher das newItem in diesem Iterationsschritt versucht werden soll, eingef�gt zu werden.
*   \Param[in]: (opt.)  iteration   Default ist 0. Gibt an in der wie vielten Iteration man sich befindet (Notwendig f�r die Rekursion; sollte niemals von einer anderen Funktion au�er von sich selbst gesetzt werden!
*/
bool Hashtable::linearProbing(Hashitem* newItem, unsigned int key, unsigned int iteration)
{
    if (iteration > maxCoalitionAllowed)
        return false;
    if (table[key] != nullptr)
        return linearProbing(newItem, (key + 1U) % table.size(), iteration + 1);
    else
    {
        table[key] = newItem;
        return true;
    }
}

/*
*   Diese Methode versucht nach dem Verfahren des "quadratischen Sondierens" einen Platz f�r das einzuf�gende Objekt unter rekursivem Selbstaufruf zu finden.
*
*   \Return:                        Bool; True falls ein Einf�gen m�glich war; false falls nicht (in diesem Fall wird gerehasht). Die Funktion ruft sich rekursiv maxCoalitionAllowed-Mal auf.
*   \Param[in]:         newItem     Pointer auf Hashitem - Das neu einzuf�gende Objekt.
*   \Param[in]:         key         Position an welcher das newItem in diesem Iterationsschritt versucht werden soll, eingef�gt zu werden.
*   \Param[in]: (opt.)  iteration   Default ist 0. Gibt an in der wie vielten Iteration man sich befindet (Notwendig f�r die Rekursion; sollte niemals von einer anderen Funktion au�er von sich selbst gesetzt werden!
*/
bool Hashtable::squareProbing(Hashitem* newItem, unsigned int key, unsigned int iteration)
{
    if (iteration > maxCoalitionAllowed)
        return false;
    if (table[key] != nullptr)
        return squareProbing(newItem, (key + (iteration * iteration)) % table.size(), iteration + 1);
    else
    {
        table[key] = newItem;
        return true;
    }
}

/*
*   Diese Methode versucht nach dem Verfahren des "doppelten Hashings" einen Platz f�r das einzuf�gende Objekt unter rekursivem Selbstaufruf zu finden.
*
*   \Return:                            Bool; True falls ein Einf�gen m�glich war; false falls nicht (in diesem Fall wird gerehasht). Die Funktion ruft sich rekursiv maxCoalitionAllowed-Mal auf.
*   \Param[in]:         newItem         Pointer auf Hashitem - Das neu einzuf�gende Objekt.
*   \Param[in]:         key             Position an welcher das newItem in diesem Iterationsschritt versucht werden soll, eingef�gt zu werden.
*   \Param[in]: (opt.)  iteration       Default ist 0. Gibt an in der wie vielten Iteration man sich befindet (Notwendig f�r die Rekursion; sollte niemals von einer anderen Funktion au�er von sich selbst gesetzt werden!
*   \Param[in]: (opt.)  nextSmaller     Default ist 0. Wert der relativ zur Tabellengr��e betrachteten n�chst kleineren Primzahl. Falls 0, wird der Wert in dieser Methode berechnet (da die Funktion rekursiv ist, dient diese Mechanik dazu, Laufzeit einzusparen).
*/
bool Hashtable::doubleHasing(Hashitem* newItem, unsigned int key, unsigned int iteration, unsigned int nextSmaller)
{
    if (nextSmaller == 0)   //Muss einmalig berechnet werden...
        nextSmaller = calcNextPrimeNumber(table.size(), true);
    if (iteration > maxCoalitionAllowed)
        return false;
    if (table[key] != nullptr)
    {
		return doubleHasing(newItem, secondHashFunction(iteration,key,nextSmaller), iteration + 1, nextSmaller);
    }
    else
    {
        table[key] = newItem;
        return true;
    }
}


//Sondierungsfunktion GetMode

/*
*   Diese Methode such nach einem Hashitem mittels rekursion und dem Vefahren des "linearen Sondierens" in der Table.
* 
*   \Return:                        Pointer of Hashitem; nullptr falls kein Ergebnis
*   \Param[in]:         key         Key zu dem Objekt nachdem in der Hashtable gesucht werden soll.
*   \Param[in]:         pos         Position auf die in der aktuellen situartion geschaut wird.
*   \Param[in]:  (opt.) iteration   Default ist 0. Gibt an in der wie vielten Iteration man sich befindet (Notwendig f�r die Rekursion; sollte niemals von einer anderen Funktion au�er von sich selbst gesetzt werden!
*   \Param[out]: (opt.) finalPos    Falls gesetzt wird an die �bergebene Position die exakte Position im Array �bergeben; dies wird z.B. von Erase/Delete genutzt. Falls ein nullptr returned wurde, ist der hier gesetzte Wert, wertlos.	
*/
Hashitem* Hashtable::linearProbingGetMode(unsigned int key, unsigned int pos, unsigned int iteration, unsigned int* finalPos)
{
	if (iteration <= maxCoalitionAllowed)
	{
		if (table[pos] != nullptr)
		{
			if (table[pos]->getKey() == key)
			{
                if (finalPos != nullptr)
                    *finalPos = pos;
				return table[pos];
			}				
		}
        return linearProbingGetMode(key, (pos + 1U) % table.size(), iteration + 1, finalPos);
	}
	return nullptr;
}

/*
*   Diese Methode such nach einem Hashitem mittels rekursion und dem Vefahren des "quadratischen Sondierens" in der Table.
*
*   \Return:                        Pointer of Hashitem; nullptr falls kein Ergebnis
*   \Param[in]:         key         Key zu dem Objekt nachdem in der Hashtable gesucht werden soll.
*   \Param[in]:         pos         Position auf die in der aktuellen situartion geschaut wird.
*   \Param[in]:  (opt.) iteration   Default ist 0. Gibt an in der wie vielten Iteration man sich befindet (Notwendig f�r die Rekursion; sollte niemals von einer anderen Funktion au�er von sich selbst gesetzt werden!
*   \Param[out]: (opt.) finalPos    Falls gesetzt wird an die �bergebene Position die exakte Position im Array �bergeben; dies wird z.B. von Erase/Delete genutzt. Falls ein nullptr returned wurde, ist der hier gesetzte Wert, wertlos.
*/
Hashitem* Hashtable::squareProbingGetMode(unsigned int key, unsigned int pos, unsigned int iteration, unsigned int* finalPos)
{
	if (iteration <= maxCoalitionAllowed)
	{
		if (table[pos] != nullptr)
		{
			if (table[pos]->getKey() == key)
			{
                if (finalPos != nullptr)
                    *finalPos = pos;
				return table[pos];
			}
		}
        return squareProbingGetMode(key, (pos + 1) % table.size(), iteration + 1, finalPos);
	}
	return nullptr;
}

/*
*   Diese Methode such nach einem Hashitem mittels rekursion und dem Vefahren des "doppelten Hashings" in der Table.
*
*   \Return:                        Pointer of Hashitem; nullptr falls kein Ergebnis
*   \Param[in]:         key         Key zu dem Objekt nachdem in der Hashtable gesucht werden soll.
*   \Param[in]:         pos         Position auf die in der aktuellen situartion geschaut wird.
*   \Param[in]:  (opt.) iteration   Default ist 0. Gibt an in der wie vielten Iteration man sich befindet (Notwendig f�r die Rekursion; sollte niemals von einer anderen Funktion au�er von sich selbst gesetzt werden!
*   \Param[out]: (opt.) finalPos    Falls gesetzt wird an die �bergebene Position die exakte Position im Array �bergeben; dies wird z.B. von Erase/Delete genutzt. Falls ein nullptr returned wurde, ist der hier gesetzte Wert, wertlos.
*   \Param[in]:  (opt.) nextSmaller Default ist 0. Wert der relativ zur Tabellengr��e betrachteten n�chst kleineren Primzahl. Falls 0, wird der Wert in dieser Methode berechnet (da die Funktion rekursiv ist, dient diese Mechanik dazu, Laufzeit einzusparen).
*/
Hashitem* Hashtable::doubleHasingGetMode(unsigned int key, unsigned int pos, unsigned int iteration, unsigned int nextSmaler, unsigned int* finalPos)
{
	if (iteration <= maxCoalitionAllowed)
	{
		if (table[pos] != nullptr)
		{
			if (table[pos]->getKey() == key)
			{
                if (finalPos != nullptr)
                    *finalPos = pos;
				return table[pos];
			}
		}
        return doubleHasingGetMode(key, secondHashFunction(iteration, pos, nextSmaler), iteration + 1, nextSmaler, finalPos);
	}
	return nullptr;
}

//Kalkulationsfunktionen
/*
*   Methode zur �berpr�fung ob die gegebene Zahl eine Primzahl ist.
*
*   \Return:            True falls Eingabe eine Primzahl war; sonst false.
*   \Param[in]:     n   Eingabe auf die die Primeigenschaft getestet werden soll.
*   Source:         https://www.geeksforgeeks.org/c-program-to-check-prime-number/
*/
bool isPrime(unsigned int n)
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
*   Die Funktion berechnet zu viel Prozent die Tabelle belegt ist.
* 
*   \Return:    Aktueller Belegungsgrad der Tabelle.
*/
double Hashtable::calcOccupancy() const
{
    return ((double)occupied / (double)table.size());
}

/*
 *   Diese Funktion berechnet aus dem int-item eines Hashitems einen pseudozuf�lligen uint Key.Damit werden auch zahlen, die eng beieinander liegen (1,2,3,0,-1...) auf die Hashtable gespreitzt.
 * 
 *   param[in]  item     Pointer auf Hashitem - Item zu dem der Key berechnet werden soll.
 *   return              Key value zu gegebenem Hashitem.
*/
unsigned int Hashtable::calcKeyvalue(Hashitem* item) const
{
    unsigned int key = item->getItem();
    srand(key);
    return rand()%1000000;
}

/*
 *   Diese Funktion berechnet die n�chste Primzahl aus gehen von einer Startposition,
 *   welche selbst nicht gepr�ft wird. Es kann auf-/ und absteigend gesucht werden.
 *
 *   \param[in]				startingPos     Ausgehend von dieser Position wird die n�chste Primzahl gesucht; die Startposition selbst wird nicht getestet.
 *   \param[in] (optional)  countDown       Default (false); Falls false wird in positiver (aufsteigend) Richtung nach der n�chsten Primzahl gesucht; sonst in negative (absteigend).
 *   \return					             N�chte gefundene Primzahl; 0 Falls keine gefunden oder Fehler.
*/
unsigned int Hashtable::calcNextPrimeNumber(unsigned int startingPos, bool countDown) const
{
    unsigned int counter = startingPos;
    while (true)
    {
        if (countDown)
            counter--;
        else
            counter++;
        if (isPrime(counter))
            return counter;
        if (counter < 2)
            return 0;
    }
}

/*
 *   Vergr��erte die Tabelle auf die Gr��e der n�chsten h�heren Primzahl.
 *
 *   ACHTUNG: Sollte vor dem rehashing das Attribut 'occupied' erh�ht worden sein, so geht diese Information verloren!
*/
void Hashtable::rehashing()
{
    //cout << "Resizeing..." << endl;
    //Alte Table sichern:
    vector<Hashitem*> oldTable = table;

    //Neue initalisieren
    unsigned int newSize = calcNextPrimeNumber(oldTable.size());
    table = vector<Hashitem*>();
    occupied = 0;
    for (int i = 0; i != newSize; i++)
        table.push_back(nullptr);

    //Alte Werte neu einf�gen:
    for (int i = 0; i != oldTable.size(); i++)
        if (oldTable[i] != nullptr)
            addItem(oldTable[i]);
}