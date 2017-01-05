#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct People{
	string name;
	int height;
};

bool com(People a, People b)
{
	if (a.height != b.height)
		return a.height > b.height;
	else
		return a.name < b.name;
}
int main()
{
	int n, m;
	People person[10001];
	vector<People> v;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		char tname[10];
		People p;
		scanf("%s%d", tname, &p.height);
		p.name = tname;
		v.push_back(p);
	}
	sort(v.begin(), v.end(), com);
	int k = n / m;
	int last = k + n % m;
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < last; j++)
			{
				int pos;
				int mid = last / 2 + 1;
				if (j == 0)
					pos = mid;
				else if (j % 2 == 0)
					pos = mid + j / 2;
				else
					pos = mid + (j + 1) / -2;
				person[pos] = v[j];
			}
			for (int j = 1; j <= last; j++)
			{
				if (j != 1)
					printf(" ");
				printf("%s", person[j].name.c_str());
			}
		}
		else
		{
			for (int j = 0; j < k; j++)
			{
				int pos;
				int mid = k / 2 + 1;
				if (j == 0)
					pos = mid;
				else if (j % 2 == 0)
					pos = mid + j / 2;
				else
					pos = mid + (j + 1) / -2;
				int tmp = j + (i - 1)*k + last;
				person[pos] = v[tmp];
			}
			for (int j = 1; j <= k; j++)
			{
				if (j != 1)
					printf(" ");
				printf("%s", person[j].name.c_str());
			}
		}
		printf("\n");
	}
	return 0;
}