#include<iostream>
using namespace std;

int visit[1001] = { 0 };
//int visitNum = 1;
int cnt = 0;

void DFS(int d[][1001],int v,int n)
{
	visit[v] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (d[v][i] != 0 && visit[i] == 0)
		{		
//			visitNum++;
			DFS(d, i, n);
		}
	}
}

int main()
{
	int n, m, k;	
	int map[1001][1001] = { { 0 } };
	int d[1001][1001] = { { 0 } };
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++)
	{
		int ti, tj;
		cin >> ti >> tj;
		map[tj][ti] = map[ti][tj] = 1;
		d[tj][ti] = d[ti][tj] = 1;
	}
	int city[1001];
	for (int i = 0; i < k; i++)
	{
		cin >> city[i];
	}
	for (int i = 0; i < k; i++)
	{
		if (i == 0)
		{
			for (int j = 1; j <= n; j++)
			{
				d[city[i]][j] = 0;
				d[j][city[i]] = 0;
				visit[j] = 0;
			}
		}
		else
		{
			for (int j = 1; j <= n; j++)
			{
				d[city[i - 1]][j] = map[city[i - 1]][j];
				d[j][city[i - 1]] = map[city[i - 1]][j];
				d[city[i]][j] = 0;
				d[j][city[i]] = 0;
				visit[j] = 0;
			}
		}
		visit[city[i]] = 1;
		cnt = 0;
		while (1)
		{
			int v = 0;
			for (int i = 1; i <= n; i++)
			{
				if (visit[i] == 0)
				{
					v = i;
					break;
				}
			}
			if (v == 0)
				break;
			DFS(d, v, n);
			cnt++;
		}
		cout << cnt -1 << endl;
	}
	return 0;
}