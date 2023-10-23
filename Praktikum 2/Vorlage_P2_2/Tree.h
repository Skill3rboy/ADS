/*************************************************
 * ADS Praktikum 2.2
 * Tree.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include "TreeNode.h"
#include "catch.h"
#include <string>

// using namespace std;

class Tree
{

private:
    ///////////////////////////////////////
    // Ihr Code hier:
    TreeNode *anker = nullptr;
    int currentNodeChronologicalID = 0;
    //
    ////////////////////////////////////

public:
    ///////////////////////////////////////
    // Ihr Code hier:
    // Konstruktor
    Tree();
    // Destruktor
    ~Tree();
    // getter

    // setter

    // Methoden
    void addNode(std::string nameN, int ageN, double incomeN, int postCodeN);
    bool deleteNode(int orderID);
    bool searchNode(std::string name);
    void printAll();
    void levelOrder();
    // Zusatz Methoden
    TreeNode *searchNodePtr(std::string name);

    //
    ////////////////////////////////////
    // friend-Funktionen sind für die Tests erforderlich und müssen unangetastet
    // bleiben!
    friend TreeNode *get_anker(Tree &TN);
};
