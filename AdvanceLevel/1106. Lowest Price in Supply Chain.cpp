#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int main()
{
	int n;
	double p, r;
	vector<int> v[100001];
	queue<int> q;
	int findRoot[100001] = { 0 };
	int deep[100001] = { 0 };
	int retailer[100001] = { 0 };
	int root = 0;
	scanf("%d%lf%lf", &n, &p, &r);
	r = 1.0 + r / 100;
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		if (k == 0)
			retailer[i] = 1;
		for (int j = 0; j < k; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			v[i].push_back(tmp);
			findRoot[tmp] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (findRoot[i] == 0)
		{
			root = i;
			break;
		}
	}
	if (n == 1)
	{
		printf("%.4lf %d", p, 1);
		return 0;
	}
	q.push(root);
	int re = -1;
	int cnt = 0;
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		if (re != -1 && deep[t] + 1>re)
			break;
		for (int i = 0; i < v[t].size(); i++)
		{
			q.push(v[t][i]);
			deep[v[t][i]] = deep[t] + 1;
			if (retailer[v[t][i]] == 1)
			{
				cnt++;
				if (re == -1)
					re = deep[v[t][i]];
			}
		}
	}
	printf("%.4lf %d", p * pow(r, re), cnt);
	return 0;
}