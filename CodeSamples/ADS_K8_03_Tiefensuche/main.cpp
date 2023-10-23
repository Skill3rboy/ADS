#include <iostream>
#include "Graph.h"
#include "Utils.h"
#include "Tiefensuche.h"

using namespace PrintUtils;

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
		<< "Tiefensuche Rekursiv:" << std::endl;

	Graphsuche::TiefensucheRekursivAusgabe(graph0, 0);

	std::cout << "\nTiefensuche Iterativ:" << std::endl;

	Graphsuche::TiefensucheIterativAusgabe(graph0, 0);

	std::cout << "\nPfadsuche mit Tiefensuche:\n"
		<< Graphsuche::PathTo(graph0, 0, 5) << std::endl
		<< std::endl;
	
	// GRAPH 1:
	Graph graph1(13);

	graph1.addEdge(0, 1);
	graph1.addEdge(0, 2);
	graph1.addEdge(0, 5);
	graph1.addEdge(0, 6);
	graph1.addEdge(3, 4);
	graph1.addEdge(3, 5);
	graph1.addEdge(4, 5);
	graph1.addEdge(4, 6);
	graph1.addEdge(7, 8);
	graph1.addEdge(9, 10);
	graph1.addEdge(9, 11);
	graph1.addEdge(9, 12);
	graph1.addEdge(11, 12);

	std::cout << "\nConnected Components:" << std::endl
		<< Graphsuche::ConnectedComponents(graph1) << std::endl;

	std::system("PAUSE");
	return 0;
}