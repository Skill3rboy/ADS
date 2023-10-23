#pragma once
#include <vector>

// Basierend auf: Data Structures and Algorithm Analysis in C++, Mark Allen Weiss

inline int leftChildIdx(int idx) {
	return 2 * idx + 1;
}

template<typename T>
void percolateDown(std::vector<T>& A, int i, int N)
{
	int child;
	T tmp;
	for (tmp = A[i]; leftChildIdx(i) < N; i = child) {
		child = leftChildIdx(i);
		if (child != N - 1 && A[child] < A[child + 1ll]) {
			child++;
		}
		if (tmp < A[child]) {
			A[i] = A[child];
		}
		else {
			break;
		}
	}
	A[i] = tmp;
}

namespace sort {
	template<typename T>
	void heapSort(std::vector<T>& A) {
		// Heap aufbauen
		for (int i = A.size() / 2; i >= 0; i--) {
			percolateDown(A, i, A.size());
		}
		// Sortieren
		for (int i = A.size() - 1; i > 0; i--) {
			std::swap(A[0], A[i]);
			percolateDown(A, 0, i);
		}
	}
}