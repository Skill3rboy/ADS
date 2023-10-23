/*************************************************
 * ADS Praktikum 2.2
 * Tree.cpp
 * Erweiterung um Hilfsfunktionen gestattet.
 *************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iomanip>
#include <iostream>
#include <stack>
#include <queue>
// using namespace std;

////////////////////////////////////
// Ihr Code hier:
// Konstruktor
Tree::Tree()
{
}
// Destruktor
Tree::~Tree()
{
    if (anker == nullptr)
    {
        return;
    }

    std::stack<TreeNode *> stack;
    TreeNode *ptr = anker;
    TreeNode *ptrD = anker;
    while (stack.empty() == false || ptr != nullptr)
    {
        if (ptr)
        {
            ptrD = ptr;
            if (ptr->getRight() != nullptr)
                stack.push(ptr->getRight());
            ptr = ptr->getLeft();
            delete ptrD;
        }
        else
        {
            ptr = stack.top();
            stack.pop();
        }
    }
}
// getter

// setter

// Methoden
void Tree::addNode(std::string nameN, int ageN, double incomeN, int postCodeN)
{
    int orderID = ageN + postCodeN + incomeN;

    TreeNode *node = new TreeNode(orderID, currentNodeChronologicalID, nameN, ageN, incomeN, postCodeN);
    currentNodeChronologicalID++;
    if (anker == nullptr)
    {
        anker = node;
        return;
    }
    else
    {
        TreeNode *ptr = anker;
        while (true)
        {
            if (orderID < ptr->getNodeOrderID())
            {
                if (ptr->getLeft() == nullptr)
                {
                    ptr->setLeft(node);
                    return;
                }
                else
                    ptr = ptr->getLeft();
            }
            else if (orderID > ptr->getNodeOrderID())
            {
                if (ptr->getRight() == nullptr)
                {
                    ptr->setRight(node);
                    return;
                }
                else
                    ptr = ptr->getRight();
            }
        }
    }
}
bool Tree::deleteNode(int orderID)
{
    TreeNode *ptr = anker;
    if (anker == nullptr)
    {
        return false;
    }
    else if ((anker->getLeft() == nullptr) && (anker->getRight() == nullptr))
    {
        anker = nullptr;
        delete ptr;
        return true;
    }
    else
    {
        if (anker->getNodeOrderID() == orderID) //  Löschen==wurzel
        {
            TreeNode *tmp = ptr->getRight();
            TreeNode *child = tmp;
            if (tmp != nullptr)
                while (child->getLeft() != nullptr)
                {
                    child = child->getLeft();
                }
            if (ptr->getRight() == nullptr && ptr->getLeft() != nullptr)
            {
                anker = ptr->getLeft();
            }
            else if (child != tmp)
            {
                tmp->setLeft(child->getRight());
                child->setLeft(ptr->getLeft());
                child->setRight(ptr->getRight());
                anker = child;
            }
            else
            {
                child->setLeft(anker->getLeft());
                anker = child;
            }
            delete ptr;
        }
        else
        {
            TreeNode *nodeParent = nullptr;
            while (true) // knoten suchen
            {
                if (ptr->getLeft() != nullptr)
                {
                    if (ptr->getLeft()->getNodeOrderID() == orderID)
                    {
                        nodeParent = ptr;
                    }
                }
                if (ptr->getRight() != nullptr)
                {
                    if (ptr->getRight()->getNodeOrderID() == orderID)
                    {
                        nodeParent = ptr;
                    }
                }

                if (orderID < ptr->getNodeOrderID())
                    ptr = ptr->getLeft();
                else if (orderID > ptr->getNodeOrderID())
                    ptr = ptr->getRight();
                else
                    break;
            }
            if (ptr->getLeft() == nullptr && ptr->getRight() == nullptr) // kein nachfolger
            {
                if (nodeParent->getLeft() == ptr) // knoten links
                    nodeParent->setLeft(nullptr);
                else // knoten rechts
                    nodeParent->setRight(nullptr);
                delete ptr;
            }
            else if (ptr->getLeft() != nullptr && ptr->getRight() != nullptr) // zwei nachfolger
            {

                TreeNode *tmp = ptr->getRight();
                TreeNode *child = tmp;
                while (child->getLeft() != nullptr)
                {
                    child = child->getLeft();
                }
                tmp->setLeft(child->getRight());
                child->setLeft(ptr->getLeft());
                child->setRight(ptr->getRight());
                if (nodeParent->getLeft() == ptr)
                    nodeParent->setLeft(child);
                else
                    nodeParent->setRight(child);
                delete ptr;
            }
            else // ein nachfolger
            {
                if (nodeParent->getLeft() == ptr) // knoten links
                {
                    if (ptr->getLeft() == nullptr) // knoten rechts
                        nodeParent->setLeft(ptr->getRight());
                    else // knoten links
                        nodeParent->setLeft(ptr->getLeft());
                }
                else // knoten rechts
                {
                    if (ptr->getLeft() == nullptr) // knoten rechts
                        nodeParent->setRight(ptr->getRight());
                    else // knoten links
                        nodeParent->setRight(ptr->getLeft());
                }
                delete ptr;
            }
        }
        currentNodeChronologicalID--;
        return true;
    }
}
bool Tree::searchNode(std::string name)
{
    if (anker == nullptr)
    {
        return false;
    }

    std::stack<TreeNode *> stack;
    TreeNode *ptr = anker;
    while (stack.empty() == false || ptr != nullptr)
    {
        if (ptr)
        {
            if (ptr->getName() == name)
                return true;
            if (ptr->getRight() != nullptr)
                stack.push(ptr->getRight());
            ptr = ptr->getLeft();
        }
        else
        {
            ptr = stack.top();
            stack.pop();
        }
    }
    return false;
}
void Tree::printAll()
{

    if (anker == nullptr)
    {
        return;
    }

    std::stack<TreeNode *> stack;
    TreeNode *ptr = anker;
    while (stack.empty() == false || ptr != nullptr)
    {
        if (ptr)
        {
            std::cout << ptr->getNodeChronologicalID() << "|" << ptr->getName() << " | " << ptr->getAge() << " | " << ptr->getIncome() << " | " << ptr->getPostCode() << " | " << ptr->getNodeOrderID() << std::endl;
            if (ptr->getRight() != nullptr)
                stack.push(ptr->getRight());
            ptr = ptr->getLeft();
        }
        else
        {
            ptr = stack.top();
            stack.pop();
        }
    }
}
void Tree::levelOrder()
{

    std::queue<TreeNode *> q;
    TreeNode *node;
    TreeNode *ptr = anker;
    if (anker != nullptr)
    {
        q.push(ptr);
        while (!q.empty())
        {
            node = q.front();
            q.pop();
            std::cout << node->getNodeChronologicalID() << "|" << node->getName() << " | " << node->getAge() << " | " << node->getIncome() << " | " << node->getPostCode() << " | " << node->getNodeOrderID() << std::endl;
            if (node->getLeft() != nullptr)
                q.push(node->getLeft());
            if (node->getRight() != nullptr)
                q.push(node->getRight());
        }
    }
}
// Zusatz Methoden
TreeNode *Tree::searchNodePtr(std::string name)
{
    if (anker == nullptr)
    {
        return nullptr;
    }

    std::stack<TreeNode *> stack;
    TreeNode *ptr = anker;
    while (stack.empty() == false || ptr != nullptr)
    {
        if (ptr)
        {
            if (ptr->getName() == name)
                return ptr;
            if (ptr->getRight() != nullptr)
                stack.push(ptr->getRight());
            ptr = ptr->getLeft();
        }
        else
        {
            ptr = stack.top();
            stack.pop();
        }
    }
    return nullptr;
}
//
////////////////////////////////////
