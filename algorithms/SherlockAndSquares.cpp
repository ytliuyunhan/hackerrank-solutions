#include <iostream>
using namespace std;


int main()
{
	int t, a, b;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		int r = (int)sqrt(b) - (int)sqrt(a);
		if (sqrt(a) - (int)sqrt(a) == 0)
			r++;
		cout << r << endl;
	}
	return 0;
}
