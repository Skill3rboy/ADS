#include <stdexcept>
#include <stack>
#include <iostream>
#include <queue>

class TreeNode
{
public:
    int key;
    TreeNode *left;
    TreeNode *right;
};

class BinarySearchTree
{
public:
    // Konstruktor
    BinarySearchTree() : m_anker(nullptr){};
    // Hier gehoert eigentlich ein Copy Konstruktor hin
    // (der wird aber fuer uebersichtlicheren Code weggelassen)

    // Dekonstruktor
    ~BinarySearchTree()
    {
        std::stack<TreeNode *> nodes;
        nodes.push(m_anker);
        while (!nodes.empty())
        {
            TreeNode *node = nodes.top();
            nodes.pop();

            if (node == nullptr)
                continue;

            nodes.push(node->left);
            nodes.push(node->right);

            delete node;
        }
    }

    // Fuegt einen Knoten zum Baum hinzu
    void add(const int &key) { m_add(key, m_anker); }

    // Guckt ob ein key im Baum vorhanden ist
    bool exists(const int &key) const { return m_search(key) != nullptr; }

    // 3. Rekursive Methode die alle Knoten in Postorder ausgibt
    void print_postorder() const;

    // 4. Iterative Methode die alle Knoten Niveauweise ausgibt
    void print_niveau() const;

    // 5. Loescht einen beliebigen Knoten im BST und setzt an dessen Stelle das Maximum vom linken Teilbaum
    bool delete_node(const int &key);

    // Gibt den maximalen Key Wert zurueck
    bool max(int &max)
    {
        if (m_anker == nullptr)
            return false;
        else
        {
            max = m_max(m_anker)->key;
            return true;
        }
    }

    // Hier gehoert eigentlich ein Assignment (copy) Operator hin
    // (der wird aber fuer uebersichtlicheren Code weggelassen)
private:
    TreeNode *m_anker;
    // 1. Fuegt einen Knoten als Nachfolger eines gegeben Knoten ein
    void m_add(const int &key, TreeNode *parent);

    // 2. Sucht einen Knoten im BST
    TreeNode *m_search(const int &key) const;

    // Hilfsmethode fuer 3.
    void m_print_postorder(TreeNode *node) const;

    // 6. Recursive Methode die den maximalen Knoten zurueck gibt
    TreeNode *m_max(TreeNode *node) const;
};

// Initalisierung eines Baumes zum testen im folgenden Code
BinarySearchTree bst;

void BinarySearchTree::m_add(const int &key, TreeNode *parent)
{
    // Ihre Loesung hier:
    TreeNode *node = new TreeNode{key};
    TreeNode *ptr = parent;
    if (m_anker == nullptr || parent == nullptr)
    {
        m_anker = node;
        return;
    }

    while (true)
    {
        while (ptr->key >= key) // kleiner
        {
            if (ptr->left == nullptr)
            {
                ptr->left = node;
                return;
            }
            ptr = ptr->left;
        }
        while (ptr->key <= key) // größer
        {
            if (ptr->right == nullptr)
            {
                ptr->right = node;
                return;
            }
            ptr = ptr->right;
        }
    }
}

TreeNode *BinarySearchTree::m_search(const int &key) const
{
    // Ihre Loesung hier:
    TreeNode *ptr = m_anker;
    if (m_anker == nullptr)
    {
        return nullptr;
    }
    while (true)
    {
        while (ptr->key >= key) // kleiner
        {
            if (ptr->left->key == key)
                return ptr->left;
            ptr = ptr->left;
        }
        while (ptr->key <= key) // größer
        {
            if (ptr->right->key == key)
                return ptr->right;
            ptr = ptr->right;
        }
    }
}

void BinarySearchTree::m_print_postorder(TreeNode *node) const
{
    // Ihre Loesung hier:
    if (m_anker == nullptr)
    {
        std::cout << "Der Baum ist Leer! " << std::endl;
        return;
    }
    if (node->left != nullptr)
    {
        m_print_postorder(node->left);
    }
    if (node->right != nullptr)
    {
        m_print_postorder(node->right);
    }
    std::cout << node->key << std::endl;
}

void BinarySearchTree::print_postorder() const
{
    // Ihre Loesung hier:
    m_print_postorder(m_anker);
}

void BinarySearchTree::print_niveau() const
{
    // Ihre Loesung hier:
    static TreeNode *const tren = nullptr;
    if (m_anker == nullptr)
        return;
    std::queue<TreeNode *> q;
    q.push(m_anker);
    q.push(tren);
    while (true)
    {
        TreeNode *current = q.front();
        q.pop();
        if (current != tren)
        {
            std::cout << current->key << " ";
            if (current->left != nullptr)
            {
                q.push(current->left);
            }
            if (current->right != nullptr)
            {
                q.push(current->right);
            }
        }
        else
        {
            std::cout << std::endl;
            if (q.empty())
                break;
            q.push(tren);
        }
    }
}

bool BinarySearchTree::delete_node(const int &key)
{
    // Ihre Loesung hier:
    TreeNode *ptr = m_anker;
    TreeNode *prev = nullptr;

    while (ptr != nullptr && ptr->key != key)
    {
        prev = ptr;
        if (key < ptr->key)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }

    if (ptr->left == nullptr || ptr->right == nullptr) // eins oder kein kind
    {

        TreeNode *newPtr;

        // links fehlt
        if (ptr->left == nullptr)
            newPtr = ptr->right;
        else
            newPtr = ptr->left;

        if (prev == nullptr)
            return newPtr;

        if (ptr == prev->left)
            prev->left = newPtr;
        else
            prev->right = newPtr;

        delete ptr;
        return true;
    }
    else // zwei kinder
    {
        TreeNode *ptr2 = ptr;
        ptr = ptr2->left;
        while (ptr->right != nullptr)
            ptr = ptr->right;
        int tmp = ptr->key;
        delete_node(tmp);
        ptr2->key = tmp;
        return true;
    }
    return false;
}
TreeNode *BinarySearchTree::m_max(TreeNode *node) const
{
    // Ihre Loesung hier:
    if (node->right != nullptr)
        return m_max(node->right);
    return node;
}

int main()
{
    bst.add(5);
    bst.add(4);
    bst.add(3);
    bst.add(9);
    bst.add(6);
    bst.add(7);
    bst.add(10);
    bst.print_niveau();
    bst.delete_node(9);
    bst.print_niveau();

    system("pause");
    return 0;
}