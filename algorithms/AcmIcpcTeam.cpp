#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int topic_count(string a, string b);

int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> knowledge(n);
	for (int i = 0; i != n; i++)
	{
		cin >> knowledge[i];
	}

	vector<int> combineTopic;
	int thisResult = 0;
	for (int i = 0; i != n-1; i++)
	{
		for (int j = i+1; j != n; j++)
		{
			thisResult = topic_count(knowledge[i], knowledge[j]);
			//cout << knowledge[i] << endl << knowledge[j] << endl << thisResult << endl;
			combineTopic.push_back(thisResult);
		}
	}
	int maximum, maxCount;
	maximum = *max_element(combineTopic.begin(), combineTopic.end());
	maxCount = count(combineTopic.begin(), combineTopic.end(), maximum);

	cout << maximum << endl << maxCount;

	int tmp;
	cin >> tmp;
	return 0;
}


int topic_count(string a, string b)
{
	int cnt = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == '1' || b[i] == '1')
			cnt++;
	}
	return cnt;
}
