#ifndef _LIST_H
#define _LIST_H
#include "Node.h"
#include <iostream>
#include <string>
template <typename T>

class List
{
    /*
    Die Klasse List dient zur Verwaltung von Knoten (Node). Mit Hilfe der Klasse
    List kann ein Stapel oder Warteschlange realisiert werden.
    */
private:
    struct form
    {
        std::string start = "<< ";
        std::string zwischen = ", ";
        std::string ende = " >>\n";
    } list_form;
    Node<T> *m_head_tail; // Zeiger auf Kopf- und End-Element -> next der 1. Knoten;
                          // -> prev der letzte Knoten
    int m_list_size;      // Länge der Kette
    bool m_temp;          // normalerweise false; ist true, wenn es sich um eine temor�re
                          // Liste handelt die innerhalb der überladenen Operatoren
                          // angelegt wird
public:
    List();
    List(const List &_List); // Kopie Konstruktor
    ~List();
    void insertFront(T value);       // Einfügen eines Knotens am Anfang
    void insertFront(List &_List);   // Einfügen einer vorhandenen Liste am Anfang
    void insertBack(T value);        // Einfügen eines Knotesn am Ende
    void insertBack(List<T> &_List); // Einfügen einer vorhandenen Liste am Ende
    bool getFront(T &value);         // Entnehmen eines Knoten am Anfang
    bool getBack(T &value);          // Entnehmen eines Knoten am Ende
    bool del(T value);               // löschen eines Knotens [key]
    bool search(T value);            // Suchen eines Knoten
    bool swap(T value1, T value2);   // Knoten in der Liste vertauschen
    int size(void);                  // Größe der Lise (Anzahl der Knoten)
    bool test(void);                 // Überprüfen der Zeigerstruktur der Liste
    void format(const std::string &start,
                const std::string &zwischen,
                const std::string &ende);
    // Mit der format-Methode kann die Ausgabe gesteuert werden: operator <<
    // start: stirng vor der Ausgabe der Liste
    // zwischen: string zwischen Listenknoten
    // ende: string am Ende der Liste
    List &operator=(const List &_List); // Zuweisungsoperator definieren
    List &
    operator+(const List &List_Append); // Listen zusammenführen zu einer Liste
    template <typename Tf>
    friend std::ostream &
    operator<<(std::ostream &stream,
               List<Tf> const &Liste); // Ausgabeoperator überladen
    template <typename Tf>
    friend Node<Tf> *get_anker(List<Tf> &l);
    template <typename Tf>
    friend int get_AnzahlNodes(List<Tf> &l);
};
#endif
template <typename T>
List<T>::List()
{
    /*
        Konstruktor für eine leere Liste
    */
    m_head_tail = new Node<T>;
    m_list_size = 0;
    m_temp = false;
    m_head_tail->next = m_head_tail;
    m_head_tail->prev = m_head_tail;
}
template <typename T>
List<T>::List(const List &_List)
{
    /*
        Konstruktor mit Übergabe einer Liste, die dann kopiert wird.
        in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden
        sollen.
    */
    list_form = _List.list_form;
    m_head_tail = new Node<T>;
    m_list_size = 0;
    m_temp = _List.m_temp;
    m_head_tail->next = m_head_tail;
    m_head_tail->prev = m_head_tail;
    Node<T> *tmp_node;
    tmp_node = _List.m_head_tail->next;
    while (tmp_node != _List.m_head_tail)
    {
        m_head_tail->prev =
            new Node<T>(tmp_node->value, m_head_tail->prev->next, m_head_tail->prev);
        m_head_tail->prev->prev->next = m_head_tail->prev;
        m_list_size++;
        tmp_node = tmp_node->next;
    }
    /*
        Ist die übergebene Liste eine m_temporäre Liste? -> aus Operator +
    */
    if (_List.m_temp)
        delete &_List;
}
template <typename T>
List<T>::~List()
{
    // ToDo

    /*
        Dekonstruktor
        Alle Knoten der Liste müssen gelöscht werden, wenn die Liste gelöscht wird.
    */

    if (m_head_tail == nullptr)
        return;

    if (m_head_tail->next != m_head_tail)
    {
        Node<T> *tmp = m_head_tail->next;
        Node<T> *prev = nullptr;

        while (tmp != m_head_tail)
        {
            prev = tmp;
            tmp = tmp->next;
            delete prev;
        }
    }
    delete m_head_tail;
}
template <typename T>
void List<T>::insertFront(T value)
{
    // ToDo
    /*
        Einfuegen eines neuen Knotens am Anfang der Liste
        Einen neuen Knoten mit dem Wert value wird am Anfang der Liste einfügen
    */

    Node<T> *new_node = new Node<T>(value);

    new_node->prev = m_head_tail;
    m_head_tail->next->prev = new_node;
    new_node->next = m_head_tail->next;
    m_head_tail->next = new_node;

    m_list_size++;
}
template <typename T>
void List<T>::insertFront(List<T> &_List)
{
    // ToDo
    /*
        Einfuegen der Liste _List am Anfang an einer vorhandenen Liste
        Die einzufuegenden Knoten werden uebernommen (nicht kopiert)
        Die einzufuegende Liste _List ist anschließend leer.
        Es darf keine Schleife und kein new benutzt werden.
    */
    /*
        gleiches Objekt -> keine Aktion
    */
    if (m_head_tail == _List.m_head_tail)
        return;

    /*
        Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
        Diese Knoten (koplette Kette) werden an den Anfang der Liste (this) übertragen ohne sie zu kopieren!
        Die Liste _List ist danach leer, aber vorhanden.
    */

    this->m_head_tail->next->prev = _List.m_head_tail->prev;
    _List.m_head_tail->prev->next = this->m_head_tail->next;
    _List.m_head_tail->next->prev = this->m_head_tail;
    this->m_head_tail->next = _List.m_head_tail->next;

    this->m_list_size += _List.m_list_size;
}
template <typename T>
void List<T>::insertBack(T value)
{
    // ToDo
    /*
        Einfuegen eines neuen Knotens am Ende der Liste
        Einen neuen Knoten mit dem Wert value wird am Ende der Liste einfügen
    */
    Node<T> *ptr = m_head_tail->prev;
    Node<T> *new_node = new Node<T>(value);
    m_head_tail->prev = new_node;
    new_node->next = m_head_tail;
    new_node->prev = ptr;
    ptr->next = new_node;
    m_list_size++;
}
template <typename T>
void List<T>::insertBack(List<T> &_List)
{
    // ToDo
    /*
        Einfuegen der Liste _List am Ende einer vorhandenen Liste
        Die einzufuegenden Knoten werden uebernommen (nicht kopiert)
        Die einzufuegende Liste _List ist anschließend leer.
        Es darf keine Schleife und kein new benutzt werden.
    */
    /*
        gleiches Objekt -> keine Aktion
    */
    if (m_head_tail == _List.m_head_tail)
        return;

    /*
        Es wird ein Objekt übergeben in dem Knoten vorhanden sein können.
        Diese Knoten (koplette Kette) werden an den Ende der Liste (this) übertragen ohne sie zu kopieren!
        Die Liste _List ist danach leer, aber vorhanden.
    */

    this->m_head_tail->prev->next = _List.m_head_tail->next;
    _List.m_head_tail->next->prev = this->m_head_tail->prev;
    _List.m_head_tail->prev->next = this->m_head_tail;
    this->m_head_tail->prev = _List.m_head_tail->prev;
    this->m_list_size += _List.m_list_size;
}
template <typename T>
bool List<T>::getFront(T &value)
{
    // ToDo
    /*
        entnehmen des Knotens am Anfang der Liste
        der Wert wird als Parameter zurueckgegeben
        der Knoten wird entnommen
        im Fehlerfall wird false zurückgegeben
    */
    /*
        gleiches Objekt -> keine Aktion
    */
    if (!m_list_size)
        return false;

    /*
        Der Wert des vorderen Knotens wird rückgegeben und der Knoten gelöscht.
        Die Methode del(value) darf nicht zum löschen benutzt werden.
    */
    Node<T> *ptr = m_head_tail->next;
    value = ptr->value;
    ptr->next->prev = m_head_tail;
    m_head_tail->next = ptr->next;
    delete ptr;
    m_list_size--;
    return true;
}
template <typename T>
bool List<T>::getBack(T &value)
{
    // ToDo
    /*
        entnehmen des Knotens am Ende der Liste
        der Wert wird als Parameter zurueckgegeben
        der Knoten wird entnommen
        im Fehlerfall wird false zurückgegeben
    */
    /*
        gleiches Objekt -> keine Aktion
    */
    if (!m_list_size)
        return false;

    /*
        Der Wert des letzten Knotens wird rückgegeben und der Knoten gelöscht.
        Die Methode del(value) darf nicht zum löschen benutzt werden.
    */
    Node<T> *ptr = m_head_tail->prev;
    value = ptr->value;
    ptr->prev->next = m_head_tail;
    m_head_tail->prev = ptr->prev;
    delete ptr;
    m_list_size--;
    return true;
}
template <typename T>
bool List<T>::del(T value)
{
    // ToDo
    /*
        Loeschen eines gegebenen Knotens
        im Fehlerfall wird false zurückgegeben
    */
    /*
        gleiches Objekt -> keine Aktion
    */
    if (!m_list_size)
        return false;

    /*
        Löschen des Knotens mit dem Wert value
    */
    Node<T> *ptr = m_head_tail->next;
    while (ptr->value != value)
    {
        if (ptr == m_head_tail)
            break;
        ptr = ptr->next;
    }
    if (ptr->value = value)
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete ptr;
        m_list_size--;
        return true;
    }
    return false;
}
template <typename T>
bool List<T>::search(T value)
{
    // ToDo
    /*
        suchen eines Knotens
        nicht gefunden -> Rueckgabe: false
    */
    /*
        leere Liste -> keine Aktion
    */
    if (!m_list_size)
        return false;

    /*
        suchen ob ein Knoten mit dem Wert value existiert.
    */
    Node<T> *ptr = m_head_tail->next;
    while (ptr->value != value)
    {
        if (ptr == m_head_tail)
            break;
        ptr = ptr->next;
    }
    if (ptr->value == value)
        return true;
    else
        return false;
}
template <typename T>
bool List<T>::swap(T value1, T value2)
{
    // ToDo
    /*
        Vertauschen von zwei Knoten
        Dabei werden die Zeiger der Knoten und deren Nachbarn veraendert.
        im Fehlerfall wird false zurueckgegeben
    */
    /*
        Wenn Liste Leer oder weniger als 2 Knoten besitzt -> Keine Aktion
    */
    if (m_list_size < 2)
        return false;
    /*
        Vertauschen von zwei Knoten mit dem Wert value1 und dem Wert value2.
        Es duerfen nicht nur einfach die Werte in den Knoten getauscht werden!
        Die Knoten sind in der Kette umzuhaengen.
    */
    if (search(value1) && search(value2))
    {
        Node<T> *ptr1 = m_head_tail;
        Node<T> *ptr2 = m_head_tail;
        while (ptr1->value != value1)
        {
            ptr1 = ptr1->next;
        }
        while (ptr2->value != value2)
        {
            ptr2 = ptr2->next;
        }
        if (ptr1->next == ptr2) // nebeneinaderliegend
        {

            ptr1->prev->next = ptr2;
            ptr2->next->prev = ptr1;

            ptr1->next = ptr2->next;
            ptr2->prev = ptr1->prev;
            ptr1->prev = ptr2;
            ptr2->next = ptr1;
        }
        else if (ptr1->prev == ptr2)
        {
            ptr2->prev->next = ptr1;
            ptr1->next->prev = ptr2;

            ptr2->next = ptr1->next;
            ptr1->prev = ptr2->prev;
            ptr2->prev = ptr1;
            ptr1->next = ptr2;
        }
        else // auseinanderliegend
        {
            Node<T> *ptrT1 = new Node<T>(0, ptr1->next, ptr1->prev);

            ptr1->prev = ptr2->prev;
            ptr2->prev->next = ptr1;
            ptr1->next = ptr2->next;
            ptr2->next->prev = ptr1;

            ptr2->prev = ptrT1->prev;
            ptrT1->prev->next = ptr2;
            ptr2->next = ptrT1->next;
            ptrT1->next->prev = ptr2;

            delete ptrT1;
        }
        return true;
    }
    else
        return false;
}
template <typename T>
int List<T>::size(void)
{
    // ToDo
    /*
        Rueckgabe der Anzahl der Knoten in der Liste mit O(1)
        d.h. die Liste darf NICHT traversiert werden um die Größe zu bestimmen.

        Anzahl der Knoten in der Liste zurückgeben.
        Hier richtiges Ergebnis zurückgeben
    */
    return m_list_size;
}
template <typename T>
bool List<T>::test(void)
{
    // Testmethode: die Methode durchläuft die Liste vom Anfang bis zum Ende und
    // zurück Es werden dabei die Anzahl der Knoten gezahlt. Stimmt die Anzahl
    // der Knoten überein liefert die Methode true
    Node<T> *tmp = m_head_tail->next;
    int i_next = 0, i_prev = 0;
    while (tmp != m_head_tail)
    {
        tmp = tmp->next;
        if (i_next > m_list_size)
            return false;
        i_next++;
    }
    if (i_next != m_list_size)
        return false;
    tmp = m_head_tail->prev;
    while (tmp != m_head_tail)
    {
        tmp = tmp->prev;
        if (i_prev > m_list_size)
            return false;
        i_prev++;
    }
    return i_prev == i_next;
}
template <typename T>
List<T> &List<T>::operator=(const List<T> &_List)
{
    // in dem Objekt _List sind die Knotenwerte enthalten, die Kopiert werden
    // sollen. Kopiert wird in das Objekt "this"
    if (this == &_List)
        return *this; //  !! keine Aktion notwendig
    list_form = _List.list_form;
    Node<T> *tmp_node;
    if (m_list_size)
    {
        Node<T> *tmp_del;
        tmp_node = m_head_tail->next;
        while (tmp_node !=
               m_head_tail) // Alle eventuell vorhandenen Knoten in this löschen
        {
            tmp_del = tmp_node;
            tmp_node = tmp_node->next;
            delete tmp_del;
        }
        m_list_size = 0;
        m_head_tail->next = m_head_tail;
        m_head_tail->prev = m_head_tail;
    }
    tmp_node = _List.m_head_tail->next; // Die Listen-Knotenwerte werden kopiert
    while (tmp_node != _List.m_head_tail)
    {
        insertBack(tmp_node->value);
        tmp_node = tmp_node->next;
    }
    if (_List.m_temp)
        delete &_List; // ist die übergebene Liste eine m_temporäre Liste? -> aus
                       // Operator +
    return *this;
}
template <typename T>
List<T> &List<T>::operator+(const List<T> &List_Append)
{
    // Die Methode +
    // Es werden zwei Listen aneinander gehangen.
    // Dabei werden beide Ursprungslisten nicht verändert. Es entsteht eine neue
    // Ergebnisliste.
    Node<T> *tmp_node;
    List<T> *tmp;
    if (m_temp)
    { // this ist eine m_temporäre Liste und kann verändert werden
        tmp = this;
    }
    else
    {
        tmp =
            new List<T>(*this); // this ist keine m_temporäre Liste -> Kopie erzeugen
        tmp->m_temp = true;     // Merker setzten, dass es sich um eine m_temporäre
                                // Liste handelt
    }
    if (List_Append.m_list_size)
    { // anhängen der übergebenen Liste an tmp
        tmp_node = List_Append.m_head_tail->next;
        while (tmp_node != List_Append.m_head_tail)
        {
            tmp->insertBack(tmp_node->value);
            tmp_node = tmp_node->next;
        }
    }
    if (List_Append.m_temp)
        delete &List_Append; // wurde eine m_temporäre Liste übergeben, dann wird
                             // diese gelöscht
    return *tmp;
}
template <typename T>
void List<T>::format(const std::string &start, const std::string &zwischen, const std::string &ende)
{
    // Setzen des Formates für die Ausgabesteuerung der Liste bei cout
    // das Format wird für den überladenen Operator << verwendet
    list_form.start = start;
    list_form.zwischen = zwischen;
    list_form.ende = ende;
}
template <typename Tf>
std::ostream &operator<<(std::ostream &stream, List<Tf> const &Liste)
{
    // Ausgabe der Liste mit cout
    stream << Liste.list_form.start;
    for (Node<Tf> *tmp = Liste.m_head_tail->next; tmp != Liste.m_head_tail;
         tmp = tmp->next)
        stream << tmp->value
               << (tmp->next == Liste.m_head_tail ? Liste.list_form.ende : Liste.list_form.zwischen);
    if (Liste.m_temp)
        delete &Liste; // wurde eine m_temporäre Liste übergeben, dann wird diese
                       // gelöscht
    return stream;
}