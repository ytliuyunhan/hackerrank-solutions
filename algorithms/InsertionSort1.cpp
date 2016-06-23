#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef vector<int>::iterator vec_iter;

void printArr(vector<int> ar);
void insertionSort(vector<int> ar);

void insertionSort(vector<int> ar) {

	int j;
	vector<int> ar_tmp_inner, ar_tmp_outer;
	for (int i = ar.size() - 1; i != 1; i--)
	{
		int x = ar[i];
		j = i - 1;
		ar_tmp_outer = ar;
		while (j != -1 && ar[j] > x)
		{
			ar_tmp_inner = ar;
			ar[j + 1] = ar[j];
			j--;
			if (ar != ar_tmp_inner)
				printArr(ar);
		}
		ar[j + 1]= x;
		if (ar != ar_tmp_outer)
			printArr(ar);
	}
}


void printArr(vector<int> ar)
{
	for (vec_iter i = ar.begin(); i != ar.end(); i++)
	{
		cout << *i << ' ';
	}
	cout << endl;
}

int main(void) {
	vector <int>  _ar;
	int _ar_size;
	cin >> _ar_size;
	for (int _ar_i = 0; _ar_i<_ar_size; _ar_i++) {
		int _ar_tmp;
		cin >> _ar_tmp;
		_ar.push_back(_ar_tmp);
	}

	insertionSort(_ar);

	int tmp;
	cin >> tmp;
	return 0;
}
