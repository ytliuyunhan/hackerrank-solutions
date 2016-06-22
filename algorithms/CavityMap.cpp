#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool is_cavity(int row, int column, const vector<string> &grid);
bool is_wall(int row, int column, int n);
bool is_largest(int row, int column, const vector<string> &grid);

int main(){
	int n;
	cin >> n;
	vector<string> grid(n);
	for (int grid_i = 0; grid_i < n; grid_i++){
		cin >> grid[grid_i];
	}

	for (int row = 0; row < grid.size(); row++)
	{
		for (int column = 0; column < grid[row].size(); column++)
		{
			if (is_cavity(row, column, grid))
			{
				cout << 'X';
			}
			else
			{
				cout << grid[row][column];
			}
		}
		cout << endl;
	}
	int tmp;
	cin >> tmp;
	return 0;
}


bool is_cavity(int row, int column, const vector<string> &grid)
{
	return is_wall(row, column, grid.size()) == false && is_largest(row, column, grid);
}


bool is_wall(int row, int column, int n)
{
	return row == 0 || row == n - 1 || column == 0 || column == n - 1;
}

bool is_largest(int row, int column, const vector<string> &grid)
{
	char num = grid[row][column];
	return num > grid[row - 1][column] && num > grid[row + 1][column] && num > grid[row][column - 1] && num > grid[row][column + 1];
}
