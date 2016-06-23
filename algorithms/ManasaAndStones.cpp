#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t)
	{
		int n, a, b;
		cin >> n;
		cin >> a;
		cin >> b;
		vector<int> results;
		if (a == b)
		{
			results.push_back((n - 1) * b);
		}
		else
		{
			for (int i = 0; i != n; i++)
			{
				results.push_back(i * a + (n - i -1) * b);
			}
		}
		sort(results.begin(), results.end());
		results.erase(unique(results.begin(), results.end()), results.end());

		typedef vector<int>::const_iterator vec_iter;

		for (vec_iter i = results.begin(); i != results.end(); i++)
		{
			cout << *i << ' ';
		}
		cout << endl;
		t--;
	}
	int tmp;
	cin >> tmp;
	return 0;
}
