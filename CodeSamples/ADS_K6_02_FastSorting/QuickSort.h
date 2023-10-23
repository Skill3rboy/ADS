#pragma once
#include <vector>

template<typename T>
int partition(std::vector<T>& A, int p, int r) {
	auto x = A[r];
	auto i = p-1;
	for (auto j = p; j < r; j++) {
		if (A[j] <= x) {
			++i;
			std::swap(A[i], A[j]);
		}
	}
	std::swap(A[i + 1ll], A[r]);
	return i + 1;
}

template<typename T>
void quickSort(std::vector<T>& A, int p, int r) {
	if (p < r) {
		auto q = partition<T>(A, p, r);
		quickSort<T>(A, p, q - 1);
		quickSort<T>(A, q + 1, r);
	}
}

namespace sort {
	template<typename T>
	void quickSort(std::vector<T>& A) {
		::quickSort<T>(A, 0, A.size() - 1);
	}
}