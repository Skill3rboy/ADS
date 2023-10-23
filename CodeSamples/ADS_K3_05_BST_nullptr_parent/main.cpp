#include <iostream>
#include "BinaryTree.h"
#include <vector>

using namespace std;

int main() {
	BinaryTree Baum_1;
	vector<int> Knoten{ 5,2,9,1,4,7,10,3,6,8 };

	Baum_1.put(99, 199);
	Baum_1.put(55, 555);
	Baum_1.remove(99);
	Baum_1.remove(55);

	for (int i = 0; i < Knoten.size(); i++) {
		Baum_1.put(Knoten[i], Knoten[i] * 100);
	}

	cout << Baum_1.get(7) << endl;
	cout << Baum_1.get(99) << endl;

	Baum_1.printInorder();
	Baum_1.printPreorder();
	Baum_1.printPostorder();
	Baum_1.printLevelorder();

	Baum_1.remove(99);
	Baum_1.remove(3);
	Baum_1.printLevelorder();
	Baum_1.put(3, 300);
	Baum_1.remove(4);
	Baum_1.printLevelorder();
	Baum_1.remove(5);
	Baum_1.printLevelorder();

	BinaryTree Baum_2;
	vector<int> Werte{ 40,20,60,10,30,50,70,55,52,58 };
	for (int i = 0; i < Werte.size(); i++) {
		Baum_2.put(Werte[i], Werte[i] * 100);
	}
	Baum_2.printLevelorder();
	Baum_2.remove(40);
	Baum_2.printLevelorder();
	Baum_2.put(80, 8000);
	Baum_2.remove(60);
	Baum_2.printLevelorder();
	Baum_2.remove(52);
	Baum_2.printLevelorder();
	Baum_2.remove(58);
	Baum_2.printLevelorder();
	Baum_2.remove(50);
	Baum_2.printLevelorder();
	Baum_2.remove(55);
	Baum_2.printLevelorder();
	Baum_2.remove(70);
	Baum_2.printLevelorder();
	Baum_2.remove(80);
	Baum_2.printLevelorder();
	Baum_2.remove(20);
	Baum_2.printLevelorder();
	Baum_2.remove(30);
	Baum_2.printLevelorder();
	Baum_2.remove(10);
	Baum_2.printLevelorder();

	BinaryTree Baum_3;
	vector<int> Werte2{ 10,20,15,30,25,40,22,50,23 };
	for (int i = 0; i < Werte2.size(); i++) {
		Baum_3.put(Werte2[i], Werte2[i] * 100);
	}
	Baum_3.printLevelorder();
	Baum_3.remove(20);
	Baum_3.printLevelorder();
	Baum_3.remove(22);
	Baum_3.printLevelorder();
	Baum_3.remove(23);
	Baum_3.printLevelorder();
	Baum_3.remove(25);
	Baum_3.printLevelorder();
	Baum_3.remove(30);
	Baum_3.printLevelorder();
	Baum_3.remove(40);
	Baum_3.printLevelorder();
	Baum_3.remove(50);
	Baum_3.printLevelorder();
	Baum_3.remove(15);
	Baum_3.printLevelorder();
	Baum_3.remove(10);
	Baum_3.printLevelorder();

	system("PAUSE");
	return 0;
}