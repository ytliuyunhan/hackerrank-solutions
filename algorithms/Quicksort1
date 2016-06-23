#include <iostream>
#include <vector>

using namespace std;
typedef vector<int>::const_iterator vec_iter;

void printArr(vector<int> arr);
vector<int> partition(vector<int> arr);

int main()
{
	int s;
	cin >> s;
	vector<int> arr(s);
	for (int i = 0; i < s; i++)
	{
		cin >> arr[i];
	}
	vector<int> result = partition(arr);
	printArr(result);

	int tmp;
	cin >> tmp;
	return 0;
}

void printArr(vector<int> arr)
{
	for (vec_iter i = arr.begin(); i != arr.end(); i++)
	{
		cout << *i << ' ';
	}
	cout << endl;
}


vector<int> partition(vector<int> arr)
{
	int pivot = arr[0];
	vector<int> left, equal, right;
	for (vec_iter i = arr.begin(); i != arr.end(); i++)
	{
		if (*i < pivot)
			left.push_back(*i);
		else if (*i == pivot)
			equal.push_back(*i);
		else
			right.push_back(*i);
	}
	vector<int> result = left;
	result.insert(result.end(), equal.begin(), equal.end());
	result.insert(result.end(), right.begin(), right.end());

	return result;
}
