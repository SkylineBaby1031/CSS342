
#include <iostream>
#include <vector> 
using namespace std;



static void BubbleSort(vector<int>& arr, int a, int n) 
{
	if(arr.size() == 0) {
		return;
	}
	int temp;
	for (int i = a; i < n; i++)
	{
		for (int j = a; j < (n - i + a); j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


static void InsertionSort(vector<int>& arr, int a, int n) 
{
	if(arr.size() == 0) {
		return;
	}
	int temp;
	int j;
	for (int i = 1 + a; i < (n+1); i++)
	{
		j = i;
		temp = arr[i];
		while ((temp < arr[j-1]) && (j > 0))
		{
			arr[j] = arr[j-1];
			j = j - 1;
		}
		arr[j] = temp;
	}
}

static void Merger(vector<int> &arr, int a, int  mi, int n)
{
	int *temp = new int[n - a + 1];
	int i = a, j = mi + 1;
	int k = 0;
	while (i <= mi && j <= n) {
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
			temp[k++] = arr[j++];
	}
	while (i <= mi)
		temp[k++] = arr[i++];
	while (j <= n)
		temp[k++] = arr[j++];
	for (k = 0, i = a; i <= n; ++i, ++k)
		arr[i] = temp[k];
	delete[]temp;
}

static void MergeSort(vector<int> &arr, int a, int n)
{
	if(arr.size() == 0) {
		return;
	}

	int mid;
	if (a < n) {
		mid = (a + n) >> 1;
		MergeSort(arr, a, mid);
		MergeSort(arr, mid + 1, n);
		Merger(arr, a, mid, n);
	}
}

static void QuickSort(vector<int> &arr, int a, int n)
{
	if(arr.size() == 0) {
		return;
	}

	int i = a, j = n;
	int tmp;
	int pivot = arr[(a + n) / 2];
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};
	if (a < j)
		QuickSort(arr, a, j);
	if (i < n)
		QuickSort(arr, i, n);
}

static void IterativeMergeSort(vector<int> &arr, int a, int n)
{
	if(arr.size() == 0) {
		return;
	}
	n += 1;
	vector<int> ans(n);
	for (int seg = 1; seg < n; seg += seg) {
		for (int beg = 0; beg < n; beg += seg + seg) {
			int low = beg, mid = min(beg + seg, n), high = min(beg + seg + seg, n);
			int i = low, j = mid, k = low;
			while (i < mid && j < high) ans[k++] = arr[i] > arr[j] ? arr[j++] : arr[i++];
			while (i < mid) ans[k++] = arr[i++];
			while (j < high) ans[k++] = arr[j++];
			for (k = beg; k < high; ++k) arr[k] = ans[k];
		}
	}
}


static int min(int a, int b)
{
	return a <= b ? a : b;
}


static void ShellSort(vector<int> &arr, int a, int n)
{
	if(arr.size() == 0) {
		return;
	}

	n+=1;
	for (int gap = (n - a) / 2; gap > 0; gap /= 2)
	{
		for (int i = gap + a; i < n; i += 1)
		{
			int temp = arr[i];
			int j;
			for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}
	}
}

