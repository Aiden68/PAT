#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

int n, s;
int weight[101] = { 0 };
int tree[101][101] = { { 0 } };
int path[101] = { 0 };
int visit[101] = { 0 };
vector<int> out[101];
int cnt = 0;

bool com(vector<int> a, vector<int> b)
{
	int size = a.size() > b.size() ? a.size() : b.size();
	if (size < 2)
		return false;
	for (int i = 1; i < size; i++)
	{
		if (a[i] != b[i])
			return a[i] > b[i];
	}
	return false;
}
void dfs(int v, int w)
{
	visit[v] = 1;
	w += weight[v];
	if (w == s && tree[v][v] == 0)
	{
		//printf("%d", weight[0]);
		out[cnt].push_back(weight[0]);
		int t = 0;
		while (path[t] != -1)
		{
//			printf(" %d", weight[path[t]]);
			out[cnt].push_back(weight[path[t]]);
			t = path[t];
		}
		cnt++;
	}
	if (tree[v][v] == 0)
		return;
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (v!= i && tree[v][i] == 1 && visit[i] == 0)
			{
				path[v] = i;
				dfs(i, w);
			}
		}
	}
}

int main()
{
	int m;
	memset(path, -1, 101 * sizeof(int));
	scanf("%d%d%d", &n, &m, &s);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &weight[i]);
	}
	for (int i = 0; i < m; i++)
	{
		int ti, tmp;
		scanf("%d%d", &ti, &tmp);
		tree[ti][ti] = 1;
		for (int j = 0; j < tmp; j++)
		{
			int tj;
			scanf("%d", &tj);
			tree[ti][tj] = 1;
		}
	}
	dfs(0, 0);
	sort(out, out + cnt, com);
	for (int i = 0; i < cnt; i++)
	{
		int space = 0;
		for (int j = 0; j < out[i].size(); j++)
		{
			if (space == 0)
				space++;
			else
				printf(" ");
			printf("%d", out[i][j]);
		}
		printf("\n");
	}
	return 0;
}