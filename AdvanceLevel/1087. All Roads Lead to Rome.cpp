#include<iostream>
#include<string>
#include<map>
using namespace std;
int route[202][202] = { { 0 } };
int visit[202] = { 0 };
int cost[202] = { 0 };
int path[202] = { 0 };
int node[202] = { 0 };
int hap[202] = { 0 };
int r[202] = { 0 };
int same[202] = { 0 };
int main()
{
	int n, k,des = 0,cnt = 1;
	char tmp[4];
	string city[202];
	int happy[201] = { 0 };
	map<string, int> m;
	scanf("%d%d", &n, &k);
	scanf("%s", tmp);
	city[0] = tmp;
	m.insert(pair<string, int>(city[0], 0));
	for (int i = 1; i < n; i++)
	{
		scanf("%s%d", tmp, &happy[i]);
//		hap[i] = happy[i];
		city[i] = tmp;
		if (city[i] == "ROM")
			des = i;
		m.insert(pair<string, int>(city[i], i));
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			route[i][j] = 999999;
		}
	}
	for (int i = 0; i < k; i++)
	{
		char ti[4], tj[4];
		int c;
		scanf("%s%s%d", ti, tj, &c);
		int x = m[ti],y = m[tj];
		route[x][y] = route[y][x] = c;
	}
	/*if (city[0] == "ROM")
	{
		printf("1 0 0 0\nROM");
		return 0;
	}*/
	for (int i = 0; i < n; i++)
	{
		cost[i] = route[0][i];
		if (cost[i] != 999999)
		{
			node[i] = 1;
			hap[i] = happy[i];
			same[i] = 1;
		}
	}
	visit[0] = 1;
	while (1)
	{
		int v = -1;
		for (int i = 1; i < n; i++)
		{
			if (visit[i] == 0 && v == -1)
				v = i;
			else if (visit[i] == 0)
			{
				if (cost[v] > cost[i])
					v = i;
			}
		}
		if (v == -1)
			break;
		else
			visit[v] = 1;
		for (int i = 0; i < n; i++)
		{
			if (route[v][i]!=999999&&cost[v] + route[v][i] < cost[i])
			{
				same[i] = same[v];
				cnt = 1;
				cost[i] = cost[v] + route[v][i];
				path[i] = v;
				hap[i] = hap[v] + happy[i];
				node[i] = node[v] + 1;
			}
			else if (route[v][i] != 999999 && cost[v] + route[v][i] == cost[i])
			{
				same[i]+=same[v];
				cnt++;
				if (hap[i] < hap[v] + happy[i])
				{
					hap[i] = hap[v] + happy[i];
					node[i] = node[v] + 1;
					path[i] = v;
				}
				else if (hap[i] == hap[v] + happy[i])
				{
					if (node[i] > node[v] + 1)
					{
						node[i] = node[v] + 1;
						path[i] = v;
					}
				}
			}
		}
	}
	printf("%d %d %d %d\n", same[des], cost[des], hap[des], hap[des] / (node[des]));
	int cn = 0 , t = des;
	while (t != 0)
	{
		r[cn++] = t;
		t = path[t];
	}
	r[cn++] = t;
	for (int i = cn - 1; i >= 0; i--)
	{
		printf("%s", city[r[i]].c_str());
		if (i != 0)
			printf("->");
	}
	return 0;
}