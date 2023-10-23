#pragma once
#include <iostream>
#include <string>

class Hashitem
{
private:
	int			 item;
	unsigned int key;
public:
	Hashitem(int item);
	Hashitem(int item, unsigned int key);
	void setKey(unsigned int newKey);
	int getItem() const;
	unsigned int getKey() const;
	friend std::ostream& operator<<(std::ostream& stream, const Hashitem& item);
};

