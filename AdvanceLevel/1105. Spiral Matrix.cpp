#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool com(int a, int b)
{
	return a > b;
}
int main()
{
	int n,m,k;
	vector<int> v;
	int visit[1001][1001] = { { 0 } };
	int spiral[1001][1001] = { { 0 } };
	scanf("%d", &n);
	int ti = n, tj = 1;
	while (ti >= tj)
	{
		if (ti * tj == n)
		{
			m = ti;
			k = tj;
			ti--;
			tj++;
		}
		else if (ti * tj > n)
			ti--;
		else
			tj++;
	}
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(),com);
	int i = 0, j = 0;
	int cnt(0);
	int corner = 0;
	int flag = 0;
	if (k == 1)
	{
		for (int i = 0; i < m; i++)
		{
			printf("%d\n", v[i]);
		}
		return 0;
	}
	while (1)
	{
		if (flag > 1)
			break;
		if (corner == 0)
			corner++;
		else
		{
			i++;
			j++;
		}
		for (; j < k; j++)
		{
			if (visit[i][j] == 0)
			{
				flag = 0;
				spiral[i][j] = v[cnt++];
				visit[i][j] = 1;
			}
			else
			{
				flag++;
				break;
			}
		}
		j--;
		i++;
		for (; i < m; i++)
		{
			if (visit[i][j] == 0)
			{
				flag = 0;
				spiral[i][j] = v[cnt++];
				visit[i][j] = 1;
			}
			else
			{
				flag++;
				break;
			}
		}
		i--;
		j--;
		for (; j >= 0; j--)
		{
			if (visit[i][j] == 0)
			{
				flag = 0;
				spiral[i][j] = v[cnt++];
				visit[i][j] = 1;
			}
			else
			{
				flag++;
				break;
			}
		}
		j++;
		i--;
		for (; i >= 0; i--)
		{
			if (visit[i][j] == 0)
			{
				spiral[i][j] = v[cnt++];
				visit[i][j] = 1;
				flag = 0;
			}
			else
			{
				flag++;
				break;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		int space = 0;
		for (int j = 0; j < k; j++)
		{
			if (space == 0)
				space++;
			else
				printf(" ");
			printf("%d", spiral[i][j]);
		}
		printf("\n");
	}
	return 0;
}