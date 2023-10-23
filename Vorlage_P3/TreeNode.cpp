/*************************************************
 * ADS Praktikum 2.2
 * TreeNode.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "TreeNode.h"
#include <iostream>
#include <string>

////////////////////////////////////
// Ihr Code hier:
// Konstruktor
TreeNode::TreeNode(int nOID, int nCID, std::string nameN, int ageN, double incomeN, int postcodeN)
{
    nodeOrderID = nOID;
    nodeChronologicalID = nCID;
    name = nameN;
    age = ageN;
    income = incomeN;
    postCode = postcodeN;
}
// getter
int TreeNode::getNodeOrderID()
{
    return nodeOrderID;
}
int TreeNode::getNodeChronologicalID()
{
    return nodeChronologicalID;
}
int TreeNode::getAge()
{
    return age;
}
int TreeNode::getPostCode()
{
    return postCode;
}
double TreeNode::getIncome()
{
    return income;
}
std::string TreeNode::getName()
{
    return name;
}
TreeNode *TreeNode::getLeft()
{
    return left;
}
TreeNode *TreeNode::getRight()
{
    return right;
}
TreeNode *TreeNode::getParent()
{
    return parent;
}
bool TreeNode::getRed()
{
    return red;
}
int TreeNode::getHeight()
{
    return height;
}
// setter
void TreeNode::setNodeOrderID(int nOID)
{
    nodeOrderID = nOID;
}
void TreeNode::setNodeChronologicalID(int nCID)
{
    nodeChronologicalID = nCID;
}
void TreeNode::setAge(int ageN)
{
    age = ageN;
}
void TreeNode::setPostCode(int pC)
{
    postCode = pC;
}
void TreeNode::setIncome(int incomeN)
{
    income = incomeN;
}
void TreeNode::setName(std::string nameN)
{
    name = nameN;
}
void TreeNode::setLeft(TreeNode *leftN)
{
    left = leftN;
}
void TreeNode::setRight(TreeNode *rightN)
{
    right = rightN;
}
void TreeNode::setParent(TreeNode *parentN)
{
    parent = parentN;
}
void TreeNode::setRed(bool redN)
{
    red = redN;
}
void TreeNode::setHeight(int heightN)
{
    height = heightN;
}
// Methoden
void TreeNode::print()
{
    std::cout << "NodeID: " << this->getNodeChronologicalID() << ", Name: " << this->getName() << ", Alter: " << this->getAge() << ", Einkommen: " << this->getIncome() << ", PLZ: " << this->getPostCode() << ", PosID: " << this->getNodeOrderID() << std::endl;
}
//
////////////////////////////////////
