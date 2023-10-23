#pragma once
#include <vector>

template<typename T>
void merge(std::vector<T>& A, int l, int m, int r) {
	size_t i, j, k;
	const size_t n1 = m - l + 1;
	const size_t n2 = r - m;

	// linkes (L) und rechtes (R) Array füllen
	std::vector<int> L(n1);
	std::vector<int> R(n2);
	for (i = 0; i < n1; i++) {
		L[i] = A[l + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = A[m + 1 + j];
	}
	// Zählervariablen zurücksetzen
	i = 0;
	j = 0;
	k = l;
	// Mergen der beiden Arrays (vector)
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
		k++;
	}
	// Kopieren von restlichen Elementen aus L (wenn exsistent)
	while (i < n1) {
		A[k] = L[i];
		i++;
		k++;
	}
	// Kopieren von restlichen Elementen aus R (wenn exsistent)
	while (j < n2) {
		A[k] = R[j];
		j++;
		k++;
	}
}

template<typename T>
void mergeSort(std::vector<T>& A, int l, int r) {
	if (l < r) {
		size_t m = size_t(std::floor((l + r) / 2));
		mergeSort<T>(A, l, m);
		mergeSort<T>(A, m + 1, r);
		merge<T>(A, l, m, r);
	}
}

namespace sort {
	template<typename T>
	void mergeSort(std::vector<T>& A) {
		::mergeSort<T>(A, 0, A.size() - 1);
	}
}

