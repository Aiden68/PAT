#include<iostream>
#include<string>
using namespace std;

string marsnum1[13] = { "tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string marsnum2[13] = { "", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
int main()
{
	int n;
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++)
	{
		string str;
		getline(cin, str);
		if (str[0] >= '0'&&str[1] <= '9')
		{
			int num;
			sscanf(str.c_str(), "%d", &num);
			if (num < 13)
				printf("%s\n", marsnum1[num].c_str());
			else
			{
				if (num % 13 != 0)
					printf("%s %s\n", marsnum2[num / 13].c_str(), marsnum1[num % 13].c_str());
				else
					printf("%s\n", marsnum2[num / 13].c_str());
			}
		}
		else if (str.size() > 4)
		{
			string str1, str2;
			int i = 0;
			for (; i < str.size(); i++)
			{
				if (str[i] == ' ')
					break;
				else
					str1 += str[i];
			}
			i++;
			for (; i < str.size(); i++)
				str2 += str[i];
			int flag = 0;
			for (int i = 1; i < 13; i++)
			{
				if (str1 == marsnum2[i])
				{
					flag = i;
					break;
				}
			}
			for (int i = 0; i < 13; i++)
			{
				if (str2 == marsnum1[i])
				{
					printf("%d\n", flag * 13 + i);
					break;
				}
			}
		}
		else
		{
			int flag = 0;
			for (int i = 0; i < 13; i++)
			{
				if (str == marsnum1[i])
				{
					printf("%d\n", i);
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				for (int i = 1; i < 13; i++)
				{
					if (str == marsnum2[i])
					{
						printf("%d\n", i * 13);
						break;
					}
				}
			}
		}
	}
	return 0;
}