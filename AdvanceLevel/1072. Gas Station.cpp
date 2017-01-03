#include<iostream>
using namespace std;

int n, m, k, ds;
int map[1015][1015] = { { 0 } };
int visit[1015] = { 0 };
int dist[1015] = { 0 };

void dijkstra(int source,int &sdis)
{
	/*memset(visit, 0, sizeof(int) * 1015);*/
	int flag = 0;
	while (1)
	{
		int min = -1;
		for (int i = 1; i <= n+m; i++)
		{
			if (visit[i] == 0 && min == -1&&dist[i]!=999999)
			{
				min = i;
			}
			else if (visit[i] == 0 && dist[min] > dist[i])
			{
				min = i;
			}
		}
		if (min == -1)
			break;
		else
			visit[min] = 1;
		if (flag == 0 && min > 0 && min <= n)
		{
			sdis = dist[min];
			flag = 1;
		}
		for (int i = 1; i <= n+m; i++)
		{
			if (map[min][i] + dist[min] < dist[i])
				dist[i] = map[min][i] + dist[min];
		}
	}
}
int main()
{
	/*memset(map, 1, sizeof(int) * 1015 * 1015);*/
	for (int i = 0; i < 1015; i++)
	{
		for (int j = 0; j < 1015; j++)
			map[i][j] = 999999;
	}
	scanf("%d%d%d%d", &n, &m, &k, &ds);
	for (int i = 0; i < k; i++)
	{
		char tx[5], ty[5];
		string stri, strj;
		int ti, tj, v;
		scanf("%s %s %d", tx, ty,&v);
		stri = tx;
		strj = ty;
		if (stri[0] != 'G')
			sscanf(stri.c_str(), "%d", &ti);
		else
		{
			stri.erase(0, 1);
			sscanf(stri.c_str(), "%d", &ti);
			ti += n;
		}
		if (strj[0] != 'G')
			sscanf(strj.c_str(), "%d", &tj);
		else
		{
			strj.erase(0, 1);
			sscanf(strj.c_str(), "%d", &tj);
			tj += n;
		}
		map[ti][tj] = map[tj][ti] = v;
	}
	int smallestDis = 0;
	int ave = 0;
	int station = -1;
	for (int i = n+1; i <= m+n; i++)
	{
		for (int j = 1; j <= m+n; j++)
		{
			dist[j] = map[i][j];
			visit[j] = 0;
		}
		visit[i] = 1;
		int sdis = 0;
		int average = 0;
		dijkstra(i, sdis);
		int flag1 = 0;
		for (int j = 1; j <= n; j++)
		{
			average += dist[j];
			if (dist[j] > ds)
			{
				flag1 = 1;
				break;
			}
		}
		if (flag1 == 1)
			continue;
		if (i == n + 1)
		{
			smallestDis = sdis;
			ave = average;
			station = i;
		}
		else 
		{
			if (smallestDis < sdis)
			{
				smallestDis = sdis;
				ave = average;
				station = i;
			}
			else if (smallestDis == sdis&&ave > average)
			{
				smallestDis = sdis;
				ave = average;
				station = i;
			}
		}
	}
	if (station == -1)
		printf("No Solution");
	else
	{
		printf("G%d\n", station-n);
		printf("%.1f %.1f", smallestDis*1.0, ave*1.0 / n);
	}
	return 0;
}