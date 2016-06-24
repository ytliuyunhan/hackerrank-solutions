#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef vector<int>::const_iterator vec_iter;

void printArr(vector<int> arr);
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


void printArr(vector<int> arr)
{
	for (int i = 0; i != arr.size(); i++)
		{
			cout << arr[i] << ' ';
		}
		cout << endl;
		
}



void quick_sort(vector<int> &arr, int low, int high)
{
	if (low < high - 1)
	{
		int p = partition(arr, low, high);
		quick_sort(arr, low, p);
		quick_sort(arr, p+1, high);
	}
}


int partition(vector<int> &arr, int low, int high)
{
	int pivot = arr[high-1];
	int i = low-1;
	for (int j = low; j < high-1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high - 1]);
	printArr(arr);
	return i + 1;
}
