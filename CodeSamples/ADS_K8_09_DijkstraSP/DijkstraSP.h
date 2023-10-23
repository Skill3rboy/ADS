#pragma once
#include <queue>
#include <vector>
#include "EdgeWeightedDigraph.h"
#include <assert.h>
#include <map>
#include <algorithm>
#include "Utils.h"

/**
* Klasse, die in einem Kantengewichteten-Digraph nach den kuerzesten Pfaden sucht.
*/
class DijkstraSP
{
private:
	std::map<int, DirectedEdge> edgeTo;  // Vektor, welcher die best moegliche Kante von s aus zu dieser Kante abspeichert (beste=geringstes Gewicht)
	std::vector<double> distToVect;  // Vektor in dem die Summe der Gewichte auf dem Pfad von s zu dieser Kante abgespeichert ist
	Utils::PriorityQueue<int> pq;  // pq fuer den Dijkstra Algo

	/**
	 * Füge eine Kante mit minimalen Kosten hinzu, die von einem
	 * Baumknoten zu einem Nicht-Baumknoten verläuft und deren
	 * Ziel w dem Startknoten s am nächsten ist.
	 * 
	 * \param[in]  G		Kantengewichteter-Digraph
	 * \param[in]  v		Zielknoten
	 */
	void relax(EdgeWeightedDigraph G, int v)
	{
		std::vector<DirectedEdge> edges = G[v];
		for (DirectedEdge e : edges)
		{
			int w = e.to();
			if (distToVect[w] > distToVect[v] + e.weight())
			{
				distToVect[w] = distToVect[v] + e.weight();
				edgeTo[w] = e;

				if (pq.contains(w))
				{
					pq.change(w, distToVect[w]);
				}
				else
				{
					pq.push(w, distToVect[w]);
				}
			}
		}
	}
public:

	/**
	 * Fuert den Dijkstra Algorithmus von s, im Graph G aus.
	 *
	 * \param[in]  G		Kantengewichteter-Digraph
	 * \param[in]  s		Startknoten
	 */
	DijkstraSP(EdgeWeightedDigraph G, int s)
	{
		this->distToVect.resize(G.getV());

		for (int v = 0; v < G.getV(); v++) {
			this->distToVect[v] = DBL_MAX;
		}
		distToVect[s] = 0.0;
		pq.push(s, 0.0);
		while (!pq.empty())
		{
			int min_node = pq.top().value;
			pq.pop();
			// Füge immer eine Kante mit minimalen Pfadkosten zu s hinzu
			relax(G, min_node);
		}
	}

	/**
	 * Gibt die Distanz von s zum Knoten v zurueck
	 *
	 * \param[in]  v		Zielknoten
	 * \return Summe der Gewichte auf dem Pfad zu v
	 */
	double distTo(int v) const { return this->distToVect[v]; }  // Abstaende von s zu v

	/**
	 * Gibt zurueck ob es einen Pfad zu v von s aus gibt
	 *
	 * \param[in]  v		Zielknoten
	 * \return true, wenn es einen Pfad von s nach v gibt, sonst false
	 */
	bool hasPathTo(int v) const { return this->distToVect[v] < DBL_MAX; }  // Gibt es einen Pfad von s zu v

	/**
	 * Gibt den Pfad von s nach v als Vektor zurueck
	 *
	 * \param[in]  v		Zielknoten
	 * \return Vektor mit allen Kanten des Pfades von s nach v
	 */
	std::vector<DirectedEdge> pathTo(int v)  // Pfad von s zu v
	{
		assert(("Es gibt keinen Pfad von s nach v!", this->hasPathTo(v)));
		//assert(("Vertex is out of bounds!", false));

		std::vector<DirectedEdge> path;
		DirectedEdge e = edgeTo[v];
		while (true)
		{
			path.push_back(e);
			if (edgeTo.count(e.from()) > 0)
			{
				e = edgeTo[e.from()];
			}
			else
			{
				break;
			}
		}

		std::reverse(path.begin(), path.end());

		return path;
	}
};