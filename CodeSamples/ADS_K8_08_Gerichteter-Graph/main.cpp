#include <iostream>
#include "EdgeWeightedDigraph.h"


int main()
{
	EdgeWeightedDigraph ewg("tinyEWD.txt");
	std::cout << ewg;
	std::system("PAUSE");
	return 0;
}