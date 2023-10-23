/*************************************************
 * ADS Praktikum 2.1
 * RingNode.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "RingNode.h"

// Ihr Code hier:
// Konstruktor
RingNode::RingNode() {}
// getter
int RingNode::getOldAge()
{
    return oldAge;
}
std::string RingNode::getDescription()
{
    return this->beschreibung;
}
std::string RingNode::getSymbolicData()
{
    return symbolicData;
}
RingNode *RingNode::getNext()
{
    return this->next;
}

// setter
void RingNode::setAge(int age)
{
    oldAge = age;
}
void RingNode::setDescription(std::string beschreibung)
{
    this->beschreibung = beschreibung;
}
void RingNode::setSymbolicData(std::string data)
{
    symbolicData = data;
}
void RingNode::setNext(RingNode *next)
{
    this->next = next;
}
// Zusatz methoden
void RingNode::print()
{
    std::cout << "Alter: " << this->getOldAge() << ", Beschreibung: " << this->getDescription() << ", Daten: " << this->getSymbolicData() << std::endl;
}
//
////////////////////////////////////