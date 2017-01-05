#include"iostream"
#include"string"
#include"algorithm"
using namespace std;

string intToString(int a,int &count)
{
	char str[10];
	count = 0;
	while (a != 0)
	{
		str[count++] = a%10+48;
		a /= 10;
	}
	reverse(str,str+count);
	return str;
}

int main()
{
	int a, b,sum,count;
	cin >> a >> b;
	sum = a + b;
	if (sum > -1000 && sum < 1000)
	{
		cout << sum;
	}
	else
	{
		if (sum > 0)
		{
			string str=intToString(sum, count);
			for (int i = 0; i <count; i++)
			{
				if ((i-count%3)%3==0&&i!=0)
					cout << ",";
				cout << str[i] - '0';
			}
		}
		else
		{
			string str = intToString(sum*-1, count);
			cout << "-";
			for (int i = 0; i <count; i++)
			{
				if ((i - count % 3) % 3 == 0&&i!=0)
					cout << ",";
				cout << str[i] - '0';
			}
		}
	}

	return 0;
}