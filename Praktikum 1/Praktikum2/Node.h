#ifndef _NODE_H
#define _NODE_H
template <typename T>
class Node
{
public:
    T value;

    Node<T> *next, *prev;

public:
    Node();
    Node(T value, Node *next = 0, Node *prev = 0);
    ~Node();
};
#endif
template <typename T>
Node<T>::Node()
{
    next = 0;
    prev = 0;
    value = 0;
}
template <typename T>
Node<T>::Node(T value, Node *next, Node *prev)
{
    this->value = value;
    this->next = next;
    this->prev = prev;
}
template <typename T>
Node<T>::~Node()
{
}