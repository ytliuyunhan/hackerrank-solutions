#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int m, n;
		cin >> m >> n;
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		bool found = false;
		vector<int> choice;
		for (int i = 0; i < n; i++)
		{
			int j = i + 1;
			while (j < arr.size() && !found)
			{
				if (arr[i] + arr[j] == m)
				{
					found = true;
					choice.push_back(i + 1);
					choice.push_back(j + 1);
				}
				j++;
			}
			if (found)
				break;
		}
		cout << choice[0] << " " << choice[1] << endl;
	}
	return 0;
}
