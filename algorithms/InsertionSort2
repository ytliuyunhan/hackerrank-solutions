#include <vector>
#include <iostream>

using namespace std;
typedef vector<int>::const_iterator vec_iter;

void printArr(vector<int> ar);
void insertionSort(vector<int> ar);

void printArr(vector<int> ar)
{
	for (vec_iter i = ar.begin(); i != ar.end(); i++)
	{
		cout << *i << ' ';
	}
	cout << endl;
}

void insertionSort(vector<int> ar) 
{
	int j;
	for (int i = 1; i != ar.size(); i++)
	{
		int x = ar[i];
		j = i - 1;
		while (j != -1 && ar[j] > x)
		{
			ar[j + 1] = ar[j];
			j--;
		}
		ar[j + 1] = x;
			printArr(ar);
	}
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

	insertionSort(arr);
	int tmp;
	cin >> tmp;
}
