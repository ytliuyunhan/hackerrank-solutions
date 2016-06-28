#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


using namespace std;

long long max_subarray_modulo(const vector<long long> &arr, long long m);

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		long long n, m;
		cin >> n >> m;
		vector<long long> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		cout << max_subarray_modulo(arr, m) << endl;
	}
	int tmp;
	cin >> tmp;
	return 0;
}

long long max_subarray_modulo(const vector<long long> &arr, long long m)
{
	vector<long long> prefix(arr.size());
	set<long long> S;
	long long maxModSum = arr[0] % m;
	for (int i = 0; i < arr.size(); i++)
	{
		prefix[i] = (arr[i] + (i > 0 ? prefix[i - 1] : 0)) % m;
		S.insert(prefix[i]);
		long long maxCurr = prefix[i];
		auto it = S.upper_bound(prefix[i]);
		if (it !=S.end())
			maxCurr = (prefix[i] - *it + m) % m;
		maxModSum = max(maxModSum, maxCurr);
	}
	return maxModSum;
}
