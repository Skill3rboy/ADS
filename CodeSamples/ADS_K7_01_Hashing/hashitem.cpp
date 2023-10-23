#include "hashitem.h"
#include <limits>

Hashitem::Hashitem(int item)
	: item{item}
	, key{ std::numeric_limits<unsigned>::max() }
{
}

Hashitem::Hashitem(int item, unsigned int key)
	: item{item}
	, key{key}
{
}


void Hashitem::setKey(unsigned int newKey)
{
	key = newKey;
}

int Hashitem::getItem() const
{
	return this->item;
}

unsigned int Hashitem::getKey() const
{
	return this->key;
}

std::ostream& operator<<(std::ostream& stream, const Hashitem& hashitem)
{
	stream << "(Item:" + std::to_string(hashitem.item) + '|' + "Key:" + std::to_string(hashitem.key) + ')';
	return stream;
}
