#include <iostream>
#include "EdgeWeightedGraph.h"
#include "PrimeMST.h"
#include "Utils.h"

int main()
{
	EdgeWeightedGraph ewg(13);

	ewg.add(Edge(0, 1, 1));
	ewg.add(Edge(0, 5, 2));
	ewg.add(Edge(0, 6, 6));
	ewg.add(Edge(1, 2, 1));
	ewg.add(Edge(1, 3, 2));
	ewg.add(Edge(1, 4, 4));
	ewg.add(Edge(2, 4, 4));
	ewg.add(Edge(3, 4, 2));
	ewg.add(Edge(3, 5, 1));
	ewg.add(Edge(4, 5, 2));
	ewg.add(Edge(4, 6, 1));
	ewg.add(Edge(4, 11, 4));
	ewg.add(Edge(5, 11, 2));
	ewg.add(Edge(6, 7, 3));
	ewg.add(Edge(6, 9, 1));
	ewg.add(Edge(6, 11, 5));
	ewg.add(Edge(7, 8, 2));
	ewg.add(Edge(8, 10, 1));
	ewg.add(Edge(9, 10, 1));
	ewg.add(Edge(9, 11, 3));
	ewg.add(Edge(9, 12, 2));
	ewg.add(Edge(11, 12, 1));

	PrimMST prim(ewg, 0);
	EdgeWeightedGraph primGraph(ewg.getV(), prim.edges());
	std::cout << primGraph << std::endl;

	system("PAUSE");
	return 0;
}