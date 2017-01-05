#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> v;
int solve(int c,int cnt,int n)
{
	if (cnt == 0||n == 0)
		return 0;
	else if (cnt == 1)
		return 1;
	int sum = 0;
	if (n >= c)
	{
		sum = v[cnt - 1];
		sum *= (n / c);
		if (n >= 2 * c)
			sum += c;
		else
			sum += (n - c + 1);
		sum += solve(c / 10, cnt - 1, n - (n / c)*c);
	}
	else
		sum += solve(c / 10, cnt - 1, n);
	return sum;
}

int main()
{
	int n;
	int cnt(0);
	int sum(0);
	scanf("%d", &n);
	int tmp = n;
	while (tmp != 0)
	{
		tmp /= 10;
		cnt++;
	}
	int c = 1;
	v.push_back(0);
	for (int i = 1; i < cnt; i++)
	{
		int temp = 1;
		c *= 10;
		for (int j = 1; j < i; j++)
		{
			temp *= 10;
		}
		sum = (temp * i);
		v.push_back(sum);
	}
	cout << solve(c, cnt, n);
	return 0;
}