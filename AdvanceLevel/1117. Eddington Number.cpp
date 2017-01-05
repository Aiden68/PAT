#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	int dist[100002] = { 0 };
	int max = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		if (tmp > 100001)
			tmp = 100001;
		if (tmp > max)
			max = tmp;
		dist[tmp]++;
	}
	int sum = dist[max];
	for (int i = max - 1; i >= 0; i--)
	{
		if (i <= sum)
		{
			cout << i;
			break;
		}
		sum += dist[i];
	}
	return 0;
}