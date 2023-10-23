#pragma once

#include <iostream>

class Stack
{
private:
	int* s;			// Stapel als Array
	int	 n;			// Array-Groesse
	int  top;		// Leseposition
	bool isEmpty();	
	bool isFull();	
public:
	Stack();
	Stack(int n);
	~Stack();
	void push(int item);
	int  pop();
	void printAll();
};

