#include "stdafx.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

bool next_better(string &s);


int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string input;
		cin >> input;
		next_better(input);
		
	}
	int tmp;
	cin >> tmp;
	return 0;
}



bool next_better(string &s)
{
	int idx = - 1;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] < s[i + 1])
		{
			idx = i;
			break;
		}
	}

	if (idx == -1)
	{
		cout << "no answer" << endl;
		return false;
	}

	for (int j = s.size() - 1; j > idx; j--)
	{
		if (s[j] > s[idx])
		{
			swap(s[idx], s[j]);
			break;
		}
	}
	reverse(s.begin() + idx + 1, s.end());
	cout << s << endl;

	return true;
}
