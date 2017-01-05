#include<iostream>
using namespace std;

int main()
{
	int n, m, k;
	int like[201], given[10001];
	int len[201][10001] = { { 0 } };
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &like[i]);
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		scanf("%d", &given[i]);
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (like[i - 1] == given[j - 1])
			{
				len[i][j] = (len[i - 1][j - 1] > len[i][j - 1] ? len[i - 1][j - 1] : len[i][j - 1]) + 1;
			}
			else
			{
				len[i][j] = len[i][j - 1] > len[i -1][j] ? len[i][j - 1] : len[i - 1][j];
			}
		}
	}
	cout << len[m][k];
	return 0;
}