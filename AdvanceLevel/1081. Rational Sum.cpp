#include<iostream>
#include<string>
using namespace std;

long long maxFactor(long long a, long long b)
{
	if (a == 0)
		return b;
	else if (b == 0)
		return a;
	else
		return a > b ? maxFactor(a % b, b) : maxFactor(a, b % a);
}

void add(long long &a, long long &b, long long c, long long d)
{
	long long ta = a*d + b*c;
	long long tb = b * d;
	long long tf = maxFactor(ta, tb);
	ta /= tf;
	tb /= tf;
	a = ta;
	b = tb;
}
int main()
{
	int n;
	long long a, b,c,d;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		string str,numerator,denominator;
		cin >> str;
		int j = 0;
		for (; j < str.size(); j++)
		{
			if (str[j] == '/')
				break;
			numerator += str[j];
		}
		j++;
		for (; j < str.size(); j++)
		{
			denominator += str[j];
		}
		if (i == 0)
		{
			sscanf(numerator.c_str(), "%lld", &a);
			sscanf(denominator.c_str(), "%lld", &b);
		}
		else
		{
			sscanf(numerator.c_str(), "%lld", &c);
			sscanf(denominator.c_str(), "%lld", &d);
			add(a, b, c, d);
		}
	}
	if (a / b != 0)
	{
		long long interger = a / b;
		a %= b;
		if (a!=0)
			printf("%lld %lld/%lld", interger, a, b);
		else
			printf("%lld", interger);
	}
	else
	{
		if (a != 0)
			printf("%lld/%lld", a, b);
		else
			printf("0");
	}
	return 0;
}