#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> price(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> price[i];
	}

	sort(price.begin(), price.end());
	int cnt = 0;
	for (auto it = price.begin(); it != price.end(); ++it)
	{
		k -= *it;
		if (k < 0)
			break;
		cnt++;
	}
	cout << cnt << endl;
	int tmp;
	cin >> tmp;
	return 0;
}
