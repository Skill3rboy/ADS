#pragma once
#include <iostream>
#include <iomanip>


class Edge  // Folie 78
{
private:
	int v;  // Knoten 1
	int w;  // Knoten 2
	double wei;  // Kantengewicht
public:
	/**
	 * Erstellt eine Kante zwischen Knoten v und w mit gewicht weight
	 *
	 * \param[in]  v		Knoten 1
	 * \param[in]  w		Knoten 2
	 * \param[in]  weight	Kantengewicht
	 */
	Edge(int v, int w, double weight) : v{ v }, w{ w }, wei{ weight } {}

	/**
	 * Gibt das Kantengewicht zurueck
	 *
	 * \return Kantengewicht
	 */
	double weight() const { return wei; }

	/**
	 * Gibt Knoten 1 zurueck
	 *
	 * \return Knoten 1
	 */
	int either() const { return v; }

	/**
	 * Gibt den anderen Knoten als vertex zurueck
	 *
	 * \param[in]  vertex	Einer der beiden Knoten
	 * \return Den anderen Knoten als vertex
	 */
	int other(int vertex) const
	{
		if (vertex == v) return w;
		else if (vertex == w) return v;
		else throw new std::invalid_argument("Illegal endpoint");
	}

	/**
	 * Gibt die Kante aus
	 *
	 * \param[in]  stream	Ausgabestream
	 * \param[in]  edge		Die auszugebende Kante
	 * \return Ausgabestream
	 */
	friend std::ostream& operator<<(std::ostream& stream, const Edge& edge) {
		stream << std::setw(3) << std::setfill(' ') << edge.v << "->" << std::setw(3) << edge.w << ' ' << std::fixed << std::setprecision(2) << std::setfill('0') << edge.wei;
		return stream;
	}
};

/**
* Vergleicht zwei Kantengwichte
*
* \param[in]  lhs		Kante 1
* \param[in]  rhs		Kante 2
* \return true, wenn das Gewicht von Kante 1 und Kante 2 gleich ist. Ansonsten false
*/
inline bool operator==(const Edge& lhs, const Edge& rhs) { return lhs.weight() == rhs.weight(); }

/**
* Vergleicht zwei Kantengwichte
*
* \param[in]  lhs		Kante 1
* \param[in]  rhs		Kante 2
* \return true, wenn das Gewicht von Kante 1 und Kante 2 ungleich ist. Ansonsten false
*/
inline bool operator!=(const Edge& lhs, const Edge& rhs) { return !operator==(lhs, rhs); }

/**
* Vergleicht zwei Kantengwichte
*
* \param[in]  lhs		Kante 1
* \param[in]  rhs		Kante 2
* \return true, wenn das Gewicht von Kante 1 kleiner als das von Kante 2 ist. Ansonsten false
*/
inline bool operator< (const Edge& lhs, const Edge& rhs) { return lhs.weight() < rhs.weight(); }

/**
* Vergleicht zwei Kantengwichte
*
* \param[in]  lhs		Kante 1
* \param[in]  rhs		Kante 2
* \return true, wenn das Gewicht von Kante 1 groesser als das von Kante 2 ist. Ansonsten false
*/
inline bool operator> (const Edge& lhs, const Edge& rhs) { return  operator< (rhs, lhs); }

/**
* Vergleicht zwei Kantengwichte
*
* \param[in]  lhs		Kante 1
* \param[in]  rhs		Kante 2
* \return true, wenn das Gewicht von Kante 1 kleiner oder gleich, wie das von Kante 2 ist. Ansonsten false
*/
inline bool operator<=(const Edge& lhs, const Edge& rhs) { return !operator> (lhs, rhs); }

/**
* Vergleicht zwei Kantengwichte
*
* \param[in]  lhs		Kante 1
* \param[in]  rhs		Kante 2
* \return true, wenn das Gewicht von Kante 1 groesser oder gleich, wie das von Kante 2 ist. Ansonsten false
*/
inline bool operator>=(const Edge& lhs, const Edge& rhs) { return !operator< (lhs, rhs); }