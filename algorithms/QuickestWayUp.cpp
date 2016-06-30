#include <map>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_distance(map<int, int> distance, vector<int> vertexQ);
map<int, int> dijkstra(const vector<vector<int>>& connections);

int main()
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		
		vector<vector<int>> connections(2);

		for (int i = 1; i <100; ++i)
		{
			for (int j = 1; j <= 6; ++j)
			{
				if (i + j <= 100)
				{
					connections[0].push_back(i);
					connections[1].push_back(i + j);
				}

			}
		}

		int l;
		cin >> l;

		for (int i = 0; i < l; ++i)
		{
			int a, b;
			cin >> a >> b;

			for (int i = 0; i != connections[0].size(); ++i)
			{
				if (connections[1][i] == a)
				{
					connections[1][i] = b;
				}
			}

		}
		int s;

		cin >> s;
		for (int i = 0; i < s; ++i)
		{
			int a, b;
			cin >> a >> b;

			for (int i = 0; i != connections[0].size(); ++i)
			{
				if (connections[1][i] == a)
				{
					connections[1][i] = b;
				}
			}
		}


		map<int, int> distance = dijkstra(connections);

		//for (auto it = distance.begin(); it != distance.end(); it++)
		//{
		//	cout << it->first << ' ' << it->second << endl;
		//}

		//map<int, int> prev = dijkstra(connections);
		//for (auto it = prev.begin(); it != prev.end(); it++)
		//{
		//	cout << it->first << ' ' << it->second << endl;
		//}

		if (abs(distance[100]) > 1000)
			distance[100] = -1;
		cout << distance[100] << endl;
	}
	
	int tmp;
	cin >> tmp;
	return 0;
}


map<int, int> dijkstra(const vector<vector<int>>& connections)
{
	map<int, int> dist;
	map<int, int> prev;
	vector<int> vertexQ;

	for (int i = 1; i <= 100; i++)
	{
		vertexQ.push_back(i);
		dist[i] = 9999;
	}

	dist[1] = 0;
	while (vertexQ.size() != 0)
	{
		int u = min_distance(dist, vertexQ);
		vertexQ.erase(remove(vertexQ.begin(), vertexQ.end(), u), vertexQ.end());

		for (int i = 0; i != connections[0].size(); i++)
		{
			if (connections[0][i] == u)
			{
				int v = connections[1][i];
				int alt = dist[u] + 1;
				if (alt < dist[v])
				{
					dist[v] = alt;
					prev[v] = u;
				}
			}
		}

	}
	return dist;
	//return prev;
}


int min_distance(map<int, int> distance, vector<int> vertexQ)
{
	int resultVertix = vertexQ[0];
	for (auto it = vertexQ.begin(); it != vertexQ.end(); it++)
	{
		if (distance[*it] < distance[resultVertix])
			resultVertix = *it;
	}

	return resultVertix;
}
