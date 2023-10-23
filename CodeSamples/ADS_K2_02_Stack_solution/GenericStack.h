#pragma once

template<class T>
class GenericStack {
private:
	T* s;		// Stapel vom Typ T als Array
	int	n;		// Array-Groesse
	int top;	// Leseposition
public:
	void push(T item);
	T    pop();
	bool isEmpty();
	bool isFull();
	void printAll();
	GenericStack();
	GenericStack(int _n);
	~GenericStack();
};

template<class T>
inline void GenericStack<T>::push(T item)
{
	if (isFull())
		std::cout << "overflow error: stack is full" << std::endl;
	else
	{
		top = top + 1;
		s[top] = item;
	}
}

template<class T>
inline T GenericStack<T>::pop()
{
	if (isEmpty())
		std::cout << "underflow error: stack is empty" << std::endl;
	else
	{
		top = top - 1;
		return s[top + 1];
	}
}

template<class T>
inline bool GenericStack<T>::isEmpty()
{
	if (top == -1) return true;
	else return false;
}

template<class T>
inline bool GenericStack<T>::isFull()
{
	if (top == n - 1) return true;
	else return false;
}

template<class T>
inline void GenericStack<T>::printAll()
{
	std::cout << "Stapel-Inhalt: ";
	for (int i = 0; i <= top; i++)
		std::cout << s[i] << " ";
	std::cout << std::endl;
}

template<class T>
inline GenericStack<T>::GenericStack() :
	n{ 10 },
	s{ new T[10] },
	top{ -1 }
{
}

template<class T>
inline GenericStack<T>::GenericStack(int _n) :
	n{ _n },
	top{ -1 }
{
	s = new T[n];
}

template<class T>
inline GenericStack<T>::~GenericStack()
{
	delete[] s;
}