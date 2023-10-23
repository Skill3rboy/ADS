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
bool Tree::addNode(std::string nameN, int ageN, double incomeN, int postCodeN)
{
    int orderID = ageN + postCodeN + incomeN;

    TreeNode *node = new TreeNode(orderID, currentNodeChronologicalID, nameN, ageN, incomeN, postCodeN);
    currentNodeChronologicalID++;
    if (anker == nullptr)
    {
        anker = node;
        anker->setParent(nullptr);
        anker->setRed(false);
        return true;
    }
    else
    {
        TreeNode *ptr = anker;
        while (true)
        {

            split4Node(ptr);
            if (orderID < ptr->getNodeOrderID())
            {
                if (ptr->getLeft() == nullptr)
                {
                    ptr->setLeft(node);
                    node->setParent(ptr);
                    break;
                }
                else
                    ptr = ptr->getLeft();
            }
            else if (orderID > ptr->getNodeOrderID())
            {
                if (ptr->getRight() == nullptr)
                {
                    ptr->setRight(node);
                    node->setParent(ptr);
                    break;
                }
                else
                    ptr = ptr->getRight();
            }
        }

        ptr = node;
        int counter = 0;
        TreeNode *rot = nullptr;
        while (ptr != nullptr && ptr != anker)
        {

            if (ptr->getRed())
            {
                counter++;
                if (counter == 1)
                    rot = ptr;
            }
            else
            {
                counter = 0;
                rot = nullptr;
            }
            if (counter == 2)
            {
                balance(rot);
                counter = 0;
                rot = nullptr;
            }
            if (ptr->getParent() == nullptr)
                return true;
            ptr = ptr->getParent();
        }
    }
    return false;
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
/*
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
*/
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
            std::cout << node->getNodeChronologicalID() << "|" << node->getName() << " | " << node->getAge() << " | " << node->getIncome() << " | " << node->getPostCode() << " | " << node->getNodeOrderID() << " | " << node->getRed() << std::endl;
            if (node->getLeft() != nullptr)
                q.push(node->getLeft());
            if (node->getRight() != nullptr)
                q.push(node->getRight());
        }
    }
}

bool Tree::split4Node(TreeNode *node)
{
    if (node->getLeft() != nullptr && node->getRight() != nullptr)
    {
        if (node->getRed() == false && node->getLeft()->getRed() && node->getRight()->getRed())
        {
            if (node != anker)
            {
                node->setRed(true);
            }
            node->getLeft()->setRed(false);
            node->getRight()->setRed(false);
            return true;
        }
    }
    return false;
}
void Tree::printLevelOrder()
{
    if (anker == nullptr)
    {
        std::cout << "Leerer Baum" << std::endl;
    }

    std::queue<TreeNode *> q;
    std::queue<int> niveau;

    q.push(anker);
    niveau.push(0);

    int level = 0;

    while (!q.empty())
    {
        TreeNode *ptr = q.front();

        if (niveau.front() == 0 || niveau.front() > level)
        {
            std::cout << std::endl;
            std::cout << "Niv. " << niveau.front() << ": ";

            if (niveau.front() > level)
            {
                level++;
            }
        }

        std::cout << "(";

        if (ptr->getLeft() != nullptr) // < ptr Node
        {
            if (!(ptr->getLeft()->getRed())) // Schwarzer Nachfolger
            {
                q.push(ptr->getLeft());
                niveau.push(level + 1);
            }
            else // Roter Nachfolger
            {
                std::cout << ptr->getLeft()->getNodeOrderID() << ", ";

                // Koennen gepusht werden da keine zwei roten aufeinander folgen in einem korekten RBBaum
                // Pruefe ob Rote Nachfolger linken Nachfolger hat
                if (ptr->getLeft()->getLeft() != nullptr)
                {
                    q.push(ptr->getLeft()->getLeft());
                    niveau.push(level + 1);
                }

                // Pruefe ob Rote Nachfolger rechten Nachfolger hat
                if (ptr->getLeft()->getRight() != nullptr)
                {
                    q.push(ptr->getLeft()->getRight());
                    niveau.push(level + 1);
                }
            }
        }

        std::cout << ptr->getNodeOrderID();

        if (ptr->getRight() != nullptr) // < ptr Node
        {
            if (!(ptr->getRight()->getRed())) // Schwarzer Nachfolger
            {
                q.push(ptr->getRight());
                niveau.push(level + 1);
            }
            else // Roter Nachfolger
            {
                std::cout << ", " << ptr->getRight()->getNodeOrderID();

                // Koennen gepusht werden da keine zwei roten aufeinander folgen in einem korekten RBBaum
                // Pruefe ob Rote Nachfolger linken Nachfolger hat
                if (ptr->getRight()->getLeft() != nullptr)
                {
                    q.push(ptr->getRight()->getLeft());
                    niveau.push(level + 1);
                }

                // Prufe ob Rote Nachfolger rechten Nachfolger hat
                if (ptr->getRight()->getRight() != nullptr)
                {
                    q.push(ptr->getRight()->getRight());
                    niveau.push(level + 1);
                }
            }
        }

        std::cout << ")";

        q.pop();
        niveau.pop();
        // std::cout << std::endl;
    }

    std::cout << std::endl;
}

