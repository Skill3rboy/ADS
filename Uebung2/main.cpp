// includes
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

unsigned long long int sum1(int n)
{
    unsigned long long int sum = 0;
    for (int i = 0; i < n; i++)
        sum++;
    return sum;
}
unsigned long long int sum2(int n)
{
    unsigned long long int sum = 0;
    for (int i = 1; i < n; i = i * 2)
        for (int j = 0; j < n; j++)
            sum++;
    return sum;
}
unsigned long long int sum3(int n)
{
    unsigned long long int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n * n; j++)
            sum++;
    return sum;
}
unsigned long long int sum4(int n)
{
    unsigned long long int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            sum++;
    return sum;
}
unsigned long long int sum5(int n)
{
    unsigned long long int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i * i; j++)
            for (int k = 0; k < j; k++)
                sum++;
    return sum;
}
unsigned long long int sum6(int n)
{
    unsigned long long int sum = 0;
    for (int i = 1; i < n; i++)
        for (int j = 1; j < i * i; j++)
            if (j % i == 0)
                for (int k = 0; k < j; k++)
                    sum++;
    return sum;
}
double timeit_no_x(unsigned long long int (*func)(int), int n, unsigned long long int &sum)
{
    // Ihre Loseung hier:
    std::fstream datei("datei.txt", std::ios::app); // gate öffnen

    auto start = std::chrono::steady_clock::now();               // Timer start
    sum = func(n);                                               // funktion call
    auto end = std::chrono::steady_clock::now();                 // timer end
    std::chrono::duration<double> elapsed_seconds = end - start; // duration

    // datei << "n: " << n << "  "
    datei << sum << "\n";
    //<< "Zeit: " << elapsed_seconds.count() << "\n";
    datei.close();

    return 0;
}

int main()
{
    unsigned long long int sum;
    for (int i = 100; i <= 10000; i = i + 100)
        timeit_no_x(sum5, i, sum);
    system("pause");
    return 0;
}