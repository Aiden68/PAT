#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool com(int a, int b){return a > b;}
int main()
{
	int n, m;
	int coin[10009] = { 0 };
	int f[10009][109] = { { 0 } };
	vector<int> v;
	scanf("%d%d",&n, &m);
	for(int i =  0; i < n; i++)
	{
		scanf("%d",&coin[i + 1]);
	}
	sort(coin + 1, coin + n + 1,com);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(j >= coin[i])
				f[i][j] = max(f[i - 1][j],f[i - 1][j - coin[i]] + coin[i]);
			else
				f[i][j] = f[i - 1][j];
		}
		if(f[n][m] == m)
			break;
		if(i == n)
		{
			cout<<"No Solution";
			return 0;
		}
	}
	int i = n;
	while(i > 0&&m > 0)
	{
		if(m >= coin[i]&&f[i - 1][m] <= f[i - 1][m - coin[i]] + coin[i])
		{
			v.push_back(coin[i]);
			m -= coin[i];
			i--;
		}
		else
			i--;
	}
	for(int i = 0; i < v.size(); i++)
	{
		if(i != 0)
			printf(" ");
		printf("%d",v[i]);
	}	
	return 0;
}