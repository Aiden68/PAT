#include<iostream>
using namespace std;

int main()
{
	int n, m;
	int contest[1001];
	int order[1001];
	int seq[1001] = { 0 };
	int count[1001] = { 0 };
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &contest[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &order[i]);
	}
	int flag = 2;
	int orde = 1;
	while(flag > 1)
	{
		flag = 0;
		int cnt = 0;
		int max = -1;
		for (int i = 0; i < n; i++)
		{
			if (seq[order[i]] == 0)
			{
				flag++;
				if (cnt % m == 0)
				{
					max = order[i];
				}
				else
				{
					if (contest[max] < contest[order[i]])
					{
						seq[max] = orde;
						max = order[i];
					}
					else
						seq[order[i]] = orde;
					count[orde]++;
				}
				cnt++;
			}
		}
		if (flag == 1)
		{
			seq[max] = orde;
			count[orde]++;
		}
		orde++;
		if (orde > 1)
			count[orde] += count[orde - 1];
	}
	int space = 0;
	for (int i = 0; i < n; i++)
	{
		if (space == 0)
			space++;
		else
			printf(" ");
		printf("%d", n - count[seq[i]] + 1);
	}
	return 0;
}