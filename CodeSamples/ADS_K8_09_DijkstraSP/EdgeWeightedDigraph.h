#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <assert.h>
#include <iomanip>
#include "DirectedEdge.h"


class EdgeWeightedDigraph  // Folie 79
{
private:
	int V;  // Anzahl der Knoten
	int E;  // Anzahl der Kanten
	std::vector<std::vector<DirectedEdge>> adj;  // Adjazenzliste

	/**
	 * Gibt zurueck ob der Knoten v ein gueltiger Knoten im Graph ist
	 *
	 * \param[in]  v		Knoten
	 * \return Gueltigkeit des Knoten
	 */
	bool validateVertex(int v) const
	{
		return v >= 0 && v < this->V;
	}

	/**
	 * Gibt eine Fehlermeldung aus, wenn der Knoten v im Graph nicht gueltig ist
	 *
	 * \param[in]  v		Knoten
	 */
	void validateVertexWithError(int v) const
	{
		assert(("Vertex is out of bounds!", this->validateVertex(v)));
	}
public:


	/**
	 * Erstellt einen Kantengewichteten-Gaph mit V Knoten
	 *
	 * \param[in]  V		Anzahl der Knoten
	 */
	EdgeWeightedDigraph(int V) : V{ V }, E{ 0 } { adj.resize(V); }

	/**
	* Erstellt einen Kantengewichteten-Gaph anhand der Kantenliste in fname
	*
	* \param[in]  fname		Dateiname der Kantenliste
	*/
	EdgeWeightedDigraph(std::string fname)
	{
		std::ifstream infile(fname);
		int tmp_e = 0;
		infile >> this->V >> tmp_e;

		this->E = 0;

		this->adj.resize(this->V, std::vector<DirectedEdge>());

		int v, w;
		double weight;
		while (infile >> v >> w >> weight)
		{
			this->add(DirectedEdge(v, w, weight));
		}

		assert(("Missing edges!", tmp_e == this->E));
	}

	/**
	 * Erstellt einen Kantengewichteten-Gaph mit V Knoten und den Kanten in edges
	 *
	 * \param[in]  V		Anzahl der Knoten
	 * \param[in]  edges	Kantenliste
	 */
	EdgeWeightedDigraph(int V, std::vector<DirectedEdge> edges)
	{
		this->V = V;
		this->adj.resize(V);

		for (DirectedEdge e : edges)
		{
			this->add(e);
		}
	}

#pragma region getter
	/**
	 * Gibt die Anzahl der Knoten zurueck
	 *
	 * \return Anzahl der Knoten
	 */
	int getV() const { return V; }

	/**
	 * Gibt die Anzahl der Kanten zurueck
	 *
	 * \return Anzahl der Kanten
	 */
	int getE() const { return E; }
#pragma endregion

	/**
	 * Fuegt die Kante e zum Graphen hinzu
	 *
	 * \param[in]  e		Kante
	 */
	void add(DirectedEdge e)
	{
		this->validateVertexWithError(e.from());
		this->validateVertexWithError(e.to());

		this->adj[e.from()].push_back(e);

		this->E++;
	}

	/**
	 * Bestimmt des Grad eine Knoten v im Graph g
	 *
	 * \return Grad des Knoten v im Graph g
	 */
	int degree(int v) const { return this->adj[v].size(); }

	/**
	 * Gibt die Kantenliste eines Knoten v zurueck
	 *
	 * \param[in]  v		Knoten
	 * \return Vektor mit den Kanten vom Knoten v
	 */
	const std::vector<DirectedEdge> operator[](int v) const { return this->adj[v]; }


	/**
	 * Gibt die Summe aller Gewichte im Graphen zurueck
	 *
	 * \return Summe aller Gewichte
	 */
	double totalWeight() const
	{
		double totalWeight = 0;
		for (DirectedEdge e : this->edges())
		{
			totalWeight += e.weight();
		}

		return totalWeight;
	}

	/**
	 * Gibt alle Kanten im Graph zurueck
	 *
	 * \return Vektor mit allen Kanten im Graph
	 */
	std::vector<DirectedEdge> edges() const
	{
		std::vector<DirectedEdge> list;
		for (int v = 0; v < this->V; v++)
		{
			for (DirectedEdge e : this->adj[v])
			{
				list.push_back(e);
			}
		}
		return list;
	}

	/**
	 * Gibt den Kantengewichteten-Graph aus
	 *
	 * \param[in]  stream	Ausgabestream
	 * \param[in]  graph	Der auszugebende Graph
	 * \return Ausgabestream
	 */
	friend std::ostream& operator<<(std::ostream& stream, const EdgeWeightedDigraph& ewg)
	{
		stream << ewg.V << " vertecies and " << ewg.E << " edges [totalWeight: " << ewg.totalWeight() << "]" << std::endl;
		for (int i = 0; i < ewg.V; i++)
		{
			stream << i << ":\t[";
			for (int j = 0; j < ewg[i].size(); j++)
			{
				stream << ewg[i][j];
				if (j < ewg[i].size() - 1)
				{
					stream << ", ";
				}
				else {
					stream << "]\n";
				}
			}
		}
		return stream;
	}
};