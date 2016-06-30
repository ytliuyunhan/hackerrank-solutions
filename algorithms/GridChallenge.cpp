#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_sortable(vector<string>& grid);
bool compare_two_row(string u, string d);

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		vector<string> grid(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> grid[i];
		}
		if (is_sortable(grid))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	int tmp;
	cin >> tmp;

	return 0;
}

bool compare_two_row(string u, string d)
{
	for (auto i = u.begin(), j = d.begin(); i != u.end() && j != d.end(); ++i, ++j)
	{
		if (*i > *j)
		{
			return false;
		}
	}
	return true;
}

bool is_sortable(vector<string>& grid)
{
	sort(grid[0].begin(), grid[0].end());

	for (int i = 1; i < grid.size(); i++)
	{
		sort(grid[i].begin(), grid[i].end());
		if (!compare_two_row(grid[i - 1], grid[i]))
		{
			return false;
		}
	}
	return true;
}
