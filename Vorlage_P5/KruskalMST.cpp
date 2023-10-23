#include "KruskalMST.h"
#include <iostream>
/**
 * Erstellt einen MST zum Graph G mit dem Kruskal Algorithmus
 *
 * \param[in]  G		Kantengewichteter-Graph
 */
KruskalMST::KruskalMST(EdgeWeightedGraph G)
{
	/*
	 * TODO
	 */
	int V = G.getV();
	treeID.resize(V, 0);
	std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
	std::vector<Edge> e = G.edges();

	for (Edge e : G.edges())
		pq.push(e);

	for (int i = 0; i < V; i++)
		treeID[i] = i;

	while (!pq.empty())
	{
		Edge e = pq.top();
		pq.pop();
		int v = e.either();
		int w = e.other(v);

		if (treeID[v] != treeID[w])
		{
			mst.push_back(e);
			int treeID_w = treeID[w];
			for (int i = 0; i < V; i++)
			{
				if (treeID[i] == treeID_w) // angleichen
					treeID[i] = treeID[v];
			}
		}
	}
}

/**
 * Gibt alle Kanten vom MST zurueck
 *
 * \return Vektor mit Kanten des MST
 */
std::vector<Edge> KruskalMST::edges() const
{
	/*
	 * TODO
	 */
	return mst;
}

/**
 * Gibt die Summe aller Gewichte im MST zurueck
 *
 * \return Summe der Gewichte im MST
 */
double KruskalMST::weight() const
{
	/*
	 * TODO
	 */
	double result = 0;
	for (size_t i = 0; i < mst.size(); i++)
		result += mst[i].weight();
	return result;
}
