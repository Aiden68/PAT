#include<iostream>
#include<vector>
#define inf 99999999
using namespace std;

int n, m, s, d;
int graphlen[505][505];
int graphtime[505][505];
int len[505],tim[505], visit[505], path[505], node[505];

void dijkstra(int graphlen[][505],int graphtime[][505],int len[],int tim[],int flag)
{
	for(int i = 0; i < n; i++)
	{
		len[i] = graphlen[s][i];
		tim[i] = graphtime[s][i];
		if(len[i] != inf)
			node[i] = 1;
		else
			node[i] = inf;
		visit[i] = 0;
		path[i] = s;
	}
	while(1)
	{
		int min = inf,v = -1;
		for(int i = 0; i < n; i++)
		{
			if(visit[i] == 0&&len[i] < min)
			{
				min = len[i];
				v = i;
			}
		}
		if(v == -1)
			break;
		visit[v] = 1;
		for(int i = 0; i < n; i++)
		{
			if(flag == 0)
			{
				if(len[i] > len[v] + graphlen[v][i])
				{
					len[i] = len[v] + graphlen[v][i];
					tim[i] = tim[v] + graphtime[v][i];
					path[i] = v;
				}
				else if(len[i] == len[v] + graphlen[v][i]&&tim[i] > tim[v] + graphtime[v][i])
				{
					len[i] = len[v] + graphlen[v][i];
					tim[i] = tim[v] + graphtime[v][i];
					path[i] = v;
				}
			}
			else
			{
				if(len[i] > len[v] + graphlen[v][i])
				{
					len[i] = len[v] + graphlen[v][i];
					node[i] = node[v] + 1;
					path[i] = v;
				}
				else if(len[i] == len[v] + graphlen[v][i]&&node[i] > node[v] + 1)
				{
					len[i] = len[v] + graphlen[v][i];
					node[i] = node[v] + 1;
					path[i] = v;
				}
			}
		}
	}
	
}
int main()
{
	vector<int> leastlen,leasttime;
	scanf("%d%d",&n, &m);
	fill(graphlen[0],graphlen[0] + 505 * 505,inf);
	fill(graphtime[0],graphtime[0] + 505 * 505,inf);
	for(int i = 0; i < m; i++)
	{
		int v1, v2, oneway, tlen, ttime;
		scanf("%d%d%d%d%d",&v1, &v2, &oneway, &tlen, &ttime);
		graphlen[v1][v2] = tlen;
		graphtime[v1][v2] = ttime;
		if(oneway != 1)
		{
			graphlen[v2][v1] = tlen;
			graphtime[v2][v1] = ttime;
		}
	}
	scanf("%d%d",&s, &d);
	dijkstra(graphlen,graphtime,len,tim,0);
	int temp = d, dis = len[d];
	while(temp != s)
	{
		leastlen.push_back(temp);
		temp = path[temp];
	}
	leastlen.push_back(s);
	dijkstra(graphtime,graphlen,tim,len,1);
	temp = d;
	while(temp != s)
	{
		leasttime.push_back(temp);
		temp = path[temp];
	}
	leasttime.push_back(s);
	if(leastlen != leasttime)
	{
		printf("Distance = %d: ",dis);
		for(int i = leastlen.size() - 1; i >= 0; i--)
		{
			if(i != leastlen.size() - 1)
				printf(" -> ");
			printf("%d",leastlen[i]);
		}
		printf("\nTime = %d: ",tim[d]);
		for(int i = leasttime.size() - 1; i >= 0; i--)
		{
			if(i != leasttime.size() - 1)
				printf(" -> ");
			printf("%d",leasttime[i]);
		}
	}
	else
	{
		printf("Distance = %d; Time = %d: ",dis, tim[d]);
		for(int i = leastlen.size() - 1; i >= 0; i--)
		{
			if(i != leastlen.size() - 1)
				printf(" -> ");
			printf("%d",leastlen[i]);
		}
	}
	return 0;
}