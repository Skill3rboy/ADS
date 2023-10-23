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
    bool addNode(std::string nameN, int ageN, double incomeN, int postCodeN);
    bool deleteNode(int orderID);
    bool searchNode(std::string name);
    void printAll();
    void levelOrder();
    void printLevelOrder();
    void printLevelOrder(int niveau);
    void balance(TreeNode *node);
    bool split4Node(TreeNode *node);
    int proofRBCriterion(TreeNode *node);
    int proofRBCriterion();
    bool rotateTreeRight(TreeNode *node);
    bool rotateTreeLeft(TreeNode *node);
    // Zusatz Methoden
    TreeNode *searchNodePtr(std::string name);
    int computeHeight(TreeNode *node);
    //
    ////////////////////////////////////
    // friend-Funktionen sind für die Tests erforderlich und müssen unangetastet
    // bleiben!
    friend TreeNode *get_anker(Tree &TN);
};
