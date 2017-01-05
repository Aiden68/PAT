#include<iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		long long a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a > c && b > c&&c >0)
			printf("Case #%d: true\n", i + 1);
		else if (a < c && b < c&&c < 0)
			printf("Case #%d: false\n", i + 1);
		else if (a < 0 && b > 0 || a > 0 && b < 0)
		{
			if (a+b>c)
				printf("Case #%d: true\n", i + 1);
			else
				printf("Case #%d: false\n", i + 1);
		}
		else
		{
			if (c - a < b)
				printf("Case #%d: true\n", i + 1);
			else
				printf("Case #%d: false\n", i + 1);
		}
	}
	return 0;
}