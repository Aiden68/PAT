#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct man{
	int id;
	int v;
	int t;
};

bool com(man a, man b)
{
	if (a.v + a.t != b.v + b.t)
		return a.v + a.t > b.v + b.t;
	else if (a.v != b.v)
		return a.v > b.v;
	else
		return a.id < b.id;
}
int main()
{
	int n, l, h;
	int cnt = 0;
	vector<man> v[4];
	scanf("%d%d%d", &n, &l, &h);
	for (int i = 0; i < n; i++)
	{
		man m;
		scanf("%d%d%d", &m.id, &m.v, &m.t);
		if (m.v >= l&& m.t >= l)
		{
			cnt++;
			if (m.v >= h&&m.t >= h)
				v[0].push_back(m);
			else if (m.t < h&&m.v >= h)
				v[1].push_back(m);
			else if (m.t <= m.v)
				v[2].push_back(m);
			else
				v[3].push_back(m);
		}
	}
	printf("%d\n", cnt);
	for (int i = 0; i < 4; i++)
	{
		sort(v[i].begin(), v[i].end(), com);
		for (int j = 0; j < v[i].size(); j++)
		{
			printf("%08d %d %d\n", v[i][j].id, v[i][j].v, v[i][j].t);
		}
	}
	return 0;
}