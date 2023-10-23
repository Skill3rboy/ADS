#include <iostream>
#include <vector>
#include <numeric>
#include <random>
#include <functional>
#include <chrono>

/**
 * Shell-Sort Algrotihmus
 *
 * \param[in/out] A unsortiere Zahlenfolge als Input und sortierte Zahlenfolge als Output
 */
template<typename T>
void shellSort(std::vector<T>& A) {
	auto N = A.size();
	// Schleife ¸ber die Abstandsfolge
	for (auto gap = N / 2; gap > 0; gap /= 2) {
		// Insertion Sort von Elementen mit Abstand gap
		for (auto i = gap; i < N; i++) {
			T tmp = A[i];
			auto j = i;
			for (; j >= gap && tmp < A[j - gap]; j -= gap) {
				A[j] = A[j - gap];
			}
			A[j] = tmp;
		}
		// Elemente sind im Abstand gap sortiert
	}
}

/**
 * Bubble-Sort (verbesserter) Algrotihmus
 *
 * \param[in/out] A unsortiere Zahlenfolge als Input und sortierte Zahlenfolge als Output
 */
template<typename T>
void bubbleSort2(std::vector<T>& A) {
	for (size_t i = 0; i < A.size() - 1; ++i) {
		auto isChanged{ false };
		auto j = A.size() - 1;
		while (j > i) {
			if (A[j] < A[j - 1]) {
				std::swap(A[j], A[j - 1]);
				isChanged = true;
			}
			j--;
		}
		if (!isChanged) return;
	}
}

/**
 * Bubble-Sort Algrotihmus
 *
 * \param[in/out] A unsortiere Zahlenfolge als Input und sortierte Zahlenfolge als Output
 */
template<typename T>
void bubbleSort(std::vector<T>& A) {
	for (size_t i = 0; i < A.size() - 1; ++i) {
		auto j = A.size() - 1;
		while (j > i) {
			if (A[j] < A[j - 1]) {
				std::swap(A[j], A[j - 1]);
			}
			j--;
		}
	}
}

/**
 * Selection-Sort Algrotihmus
 *
 * \param[in/out] A unsortiere Zahlenfolge als Input und sortierte Zahlenfolge als Output
 */
template<typename T>
void selectionSort(std::vector<T>& A) {
	for (size_t i = 0; i < A.size(); ++i) {
		auto min = i;
		for (int j = i; j < A.size(); ++j) {
			if (A[j] < A[min])
				min = j;
		}
		std::swap(A[min], A[i]);
	}
}

/**
 * Insertion-Sort Algrotihmus
 *
 * \param[in/out] A unsortiere Zahlenfolge als Input und sortierte Zahlenfolge als Output
 */
template<typename T>
void insertionSort(std::vector<T>& A) {
	for (int i = 1; i < A.size(); ++i) {
		auto key = A[i];
		auto j = i - 1;
		while (j >= 0 && A[j] > key) {
			A[j + 1ll] = A[j];
			j--;
		}
		A[j + 1ll] = key;
	}
}

/**
 * Hilfsmethode um ein std::vector auszugeben
 *
 * \param[in] A std::vector mit den Daten
 */
template<typename T>
void printArray(std::vector<T> const& A) {
	for (auto const& num : A) {
		std::cout << num << " ";
	}
	std::cout << std::endl;
}

enum class TestMode {sorted, shuffle, reversed};

/**
 * Laufzeitenbestimmung f¸r verschiedene Sortieralgorithmen in Abh‰ngigkeit von N
 *
 * \param[in] sort_func Name der Sortierfunktion
 * \param[in] sort_func Sortieralgorithmus (Implementierung)
 * \param[in] N	Testgrˆﬂe
 * \param[in] printDataset (default=true) gibt die generierten Zahlen aus
 * \param[in] mode gibt den Test-Modus der Zahlenfolge vor (default=shuffle)
 */
template<typename T>
void testSortingAlgorithm(std::string name, std::function<void(std::vector<T>&)> sort_func, unsigned N, bool printDataset=true, TestMode mode=TestMode::shuffle) {
	// Daten vorbereiten
	std::vector<T> numbers(N);
	std::iota(numbers.begin(), numbers.end(), 0);
	if (mode == TestMode::shuffle) {
		std::shuffle(numbers.begin(), numbers.end(), std::mt19937{ std::random_device{}() });
	}
	else if (mode == TestMode::reversed) {
		std::reverse(numbers.begin(), numbers.end());
	}
	// Daten anzeigen
	std::cout << name << std::endl;
	if (printDataset) printArray(numbers);
	// Start der Zeitmessung
	auto start = std::chrono::high_resolution_clock::now();
	// Sortieren der Daten
	sort_func(numbers);
	auto finish = std::chrono::high_resolution_clock::now();
	// Ergebinis + benˆtige Rechenzeit ausgeben
	if (printDataset) printArray(numbers);
	std::cout << "time: " << std::chrono::duration<double, std::milli>(finish - start).count() << "[ms]" << std::endl << std::endl;
}


int main() {

	// Test mit kleinen Arrays
	auto N = 25;
	testSortingAlgorithm<int>("Insertion sort", insertionSort<int>, N, true, TestMode::shuffle);
	testSortingAlgorithm<int>("Selection sort", selectionSort<int>, N);
	testSortingAlgorithm<int>("Bubble sort", bubbleSort<int>, N);
	testSortingAlgorithm<int>("Bubble sort 2", bubbleSort2<int>, N);
	testSortingAlgorithm<int>("Shell sort", shellSort<int>, N);


	// Test mit groﬂen Arrays (keine Ausgabe der Zahlen)
	N = 100000;
	testSortingAlgorithm<int>("Insertion sort", insertionSort<int>, N, false, TestMode::shuffle);
	testSortingAlgorithm<int>("Selection sort", selectionSort<int>, N, false);
	testSortingAlgorithm<int>("Bubble sort", bubbleSort<int>, N, false);
	testSortingAlgorithm<int>("Bubble sort 2", bubbleSort2<int>, N, false);
	testSortingAlgorithm<int>("Shell sort", shellSort<int>, N, false);
}