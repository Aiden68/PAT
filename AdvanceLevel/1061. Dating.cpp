#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str1, str2, str3, str4;
	string week[8] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	cin >> str1 >> str2 >> str3 >> str4;
	int flag = 0;
	for (int i = 0; i < str1.size()&&flag != 2; i++)
	{
		if (str1[i] == str2[i])
		{
			if (flag == 0 && str1[i] >= 'A'&&str1[i] <= 'G')
			{
				flag++;
				cout << week[str1[i] - 'A'] << " ";
			}
			else if (flag == 1)
			{
				if (str1[i] >= 'A'&&str1[i] <= 'N')
				{
					printf("%d:", 10 + str1[i] - 'A');
					flag++;
				}
				else if (str1[i] >= '0'&&str1[i] <= '9')
				{
					printf("%02d:",  str1[i] - '0');
					flag++;
				}
			}
		}
	}
	for (int i = 0; i < str3.size(); i++)
	{
		if (str3[i] == str4[i])
		{
			if (str3[i] >= 'A' && str3[i] <= 'Z' || str3[i] >= 'a' && str3[i] <= 'z')
			{
				printf("%02d\n", i);
				break;
			}
		}
	}
	return 0;
}