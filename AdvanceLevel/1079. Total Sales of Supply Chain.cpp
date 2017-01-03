#include<iostream>
#include<vector>
using namespace std;

int n;
double p, r, total = 0;
vector<int> chain[100001];
int retailer[100001] = { 0 };
bool visit[100001] = { false };
void dfs(int root,double p)
{
	visit[root] = true;
	if(retailer[root] != 0)
	{
		total += p * retailer[root];
	}
	for(int i = 0; i < chain[root].size(); i++)
	{
		if(visit[chain[root][i]] == false)
			dfs(chain[root][i],p * r);
	}
}
int main()
{
	scanf("%d %lf %lf",&n, &p, &r);
	r = 1 + r / 100;
	for(int i = 0; i < n; i++)
	{
		int m;
		scanf("%d",&m);
		if(m != 0)
		{
			for(int j = 0; j < m; j++)
			{
				int temp;
				scanf("%d", &temp);
				chain[i].push_back(temp);
			}
		}
		else
			scanf("%d", &retailer[i]);
	}
	dfs(0,p);
	printf("%.1lf",total);
	return 0;
}