#include<iostream>
#include<queue>
using namespace std;

int n, l, k;
int g[1010][1010];
int visit[1010];
int add[1010];

int bfs(int v,int level,int forward)
{
	queue<int> q;
	q.push(v);
	visit[v] = 1;
	int tail = v;
	while(!q.empty())
	{
		int temp = q.front();
		q.pop();
		forward++;
		for(int i = 1;i <= n; i++)
		{
			if(g[temp][i] == 1&&visit[i] == 0)
			{
				q.push(i);
				visit[i] = 1;
			}
		}
		if(tail == temp)
		{
			if(!q.empty())
				tail = q.back();
			level++;
		}
		if(level > l)
			break;
	}
	return forward;
}

int main()
{
	int forward = 0;
	scanf("%d%d",&n, &l);
	for(int i = 1; i <= n; i++)
	{
		int m;
		scanf("%d",&m);
		for(int j = 0; j < m; j++)
		{
			int list;
			scanf("%d",&list);
			g[list][i] = 1;
		}
	}
	scanf("%d",&k);
	for(int i = 0; i < k; i++)
	{
		int query;
		scanf("%d",&query);
		forward = -1;
		fill(visit,visit + n + 1,0);
		printf("%d\n",bfs(query,0,forward));
	}
	return 0;
}