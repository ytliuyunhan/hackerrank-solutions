#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef vector<int>::iterator vec_iter;


int main(){
	int n;
	int t;
	cin >> n >> t;
	vector<int> width(n);
	for (int width_i = 0; width_i < n; width_i++){
		cin >> width[width_i];
	}
	
	for (int a0 = 0; a0 < t; a0++){
		int i;
		int j;
		cin >> i >> j;

		
		//size = *min_element(width.begin() + i, width.begin() + j);
		//cout << size;
		vector<int> slice;
		for (vec_iter cur = width.begin() + i; cur != width.begin() + j+ 1; cur++)
		{
			slice.push_back(*cur);
		}
		int size;
		size = *min_element(slice.begin(), slice.end());

		cout << size << endl;
	}


	return 0;
}
