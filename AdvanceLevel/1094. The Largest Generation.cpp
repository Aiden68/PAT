#include<iostream>
using namespace std;

int n, m;
int map[101][101];
int levelNum[101];
int visit[101];

void dfs(int v,int deep)
{
	visit[v] = 1;
	levelNum[deep]++;
	for (int i = 1; i <= n; i++)
	{
		if (map[v][i] == 1 && visit[i] == 0)
		{
			dfs(i, deep + 1);
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int id, k;
		scanf("%d%d", &id, &k);
		for (int i = 0; i < k; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			map[id][tmp] = map[tmp][id] = 1;
		}
	}
	dfs(1, 1);
	int maxNum = levelNum[1];
	int level = 1;
	for (int i = 2; i <= n; i++)
	{
		if (maxNum < levelNum[i])
		{
			maxNum = levelNum[i];
			level = i;
		}
	}
	printf("%d %d", maxNum, level);
	return 0;
}