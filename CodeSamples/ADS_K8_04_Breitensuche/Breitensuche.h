#include <vector>
#include <queue>
#include <iostream>

#include "Graph.h"

namespace Graphsuche
{
#pragma region Iterativ
	/**
	 * Fuehrt eine iterative Breitensuche im Graphen g, ab dem Knoten v aus
	 *
	 * \param[in]  g		Graph
	 * \param[in]  v		Knoten
	 */
	void BreitensucheIterativ(const Graph& g, int s)  // Algorithm 9 erweitert
	{
		std::vector<bool> marked(g.getV(), false);
		std::vector<int> edgeTo(g.getV(), -1);

		std::queue<int> q;
		q.push(s);

		while (!q.empty())
		{
			int v = q.front();
			q.pop();

			if (marked[v]) continue;

			marked[v] = true;

			for (auto w : g[v])
			{
				if (!marked[w])
				{
					edgeTo[w] = v;
					q.push(w);
				}
			}
		}
	}

	/**
	 * Fuehrt eine iterative Breitensuche im Graphen g, ab dem Knoten v aus. Ausserdem werden alle besuchten Knoten ausgegeben.
	 *
	 * \param[in]  g		Graph
	 * \param[in]  v		Knoten
	 */
	void BreitensucheIterativAusgabe(const Graph& g, int s)  // Algorithm 9 erweitert
	{
		std::vector<bool> marked(g.getV(), false);
		std::vector<int> edgeTo(g.getV(), -1);

		std::queue<int> q;
		q.push(s);

		while (!q.empty())
		{
			int v = q.front();
			q.pop();

			if (marked[v]) continue;

			marked[v] = true;

			std::cout << v << ", ";

			for (auto w : g[v])
			{
				if (!marked[w])
				{
					edgeTo[w] = v;
					q.push(w);
				}
			}
		}
	}
#pragma endregion
}