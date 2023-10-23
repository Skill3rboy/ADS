#include <iostream>

#include "Graph.h"
#include "Grad.h"

using namespace PrintUtils;

int main() {
	// Graph erstellen
	Graph graph0(5);

	// Kanten hinzufuegen
	graph0.addEdge(0, 1);
	graph0.addEdge(0, 3);
	graph0.addEdge(1, 3);
	graph0.addEdge(2, 3);

	// Graph ausgeben
	std::cout << "Graph 0:" << std::endl
		<< graph0 << std::endl
		<< "degree(1): " << Grad::degree(graph0, 1) << std::endl
		<< "maxDegree: " << Grad::maxDegree(graph0) << std::endl
		<< "avgDegree: " << Grad::avgDegree(graph0) << std::endl
		<< std::endl
		<< std::endl;


	// Graph erstellen
	Graph graph1("tinyG.txt");

	// Graph ausgeben
	std::cout << "Graph 1:" << std::endl
		<< graph1 << std::endl
		<< "degree(1): " << Grad::degree(graph1, 1) << std::endl
		<< "maxDegree: " << Grad::maxDegree(graph1) << std::endl
		<< "avgDegree: " << Grad::avgDegree(graph1) << std::endl;



	system("PAUSE");
	return 0;
}