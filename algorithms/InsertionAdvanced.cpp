#include <vector>
#include <iostream>

using namespace std;
long long merge_sort(vector<int>&);

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int s;
		cin >> s;
		vector<int> arr(s);
		for (int i = 0; i < s; i++)
		{
			cin >> arr[i];
		}
		cout << merge_sort(arr) << endl;

	}
	int tmp;
	cin >> tmp;
	return 0;
}


long long merge_sort(vector<int> &v)
{
	if (v.size() <= 1)
		return 0;

	long long ans = 0;
	int m = v.size() / 2;
	
	vector<int> v1(m);
	copy(v.begin(), v.begin() + m, v1.begin());

	vector<int> v2(v.size() - m);
	copy(v.begin() + m, v.end(), v2.begin());

	ans += merge_sort(v1);
	ans += merge_sort(v2);

	auto it = v.begin();
	auto it1 = v1.begin();
	auto it2 = v2.begin();

	while (it1 != v1.end() && it2 != v2.end())
	{
		if (*it1 <= *it2)
		{
			*it++ = *it1++;
		}
		else
		{
			ans += v1.end() - it1;
			*it++ = *it2++;
		}
	}
	while (it1 != v1.end())
	{
		*it++ = *it1++;
	}
	while (it2 != v2.end())
	{
		*it++ = *it2++;
	}

	return ans;
}
