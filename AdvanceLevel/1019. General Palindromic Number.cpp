#include<iostream>
using namespace std;

int main()
{
	int n, b;
	string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	int digit[50];
	for (int i = 0; i < 50; i++)
	{
		digit[i] = -1;
	}
	cin >> n >> b;
	int cnt = 0;
	int tmp = 1;
	int num = n;
	while (num != 0)
	{
		digit[cnt++] = num % b ;
		num /= b;
	}
	int start = 0;
	int end = cnt - 1;
	int flag = 0;
	while (start < end)
	{
		if (digit[start] != digit[end])
		{
			cout << "No" << endl;
			flag = 1;
			break;
		}
		start++;
		end--;
	}
	if (flag == 0)
		cout << "Yes" << endl;
	for (int  i = cnt - 1; i >= 0; i--)
	{
		if (i != cnt - 1)
		{
			cout << " ";
		}
		cout << digit[i];
	}
	if (n == 0)
		cout << 0;
	return 0;
}