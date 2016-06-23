#include <iostream>
#include <string>
using namespace std;

string caesar(string s, int k);
int binary_step(char x);

int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int k;
	cin >> k;
	cout << caesar(s, k) << endl;
	int tmp;
	cin >> tmp;
	return 0;
}

string caesar(string s, int k)
{
	k %= 26;
	k += 26;
	k %= 26;
	string crypted = s;
	for (int i = 0; i < s.length(); i++)
	{
		if (crypted[i] <= 'Z' && crypted[i] >= 'A')
		{
			crypted[i] += k;
			crypted[i] -= binary_step(crypted[i] - 'Z') * 26;
		}
		else if (crypted[i] <= 'z' && crypted[i] >= 'a')
		{
			crypted[i] += k;
			crypted[i] -= binary_step(crypted[i] - 'z') * 26;
		}
	}
	return crypted;
}


int binary_step(char x)
{
	if ((int)x > 0)
		return 1;
	else
		return 0;
}
