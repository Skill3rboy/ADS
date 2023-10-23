/*************************************************
 * ADS Praktikum 2.2
 * TreeNode.h
 * Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
 *************************************************/
#pragma once
#include <string>

// using namespace std;

class TreeNode
{

private:
    ///////////////////////////////////////
    // Ihr Code hier:
    int nodeOrderID = 0;
    int nodeChronologicalID = 0;
    std::string name = "";
    int age = 0;
    double income = 0;
    int postCode = 0;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;

    //
    ////////////////////////////////////

public:
    ///////////////////////////////////////
    // Ihr Code hier:
    // Konstruktor
    TreeNode(int nodeOrderID, int nodeOrderChronID, std::string name, int age, double income, int postcode);
    // getter
    int getNodeOrderID();
    int getNodeChronologicalID();
    int getAge();
    int getPostCode();
    double getIncome();
    std::string getName();
    TreeNode *getLeft();
    TreeNode *getRight();
    // setter
    void setNodeOrderID(int nOID);
    void setNodeChronologicalID(int nCID);
    void setAge(int ageN);
    void setPostCode(int pC);
    void setIncome(int incomeN);
    void setName(std::string nameN);
    void setLeft(TreeNode *leftN);
    void setRight(TreeNode *rightN);
    // Methoden
    void print();
    //
    ////////////////////////////////////
};
