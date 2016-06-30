#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;
int get_pair_count(unordered_map<int, int> ma, unordered_map<int, int> mb);

int main()
{
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	unordered_map<int, int> ma, mb;
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		a[i] = tmp;
		++ma[tmp];
	}
	for (int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		b[i] = tmp;
		++mb[tmp];
	}
	cout << get_pair_count(ma, mb) << endl;
	int tmp;
	cin >> tmp;
}


int get_pair_count(unordered_map<int, int> ma, unordered_map<int, int> mb)
{
	int cnt = 0;
	int aMore = 0;
	int bMore = 0;
	for (auto it = ma.begin(); it != ma.end(); it++)
	{
		auto itb = mb.find(it->first);
		if (itb != mb.end())
		{
			cnt += min(it->second, itb->second);
			if (it->second > itb->second)
				++aMore;
			else if (it->second < itb->second)
				++bMore;
		}
		else
			++aMore;
	}

	if (aMore > 0 || bMore > 0)
		++cnt;
	else
		--cnt;
	return cnt;
}

