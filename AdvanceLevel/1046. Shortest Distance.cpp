#include<iostream>
using namespace std;

int main()
{
	int n , m;
	int circle[100001] = { 0 };
	int map[100001] = { 0 };
	int sum(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &circle[i + 1]);
		map[i + 1] = map[i] + circle[i + 1];
		
	}
	sum = map[n];
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int ti, tj;
		scanf("%d %d", &ti, &tj);
		int tsum(0);
		if (ti > tj)
		{
			int tmp = ti;
			ti = tj;
			tj = tmp;
		}
		tsum = map[tj-1] - map[ti-1];
		if (tsum >= (sum * 1.0 / 2))
			printf("%d\n", sum - tsum);
		else
			printf("%d\n", tsum);
	}
	return 0;
}