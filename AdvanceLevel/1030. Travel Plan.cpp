#include<iostream>
using namespace std;

int main()
{
	int n, m, s, d;
	int map[501][501];
	int mapcost[501][501];
	int visit[501] = { 0 };
	int length[501];
	int cost[501];
	int path[501][501];
	cin >> n >> m >> s >> d;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				map[i][j] = 0;
				mapcost[i][j] = 0;
				continue;
			}
			map[i][j] = 999999;
			mapcost[i][j] = 999999;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int ti, tj,tlength,tcost;
		cin >> ti >> tj >> tlength >> tcost;
		map[ti][tj] = map[tj][ti] = tlength;
		mapcost[ti][tj] = mapcost[tj][ti] = tcost;
	}
	visit[s] = 1;
	for (int i = 0; i < n; i++)
	{
		length[i] = map[s][i];
		cost[i] = mapcost[s][i];
		if (map[s][i] < 999999)
			path[s][i] = s;
	}
	while (1)
	{
		int min = 999999;
		int v = -1;
		for (int i = 0; i < n; i++)
		{
			if (min > length[i] && visit[i] == 0)
			{
				v = i;
				min = length[i];
			}
		}
		if (v == -1)
			break;
		visit[v] = 1;
		for (int i = 0; i < n; i++)
		{
			if (length[i] > length[v] + map[v][i])
			{
				length[i] = length[v] + map[v][i];
				cost[i] = cost[v] + mapcost[v][i];
				path[s][i] = v;
			}
			else if (length[i] == length[v] + map[v][i])
			{
				if (cost[i] > cost[v] + mapcost[v][i])
				{
					cost[i] = cost[v] + mapcost[v][i];
					path[s][i] = v;
				}
			}
		}
	}
	int pathPrint[501];
	int cnt = 0;
	int tmp = d;
	pathPrint[cnt++] = d;
	while (path[s][tmp] != s)
	{
		tmp = path[s][tmp];
		pathPrint[cnt++] = tmp;
	}
	cout << s << " ";
	while (cnt > 0)
	{
		cout << pathPrint[--cnt] << " ";
	}
	cout << length[d] << " " << cost[d];
	return 0;
}