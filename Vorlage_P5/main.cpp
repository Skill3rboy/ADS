#define CATCH_CONFIG_RUNNER
#include "catch.h"
#include <iostream>
#include "EdgeWeightedGraph.h"
#include "PrimMST.h"
#include "Graphsearch.h"
#include "KruskalMST.h"
#include "DijkstraSP.h"

void printMenu();
EdgeWeightedGraph Menu1();
EdgeWeightedDigraph Menu1Di();
void printMST(std::vector<Edge> edges);
void printADJ(std::vector<std::vector<Edge>> adj);
void printADJD(std::vector<std::vector<DirectedEdge>> adj);
int main()
{
	// Starte Unit-Tests
	Catch::Session().run();
	/* // Kommentare
	//------------------------------------------------------------------------
	// 1. Ausgabe eines Graphen als Adjazenzliste implementieren
	//------------------------------------------------------------------------

	//------------------------------------------------------------------------
	// 2. Suche in Graphen
	//------------------------------------------------------------------------
	// Verwenden Sie hierf�r die Vorlagen in Graphsearch.h
	//
	// Beispielaufruf der Tiefensuche:
	// std::vector<bool> marked;
	// std::vector<int>  edgeTo;
	// bool connected = Graphsearch::DFS(G1, start, marked, edgeTo);

	//------------------------------------------------------------------------
	// 3. Minimaler Spannbaum mit Prim und Kruskal
	//------------------------------------------------------------------------
	// Vorlage f�r Prim ist die Klasse PrimMST (PrimMST.h + PrimMST.cpp)
	// Vorlage f�r Kruskal ist die Klasse KruskalMST (KruskalMST.h + KruskalMST.cpp)
	//
	// Beispielaufruf von Prim:
	// PrimMST prim(G, 0);

	//------------------------------------------------------------------------
	// 4. Kuerzeste Wege mit Dijkstra
	//------------------------------------------------------------------------
	// Beispielaufruf von Dijkstra
	//
	// EdgeWeightedDigraph G1_directed("graph1.txt");
	// Dijkstra dijkstra(G1_directed, start);
	// path = dijkstra.pathTo(target);

	//------------------------------------------------------------------------
	// 5. Men� f�r Benutzereingaben
	//------------------------------------------------------------------------
	// Alle Funktionalit�ten aus der Aufgabenstellung muessen umgesetzt werden
	*/
	int i = 0, k = 0;
	EdgeWeightedGraph G1(0);
	EdgeWeightedDigraph G2(0);
	std::vector<bool> marked;
	std::vector<int> edgeTo;
	while (true)
	{
		printMenu();
		std::cin >> i;

		if (i == 1) // Graph Einlesen
		{
			if (k != 0)
				throw;
			std::cout << "Waehle ob Normaler(1) oder Gerichteter Graph(2) :";
			std::cin >> k;
			if (k == 1)
				G1 = Menu1();
			else if (k == 2)
				G2 = Menu1Di();
		}
		else if (i == 2) // Tiefen suche
		{
			if (k == 2)
				throw;
			int y = 0;
			std::cout << "Knoten eingeben ";
			std::cin >> y;

			std::cout << "Tiefensuche (Depth-First-Search (DFS)) - Startknoten: " << y << std::endl;
			Graphsearch::DFS(G1, y, marked, edgeTo);
			std::cout << std::endl;
			std::cout << std::endl
					  << "EdgeTo liste:" << std::endl;
			for (size_t x = 0; x < edgeTo.size(); x++)
				std::cout << x << "-> " << edgeTo[x] << std::endl;
			std::cout << std::endl
					  << "Marked liste:" << std::endl;
			for (size_t x = 0; x < marked.size(); x++)
				std::cout << x << "-> " << std::boolalpha << marked[x] << std::endl;
			bool correct = true;
			for (size_t i = 0; i < marked.size(); i++)
				if (marked[i] == false)
					correct = false;
			if (correct)
				std::cout << std::endl
						  << "Graph ist zusammenhaengend" << std::endl;
			else
				std::cout << std::endl
						  << "Graph ist nicht zusammenhaengend" << std::endl;
		}
		else if (i == 3) // Breitensuche
		{
			if (k == 2)
				throw;
			int y = 0;
			std::cout << "Knoten eingeben ";
			std::cin >> y;

			std::cout << "Breitensuche (Breadth-First-Search (BFS)) - Startknoten: " << y << std::endl;
			Graphsearch::BFS(G1, y, marked, edgeTo);
			std::cout << std::endl;
			std::cout << std::endl
					  << "EdgeTo liste:" << std::endl;
			for (size_t x = 0; x < edgeTo.size(); x++)
				std::cout << x << "-> " << edgeTo[x] << std::endl;
			std::cout << std::endl
					  << "Marked liste:" << std::endl;
			for (size_t x = 0; x < marked.size(); x++)
				std::cout << x << "-> " << std::boolalpha << marked[x] << std::endl;
			bool correct = true;
			for (size_t i = 0; i < marked.size(); i++)
				if (marked[i] == false)
					correct = false;
			if (correct)
				std::cout << std::endl
						  << "Graph ist zusammenhaengend" << std::endl;
			else
				std::cout << std::endl
						  << "Graph ist nicht zusammenhaengend" << std::endl;
		}
		else if (i == 4) // MST nach Prim (Eingabe: Startknoten)
		{
			if (k == 2)
				throw;
			int y = 0;
			std::cout << "Knoten eingeben ";
			std::cin >> y;
			PrimMST mst(G1, 0);
			auto edges = mst.edges();
			std::cout << "Mininmaler Spannbaum(MST) nach Prim mit Knoten " << y << ": " << std::endl
					  << "Gewicht: " << mst.weight() << std::endl
					  << "Adjazenzliste: " << std::endl;
			printMST(edges);
		}
		else if (i == 5) // MST nach Kruskal
		{
			if (k == 2)
				throw;
			KruskalMST mst(G1);
			auto edges = mst.edges();
			std::cout << "Mininmaler Spannbaum(MST) nach Kruskal" << std::endl
					  << "Gewicht: " << mst.weight() << std::endl
					  << "Adjazenzliste: " << std::endl;
			printMST(edges);
		}
		else if (i == 6) // Kuerzeste Wege nach Dijkstra (Eingabe: Startknoten)
		{
			if (k == 1)
				throw;
			int start = 0,
				ziel = 0;
			std::cout << "Kuerzester Weg (Dijkstra): " << std::endl
					  << "Start: ";
			std::cin >> start;
			std::cout << "Ziel: ";
			std::cin >> ziel;
			std::cout << "Pfad: ";
			DijkstraSP dijkstra(G2, start);

			std::cout << start;
			for (DirectedEdge e : dijkstra.pathTo(ziel))
			{
				std::cout << " [" << e.weight() << "] "
						  << " -> " << e.to();
			}
			std::cout << std::endl
					  << "Kosten: " << dijkstra.distTo(ziel) << std::endl;
		}
		else if (i == 7) // Ausgabe der Adjazenzliste
		{
			if (k == 1)
				printADJ(G1.getAdj());
			else if (k == 2)
				printADJD(G2.getAdj());
		}
		else if (i == 8) // Kante loeschen
		{
			int A = 0, B = 0;
			double gewicht = 0;
			std::cout << "Welche Kante wird geloescht? A zu B mit Gewicht:";
			std::cin >> A;
			std::cin >> B;
			std::cin >> gewicht;
			Edge e(A, B, gewicht);
			DirectedEdge e1(A, B, gewicht);
			if (k == 1)
				G1.del_Edge(e);
			else if (k == 2)
				G2.del_Edge(e1);
		}
		else if (i == 9) // Kante hinzufuegen
		{
			int A = 0, B = 0;
			double gewicht = 0;
			std::cout << "Welche Kante wird Hinzugefuegt? A zu B mit Gewicht:";
			std::cin >> A;
			std::cin >> B;
			std::cin >> gewicht;
			Edge e(A, B, gewicht);
			DirectedEdge e1(A, B, gewicht);
			if (k == 1)
				G1.add(e);
			else if (k == 2)
				G2.add(e1);
		}
		else if (i == 10) // Programm beenden
			throw;
	}

	system("pause");
	return 0;
}