void Tree::printAll() // Tabelle
{
    levelOrder();
}
int Tree::proofRBCriterion(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left = 0;
    int right = 0;
    left = proofRBCriterion(root->getLeft());
    if (left == -1)
    {
        root = nullptr;
    }
    right = proofRBCriterion(root->getRight());
    if (left == right)
    {
        if (!root->getRed())
        {
            return ++left;
        }
        return left;
    }
    return -1;
}
int Tree::proofRBCriterion()
{
    if (proofRBCriterion(anker) != -1)
        return 1;
    else
        return -1;
}
bool Tree::rotateTreeRight(TreeNode *node)
{
    if (node == nullptr || node == anker)
    {
        return false;
    }

    TreeNode *parent = node->getParent();

    if (parent->getParent() == nullptr) // Case: Rotation mit Anker als Parent
    {
        parent->setLeft(node->getRight());

        if (parent->getLeft() != nullptr)
        {
            parent->getLeft()->setParent(parent);
        }

        node->setRight(parent);

        parent->setParent(node);
        node->setParent(nullptr);

        anker = node;

        return true;
    }
    else // Case: Rotation im Baum
    {
        parent->setLeft(node->getRight());

        if (parent->getLeft() != nullptr)
        {
            parent->getLeft()->setParent(parent);
        }

        node->setRight(parent);
        if (parent->getParent()->getLeft() == parent)
        {
            parent->getParent()->setLeft(node);
        }
        else
        {
            parent->getParent()->setRight(node);
        }
        node->setParent(parent->getParent());
        parent->setParent(node);

        return true;
    }

    return false; // Error Handling
}
bool Tree::rotateTreeLeft(TreeNode *node)
{
    if (node == nullptr || node == anker)
    {
        return false;
    }

    TreeNode *parent = node->getParent();

    if (parent->getParent() == nullptr) // Case: Rotation mit Anker als Parent
    {
        parent->setRight(node->getLeft());

        if (parent->getRight() != nullptr)
        {
            parent->getRight()->setParent(parent);
        }

        node->setLeft(parent);

        parent->setParent(node);
        node->setParent(nullptr);

        anker = node;

        return true;
    }
    else // Case: Rotation im Baum
    {
        parent->setRight(node->getLeft());

        if (parent->getRight() != nullptr)
        {
            parent->getRight()->setParent(parent);
        }
        node->setLeft(parent);

        if (parent->getParent()->getLeft() == parent)
        {
            parent->getParent()->setLeft(node);
        }
        else
        {
            parent->getParent()->setRight(node);
        }
        node->setParent(parent->getParent());
        parent->setParent(node);

        return true;
    }

    return false; // Error Handling
}

