#include <iostream>
#include "EdgeWeightedGraph.h"


int main()
{
	EdgeWeightedGraph ewd("tinyEWG.txt");
	std::cout << ewd;

	std::system("PAUSE");
	return 0;
}