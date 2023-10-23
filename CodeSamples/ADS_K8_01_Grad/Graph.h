#pragma once

#include <vector>
#include <cassert>
#include <string>
#include <ostream>
#include <fstream>

#include "Utils.h"

class Graph
{
public:

#pragma region constructor
	/**
	 * Erstellt einen Gaph mit V Knoten
	 *
	 * \param[in]  V		Anzahl der Knoten
	 */
	Graph(int V) : V{ V }, E{ 0 } {
		this->adj.resize(V, std::vector<int>());
	}

	/**
	 * Erstellt einen Gaph anhand der Kantenliste in fname
	 *
	 * \param[in]  fname		Dateiname der Kantenliste
	 */
	Graph(std::string fname);
#pragma endregion

#pragma region getter
	/**
	 * Gibt die Anzahl der Knoten zurueck
	 *
	 * \return Anzahl der Knoten
	 */
	int getV() const;

	/**
	 * Gibt die Anzahl der Kanten zurueck
	 *
	 * \return Anzahl der Kanten
	 */
	int getE() const;
#pragma endregion

	/**
	 * Fuegt eine Kante zwischen den Knoten v und w hinzu
	 *
	 * \param[in]  v		Knoten 1
	 * \param[in]  w		Knoten 2
	 */
	void addEdge(int v, int w);

	/**
	 * Entfernt eine Kante zwischen den Knoten v und w hinzu
	 *
	 * \param[in]  v		Knoten 1
	 * \param[in]  w		Knoten 2
	 * \return Erfolgreich entfernt
	 */
	bool removeEdge(int v, int w);

	/**
	 * Bestimmt des Grad eine Knoten v im Graph g
	 *
	 * \return Grad des Knoten v im Graph g
	 */
	int degree(int v);

	/**
	 * Gibt die verbunden Knoten eines Knoten v zurueck
	 *
	 * \param[in]  v		Knoten
	 * \return Verbunden Knoten des Knoten v
	 */
	const std::vector<int> operator[](int v) const;


	/**
	 * Gibt den Graphen aus
	 *
	 * \param[in]  stream	Ausgabestream
	 * \param[in]  graph	Der auszugebende Graph
	 * \return Ausgabestream
	 */
	friend std::ostream& operator<<(std::ostream& stream, const Graph& graph);

private:
	int V;  // Anzahl der Knoten im Graph
	int E;  // Anzahl der Kanten im Graph
	std::vector<std::vector<int>> adj;  // Adjazenzliste

	/**
	 * Gibt zurueck ob der Knoten v ein gueltiger Knoten im Graph ist
	 *
	 * \param[in]  v		Knoten
	 * \return Gueltigkeit des Knoten
	 */
	bool validateVertex(int v) const;

	/**
	 * Gibt eine Fehlermeldung aus, wenn der Knoten v im Graph nicht gueltig ist
	 *
	 * \param[in]  v		Knoten
	 */
	void validateVertexWithError(int v) const;
};

