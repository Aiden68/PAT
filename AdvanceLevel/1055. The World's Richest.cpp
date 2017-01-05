#include<iostream>
#include<algorithm>
using namespace std;

struct Richest{
	string name;
	int age;
	int worth;
};

bool com(Richest a, Richest b)
{
	if (a.worth != b.worth)
		return a.worth > b.worth;
	else if (a.age != b.age)
		return a.age < b.age;
	else
		return a.name < b.name;
}

int main()
{
	int n, k;
	Richest richer[100001];
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		char tmp[10];
		scanf("%s %d %d", tmp, &richer[i].age, &richer[i].worth);
		richer[i].name = tmp;		
	}
	sort(richer, richer + n, com);
	for (int i = 0; i < k; i++)
	{
		int m, ageMin, ageMax;
		scanf("%d %d %d", &m, &ageMin, &ageMax);
		int flag = 0;
		printf("Case #%d:\n", i + 1);
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (cnt == m)
				break;
			if (richer[j].age >= ageMin&&richer[j].age <= ageMax)
			{
				printf("%s %d %d\n", richer[j].name.c_str(), richer[j].age, richer[j].worth);
				flag = 1;
				cnt++;
			}
		}
		if (flag == 0)
			printf("None\n");
	}
	return 0;
}