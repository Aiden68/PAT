#include"iostream"
using namespace std;

int main()
{
	int n, m, c1, c2;
	cin >> n >> m >> c1 >> c2;
	int *team = new int[n];
	int *path = new int[n];
	int *pathel = new int[n];
	int *pathcn = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> team[i];
		pathel[i] = 0;
		pathcn[i] = 0;
	}
	int **g;
	g = new int *[n];
	for (int i = 0; i < n; i++)
	{
		g[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				g[i][j] = 0;
			else
				g[i][j] = 999999;
		}
	}
	for (int i = 0; i < m; i++)
	{
		int tempc1, tempc2;
		int length;
		cin >> tempc1 >> tempc2 >> length;
		g[tempc1][tempc2] = length;
		g[tempc2][tempc1] = length;
	}
	pathel[c1] = team[c1];
	pathcn[c1] = 1;
	int *dist = new int[n];
	for (int i = 0; i < n; i++)
	{
		dist[i] = g[c1][i];
		if (dist[i] != 999999)
		{
			if (i != c1)
				pathel[i] = pathel[c1] + team[i];
			pathcn[i] = pathcn[c1];
		}
	}
	int mt = team[c1] + team[c2];
	for (int i = 0; i < n; i++)
	{
		path[i] = -1;
	}
	int s = 0;
	path[c1] = s++;
	path[c2] = n-1;
	int count = 1;
	while (1)
	{	
		int flagc = -1;
		int tm = 999999;
		for (int i = 0; i < n; i++)
		{
			if (path[i] == -1 && dist[i] < tm)
			{
				tm = dist[i];
				flagc = i;
			}
		}
		if (flagc == -1)
			break;
		else
			path[flagc] = s++;		
		for (int i = 0; i < n; i++)
		{
			if (dist[i] > dist[flagc] + g[flagc][i])
			{
				dist[i] = dist[flagc] + g[flagc][i];
				pathcn[i] = pathcn[flagc];
				pathel[i] = pathel[flagc] + team[i];
			}
			else if (dist[i] == dist[flagc] + g[flagc][i])
			{
				if (i != flagc)
				{
					pathcn[i] = pathcn[flagc] + pathcn[i];
					if (pathel[i] < pathel[flagc] + team[i])
					{
						pathel[i] = pathel[flagc] + team[i];
					}
				}
				
			}
		}	
	}
	cout << pathcn[c2]<<" "<<pathel[c2];
	return 0;
}