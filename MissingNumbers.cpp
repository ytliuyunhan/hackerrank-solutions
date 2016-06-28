#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int m;
	cin >> m;
	vector<int> b(m);

	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}

	vector<int> x(10000, 0);

	for (auto i = b.begin(); i != b.end(); i++)
	{
		x[*i] += 1;
	}

	for (auto j = a.begin(); j != a.end(); j++)
	{
		x[*j] -= 1;
	}

	vector<int> result;
	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] != 0)
			result.push_back(i);
	}

	for (auto i = result.begin(); i != result.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;

	int tmp;
	cin >> tmp;
	return 0;
}