void printMenu()
{
	std::cout << std::endl
			  << "Prakikum 5: Graphenalgorithmen: " << std::endl
			  << "1) Graph einlesen " << std::endl
			  << "2) Tiefensuche" << std::endl
			  << "3) Breitensuche " << std::endl
			  << "4) Mst nach Prim(Eingabe: Startknoten)" << std::endl
			  << "5) Mst nach Kruskal " << std::endl
			  << "6) Kuerzeste Wege nach Dijkstra(Eingabe: Startknoten)" << std::endl
			  << "7) Ausgabe der Adjazenliste " << std::endl
			  << "8) Kante Loeschen" << std::endl
			  << "9) Kante Hinzufuegen" << std::endl
			  << "10) Programm Beenden" << std::endl;
}

EdgeWeightedGraph Menu1()
{
	int i = 0;

	std::cout
		<< "Waehlen sie zwischen den 1-3 Graphen: ";
	std::cin >> i;
	if (i == 1)
	{
		EdgeWeightedGraph G("graph1.txt");
		return G;
	}
	else if (i == 2)
	{
		EdgeWeightedGraph G("graph2.txt");
		return G;
	}
	else if (i == 3)
	{
		EdgeWeightedGraph G("graph3.txt");
		return G;
	}
	else
	{
		std::cout << " Fehler, Eingabe muss zwischen 1-3 sein" << std::endl;
		return Menu1();
	}
}
EdgeWeightedDigraph Menu1Di()
{
	int i = 0;

	std::cout
		<< "Waehlen sie zwischen den 1-3 Graphen: ";
	std::cin >> i;
	if (i == 1)
	{
		EdgeWeightedDigraph G("graph1.txt");
		return G;
	}
	else if (i == 2)
	{
		EdgeWeightedDigraph G("graph2.txt");
		return G;
	}
	else if (i == 3)
	{
		EdgeWeightedDigraph G("graph3.txt");
		return G;
	}
	else
	{
		std::cout << " Fehler, Eingabe muss zwischen 1-3 sein" << std::endl;
		return Menu1Di();
	}
}

void printMST(std::vector<Edge> edges)
{
	for (size_t i = 0; i < edges.size(); i++)
	{
		std::cout << i;
		for (size_t j = 0; j < edges.size(); j++)
		{
			if (size_t(edges[j].either()) == i)
			{
				std::cout << " -> " << edges[j].other(i) << " [" << edges[j].weight() << "] ";
			}
		}
		std::cout << std::endl;
	}
}

void printADJ(std::vector<std::vector<Edge>> adj)
{
	for (size_t i = 0; i < adj.size(); i++)
	{
		std::cout << i;
		for (size_t k = 0; k < adj[i].size(); k++)
		{
			std::cout << " -> " << adj[i][k].other(i) << "[" << adj[i][k].weight() << "]";
		}
		std::cout << std::endl;
	}
}

void printADJD(std::vector<std::vector<DirectedEdge>> adj)
{
	for (size_t i = 0; i < adj.size(); i++)
	{
		std::cout << i;
		for (size_t k = 0; k < adj[i].size(); k++)
		{
			if (size_t(adj[i][k].from()) == i)
				std::cout << " -> " << adj[i][k].to() << "[" << adj[i][k].weight() << "]";
		}
		std::cout << std::endl;
	}
}
