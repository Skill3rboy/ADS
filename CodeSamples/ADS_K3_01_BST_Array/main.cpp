#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main() {
	BinaryTree BST(10);
	vector<int> key{ 40, 60, 20, 30, 10, 50, 70 };
	for (int i=0;i<key.size();i++)
		BST.put(key[i], key[i] * 10);
	for (int i = 0; i < key.size(); i++)
		cout << key[i] << "->" << BST.get(key[i]) << "  ";
	cout << endl;
	system("PAUSE");
	return 0;
}