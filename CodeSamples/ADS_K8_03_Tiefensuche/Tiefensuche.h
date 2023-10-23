#pragma once
#include "Graph.h"
#include <iostream>
#include <stack>

namespace Graphsuche
{
#pragma region Rekursiv

	/**
	 * Fuehrt eine rekursive Tiefensuche im Graphen g, ab dem Knoten v aus und markiert alle besuchten Knoten in marked
	 *
	 * \param[in]  g		Graph
	 * \param[in]  v		Knoten
	 * \param[in]  marked	Bereits besuchten Knoten
	 */
	void TiefensucheRekursiv(const Graph& g, int v, std::vector<bool>& marked)  // Algorithm 1
	{
		// AKTION

		// DFS
		marked[v] = true;
		for (auto w : g[v])
		{
			if (!marked[w])
			{
				TiefensucheRekursiv(g, w, marked);
			}
		}
	}

	/**
	 * Fuehrt eine rekursive Tiefensuche im Graphen g, ab dem Knoten v aus (Starterfunktion zu "TiefensucheRekursiv(Graph, int, std::vector<bool>")
	 *
	 * \param[in]  g		Graph
	 * \param[in]  v		Knoten
	 */
	void TiefensucheRekursiv(const Graph& g, int v = 0)  // Algorithm 1
	{
		std::vector<bool> marked(g.getV(), false);
		TiefensucheRekursiv(g, v, marked);
	}

	/**
	 * Fuehrt eine rekursive Tiefensuche im Graphen g, ab dem Knoten v aus und markiert alle besuchten Knoten in marked. Ausserdem werden alle besuchten Knoten ausgegeben.
	 *
	 * \param[in]  g		Graph
	 * \param[in]  v		Knoten
	 * \param[in]  marked	Bereits besuchten Knoten
	 */
	void TiefensucheRekursivAusgabe(const Graph& g, int v, std::vector<bool>& marked, int depth)  // Algorithm 1 advanced
	{
		std::cout << v;

		// DFS
		marked[v] = true;
		int i = 0;
		for (auto w : g[v])
		{
			if (!marked[w])
			{
				if (i > 0)
				{
					std::cout << std::endl;
					for (int j = 0; j < depth; j++)
					{
						std::cout << "\t";
					}
				}
				std::cout << "\t-> ";
				TiefensucheRekursivAusgabe(g, w, marked, depth + 1);

				i++;
			}
		}
	}

	/**
	 * Fuehrt eine rekursive Tiefensuche im Graphen g, ab dem Knoten v aus. Ausserdem werden alle besuchten Knoten ausgegeben.
	 * (Starterfunktion zu "TiefensucheRekursivAusgabe(Graph, int, std::vector<bool>")
	 *
	 * \param[in]  g		Graph
	 * \param[in]  v		Knoten
	 */
	void TiefensucheRekursivAusgabe(const Graph& g, int v = 0)  // Algorithm 1 advanced
	{
		std::vector<bool> marked(g.getV(), false);
		TiefensucheRekursivAusgabe(g, v, marked, 0);
	}

	/**
	 * Fuehrt eine rekursive Tiefensuche im Graphen g, ab dem Knoten v aus und markiert alle besuchten Knoten in marked und speichert die Kantenverbindungen in edgeTo
	 *
	 * \param[in]  g		Graph
	 * \param[in]  v		Knoten
	 * \param[in]  marked	Bereits besuchten Knoten
	 * \param[in]  edgeTo	Kantenverbindungen
	 */
	void TiefensucheRekursivModifPathTo(const Graph& g, int v, std::vector<bool>& marked, std::vector<int>& edgeTo)  // Algorithm 4
	{
		// AKTION

		// DFS
		marked[v] = true;
		for (auto w : g[v])
		{
			if (!marked[w])
			{
				edgeTo[w] = v;
				TiefensucheRekursivModifPathTo(g, w, marked, edgeTo);
			}
		}
	}

	/**
	 * Fuehrt eine rekursive Tiefensuche im Graphen g, ab dem Knoten v aus.
	 * (Starterfunktion zu "TiefensucheRekursivModifPathTo(Graph, int, std::vector<bool>, std::vector<bool>")
	 *
	 * \param[in]  g		Graph
	 * \param[in]  v		Knoten
	 */
	void TiefensucheRekursivModifPathTo(const Graph& g, int v = 0)  // Algorithm 4
	{
		std::vector<bool> marked(g.getV(), false);
		std::vector<int> edgeTo(g.getV(), -1);
		TiefensucheRekursivModifPathTo(g, v, marked, edgeTo);
	}

	/**
	 * Fuehrt eine rekursive Tiefensuche im Graphen g, ab dem Knoten v aus und markiert alle besuchten Knoten und die Teilgraph-Nummer in marked
	 *
	 * \param[in]  g		Graph
	 * \param[in]  v		Knoten
	 * \param[in]  marked	Besuchte Knoten und ihr Teilgraph
	 */
	void TiefensucheRekursivModifConnectedComponents(const Graph& g, int v, std::vector<bool>& marked, std::vector<int>& id, int& count)  // Algorithm 7
	{
		marked[v] = true;
		id[v] = count;

		for (auto w : g[v])
		{
			if (!marked[w])
			{
				TiefensucheRekursivModifConnectedComponents(g, w, marked, id, count);
			}
		}
	}
#pragma endregion

#pragma region Iterativ
	/**
	 * Fuehrt eine iterative Tiefensuche im Graphen g, ab dem Knoten v aus
	 *
	 * \param[in]  g		Graph
	 * \param[in]  v		Knoten
	 */
	void TiefensucheIterativ(const Graph& g, int s)  // Algorithm 2
	{
		std::vector<bool> marked(g.getV(), false);
		std::vector<int> edgeTo(g.getV(), -1);

		std::stack<int> st;
		st.push(s);

		while (!st.empty())
		{
			int v = st.top();
			st.pop();


			if (marked[v]) continue;
			//AKTION

			marked[v] = true; 
			
			for (int w : g[v])
			{
				if (!marked[w])
				{
					edgeTo[w] = v;
					st.push(w);
				}
			}
		}
	}

