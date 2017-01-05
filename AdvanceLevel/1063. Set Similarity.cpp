#include<iostream>
#include<set>
#include<iterator>
#include<algorithm>
#include<set>
using namespace std;

int main()
{
	int n, m, k;
	set<int> s[51];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &m);
		for (int j = 0; j < m; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			s[i].insert(tmp);
		}
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
	{
		int t1, t2;
		scanf("%d%d", &t1, &t2);
		int cnt = 0;
		for (set<int>::iterator iter = s[t1 - 1].begin(); iter != s[t1 - 1].end(); ++iter){
			if (s[t2 - 1].find(*iter) != s[t2 - 1].end())
				cnt++;
		}
		printf("%.1f%%\n", cnt * 100.0 / (s[t1 - 1].size() + s[t2 - 1].size() - cnt));
	}
	return 0;
}