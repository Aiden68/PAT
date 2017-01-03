#include<iostream>
using namespace std;

bool isPrime(int a)
{
	if(a < 2)
		return false;
	for(int i = 2; i * i <= a; i++)
	{
		if(a % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int n, size;
	bool flag[10010] = { false };
	scanf("%d%d",&size, &n);
	while(!isPrime(size))
		size++;
	for(int i = 0; i < n; i++)
	{
		int temp, pos;
		scanf("%d", &temp);
		temp %= size;
		pos = temp;
		int probe = 1;
		while(flag[pos] == true &&probe <= size)
		{
			pos = (temp + probe * probe) % size;
			probe++;
		}
		if(i != 0)
			printf(" ");
		if(probe != size + 1)
		{
			printf("%d",pos);
			flag[pos] = true;
		}
		else
			printf("-");
	}
	return 0;
}