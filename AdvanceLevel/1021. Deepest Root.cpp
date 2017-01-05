#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int cnt = 0;
vector<int> out;
vector<int> farest;
int maxdeep = 0;
void DFS(int v, int n, vector<int>* map,int *visit,int deep)
{
	if (maxdeep < deep)
	{
		maxdeep = deep;
		farest.clear();
		farest.push_back(v);
	}
	else if (maxdeep == deep)
	{
		farest.push_back(v);
	}
	visit[v] = 1;
	cnt++;
	for (int i = 0; i < map[v].size(); i++)
	{
		if (visit[map[v][i]] == 0)
			DFS(map[v][i], n,map,visit,deep+1);
	}
}


int main()
{
	int n;
	cin >> n;
	int visit[10001] = { 0 };
	vector<int>* map = new vector<int>[n+1];
	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	for (int i = 0; i < n - 1; i++)
	{
		int ti, tj;
		cin >> ti >> tj;
		map[ti].push_back(tj);
		map[tj].push_back(ti);
	}
	DFS(2, n,map,visit,0);
	int k = 1;
	while (cnt < n)
	{
		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == 0)
			{
				k++;
				DFS(i, n,map,visit,1);
				break;
			}
		}
	}
	if (k > 1)
	{
		cout << "Error: " << k << " components";
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		visit[i] = 0;
	}
	for (int i = 0; i < farest.size(); i++)
	{
		out.push_back(farest[i]);
	}
	DFS(farest[0], n, map, visit, 0);
	for (int i = 0; i < farest.size(); i++)
	{
		out.push_back(farest[i]);
	}
	sort(out.begin(), out.end());
	for (int i = 0; i < out.size(); i++)
	{
		if (i != 0)
		{
			if (out[i] != out[i - 1])
				cout << out[i] << endl;
		}
		else
			cout << out[i] << endl;
	}
	return 0;
}