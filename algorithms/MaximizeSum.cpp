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
	for (int i = 0; i < arr.size(); i++)
	{
		prefix[i] = (arr[i] + (i > 0 ? prefix[i - 1] : 0)) % m;
	}
	set<long long> S;
	long long result = 0;
	for (int i = arr.size() - 1; i >= 0; i--)
	{
		S.insert(prefix[i]);
		long long a = (arr[i] - prefix[i] + m) % m;
		auto it = S.lower_bound(m - a);
		if (it != begin(S))
			result = max(result, *prev(it) + a);
		result = max(result, (*prev(end(S)) + a) % m);
	}
	return result;
}
