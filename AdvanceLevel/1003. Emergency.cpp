#include<iostream>
using namespace std;
const int inf = 99999999;

int visit[550] = { 0 };
int shortestPath[550];
int teamNum[550];
int n, m, c1, c2;
int team[550] = { 0 };
int graph[550][550] = { 0 };
int dist[550] = { 0 };
void dijkstra()
{
	visit[c1] = 1;
	while(1)
	{
		int min = inf;
		int v = -1;
		for(int i = 0; i < n; i++)
		{
			if(min > dist[i] && visit[i] == 0)
			{
				min = dist[i];
				v = i;
			}
		}
		if(v == -1)
			break;
		visit[v] = 1;
		for(int i = 0; i < n; i++)
		{
			if(dist[i] > dist[v] + graph[v][i])
			{
				dist[i] = dist[v] + graph[v][i];
				shortestPath[i] = shortestPath[v];
				teamNum[i] = teamNum[v] + team[i];
			}
			else if(dist[i] == dist[v] + graph[v][i])
			{
				shortestPath[i] += shortestPath[v];
				if(teamNum[i] < teamNum[v] + team[i])
					teamNum[i] = teamNum[v] + team[i];
			}
		}
	}
}
int main()
{
	fill(graph[0], graph[0] + 550 * 550, inf);
	scanf("%d%d%d%d", &n, &m, &c1, &c2);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &team[i]);
	}
	for(int i = 0; i < m; i++)
	{
		int v1, v2, len;
		scanf("%d%d%d", &v1, &v2, &len);
		graph[v1][v2] = graph[v2][v1] = len;
	}
	for(int i = 0; i < n; i++)
	{
		dist[i] = graph[c1][i];
		if(dist[i] != inf)
		{
			shortestPath[i] = 1;
			teamNum[i] = team[i] + team[c1];
		}
	}
	teamNum[c1] = team[c1];
	shortestPath[c1] = 1;
	dist[c1] = 0;
	dijkstra();
	printf("%d %d", shortestPath[c2], teamNum[c2]);
	return 0;
}
