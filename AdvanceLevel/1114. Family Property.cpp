#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ufs[10005], size[10005], set[10005];
double area[10005];
int gethead(int a)
{
	if(ufs[a] == a)
		return a;
	while(ufs[a] >= 0)
		a = ufs[a];
	return a;
}

void solve(int ha, int hb)
{
	ufs[ha] = -1;
	ufs[hb] = ha;
	set[ha] += set[hb];
	area[ha] += area[hb];
	size[ha] += size[hb];
}
void unite(int a, int b)
{
	int ha = gethead(a);
	int hb = gethead(b);
	if(ha != hb)
	{
		if(ha < hb)
			solve(ha, hb);
		else
			solve(hb, ha);
	}
}

bool com(int a, int b)
{
	if(area[a] / size[a] != area[b] / size[b])
		return area[a] / size[a] > area[b] / size[b];
	else
		return a < b;
}

int main()
{
	int n;
	vector<int> v;
	scanf("%d", &n);
	for(int i = 0; i < 10000; i++)
	{
		ufs[i] = i;
		size[i] = 1;
	}
	for(int i = 0; i < n; i++)
	{
		int id, fid, mid, k, tset;
		double tarea;
		scanf("%d%d%d%d", &id, &fid, &mid, &k);
		if(ufs[id] == id)
			ufs[id] = -1;
		if(fid != -1)
			unite(id, fid);
		if(mid != -1)
			unite(id, mid);
		for(int j = 0; j < k; j++)
		{
			int cid;
			scanf("%d", &cid);
			unite(id, cid);
		}
		scanf("%d%lf",&tset, &tarea);
		set[gethead(id)] += tset;
		area[gethead(id)] += tarea;
	}
	for(int i = 0; i < 10000; i++)
	{
		if(ufs[i] < 0)
			v.push_back(i);
	}
	sort(v.begin(),v.end(),com);
	printf("%d\n", v.size());
	for(int i = 0; i < v.size(); i++)
	{
		printf("%04d %d %.3lf %.3lf\n", v[i], size[v[i]], 
			set[v[i]] * 1.0 / size[v[i]], area[v[i]] / size[v[i]]);
	}
	return 0;
}