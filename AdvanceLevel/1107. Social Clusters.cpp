#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int ufs[1001] = { 0 };
int getHead(int a)
{
	if (ufs[a] == a)
		return a;
	while (ufs[a] >= 0)
		a = ufs[a];
	return a;
}

void unit(int a, int b)
{
	int ha = getHead(a);
	int hb = getHead(b);
	if (ha == hb)
		return;
	else if (a == ufs[a] && b == ufs[b])
	{
		ufs[a] = -2;
		ufs[b] = a;
	}
	else if (ufs[ha] < 0 && ufs[hb] < 0)
	{
		ufs[ha] += ufs[hb];
		ufs[hb] = ha;
	}
	else if (ufs[ha] < 0)
	{
		ufs[ha]--;
		ufs[hb] = ha;
	}
	else if (ufs[hb] < 0)
	{
		ufs[hb]--;
		ufs[ha] = hb;
	}
}
int main()
{
	int n;
	vector<int> v[1001];
	int max = -1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		char ch[5];
		scanf("%s", ch);
		string str = ch;
		str.erase(str.end()-1);
		int m;
		sscanf(str.c_str(), "%d", &m);
		for (int j = 0; j < m; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			if (max < tmp)
				max = tmp;
			v[tmp].push_back(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		ufs[i] = i;
	}
	for (int i = 1; i <= max; i++)
	{
		if (v[i].size() > 1)
		{
			int th = v[i][0];
			for (int j = 1; j < v[i].size(); j++)
			{
				unit(th, v[i][j]);
			}
		}		
	}
	vector<int> re;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (ufs[i] < 0)
		{
			cnt++;
			re.push_back(ufs[i]);
		}
		if (ufs[i] == i)
		{
			cnt++;
			re.push_back(-1);
		}
	}
	sort(re.begin(), re.end());
	printf("%d\n", cnt);
	int space = 0;
	for (int i = 0; i < cnt; i++)
	{
		if (space == 0)
			space++;
		else
			printf(" ");
		printf("%d", re[i]*-1);
	}
	return 0;
}