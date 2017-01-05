#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
int main()
{
	int n;
	int pos[100001] = { 0 };
	int flag0 = 0;
	vector<int> v, vr;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if (tmp == 0)
			flag0 = i;
		v.push_back(tmp);
		vr.push_back(i);
		pos[tmp] = i;
	}
	int flag = -1;
	int cnt = 0;
	int index = 0;
	while (1)
	{
		for (int i = index; i < n; i++)
		{
			if (v[i] != i)
			{
				flag = i;
				index = i;
				break;
			}
		}
		if (flag == -1)
			break;
		else if (flag != 0)
		{
			v[0] = v[flag];
			pos[v[flag]] = 0;
			v[flag] = 0;
			flag0 = flag;
			flag = -1;
			cnt++;
		}
		else
			flag = -1;
		while (v[0] != 0)
		{
			v[flag0] = flag0;
			v[pos[flag0]] = 0;
			flag0 = pos[flag0];
			cnt++;
		}
	}
	printf("%d", cnt);
	return 0;
}