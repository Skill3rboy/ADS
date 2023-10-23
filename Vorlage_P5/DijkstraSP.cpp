#include <assert.h>
#include "DijkstraSP.h"

/**
 * F�ge eine Kante mit minimalen Kosten hinzu, die von einem
 * Baumknoten zu einem Nicht-Baumknoten verl�uft und deren
 * Ziel w dem Startknoten s am n�chsten ist.
 *
 * \param[in]  G		Kantengewichteter-Digraph
 * \param[in]  v		Zielknoten
 */
void DijkstraSP::relax(EdgeWeightedDigraph G, int v)
{
	/*
	 * TODO
	 */
	std::vector<DirectedEdge> e = G.getAdj(v);
	for (size_t i = 0; i < e.size(); i++)
	{
		int w = e[i].to();
		if (distToVect[w] > distToVect[v] + e[i].weight())
		{
			distToVect[w] = distToVect[v] + e[i].weight();
			edgeTo[w] = e[i];
			if (pq.contains(w))
				pq.change(w, distToVect[w]);
			else
				pq.push(w, distToVect[w]);
		}
	}
}

/**
 * Fuert den Dijkstra Algorithmus von s, im Graph G aus.
 *
 * \param[in]  G		Kantengewichteter-Digraph
 * \param[in]  s		Startknoten
 */
DijkstraSP::DijkstraSP(EdgeWeightedDigraph G, int s)
{
	/*
	 * TODO
	 *
	 */

	distToVect.assign(G.getV(), std::numeric_limits<double>::max());

	distToVect[s] = 0.0;
	pq.push(s, 0.0);

	while (!pq.empty())
	{
		relax(G, pq.pop_top());
	}
}

/**
 * Gibt die Distanz von s zum Knoten v zurueck
 *
 * \param[in]  v		Zielknoten
 * \return Summe der Gewichte auf dem Pfad zu v
 */
double DijkstraSP::distTo(int v) const
{
	/*
	 * TODO
	 */
	return distToVect[v];
}

/**
 * Gibt zurueck ob es einen Pfad zu v von s aus gibt
 *
 * \param[in]  v		Zielknoten
 * \return true, wenn es einen Pfad von s nach v gibt, sonst false
 */
bool DijkstraSP::hasPathTo(int v) const
{
	/*
	 * TODO
	 */
	return distToVect[v] < std::numeric_limits<double>::infinity();
}

/**
 * Gibt den Pfad von s nach v als Vektor zurueck
 *
 * \param[in]  v		Zielknoten
 * \return Vektor mit allen Kanten des Pfades von s nach v
 */
std::vector<DirectedEdge> DijkstraSP::pathTo(int v)
{
	/*
	 * TODO
	 */
	std::vector<DirectedEdge> path;
	DirectedEdge eEmpty;
	if (!hasPathTo(v))
		return path;
	for (DirectedEdge e = edgeTo[v]; e != eEmpty; e = edgeTo[e.from()])
		path.insert(path.begin(), e);

	return path;
}
