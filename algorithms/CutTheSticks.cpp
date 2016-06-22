#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int arr_i = 0; arr_i < n; arr_i++){
		cin >> arr[arr_i];
	}
	while (!arr.empty())
	{
		cout << arr.size() << endl;
		int shortest;
		shortest = *min_element(arr.begin(), arr.end());
		arr.erase(remove(arr.begin(), arr.end(), shortest), arr.end());
	}
	int tmp;
	cin >> tmp;
	return 0;
}
