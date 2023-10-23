// includes
#include <iostream>
#include <vector>
#include <limits>
#include <math.h>
using namespace std;

// fuer eine bessere Lesbarkeit:
// int INT_MAX = std::numeric_limits<int>::max();

// Aufgabe 1
//
//
// Gegeben sei die folgende Zahlenfolge:
std::vector<int> nums = {19, 85, 27, 22, 83, 95, 73, 28, 53, 20};

// Optionale Hilfsfunktion zur Ausgabe von Vectoren hier:
void print(std::vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec.at(i) << "  |  ";
    }
    std::cout << std::endl;
}
// Zeigen Sie das Ablaufprotokoll, wenn Sie die Folge in aufsteigender Reihenfolge mit den folgenden Verfahren sortieren.
//
// 1.Selection Sort
// 2.Insertion Sort
// 3.BubbleSort
// Geben Sie das Array nach jedem einzelnen Sortierdurchlauf aus.

// SelectionSort
std::vector<int> selection_sort(std::vector<int> vec)
{
    // Ihre Loseung hier
    int min;
    int N = vec.size();
    for (int i = 0; i < N; i++)
    {
        min = i;
        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[min])
                min = j;
        }
        std::swap(vec[min], vec[i]);
        print(vec);
    }
    return vec;
}

// InsertionSort
std::vector<int> insertion_sort(std::vector<int> vec)
{
    int N = vec.size();
    for (int i = 1; i < N; i++)
    {
        int tmp = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > tmp)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = tmp;
        print(vec);
    }
    // Ihre Loseung hier
    return vec;
}

// BubbleSort
std::vector<int> bubble_sort(std::vector<int> vec)
{
    // Ihre Loseung hier
    int N = vec.size();
    int k;
    for (int i = 0; i < N; i++)
    {
        k = N - 1;
        while (k > i)
        {
            if (vec[k] < vec[k - 1])
                std::swap(vec[k], vec[k - 1]);
            k--;
        }
        print(vec);
    }
    return vec;
}
// Aufgabe 2

// Zeigen Sie das Ablaufprotokoll analog zur Aufgabe 1 wie ShellSort das Array :

std::vector<int> nums_shell = {16, 45, 33, 98, 14, 19, 8, 11, 49, 97};

// sortiert. Verwenden Sie zur Sortierung die folgende Abstandsfolge Hneu = 2Halt + 1.

std::vector<int> shell_sort(std::vector<int> vec)
{
    // Ihre Loesung hier:
    int N = vec.size();
    for (int gap = 1; gap < N; gap = 2 * gap + 1)
    {
        for (int i = gap; i < N; i++)
        {
            int tmp = vec[i];
            int j = i;
            while (j >= gap && tmp < vec[j - gap])
            {
                vec[j] = vec[j - gap];
                j = j - gap;
            }
            vec[j] = tmp;
            print(vec);
        }
    }
    return vec;
}

// Aufgabe 3

// Gegeben sei die folgende Folge :

std::vector<int> nums_adv = {50, 45, 30, 42, 20, 98, 11, 22, 33, 60};

// Sortieren Sie die Folge in aufsteigender Reihenfolge mit :
//
// 1.Quick Sort
// 2.Merge Sort
// 3.Heap Sort
// Geben Sie jeweils das Zwischenergebnis des gesamten Arrays nach jedem Durchlauf aus.
// Geben Sie zu QuickSort und MergeSort jeweils die rekursiven Aufrufe aus und geben Sie beim HeapSort dasjenige Element aus,
// das bei jedem Schritt durchsickert(perc_down - Element).

int partition(std::vector<int> &vec, int p, int r)
{
    // Ihre Loesung hier:
    int x = vec[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (vec[j] <= x)
        {
            ++i;
            std::swap(vec[i], vec[j]);
            print(vec);
        }
    }
    std::swap(vec[i + 1ll], vec[r]);
    return i + 1;
}

void quick_sort(std::vector<int> &vec, int p, int r)
{
    // Ihre Loesung hier:
    if (p < r)
    {
        int q = partition(vec, p, r);
        quick_sort(vec, p, q - 1);
        quick_sort(vec, q + 1, r);
    }
}

