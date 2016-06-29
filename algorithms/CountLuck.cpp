#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<pair<int, int>>::iterator vec_iter;

void dfs(const vector<string>& grid, vector<vector<bool>> &record, int i, int j, vector<pair<int, int>>& path);
bool is_visited(const vector<vector<bool>> &record, int i, int j);
bool is_adjacent(const vector<string> &grid, int prev_i, int prev_j, int i, int j);
bool is_turns(const vector<string> &grid, int i, int j);
int get_turns(vector<pair<int, int>>& path, const vector<string> &grid, int end_i, int end_j);
bool connected(vec_iter i, vec_iter j);

/*
this code is very convoluted and ugly!!
*/
int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int n, m;
		cin >> n >> m;
		vector<string> grid(n);
		vector<vector<bool>> visitRecord(n, vector<bool>(m));
		for (int i = 0; i < n; i++)
		{
			cin >> grid[i];
		}
		int start_i, start_j, end_i, end_j;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				visitRecord[i][j] = false;
				if (grid[i][j] == 'M')
				{
					start_i = i;
					start_j = j;
				}
				if (grid[i][j] == '*')
				{
					end_i = i;
					end_j = j;
				}
			}
		}
		vector<pair<int, int>> path;
		dfs(grid, visitRecord, start_i, start_j, path);
		
		for (auto i = path.begin(); i != path.end(); i++)
		{
			cout << (*i).first << " " << (*i).second << ";" ;
		}
		cout << endl;
		
		int turns = get_turns(path, grid, end_i, end_j);
		
		cout << turns << endl;
		
		int k;
		cin >> k;
		if (k == turns)
			cout << "Impressed" << endl;
		else
			cout << "Oops!" << endl;
		
	}
	int tmp;
	cin >> tmp;
	return 0;
}

int get_turns(vector<pair<int, int>>& path, const vector<string> &grid, int end_i, int end_j)
{
	vec_iter endIter;
	for (vec_iter i = path.begin(); i != path.end(); i++)
	{
		if ((*i).first == end_i && (*i).second == end_j)
		{
			endIter = i;
			break;
		}
	}

	vec_iter i = endIter;
	vec_iter j = endIter-1;

	int turns = 0;

	while (i != path.begin())
	{
		i=j;
		if (j != path.begin())
			j--;
		if (is_turns(grid, (*i).first, (*i).second))
			turns++;
		while (!connected(i, j))
			j--;
	}
	return turns;
}

bool connected(vec_iter i, vec_iter j)
{
	int distance = abs((*i).first - (*j).first) + abs((*i).second - (*j).second);
	if (distance > 1)
		return false;
	else
		return true;
}


bool is_adjacent(const vector<string> &grid, int prev_i, int prev_j, int i, int j)
{
	if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 'X' || abs(i - prev_i) + abs(j-prev_j) > 1)
		return false;
	else
		return true;
}

bool is_visited(const vector<vector<bool>> &record, int i, int j)
{
	if (record[i][j] == true)
		return true;
	else
		return false;
}

void dfs(const vector<string>& grid, vector<vector<bool>> &record, int i, int j, vector<pair<int, int>>& path)
{
	record[i][j] = true;
	pair<int, int> curr = make_pair(i, j);
	path.push_back(curr);
	for (int v = -1; v <= 1; v++)
	{
		for (int h = -1; h <= 1; h++)
		{
			if (is_adjacent(grid, i, j, i + v, j + h) && !is_visited(record, i + v, j + h))
				dfs(grid, record, i + v, j + h, path);
		}
	}
	return;
}

bool is_turns(const vector<string> &grid, int i, int j)
{
	int count = 0;
	for (int v = -1; v <= 1; v++)
	{
		for (int h = -1; h <= 1; h++)
		{
			if (is_adjacent(grid, i, j, i + v, j + h))
				count++;
		}
	}
	if (grid[i][j] == 'M' && count >= 3)
		return true;
	else if (!is_corner(grid, i, j) && count >= 4)
		return true;
	else
		return false;
}

