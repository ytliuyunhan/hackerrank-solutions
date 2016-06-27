#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

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

		bool yesFlag = false || (s == 1);

		auto it = arr.begin() + 1;

		long long sumLeft = 0;
		long long sumRight = accumulate(it, arr.end(), 0);
		while (it != arr.end())
		{
			sumLeft += *(it - 1);
			sumRight -= *(it);
			if (sumLeft == sumRight)
			{
				yesFlag = true;
				break;
			}
			it++;
		}
		if (yesFlag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	int tmp;
	cin >> tmp;
	return 0;
}