// Startfunktion:
std::vector<int> quick_sort(std::vector<int> vec)
{
    std::vector<int> tmp = vec;

    // int center = (tmp[0] + tmp[tmp.size() - 1]) / 2;
    // int right = tmp.size() - 1;
    // if (tmp[center] < tmp[0])
    // {
    //     std::swap(tmp[0], tmp[center]);
    // }
    // if (tmp[right] < tmp[0])
    // {
    //     std::swap(tmp[0], tmp[right]);
    // }
    // if (tmp[right] < tmp[center])
    // {
    //     std::swap(tmp[center], tmp[right]);
    // }
    // int pivo = tmp[center];
    quick_sort(vec, 0, vec.size() - 1);
    return vec;
}

// Merge Sort

void merge(std::vector<int> &vec, int l, int m, int r)
{
    // Ihre Loesung hier:
    size_t i, j, k;
    const size_t n1 = m - l + 1;
    const size_t n2 = r - m;

    std::vector<int> L(n1);
    std::vector<int> R(n2);
    for (i = 0; i < n1; i++)
    {
        L[i] = vec[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = vec[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vec[k] = L[i];
            i++;
        }
        else
        {
            vec[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        vec[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        vec[k] = R[j];
        j++;
        k++;
    }
    print(vec);
}

void merge_sort(std::vector<int> &vec, int l, int r)
{
    // Ihre Loesung hier:
    if (l < r)
    {
        size_t m = size_t(std::floor((l + r) / 2));
        merge_sort(vec, l, m);
        merge_sort(vec, m + 1, r);
        merge(vec, l, m, r);
    }
}
// Startfunktion:
std::vector<int> merge_sort(std::vector<int> &vec)
{
    merge_sort(vec, 0, vec.size() - 1);
    return vec;
}

// HeapSort

inline int left_child_idx(int idx) { return 2 * idx + 1; }

void perc_down(std::vector<int> &vec, int i, int n)
{
    // Ihre Loesung hier:
    int child;
    int tmp;
    for (tmp = vec[i]; left_child_idx(i) < n; i = child)
    {
        child = left_child_idx(i);
        if (child != n - 1 && vec[child] < vec[child + 1ll])
        {
            child++;
        }
        if (tmp < vec[child])
        {
            vec[i] = vec[child];
        }
        else
        {
            break;
        }
    }
    vec[i] = tmp;
}

std::vector<int> heap_sort(std::vector<int> vec)
{
    // Ihre Loesung hier:
    for (int i = vec.size() / 2; i >= 0; i--)
    {
        perc_down(vec, i, vec.size());
    }
    // Sortieren
    for (int i = vec.size() - 1; i > 0; i--)
    {
        std::swap(vec[0], vec[i]);
        perc_down(vec, 0, i);
        print(vec);
    }
    return vec;
}

int main()
{

    // Aufgabe 1
    // Testen Aufgabe1.1  Selection Sort // ready

    // std::vector<int> res_selection = selection_sort(nums);
    // std::cout << "Result: ";
    // print(res_selection);

    // Testen Aufgabe1.2 Insertion Sort // Ready
    // std::vector<int> res_insertion = insertion_sort(nums);
    // std::cout << "Result: ";
    //  print(res_insertion);

    // Testen Aufgabe1.3 Bubble Sort //Ready
    // std::vector<int> res_bubble = bubble_sort(nums);
    // std::cout << "Result: ";
    // print(res_bubble);

    ////Aufgabe 2 // Geht aber "Shellsort"??
    ////Testen Aufgabe 2 Shell Sort
    // std::vector<int> res_shell = shell_sort(nums_shell);
    // std::cout << "Result: ";
    // print(res_shell);

    ////Aufgabe 3

    ////Testen Aufgabe 3.1 Quick Sort //funktioniert so halb, ohne pivo element
    // std::vector<int> res_quick = quick_sort(nums_adv);
    // std::cout << "Result: ";
    // print(res_quick);

    ////testen aufgabe 3.2 merge sort // Ready
    // std::vector<int> res_merge = merge_sort(nums_adv);
    // std::cout << "result: ";
    // print(res_merge);

    ////Testen Aufgabe 3.3 Heap Sort // Ready
    // std::vector<int> res_heap = heap_sort(nums_adv);
    // std::cout << "Result: ";
    // print(res_heap);
    system("pause");
    return 1;
}
