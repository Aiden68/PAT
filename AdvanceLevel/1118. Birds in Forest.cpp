#include<iostream>
#include<vector>
using namespace std;

int getHead(int a,int *ufs)
{
	if (ufs[a] == 0)
		return a;
	while (ufs[a] > 0)
		a = ufs[a];
	return a;
}
int main()
{
	int n;
	int ufs[10001] = { 0 };
	scanf("%d", &n);
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		int m;
		int flag = 0;
		vector<int> unit;
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			int tmp;
			scanf("%d", &tmp);
			if (tmp > max)
				max = tmp;
			unit.push_back(tmp);
			if (ufs[tmp] != 0)
				flag = getHead(tmp,ufs);
		}
		if (flag == 0)
		{
			ufs[unit[0]] = -1;
			for (int i = 1; i < unit.size(); i++)
			{
				ufs[getHead(unit[i],ufs)] = unit[0];
			}
		}
		else
		{
			for (int i = 0; i < unit.size(); i++)
			{
				int temp = getHead(unit[i], ufs);
				if (temp != flag)
				{
					ufs[temp] = flag;
				}
			}
		}
	}
	int treeNum = 0;
	for (int i = 1; i <= max; i++)
	{
		if (ufs[i] < 0)
			treeNum++;
	}
	cout << treeNum << " " << max << endl;
	int k;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int ti, tj;
		scanf("%d %d", &ti, &tj);
		if (getHead(ti, ufs) == getHead(tj, ufs))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}