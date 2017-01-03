#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPrime(long long n)
{
	if (n < 2)
		return false;
	if (n % 2 == 0)
		return false;
	for (long long i = 3; i*i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
int main()
{
	long long num;
	long long cnt = 0;
	long long max = 0;
	long long flag = 0;
	scanf("%lld", &num);
	long long tmp = num;
	if (isPrime(num))
	{
		printf("1\n%lld", num);
		return 0;
	}
	for (long long i = 2; i * i <= num; i++)
	{
		tmp = num;
		cnt = 0;
		for (long long j = i; j <= tmp; j++)
		{
			if (tmp % j == 0 )
			{
				cnt++;
				tmp /= j;
			}
			else
				break;
		}
		if (max < cnt)
		{
			max = cnt;
			flag = i;
		}
	}
	if (max != 0)
	{
		printf("%lld\n", max);
		for (long long i = flag; i < flag + max; i++)
		{
			if (i != flag)
				printf("*");
			printf("%lld", i);
		}
	}
	else
		printf("1\n%lld", num);
	return 0;
}