#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <cstdio>
#include<string>
#include<algorithm>
using namespace std;

struct score
{
	string id;
	int c;
	int m;
	int e;
	int a;
};

bool comA(score a, score b)
{
	return a.a > b.a;
}
bool comC(score a, score b)
{
	return a.c > b.c;
}

bool comM(score a, score b)
{
	return a.m > b.m;
}

bool comE(score a, score b)
{
	return a.e > b.e;
}

void bestRank(string id,score *c,int n)
{
	int i= 0;
	int best = n;
	char course;
	while (i < n && c[i].id != id)
		i++;
	if (i == n)
	{
		cout << "N/A" << endl;
		return;
	}
	i = 0;
	sort(c, c + n, comA);
	while (i < n && c[i].id != id)
		i++;
	if (i == n)
	{
		cout << "N/A"<<endl;
		return;
	}
	while (i > 0 && c[i].a == c[i - 1].a)
		i--;
	if (best > i)
	{
		best = i;
		course = 'A';
	}
	i = 0;
	sort(c, c + n, comC);
	while (c[i].id != id)
		i++;
	while (i > 0 && c[i].c == c[i - 1].c)
		i--;
	if (best > i)
	{
		best = i;
		course = 'C';
	}
	i = 0;
	sort(c, c + n, comM);
	while (c[i].id != id)
		i++;
	while (i > 0 && c[i].m == c[i - 1].m)
		i--;
	if (best > i)
	{
		best = i;
		course = 'M';
	}
	i = 0;
	sort(c, c + n, comE);
	while (c[i].id != id)
		i++;
	while (i > 0 && c[i].e == c[i - 1].e)
		i--;
	if (best > i)
	{
		best = i;
		course = 'E';
	}
	i = 0;
	cout << best + 1 << " " << course << endl;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	score *c = new score[n];
	string searchId[2001];
	for (int i = 0; i < n; i++)
	{
		cin >> c[i].id;
		scanf("%d %d %d", &c[i].c, &c[i].m, &c[i].e);
		c[i].a = (c[i].c + c[i].m + c[i].e) / 3;
	}
	string s;
	for (int i = 0; i < m; i++)
	{
		cin >> searchId[i];
	}
	for (int i = 0; i < m; i++)
	{
		bestRank(searchId[i], c, n);
	}
	return 0;
}