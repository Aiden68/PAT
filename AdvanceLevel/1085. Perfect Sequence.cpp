#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	long long p;
	long long seq[100001];
	scanf("%d%lld", &n, &p);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &seq[i]);
	}
	sort(seq, seq + n);
	int flag = 0;
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (n - i <= max)
			break;
		for (int j = flag; j < n; j++)
		{
			if (seq[j] > seq[i] * p)
			{
				if (max < j - i)
					max = j - i;
				flag = j;
				break;
			}
			if (j == n - 1)
			{
				if (max < j - i + 1)
					max = j - i + 1;
			}
		}
	}
	printf("%d", max);
	return 0;
}