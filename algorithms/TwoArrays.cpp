#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, k;
		cin >> n >> k;
		vector<int> a(n), b(n), c(n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> b[i];
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end()); 
		reverse(b.begin(), b.end());

		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			c[i] = a[i] + b[i];
			if (c[i] < k)
			{
				flag = false;
				break;
			}
		}

		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}
	int tmp;
	cin >> tmp;
	return 0;
}
