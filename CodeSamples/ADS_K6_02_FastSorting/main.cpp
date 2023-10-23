#include <iostream>
#include <vector>
#include <functional>
#include <chrono>
#include <random>
#include <numeric>

#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"

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

enum class TestMode { sorted, shuffle, reversed };

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
void testSortingAlgorithm(std::string name, std::function<void(std::vector<T>&)> sort_func, unsigned N, bool printDataset = true, TestMode mode = TestMode::shuffle) {
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
	testSortingAlgorithm<int>("Merge Sort", sort::mergeSort<int>, N);
	testSortingAlgorithm<int>("Quick Sort", sort::quickSort<int>, N);
	testSortingAlgorithm<int>("Heap Sort", sort::heapSort<int>, N);

	// Test mit groﬂen Arrays
	N = 10000;
	testSortingAlgorithm<int>("Merge Sort", sort::mergeSort<int>, N, false);
	testSortingAlgorithm<int>("Quick Sort", sort::quickSort<int>, N, false);
	testSortingAlgorithm<int>("Heap Sort", sort::heapSort<int>, N, false);
}
