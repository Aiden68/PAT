#include<iostream>
#include<vector>
using namespace std;

int n , root;
int supply[100001] = { 0 };
vector<int> v[100001];
int visit[100001];
int maxdeep = 0;
int num = 0;
void dfs(int root,int deep)
{
	visit[root] = 1;
	if(maxdeep < deep)
	{
		maxdeep = deep;
		num = 1;
	}
	else if(maxdeep == deep)
	{
		num++;
	}
	for(int i = 0; i < v[root].size(); i++)
	{
		if(visit[v[root][i]] == 0)
		{
			dfs(v[root][i],deep + 1);
		}
	}
}
int main()
{
	double p,r;
	scanf("%d%lf%lf",&n,&p,&r);
	r /= 100;
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&supply[i]);
		if(supply[i] == -1)
		{
			root = i;
		}
		else
		{
			v[supply[i]].push_back(i);
		}
	}
	dfs(root,0);
	for(int i = 0; i < maxdeep; i++)
	{
		p *= (1 + r);
	}
	printf("%.2lf %d",p,num);
	return 0;
}