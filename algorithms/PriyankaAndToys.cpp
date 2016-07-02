#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_minimum_cout(vector<int>& weights);

int main()
{
	int n;
	cin >> n;
	vector<int> weights(n);
	for (int i = 0; i != weights.size(); ++i)
	{
		cin >> weights[i];
	}
	cout << get_minimum_cout(weights);
	int tmp;
	cin >> tmp;
	return 0;
}

int get_minimum_cout(vector<int>& weights)
{
	sort(weights.begin(), weights.end());
	int curr = -100;
	int cost = 0;
	for (vector<int>::const_iterator it = weights.begin(); it != weights.end(); ++it)
	{
		if (abs(*it - curr) > 4)
		{
			curr = *it;
			cost++;
		}
	}
	return cost;
}