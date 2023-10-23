#pragma once
#include "EdgeWeightedDigraph.h"
#include "EdgeWeightedGraph.h"
#include <iostream>
#include <queue>

namespace Graphsearch
{

	/**
	 * Fuehrt eine rekursive Tiefensuche im Graphen G,
	 * ab dem Knoten v aus und markiert alle besuchten
	 * Knoten in marked.
	 * Alle besuchten Knoten werden ausgegeben.
	 *
	 * \param[in]	 G			Graph
	 * \param[in]	 v			Startknoten
	 * \param[in/out] marked		Bereits besuchte Knoten
	 * \param[in/out] edgeTo		Vektor mit dem Nachfolgeknoten zu jedem Knoten
	 */
	void DFS_recursive(const EdgeWeightedGraph &G, int v, std::vector<bool> &marked, std::vector<int> &edgeTo)
	{
		/*
		 * TODO
		 */
		marked[v] = true;

		for (Edge edges : G.getAdj(v))
		{

			int w = edges.other(v);
			if (marked[w] == false)
			{
				edgeTo[w] = v;
				std::cout << " -> " << w;
				DFS_recursive(G, w, marked, edgeTo);
			}
		}
	}

	/**
	 * Fuehrt eine rekursive Tiefensuche im Graphen g, ab dem Knoten v aus.
	 * Alle besuchten Knoten werden ausgegeben.
	 * Starterfunktion zu DFS_recursive(EdgeWeigtedGraph, int, std::vector<bool>, std::vector<int>)
	 *
	 * \param[in]  G			Graph
	 * \param[out] marked	Bereits besuchte Knoten
	 * \param[out] edgeTo	Vektor mit dem Nachfolgeknoten zu jedem Knoten
	 * \param[in]  v			Startknoten
	 * \return	  true		Graph ist zusammenhaengend
	 *			  false		Graph ist nicht zusammenhaengend
	 */

	bool DFS(const EdgeWeightedGraph &G, int v, std::vector<bool> &marked, std::vector<int> &edgeTo)
	{
		/*
		 * TODO
		 */
		marked.assign(G.getV(), false);
		edgeTo.assign(G.getV(), -1);
		std::cout << "Besuchsreihenfolge: " << std::endl
				  << v;
		DFS_recursive(G, v, marked, edgeTo);

		bool correct = true;
		for (auto i = 0; i < G.getV(); i++)
			if (marked[i] == false)
				correct = false;

		return correct;
	}

	/**
	 * Fuehrt eine iterative Breitensuche im Graphen g, ab dem Knoten v aus.
	 * Alle besuchten Knoten werden ausgegeben.
	 *
	 * \param[in]  G			Graph
	 * \param[in]  v			Startknoten
	 * \param[out] marked	Gibt an welche Knoten besucht wurden bei der Suche
	 * \param[out] edgeTo	Gibt den Nachfolgerknoten eines Knoten an
	 * \return	  true		Graph ist zusammenhaengend
	 *			  false		Graph ist nicht zusammenhaengend
	 */
	bool BFS(const EdgeWeightedGraph &G, int v, std::vector<bool> &marked, std::vector<int> &edgeTo)
	{
		/*
		 * TODO:
		 */
		marked.assign(G.getV(), false);
		edgeTo.assign(G.getV(), -1);
		std::queue<int> q;
		q.push(v);
		while (!q.empty())
		{
			v = q.front();
			q.pop();

			if (marked[v])
				continue;

			marked[v] = true;
			for (Edge edges : G.getAdj(v))
			{
				int w = edges.other(v);
				if (marked[w] == false)
				{
					if (edgeTo[w] == -1)
						edgeTo[w] = v;
					q.push(w);
				}
			}
		}
		bool correct = true;
		for (auto i = 0; i < G.getV(); i++)
			if (marked[i] == false)
				correct = false;

		return correct;
	}
}
