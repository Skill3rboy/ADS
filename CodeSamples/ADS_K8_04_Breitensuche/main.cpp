#include <iostream>
#include "Breitensuche.h"

int main()
{
	// GRAPH 0:
	Graph graph0(6);

	graph0.addEdge(0, 2);
	graph0.addEdge(0, 1);
	graph0.addEdge(0, 5);
	graph0.addEdge(1, 2);
	graph0.addEdge(3, 5);
	graph0.addEdge(2, 3);
	graph0.addEdge(2, 4);

	std::cout << "Graph0: \n"
		<< graph0 << std::endl
		<< "Breitensuche Iterativ:" << std::endl;

	Graphsuche::BreitensucheIterativAusgabe(graph0, 0);

	std::cout << std::endl;
	system("PAUSE");
	return 0;
}