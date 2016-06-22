#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int t;
	cin >> t;
	for (int a0 = 0; a0 < t; a0++){
		int n;
		int c;
		int m;
		cin >> n >> c >> m;

		int totalChoco = 0, newChoco = 0, wrapper = 0;
		totalChoco = n / c;
		wrapper = totalChoco;
		while (wrapper >= m){
			newChoco = wrapper / m;
			totalChoco += newChoco;
			wrapper -= newChoco * m;
			wrapper += newChoco;
		}
		cout << totalChoco << endl;
	}
	
	int tmp;
	cin >> tmp;
	return 0;
}
