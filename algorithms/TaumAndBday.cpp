#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long t;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		long long b, w, x, y, z;
		cin >> b >> w;
		cin >> x >> y >> z;

		long long total;

		long long noConv, convB, convW;
		noConv = b*x + w * y;
		convB = (b + w) * x + w * z;
		convW = (b + w) * y + b * z;

		total = min(noConv, min(convW, convB));

		cout << total << endl;
	}

	return 0;
}
