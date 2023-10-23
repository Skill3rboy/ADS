/*************************************************
 * ADS Praktikum 2.1
 * Ring.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
// Ring .cpp
#include "Ring.h"
#include <iostream>

// Ihr Code hier:

// Konstruktor
Ring::Ring()
{
}

// Methoden
void Ring::addNewNode(std::string beschreibung, std::string data)
{
    RingNode *node = new RingNode(0, beschreibung, data);
    if (countNodes == 0)
    {
        anker = node;
        anker->setNext(anker);
        countNodes++;
    }
    else if (countNodes < 6)
    {

        node->setNext(anker->getNext());
        anker->setNext(node);
        anker = node;
        RingNode *ptr = anker->getNext();
        while (ptr != anker)
        {
            ptr->setAge(ptr->getOldAge() + 1);
            ptr = ptr->getNext();
        }
        countNodes++;
    }
    else
    {
        RingNode *ptrD = anker->getNext();
        RingNode *ptr = anker->getNext()->getNext(); // probably fehler?

        if (ptrD != nullptr)
            while (ptrD != anker)
            {
                ptrD->setAge(ptrD->getOldAge() + 1);
                ptrD = ptrD->getNext();
            }
        ptrD = anker->getNext();
        anker->setNext(node);
        node->setNext(ptr);
        anker = node;
        delete ptrD;
        ptr = anker->getNext();
    }
}
bool Ring::search(std::string data)
{
    RingNode *ptr = anker;
    if (ptr != nullptr)
    {
        if (ptr == anker)
        {
            if (ptr->getSymbolicData() == data)
                return true;
        }
        ptr = anker->getNext();
        while (ptr != anker)
        {
            if (ptr->getSymbolicData() == data)
                return true;
            ptr = ptr->getNext();
        }
    }
    else
    {
        if (anker->getSymbolicData() == data)
            return true;
    }
    return false;
}
void Ring::print()
{
    printR(anker->getNext());
}
void Ring::printR(RingNode *ptr)
{

    if (ptr != anker)
        printR(ptr->getNext());
    std::cout << "Alter: " << ptr->getOldAge() << ", Beschreibung : " << ptr->getDescription() << ", Daten: " << ptr->getSymbolicData() << std::endl
              << "-------------------------- " << std::endl;
}
// Zusatz Methoden
RingNode *Ring::searchPtr(std::string data)
{
    RingNode *ptr = anker;
    if (ptr != nullptr)
    {
        if (ptr == anker)
        {
            if (ptr->getSymbolicData() == data)
                return ptr;
        }
        ptr = anker->getNext();
        while (ptr != anker)
        {
            if (ptr->getSymbolicData() == data)
                return ptr;
            ptr = ptr->getNext();
        }
    }
    else
    {
        if (anker->getSymbolicData() == data)
            return anker;
    }
    return nullptr;
}
//
////////////////////////////////////