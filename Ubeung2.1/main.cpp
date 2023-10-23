// includes
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

int g(int a)
{
    return a % 2 == 0;
}
int gtest(int li, int re)
{
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    if (li > re)
        return 0;
    int m = (li + re) / 2;
    return gtest(li, m - 1) + g(a[m - 1]) + gtest(m + 1, re);
}
int gtestI(int li, int re)
{
    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    if (li > re)
        return 0;

    int m = 0;
    int j = 0;
    for (int i = 0; i < re; i++)
    {
        m += a[i];
        j++;
    }
    return (m / j);
}
int main()
{
    for (int n = 1; n <= 10; n++)
        std::cout << n << ". Output: " << gtest(1, n) << std::endl;
    std::cout << std::endl
              << std::endl;
    for (int n = 1; n <= 10; n++)
        std::cout << n << ". Output: " << gtestI(1, n) << std::endl;

    system("pause");
    return 0;
}