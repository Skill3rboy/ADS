#include <iostream>
#include "Nodelist2Adjlist.h"
#include "Utils.h"

using namespace PrintUtils;

int main()
{
	std::vector<int> G = { 6, 11, 2, 2, 3, 0, 3, 1, 4, 6, 1, 1, 2, 3, 5, 3, 2, 4, 5 };  // Knotenliste
	std::map<int, std::vector<int>> G_adj = NodeList2Adjlist::nodelist2adjlist(G);  // Adjazenzliste

	std::cout << "Knotenliste: \n"
		<< G << std::endl
		<< "\nAdjazenzliste:\n" 
		<< G_adj << std::endl;

	std::system("PAUSE");
	return 0;
}