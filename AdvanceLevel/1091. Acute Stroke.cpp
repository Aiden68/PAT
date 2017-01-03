#include<iostream>
using namespace std;

int m,n,l,t;
int ufs[85*1286*128];
bool slice[65][1300][135];

int gethead(int a)
{
	if(ufs[a] == a)
		return a;
	while(ufs[a] > 0)
		a = ufs[a];
	return a;
}

void unite(int a, int b)
{
	int ha = gethead(a);
	int hb = gethead(b);
	if(ha == hb)
		return;
	else if(ufs[a] == a&&ufs[b] == b)
	{
		ufs[a] = -2;
		ufs[b] = a;
	}
	else if(ufs[ha] < 0&&ufs[hb] < 0)
	{
		if(ufs[ha] < ufs[hb])
		{
			ufs[ha] += ufs[hb];
			ufs[hb] = ha;
		}
		else
		{
			ufs[hb] += ufs[ha];
			ufs[ha] = hb;
		}
	}
	else if(ufs[ha] < 0)
	{
		ufs[ha]--;
		ufs[hb] = ha;
	}
	else if(ufs[hb] < 0)
	{
		ufs[hb]--;
		ufs[ha] = hb;
	}
}
int main()
{	
	scanf("%d%d%d%d",&m,&n,&l,&t);
	for(int i = 1; i <= l; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			for(int k = 1; k <= n; k++)
			{
				int temp;
				scanf("%d",&temp);
				slice[i][j][k] = temp;
			}
		}
	}
	int num = l * m * n;
	for(int i = 1; i <= num; i++)
		ufs[i] = i;
	for(int i = 1; i <= l; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			for(int k = 1; k <= n; k++)
			{
				int temp = (i - 1) * m * n + (j - 1) * n + k;
				if(slice[i][j][k]==0)
					continue;
				if(temp + m * n <= num&&slice[i + 1][j][k] != 0)
					unite(temp,temp + m * n);
				if(temp + n <= num&&slice[i][j + 1][k] != 0)
					unite(temp,temp + n);
				if(temp + 1 <= num&&slice[i][j][k + 1] != 0)
					unite(temp,temp + 1);
				if(ufs[temp] == temp)
					ufs[temp] = -1;
			}
		}
	}
	int sum = 0;
	for(int i = 1; i <= num; i++)
	{
		if(ufs[i] != i)
		{
			int tt = abs(ufs[gethead(i)]);
			if(tt >= t)
			{
				sum++; 
			}
		}
	}
	cout<<sum;
	return 0;
}