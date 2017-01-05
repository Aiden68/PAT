#include<iostream>
using namespace std;

bool isPrime(long long n)
{
	if (n < 2)
		return false;
	else if (n == 2)
		return true;
	else if (n % 2 == 0)
		return false;
	else
	{
		for (long long i = 3; i * i <= n; i++)
		{
			if (n % i == 0)
				return false;
		}
	}
	return true;
}

int main()
{
	long long num;
	long long cnt = 0;
	long long factor[10000] = { 0 };
	long long factorN[10000] = { 0 };
	cin >> num;
	long long n = num;
	long long i = 2;
	while (i <= num)
	{
		if (num % i == 0&&isPrime(i))
		{
			num /= i;
			if (cnt > 0 && i == factor[cnt - 1])
			{
				factorN[cnt - 1]++;
			}
			else
			{
				factorN[cnt]++;
				factor[cnt++] = i;				
			}
		}
		else
			i++;
	}
	if (n == 1)
	{
		printf("1=1\n");
		return 0;
	}
	for (long long i = 0; i < cnt; i++)
	{
		if (i == 0)
			cout << n << "=" << factor[i];
		else
			cout << "*" << factor[i];
		if (factorN[i] > 1)
			cout << "^" << factorN[i];
	}
	return 0;
}