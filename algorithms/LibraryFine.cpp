#include <iostream>

using namespace std;

int main(){
	int d1;
	int m1;
	int y1;
	cin >> d1 >> m1 >> y1;
	int d2;
	int m2;
	int y2;
	cin >> d2 >> m2 >> y2;
	
	
	int hackos = 0;
	if (y1 > y2)
	{
		hackos = 10000;
	}
	else if (y1 == y2 && m1 > m2)
	{
		hackos = (m1 - m2) * 500;
	}
	else if (y1 == y2 && m1 == m2 && d1 > d2)
	{
		hackos = (d1 - d2) * 15;
	}
	cout << hackos;
	int tmp;
	cin >> tmp;

	return 0;
}
