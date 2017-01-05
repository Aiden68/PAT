#include<iostream>
#include<string>
using namespace std;

int main()
{
	int broken[501] = { 0 };
	string str1, str2;
	char output[500];
	cin >> str1 >> str2;
	int cnt = 0;
	int j = 0;
	for (int i = 0; i < str1.size(); i++)
	{
		char tmpi = str1[i];
		if (tmpi >= 'a'&& tmpi <= 'z')
			tmpi = tmpi - 32;
		if (j >= str2.size() && broken[(int)tmpi] == 0)
		{
			broken[(int)tmpi] = 1;
			output[cnt++] = tmpi;
			continue;
		}
		char tmpj = str2[j];
		if (tmpj >= 'a'&& tmpj <= 'z')
			tmpj = tmpj - 32;
		if (tmpi != tmpj )
		{
			if (broken[(int)tmpi] == 0)
			{
				broken[(int)tmpi] = 1;
				output[cnt++] = tmpi;
			}
		}
		else
			j++;
	}
	for (int i = 0; i < cnt; i++)
	{
		cout << output[i];
	}
	return 0;
}