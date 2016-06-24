#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int>::const_iterator vec_iter;

void printArr(vector<int> arr, int low, int high);
void quick_sort(vector<int> &arr, int low, int high);
int partition(vector<int> &arr, int low, int high);

int main()
{
	int s;
	cin >> s;
	vector<int> arr(s);
	for (int i = 0; i < s; i++)
	{
		cin >> arr[i];
	}
	quick_sort(arr, 0, arr.size());

	int tmp;
	cin >> tmp;
	return 0;
}


void printArr(vector<int> arr, int low, int high)
{
	if (low < high - 1)
	{
		for (int i = low; i != high; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << endl;
	}
}



void quick_sort(vector<int> &arr, int low, int high)
{
	if (low < high - 1)
	{
		int p = partition(arr, low, high);
		quick_sort(arr, low, p-1);
		quick_sort(arr, p, high);
	}
	printArr(arr, low, high);
	
}


int partition(vector<int> &arr, int low, int high)
{
	int pivot = arr[low];
	int i = low;
	for (int j = low + 1; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			//i += 1;
			//int tmp = arr[i];
			//arr[i] = arr[j];
			//arr[j] = tmp;
			rotate(arr.begin() + i, arr.begin() + j, arr.begin() + j + 1);
			i += 1;
		}
	}

	return i+1;
}
