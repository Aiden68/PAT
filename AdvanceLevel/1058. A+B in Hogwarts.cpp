#include<iostream>
#include<string>
using namespace std;

void solve(int &g,int &s,int &k,string str)
{
	int i = 0;
	while (str[i] != '.')
	{
		g = g * 10 + str[i] - '0';
		i++;
	}
	i++;
	while (str[i] != '.')
	{
		s = s * 10 + str[i] - '0';
		i++;
	}
	i++;
	while (i < str.size())
	{
		k = k * 10 + str[i] - '0';
		i++;
	}
}

int main()
{
	string a, b;
	int gallenA = 0, sickleA = 0, knutA = 0, gallenB = 0, sickleB = 0, knutB = 0;
	cin >> a >> b;
	solve(gallenA, sickleA, knutA, a);
	solve(gallenB, sickleB, knutB, b);
	int flag = 0;
	int g, s, k;
	k = knutA + knutB;
	if (k > 28)
	{
		flag = 1;
		k -= 29;
	}
	s = sickleA + sickleB + flag;
	flag = 0;
	if (s > 16)
	{
		flag = 1;
		s -= 17;
	}
	g = gallenA + gallenB + flag;
	printf("%d.%d.%d", g, s, k);
	return 0;
}