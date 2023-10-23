#include "LinkedList_Stack.h"

LinkedList_Stack::LinkedList_Stack() :
	head{nullptr}
{
}

LinkedList_Stack::~LinkedList_Stack()
{
	while (head != nullptr) {
		auto delNode = head;
		head = head->next;
		delete delNode;
	}
}

void LinkedList_Stack::push(int key)
{
	auto newNode = new Node(key);
	newNode->next = head;
	head = newNode;
}

bool LinkedList_Stack::pop(Node& popNode)
{
	if (head == nullptr) {
		// Liste ist leer
		return false;
	}
	popNode = *head;
	auto delNode = head;
	head = head->next;
	delete delNode;
	return true;
}

void LinkedList_Stack::print() const
{
	std::cout << "Elemente des Stacks:" << std::endl;
	if (head == nullptr) {
		// Stack ist leer
		std::cout << "{}" << std::endl;
		return;
	}
	auto node = head;
	while (node != nullptr) {
		std::cout << node->key << std::endl;
		node = node->next;
	}
	
}
