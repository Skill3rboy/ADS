#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print(int item) {
	cout << item << " ";
}

int main() {
	vector<int> a;
	a.push_back(10);
	a.push_back(20);
	a.push_back(30);
	a.push_back(40);
	a.push_back(50);
	a.pop_back();

	// classic C++98 for loop
	cout << "classic C++98 for loop: ";
	for (int i = 0; i < (int)a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	// C++98 for loop with iterators
	cout << "C++98 for loop with iterators: ";
	vector<int>::iterator it;
	for (it = a.begin(); it != a.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	// C++11 range-based for loop
	cout << "C++11 range - based for loop: ";
	for (auto const& item : a) {
		cout << item << " ";
	}
	cout << endl;

	// C++11 std::for_each
	cout << "C++11 std::for_each: ";
	std::for_each(a.begin(), a.end(), print);
	cout << endl;

	// C++11 std::for_each with lambda
	cout << "C++11 std::for_each with lambda: ";
	std::for_each(a.begin(), a.end(), [](const int &item) { cout << item << " "; });
	cout << endl;
}