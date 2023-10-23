#pragma once
#include <vector>
#include <map>
namespace NodeList2Adjlist
{
	/**
	 * Wandelt eine Knotenliste in eine Adjazenzliste um
	 *
	 * \param[in]  a		Knotenliste
	 * \return Adjazenzliste
	 */
	std::map<int, std::vector<int>> nodelist2adjlist(const std::vector<int>& a)  // Folie 35
	{
		int V = a[0];
		int E = a[1];
		
		int nodelistSize = V + E + 2;
		
		int i = 2; int j = 1;
		
		std::map<int, std::vector<int>> adj;

		while (i < nodelistSize)
		{
			int ag = a[i];
			adj[j];
			for (int k = i + 1; k < i + ag + 1; k++)
			{
				int node = a[k];
				adj[j].push_back(node);
			}
			i = i + ag + 1;
			j++;
		}

		return adj;
	}
}