	/**
	 * Fuehrt eine iterative Tiefensuche im Graphen g, ab dem Knoten v aus. Ausserdem werden alle besuchten Knoten ausgegeben.
	 *
	 * \param[in]  g		Graph
	 * \param[in]  v		Knoten
	 */
	void TiefensucheIterativAusgabe(const Graph& g, int s)  // Algorithm 2
	{
		std::vector<bool> marked(g.getV(), false);
		std::vector<int> edgeTo(g.getV(), -1);

		std::stack<int> st;
		st.push(s);

		while (!st.empty())
		{
			
			int v = st.top();
			st.pop();
			
			if (marked[v]) continue;

			std::cout << v << ", ";

			marked[v] = true;
			
			for (int w : g[v])
			{
				if (!marked[w])
				{
					edgeTo[w] = v; 
					st.push(w);
				}
			}
		}
	}

	/**
	 * Fuehrt eine iterative Tiefensuche im Graphen g, ab dem Knoten v aus. Mit Rheienfolge aus (marked muesste zurueckgegeben werden.)
	 *
	 * \param[in]  g		Graph
	 * \param[in]  v		Knoten
	 */
	void TiefensucheIterativMitRheienfolge(const Graph& g, int s)  // Algorithm 3
	{
		std::vector<int> marked(g.getV(), 0);
		std::vector<int> edgeTo(g.getV(), -1);

		std::stack<int> st;
		st.push(s);

		int count = 0;

		while (!st.empty())
		{
			int v = st.top();
			st.pop();

			//AKTION

			if (marked[v] == 0)
			{
				count++;
				marked[v] = count;  
			}
			for (int w : g[v])
			{
				if (marked[w] == 0)
				{
					edgeTo[w] = v;
					st.push(w);
				}
			}
		}
	}
#pragma endregion

#pragma region Pfadsuche
	/**
	 * Fuehrt eine rekursive Tiefensuche im Graphen g und sucht einen Pfad von s nach v
	 *
	 * \param[in]  g		Graph
	 * \param[in]  s		Startknoten
	 * \param[in]  v		Endknoten
	 * \return Pfad von s nach v
	 */
	std::vector<int> PathTo(const Graph& g, int s, int v)  // Algorithm 5
	{
		std::vector<bool> marked(g.getV(), false);
		std::vector<int> edgeTo(g.getV(), 0);

		TiefensucheRekursivModifPathTo(g, s, marked, edgeTo);

		assert(("Es wurde kein Pfad gefunden!", marked[v]));

		std::vector<int> path;

		for (int x = v; x != s; x = edgeTo[x])
		{
			path.push_back(x);
		}
		path.push_back(s);

		return path;
	}
#pragma endregion

#pragma region Connected Components
	/**
	 * Fuehrt eine rekursive Tiefensuche im Graphen g und sucht zusammenhaengende Teilgraphen
	 *
	 * \param[in]  g		Graph
	 * \return Liste mit zusammenhaengenden Teilgraphen
	 */
	std::vector<int> ConnectedComponents(const Graph& g)  // Algorithm 6
	{
		std::vector<bool> marked(g.getV(), false);
		std::vector<int> id(g.getV(), 0);

		int count = 0;
		for (int s = 0; s < g.getV(); s++)
		{
			if (!marked[s])
			{
				TiefensucheRekursivModifConnectedComponents(g, s, marked, id, count);
				count++;
			}
		}

		return id;
	}

	/**
	 * Gibt zurueck, ob Knoten v und w im Graph g verbunden sind
	 *
	 * \param[in]  g		Graph
	 * \param[in]  v		Knoten1
	 * \param[in]  w		Knoten2
	 * \return Sind die Knoten v und w verbunden
	 */
	bool connected(const Graph& g, int v, int w)  // Folie 64
	{
		std::vector<int> id = ConnectedComponents(g);
		return id[v] == id[w];
	}

	/**
	 * Gibt die Teilgraph-Nummer vom Knoten v zurueck
	 *
	 * \param[in]  g		Graph
	 * \param[in]  v		Knoten
	 * \return Teilgraph-Nummer vom Knoten v
	 */
	bool id(const Graph& g, int v)  // Folie 64
	{
		std::vector<int> id = ConnectedComponents(g);
		return id[v];
	}

	/**
	 * Zaehlt die Teilgraphen im Graph g
	 *
	 * \param[in]  g		Graph
	 * \return Anzahl der Teilgraphen
	 */
	bool count(const Graph& g)  // Folie 64
	{
		std::vector<int> id = ConnectedComponents(g);
		return Utils::maximum(id) + 1;
	}
#pragma endregion
}