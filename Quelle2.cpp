// includes
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

int sum1(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum++;
    return sum;
}
int sum2(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i = i * 2)
        for (int j = 0; j < n; j++)
            sum++;
    return sum;
}
int sum3(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n * n; j++)
            sum++;
    return sum;
}
int sum4(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            sum++;
    return sum;
}
int sum5(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i * i; j++)
            for (int k = 0; k < j; k++)
                sum++;
    return sum;
}
int sum6(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
        for (int j = 1; j < i * i; j++)
            if (j % i == 0)
                for (int k = 0; k < j; k++)
                    sum++;
    return sum;
}
double timeit_no_x(int (*func)(int), int n, int& sum)
{
    // Ihre Loseung hier:
    std::fstream datei("datei.txt", std::ios::app); // gate öffnen

    auto start = std::chrono::steady_clock::now();               // Timer start
    sum = func(n);                                               // funktion call
    auto end = std::chrono::steady_clock::now();                 // timer end
    std::chrono::duration<double> elapsed_seconds = end - start; // duration

    datei << "n: " << n << "  "
        << "sum: " << sum << "    "
        << "Zeit: " << elapsed_seconds.count() << "\n";
    datei.close();

    return 0;
}

int main()
{
    int sum;
    for (int i = 100; i <= 10000; i = i + 100)
        timeit_no_x(sum3, i, sum);
    system("pause");
    return 0;
}