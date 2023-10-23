#include "sorting.h"

namespace sorting
{

	//************
	// QuickSort *
	//************
	void QuickSort(vector<int> &arr, int left, int right)
	{
		if (left < right)
		{
			int q = partition(arr, left, right);
			QuickSort(arr, left, q - 1);
			QuickSort(arr, q + 1, right);
		}
	}
	void QuickSortHybrid(vector<int> &arr, int left, int right)
	{
		if (right - left + 1 < 10)
		{
			int N = arr.size();
			for (int i = 1; i < N; i++)
			{
				int tmp = arr[i];
				int j = i - 1;
				while (j >= 0 && arr[j] > tmp)
				{
					arr[j + 1] = arr[j];
					j--;
				}
				arr[j + 1] = tmp;
			}
		}
		else
		{
			QuickSort(arr, left, right);
		}
	}
	//************
	// MergeSort *
	//************
	void Merge(vector<int> &a, vector<int> &b, int leftPos, int rightPos, int rightEnd)
	{
		int leftEnd = rightPos - 1;
		int tmpPos = leftPos;
		int n = rightEnd - leftPos + 1;

		while ((leftPos <= leftEnd) && (rightPos <= rightEnd))
		{
			if (a[leftPos] <= a[rightPos])
			{
				b[tmpPos] = a[leftPos];
				leftPos++;
			}
			else
			{
				b[tmpPos] = a[rightPos];
				rightPos++;
			}
			tmpPos++;
		}
		while (leftPos <= leftEnd)
		{
			b[tmpPos++] = a[leftPos++];
		}
		while (rightPos <= rightEnd)
		{
			b[tmpPos++] = a[rightPos++];
		}
		for (int i = rightEnd - n + 1; i <= rightEnd; i++) // Kopieren von B in A zurück
		{
			a[i] = b[i];
		}
	}

	void MergeSort(vector<int> &a, vector<int> &b, int left, int right)
	{
		if (left < right)
		{
			int middle = (left + right) / 2;
			MergeSort(a, b, left, middle);
			MergeSort(a, b, middle + 1, right);
			Merge(a, b, left, middle + 1, right);
		}
	}

	void natMerge(vector<int> &a, vector<int> &b, int left, int middle, int right)
	{
		int leftEnd = middle - 1;
		int tmpPos = left;
		int n = right - left + 1;

		while (left <= leftEnd && middle < right)
		{
			if (a[left] <= a[middle])
			{
				b[tmpPos] = a[left];
				left++;
			}
			else
			{
				b[tmpPos] = a[middle];
				middle++;
			}
			tmpPos++;
		}

		while (left <= leftEnd)
		{
			b[tmpPos++] = a[left++];
		}

		while (middle < right)
		{
			b[tmpPos++] = a[middle++];
		}

		int i = right - n + 1;

		while (i < right)
		{
			a[i] = b[i];
			i++;
		}
	}

	void natMergeSort(vector<int> &a, vector<int> &b)
	{
		int n = a.size();
		vector<pair<int, int>> runs;

		int left = 0;
		while (left < n)
		{
			int i = left;

			while (i < n - 1 && a[i] <= a[i + 1])
				i++;

			if (i == n)
				break;

			int right = i;
			while (right < n - 1 && a[right] <= a[right + 1])
				right++;

			runs.push_back(make_pair(left, right));

			left = right + 1;
		}

		while (runs.size() > 1)
		{
			vector<pair<int, int>> newRuns;
			for (size_t i = 0; i < runs.size() - 1; i += 2)
			{
				int left = runs[i].first;
				int middle = runs[i].second;
				int right = runs[i + 1].second;

				Merge(a, b, left, middle + 1, right);
				newRuns.push_back(make_pair(left, right));
			}

			if (runs.size() % 2 == 1)
			{
				newRuns.push_back(runs.back());
			}

			runs = newRuns;
		}
	}

	//************
	// Heapsort  *
	// n= a.size *
	//************
	// void heapify(vector<int> &a, int n, int i){} // Verstehe ich nicht

	void HeapSort(vector<int> &a, int n)
	{
		int i = (n / 2);
		while (i >= 0)
		{
			percDown(a, i, n);
			i--;
		}

		int j = n - 1;
		while (j > 0)
		{
			std::swap(a[0], a[j]);
			percDown(a, 0, j);
			j--;
		}
	}

	//************
	// Shellsort *
	//************
	// Hier soll Hibbard implementiert werden
	void ShellSort_2n(vector<int> &a, int n)
	{

		for (int gap = (n / 2); gap > 0; gap = (gap / 2))
		{
			for (int i = gap; i < n; i++)
			{
				int tmp = a[i];
				int j = i;
				for (; j >= gap && tmp < a[j - gap]; j -= gap)
				{
					a[j] = a[j - gap];
				}
				a[j] = tmp;
			}
		}
	}
	void ShellSort_3n(vector<int> &a, int n)
	{

		for (int gap = (n / 3); gap > 0; gap = (gap / 3))
		{
			for (int i = gap; i < n; i++)
			{
				int tmp = a[i];
				int j = i;
				for (; j >= gap && tmp < a[j - gap]; j -= gap)
				{
					a[j] = a[j - gap];
				}
				a[j] = tmp;
			}
		}
	}

	//*******************
	// Helper functions *
	//*******************
	void randomizeVector(vector<int> &array, int n)
	{
		array.resize(n);

		for (unsigned int i = 0; i < array.size(); i++)
			array[i] = rand() % 1000000;
	}

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
			}
		}
		std::swap(vec[i + 1ll], vec[r]);
		return i + 1;
	}

	void percDown(vector<int> &a, int p, int n)
	{
		int child;
		int tmp;
		for (tmp = a[p]; leftChild(p) < n; p = child)
		{
			child = leftChild(p);
			if (child != n - 1 && a[child] < a[child + 1ll])
			{
				child++;
			}
			if (tmp < a[child])
			{
				a[p] = a[child];
			}
			else
			{
				break;
			}
		}
		a[p] = tmp;
	}
	int leftChild(int i)
	{
		return 2 * i + 1;
	}

}
