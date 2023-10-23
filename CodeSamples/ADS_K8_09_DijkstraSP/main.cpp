#include <iostream>
#include "EdgeWeightedDigraph.h"
#include "DijkstraSP.h"
#include "Utils.h"

using namespace PrintUtils;

int main()
{
	EdgeWeightedDigraph ewd("tinyEWD.txt");

	DijkstraSP dsp(ewd, 0);

	std::cout << ewd;

	std::cout << "Path from 0 to 6: " << dsp.pathTo(6) << std::endl;

	std::system("PAUSE");
	return 0;
}