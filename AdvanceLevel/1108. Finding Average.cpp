#include<iostream>
#include<string>
using namespace std;

int flagDigit;
bool isLegal(string str)
{
	if (str[0] == '.'||str[0] == '-'&&str[1] == '.')
		return false;
	int flagPoint = 0;
	flagDigit = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '.')
		{
			flagPoint++;
			flagDigit = str.size() - i - 1;
			if (flagDigit > 2)
				return false;
		}
		else if (str[i] == '-'&&i != 0)
			return false;
		else if (i != 0&&str[i] < '0' || str[i]>'9')
			return false;
	}
	if (flagPoint > 1)
		return false;
	else
		return true;
}

double strToD(string str)
{
	double re = 0;
	double chu = 1;
	for (int i = 0; i < flagDigit; i++)
	{
		chu *= 10;
	}
	if (str[0] == '-')
	{
		for (int i = 1; i < str.size(); i++)
		{
			if (str[i] != '.')
			{
				re = re * 10 + (str[i] - '0');
			}
		}
		re *= -1;
	}
	else
	{
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] != '.')
			{
				re = re * 10 + (str[i] - '0');
			}
		}
	}
	return re / chu;
}

int main()
{
	int n;
	double sum(0);
	int cnt(0);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		if (!isLegal(tmp))
			printf("ERROR: %s is not a legal number\n", tmp.c_str());
		else if (strToD(tmp)<-1000 || strToD(tmp)>1000)
			printf("ERROR: %s is not a legal number\n", tmp.c_str());
		else
		{
			sum += strToD(tmp);
			cnt++;
		}
	}
	if (cnt == 1)
	{
		printf("The average of 1 number is %.2lf", sum / cnt);
	}
	else if (cnt == 0)
	{
		printf("The average of 0 numbers is Undefined");
	}
	else
		printf("The average of %d numbers is %.2lf", cnt, sum / cnt);
	return 0;
}