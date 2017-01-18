#include<iostream>
#define inf 999999999
using namespace std;

int main()
{
	int n, m;
	int graph[1010][1010] = { { 0 } };
	int temp = inf;
	int s = 0;
	int dis[1010] = { 0 };
	int visit[1010] = { 0 };
	int cnt = 1;
	int sum = 0;
	scanf("%d%d", &n, &m);
	fill(graph[0], graph[0] + 1010 * 1010, inf);
	for (int i = 0; i < m; i++)
	{
		int v1, v2, cost;
		scanf("%d%d%d", &v1, &v2, &cost);
		if (temp > cost)
		{
			temp = cost;
			s = v1;
		}
		graph[v1][v2] = graph[v2][v1] = cost;
	}
	for (int i = 1; i <= n; i++)
	{
		dis[i] = graph[s][i];
	}
	visit[s] = 1;
	while (1)
	{
		int min = inf;
		int v = 0;
		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == 0 && min > dis[i])
			{
				min = dis[i];
				v = i;
			}
		}
		if (v == 0)
			break;
		cnt++;
		sum += min;
		visit[v] = 1;
		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == 0 && dis[i] > graph[v][i])
			{
				dis[i] = graph[v][i];
			}
		}
	}
	if (cnt == n)
		cout << sum;
	else
		cout << -1;
	return 0;
}