void Tree::printLevelOrder(int pniveau)
{
    if (anker == nullptr)
    {
        std::cout << "Leerer Baum" << std::endl;
        return;
    }

    std::queue<TreeNode *> q;
    std::queue<int> niveau;

    q.push(anker);
    niveau.push(0);

    int level = 0;

    std::string res;

    while (!q.empty())
    {
        TreeNode *ptr = q.front();

        std::string left = "";
        std::string right = "";

        if (niveau.front() == 0 || niveau.front() > level)
        {
            // std::cout << std::endl;
            // std::cout << "Niv. " << niveau.front() << ": ";

            if (niveau.front() > level)
            {
                level++;
            }
        }
        // level++;
        // std::cout << "(";

        if (ptr->getLeft() != nullptr) // < ptr Node
        {
            if (!(ptr->getLeft()->getRed())) // Schwarzer Nachfolger
            {
                q.push(ptr->getLeft());
                niveau.push(level + 1);
            }
            else // Roter Nachfolger
            {
                left = std::to_string(ptr->getLeft()->getNodeOrderID()) + ", ";

                // Koennen gepusht werden da keine zwei roten aufeinander folgen in einem korekten RBBaum
                // Pruefe ob Rote Nachfolger linken Nachfolger hat
                if (ptr->getLeft()->getLeft() != nullptr)
                {
                    q.push(ptr->getLeft()->getLeft());
                    niveau.push(level + 1);
                }

                // Prufe ob Rote Nachfolger rechten Nachfolger hat
                if (ptr->getLeft()->getRight() != nullptr)
                {
                    q.push(ptr->getLeft()->getRight());
                    niveau.push(level + 1);
                }
            }
        }

        // std::cout << ptr->getNodeOrderID();

        if (ptr->getRight() != nullptr) // < ptr Node
        {
            if (!(ptr->getRight()->getRed())) // Schwarzer Nachfolger
            {
                q.push(ptr->getRight());
                niveau.push(level + 1);
            }
            else // Roter Nachfolger
            {
                right = ", " + std::to_string(ptr->getRight()->getNodeOrderID());

                // Koennen gepusht werden da keine zwei roten aufeinander folgen in einem korekten RBBaum
                // Pruefe ob Rote Nachfolger linken Nachfolger hat
                if (ptr->getRight()->getLeft() != nullptr)
                {
                    q.push(ptr->getRight()->getLeft());
                    niveau.push(level + 1);
                }

                // Prufe ob Rote Nachfolger rechten Nachfolger hat
                if (ptr->getRight()->getRight() != nullptr)
                {
                    q.push(ptr->getRight()->getRight());
                    niveau.push(level + 1);
                }
            }
        }

        // std::cout << ")";

        if (level == pniveau)
        {
            // std::cout << "Niv. " << niveau.front() << ": (" << left << ptr->getNodeOrderID() << right << ")" << std::endl;
            // break;
            res += "(" + left + std::to_string(ptr->getNodeOrderID()) + right + ")";
        }

        q.pop();
        niveau.pop();
    }
    std::cout << "Niv. " << pniveau << ": " << res << std::endl;
    std::cout << std::endl;
}

void Tree::balance(TreeNode *node)
{
    TreeNode *rot2 = node->getParent();
    TreeNode *parent = nullptr;
    if (rot2 != nullptr)
        parent = rot2->getParent();

    if (rot2 == nullptr || parent == nullptr || node == nullptr)
        return;
    if (parent->getLeft() == rot2) // erste links
    {
        if (rot2->getLeft() == node) // zweite links
        {
            rotateTreeRight(rot2);
            rot2->setRed(false);
            if (rot2->getLeft() != nullptr)
                rot2->getLeft()->setRed(true);
            if (rot2->getRight() != nullptr)
                rot2->getRight()->setRed(true);
        }
        else if (rot2->getRight() == node) // zweite Rechts
        {
            rotateTreeLeft(node);
            rotateTreeRight(node);
            node->setRed(false);
            if (node->getLeft() != nullptr)
                node->getLeft()->setRed(true);
            if (node->getRight() != nullptr)
                node->getRight()->setRed(true);
        }
    }
    else if (parent->getRight() == rot2) // erste Rechts
    {
        if (rot2->getLeft() == node) // zweite links
        {
            rotateTreeRight(node);
            rotateTreeLeft(node);
            node->setRed(false);
            if (node->getLeft() != nullptr)
                node->getLeft()->setRed(true);
            if (node->getRight() != nullptr)
                node->getRight()->setRed(true);
        }
        else if (rot2->getRight() == node) // zweite Rechts
        {
            rotateTreeLeft(rot2);
            rot2->setRed(false);
            if (rot2->getLeft() != nullptr)
                rot2->getLeft()->setRed(true);
            if (rot2->getRight() != nullptr)
                rot2->getRight()->setRed(true);
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
int Tree::computeHeight(TreeNode *node)
{
    if (node == nullptr)
        return -1;
    int leftHeight = computeHeight(node->getLeft());
    int rightHeight = computeHeight(node->getRight());

    node->setHeight(leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1);
    return node->getHeight();
}
//
////////////////////////////////////
