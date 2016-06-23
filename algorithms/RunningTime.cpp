#include <vector>
#include <iostream>

using namespace std;
typedef vector<int>::const_iterator vec_iter;

void insertion_sort(vector<int> arr);
void printArr(vector<int> arr);

void printArr(vector<int> arr)
{
	for (vec_iter i = arr.begin(); i != arr.end(); i++)
	{
		cout << *i << ' ';
	}
	cout << endl;
}


void insertion_sort(vector<int> arr)
{
	int j, x;
	int shift = 0;
	for (int i = 1; i != arr.size(); i++)
	{
		x = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > x)
		{
			arr[j + 1] = arr[j];
			j--;
			shift++;
		}
		arr[j + 1] = x;
	}
	//printArr(arr);
	cout << shift;
}


int main()
{
	int s;
	cin >> s;
	vector<int> arr(s);
	for (int i = 0; i < s; i++)
	{
		cin >> arr[i];
	}
	insertion_sort(arr);
	int tmp;
	cin >> tmp;
}
