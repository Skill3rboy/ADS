#pragma once
#include "Node.h"

class LinkedList_Queue
{
private:
	Node* head;
	Node* tail;
public:
	LinkedList_Queue();
	~LinkedList_Queue();
	void enqueue(int key);
	bool dequeue(Node& dequeueNode);
	void print();
};


