#include<iostream>
#include<string.h>
using namespace std;

bool isPrime(int a)
{
	if (a <= 2)
		return false;
	if (a % 2 == 0)
		return false;
	for (int i = 3; i * i <= a; i++)
	{
		if (a % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int n, m;
	int contest[10001];
	int hashContest[10000] = { 0 };
	memset(hashContest, -1, 10000 * sizeof(int));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &contest[i]);
		hashContest[contest[i]] = i;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int tmp,rank;
		scanf("%d", &tmp);
		rank = hashContest[tmp] + 1;
		if (hashContest[tmp] != -1)
			hashContest[tmp] = -2;
		if (rank == -1)
			printf("%04d: Checked\n", tmp);
		else if (rank == 1)
			printf("%04d: Mystery Award\n", tmp);
		else if (isPrime(rank))
			printf("%04d: Minion\n", tmp);
		else if (rank == 0)
			printf("%04d: Are you kidding?\n", tmp);
		else
			printf("%04d: Chocolate\n", tmp);
	}
	return 0;
}