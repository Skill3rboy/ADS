#include "LinkedList_Queue.h"

LinkedList_Queue::LinkedList_Queue() :
	head{ nullptr },
	tail{ nullptr }
{
}

LinkedList_Queue::~LinkedList_Queue()
{
	while (head != nullptr) {
		auto delNode = head;
		head = head->next;
		delete delNode;
	}
}

void LinkedList_Queue::enqueue(int key)
{
	auto newNode = new Node(key,nullptr);
	if (head == nullptr && tail == nullptr) {
		// Einfügen in leere Queue/Liste
		head = newNode;
		tail = newNode;
	} else {
		tail->next = newNode;
		tail = tail->next;
	}
}

bool LinkedList_Queue::dequeue(Node& dequeueNode)
{
	if (head != nullptr) {
		dequeueNode = *head;
		auto delNode = head;
		auto tmpNode = head->next;
		delete delNode;
		head = tmpNode;
		return true;
	}
	return false;
}

void LinkedList_Queue::print()
{
	auto node = head;
	while (node != nullptr) {
		std::cout << *node;
		node = node->next;
	}
	std::cout << std::endl;
}
