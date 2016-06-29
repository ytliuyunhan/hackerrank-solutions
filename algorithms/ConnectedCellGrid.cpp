#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_vertex(const vector<vector<int>> &grid, int i, int j);
bool is_visited(const vector<vector<bool>> &record, int i, int j);
bool is_adjacent(const vector<vector<int>> &grid, int i, int j);
void dfs(const vector<vector<int>>& grid, vector<vector<bool>> &record, int i, int j, int& length);

int main()
{
	int m, n;
	cin >> m;
	cin >> n;
	vector<vector<int>> grid(m, vector<int>(n));
	vector<vector<bool>> visitRecord(m, vector<bool>(n));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> grid[i][j];
			visitRecord[i][j] = false;
		}
	}

	int longest = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (is_vertex(grid, i, j) && !is_visited(visitRecord, i, j))
			{
				int thisResult = 0;
				dfs(grid, visitRecord, i, j, thisResult);
				longest = max(thisResult, longest);
			}
		}
	}

	cout << longest << endl;
	int tmp;
	cin >> tmp;
}

bool is_vertex(const vector<vector<int>> &grid, int i, int j)
{
	if (grid[i][j] == 1)
		return true;
	else
		return false;
}

bool is_visited(const vector<vector<bool>> &record, int i, int j)
{
	if (record[i][j] == true)
		return true;
	else
		return false;
}

bool is_adjacent(const vector<vector<int>> &grid, int i, int j)
{
	if (i < 0 || i>= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
		return false;
	else
		return true;
}

void dfs(const vector<vector<int>>& grid, vector<vector<bool>> &record, int i, int j, int& length)
{
	length++;
	record[i][j] = true;
	for (int v = -1; v <= 1; v++)
	{
		for (int h = -1; h <= 1; h++)
		{
			if (is_adjacent(grid, i + v, j + h) && !is_visited(record, i + v, j + h))
				dfs(grid, record, i + v, j + h, length);
		}
	}
	return;
}

