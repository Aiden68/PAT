#include<iostream>
using namespace std;

int main()
{
	int n;
	int cnt[10001] = { 0 };
	int input[100001] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		cnt[tmp]++;
		input[i] = tmp;
	}
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (cnt[input[i]] == 1)
		{
			cout << input[i];
			flag = 1;
			break;
		}
	}
	if (flag == 0)
		cout << "None";
	return 0;
}