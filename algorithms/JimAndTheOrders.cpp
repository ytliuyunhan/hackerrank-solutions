#include <iostream>
#include <map>

using namespace std;

int main()
{
	int n;
	cin >> n;
	multimap<int, int> orders;
	for (int i = 0; i < n; i++)
	{
		int t, d;
		cin >> t >> d;
		orders.insert(make_pair(t+d, i+1));
	}

	for (auto it = orders.begin(); it != orders.end(); it++)
		cout << it->second << ' ';
	cout << endl;
	
	int tmp;
	cin >> tmp;

	return 0;
}
