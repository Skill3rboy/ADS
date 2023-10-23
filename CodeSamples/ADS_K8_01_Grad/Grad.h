#pragma once
#include "Graph.h"

namespace Grad
{
	/**
	 * Bestimmt den Grad eine Knoten v im Graph g
	 *
	 * \param[in]  G		Graph
	 * \param[in]  v		Knoten
	 * \return Grad des Knoten v im Graph g
	 */
	int degree(Graph G, int v)  // Folie 22 
	{
		// hole Array der adjazenten Knoten zu v
		std::vector<int> adjv = G[v];  // G.adj[v];
		return adjv.size();
	}

	/**
	 * Bestimmt den maximalen Grad eines Knoten im Graphen g
	 *
	 * \param[in]  G		Graph
	 * \return Maximale Grad im Graph g
	 */
	int maxDegree(Graph G)  // Folie 22
	{
		int max = 0;
		for (int v = 0; v < G.getV(); v++)
		{
			int maxv = degree(G, v);
			if (maxv > max) max = maxv;
		}
		return max;
	}


	/**
	 * Bestimmt den durchschnittlichen Grad der Knoten im Graphen g
	 *
	 * \param[in]  G		Graph
	 * \return Durchschnittliche Grad im Graph g
	 */
	double avgDegree(Graph G)
	{
		return (double)2 * G.getE() / (double)G.getV();
	}
}