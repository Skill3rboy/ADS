#include <iostream>
#include <chrono>
#include <vector>
#include <functional>
#include <iomanip>

typedef unsigned long long ull;

namespace recursive {
/**
 * Fibonacci-Zahlen rekursiv berechnen
 *
 * \return es wird die n'te Fibonacci-Zahl zurückgegeben
 */
ull fib(ull const n) {
	if (n <= 1) return n;
	else return fib(n - 1) + fib(n - 2);
}
} // namespace recursive

namespace iterative {
/**
 * Fibonacci-Zahlen iterativ berechnen 
 *
 * \return es wird die n'te Fibonacci-Zahl zurückgegeben
 */
ull fib(ull const n) {
	std::vector<ull> fib_array(n+1,0);
	if (n > 0) {
		fib_array[1] = 1;
		for (ull i = 2; i <= n; ++i) {
			fib_array[i] = fib_array[i - 2] + fib_array[i - 1];
		}
	}
	return fib_array[n];
}
} // namespace iterative

/**
 * Laufzeitenbestimmung für verschiedene Fibonacci-Funktionen in Abhängigkeit von N
 *
 * \param[in] fib_func Fibonacci-Function
 * \param[in] N	Array mit den verschiedenen Testgrößen
 * \param[in] func_name Name der Funktion
 */
void runtime_test(std::function<ull(ull)> fib_func, std::vector<ull> const& N, std::string func_name) {
	for (auto const& n : N) {
		auto start = std::chrono::high_resolution_clock::now();
		auto fib = fib_func(n);
		auto finish = std::chrono::high_resolution_clock::now();
		std::cout << func_name <<"(" << n << ") = " << std::left << std::setw(21) <<fib << std::chrono::duration<double, std::milli>(finish - start).count() << "[ms]" << std::endl;
	}
}

int main() {
	std::vector<ull> N{ 10,20, 30, 40, 50 };
	runtime_test(recursive::fib, N, "recusrive::fib");

	N.clear();
	N = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 91, 93 /*Werte > 93 sind zu groß für unsigned long long*/};
	runtime_test(iterative::fib, N, "iterative::fib");

	}