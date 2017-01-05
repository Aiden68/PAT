#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int k;
	string str;
	vector<char> v;
	int flag[256] = { 0 };
	int flagp[256] = { 0 };
	scanf("%d", &k);
	cin >> str;
	int cnt = 1;
	for (int i = 0; i < str.size() - 1; i++)
	{
		int tmp = (int)str[i];
		if (str[i] == str[i + 1])
		{
			cnt++;
		}
		else
		{
			cnt = 1;
			flag[tmp] = -1;
		}
		if (i == str.size() - 2 && cnt != k)
		{
			flag[tmp] = -1;
		}
		if (cnt == k)
		{
			if (flag[tmp] != -1)
			{
				flag[tmp] = 1;
				v.push_back(str[i]);
			}
			cnt = 1;
			i++;
			if (i == str.size() - 2)
			{
				flag[str[str.size() - 1]] = -1;
				flag[str[str.size() - 1]] = -1;
			}
		}
	}
	if (str[str.size() - 1] != str[str.size() - 2])
	{
		int tmp = (int)str[str.size() - 1];
		flag[tmp] = -1;
	}
	/*for (int i = 48; i < 123; i++)
	{
		if (i < 58 || i == 95 || i>96)
		{
			if (flag[i] == 1)
				printf("%c", i);
		}
	}*/
	for (int i = 0; i < v.size(); i++)
	{
		if (flag[v[i]] != -1 && flagp[v[i]] == 0)
		{
			printf("%c", v[i]);
			flagp[v[i]] = 1;
		}
	}
	printf("\n");
	for (int i = 0; i < str.size(); i++)
	{
		printf("%c", str[i]);
		if (flag[str[i]] == 1)
			i += (k - 1);
	}
	return 0;
}

