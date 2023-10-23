#pragma once
#include <vector>
#include <queue>
#include "EdgeWeightedGraph.h"


class PrimMST
{
private:
	std::vector<bool> marked;  // Vektor der speichert ob ein Knoten besucht wurde
	std::vector<Edge> mst;  // Vektor mit allen Kanten fuer den MST
	std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;  // PriorityQueue die alle Kanten speichert und mit pq.top() die Kante mit dem kleinsten Gewicht zurueck gibt
public:
	/**
	 * Erstellt einen MST zum Graph G mit dem Prim Algorithmus
	 *
	 * \param[in]  G		Kantengewichteter-Graph
	 * \param[in]  s		Startknoten
	 */
	PrimMST(EdgeWeightedGraph G, int s)  // Folie 86
	{
		marked.resize(G.getV(), false);
		this->visit(G, s);
		while (!pq.empty())
		{
			Edge e = pq.top();
			pq.pop();
			int v = e.either();
			int w = e.other(v);

			// Überspringen, falls beide Knoten im Baum markiert sind
			if (marked[v] && marked[w]) continue; // Zykel-Detektion	

			mst.push_back(e); // Füge Kante e zum MSP hinzu
			if (!marked[v]) visit(G, v); // Knoten v oder w zum MSP
			if (!marked[w]) visit(G, w); // hinzufügen
		}
	}

	/**
	 * Markiert Knoten v im Graph G als markiert und fuegt alle Nachbarn zur pq hinzu
	 *
	 * \param[in]  G		Kantengewichteter-Graph
	 * \param[in]  v		Knoten im Graph G
	 */
	void visit(EdgeWeightedGraph G, int v)  // Folie 87
	{
		// Markiere Knoten v als besucht
		marked[v] = true;
		std::vector<Edge> edges = G[v];
		for (int i = 0; i < edges.size(); i++) {
			// Lege alle Kanten von v zu unmarkierten
			// (noch nicht besuchten) Knoten in die PQ ab
			if (!marked[edges[i].other(v)]) pq.push(edges[i]);
		}
	}

	/**
	 * Gibt alle Kanten vom MST zurueck
	 *
	 * \return Vektor mit Kanten des MST
	 */
	const std::vector<Edge> edges() const { return mst; }

	/**
	 * Gibt die Summe aller Gewichte im MST zurueck
	 *
	 * \return Summe der Gewichte im MST
	 */
	double weight() const
	{
		double totalWeight = 0;
		for (Edge e : mst)
		{
			totalWeight += e.weight();
		}
		return totalWeight;
	}
};