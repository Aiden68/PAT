#include<iostream>
using namespace std;

bool isPrime(int n)
{
	if(n < 2)
		return false;
	if(n == 2)
		return true;
	if(n % 2 == 0)
		return false;
	for(int i = 3; i * i <= n; i++)
	{
		if(n % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int n,d;
	scanf("%d",&n);
	while(n > 0)
	{
		scanf("%d",&d);
		if(isPrime(n))
		{
			int rn = 0;
			while(n != 0)
			{
				rn = rn * d + (n % d);
				n /= d;
			}
			if(isPrime(rn))
				printf("Yes\n");
			else
				printf("No\n");
		}
		else
			printf("No\n");
		scanf("%d",&n);
	}
	return 0;
}