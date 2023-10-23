#include "Stack.h"
#include <iostream>		// std::cout

void Stack::push(int item) {
	if (isFull())
		std::cout << "overflow error: stack is full" << std::endl;
	else
	{
		top = top + 1;
		s[top] = item;
	}
}
int Stack::pop() {
	if (isEmpty())
		std::cout << "underflow error: stack is empty" << std::endl;
	else
	{
		top = top - 1;
		return s[top + 1];
	}
}

bool Stack::isEmpty() {
	if (top == -1) return true;
	else return false;
}

bool Stack::isFull() {
	if (top == n - 1) return true;
	else return false;
}

void Stack::printAll() {
	std::cout << "Stapel-Inhalt: ";
	for (int i = 0; i <= top; i++)
		std::cout << s[i] << " ";
	std::cout << std::endl;
}

Stack::Stack() { // Konstruktor
	this->s = new int[10];
	this->n = 10;
	this->top = -1;
}

Stack::Stack(int n) { // Ueberladener Konstruktor
	this->s = new int[n];
	this->n = n;
	this->top = -1;
}

Stack::~Stack() { // Destruktor
	delete[] this->s;
}
