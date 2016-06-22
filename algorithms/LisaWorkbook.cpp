#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int find_page(const int n, const int k, const vector<int> &problems, const vector<int> &numPages)
{
	int cnt = 0;
	int page = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int c = 1; c <= numPages[i]; c++)
		{
			if (page >= ((c - 1)* k + 1) && page <= min(c * k, problems[i]))
				cnt++;
			page++;
		}
	}
	return cnt;
}


int main() {
	int n, k;
	cin >> n >> k;
	vector<int> problems(n+1);
	for (int chap_i = 1; chap_i <= n; chap_i++)
	{
		cin >> problems[chap_i];
	}

	vector<int> numPages(n + 1);
	for (int chap_i = 1; chap_i <= n; chap_i++)
	{
		numPages[chap_i] =ceil((float)problems[chap_i] / k);
	}

	cout << find_page(n, k, problems, numPages) << endl;
	int tmp;
	cin >> tmp;
	return 0;
}
