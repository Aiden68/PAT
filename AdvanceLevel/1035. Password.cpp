#include<iostream>
#include<string>
using namespace std;

struct Account{
	string user;
	string password;
};
int main()
{
	int n;
	Account account[1001];
	int modify[1001] = { 0 };
	int flag = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> account[i].user >> tmp;
		int modifyFlag = 0;
		for (int i = 0; i < tmp.size(); i++)
		{
			switch (tmp[i])
			{
				case '1':
					tmp[i] = '@';
					modifyFlag = 1;
					break;
				case '0':
					tmp[i] = '%';
					modifyFlag = 1;
					break;
				case 'l':
					tmp[i] = 'L';
					modifyFlag = 1;
					break;
				case 'O':
					tmp[i] = 'o';
					modifyFlag = 1;
					break;
			}
		}
		if (modifyFlag == 1)
		{
			flag++;
			modify[i] = 1;
		}
		account[i].password = tmp;
	}
	if (flag == 0 && n == 1)
	{
		cout << "There is 1 account and no account is modified";
	}
	else if (flag == 0)
	{
		printf("There are %d accounts and no account is modified", n);
	}
	else
	{
		cout << flag << endl;
		for (int i = 0; i < n; i++)
		{
			if (modify[i] == 1)
			{
				cout << account[i].user << " " << account[i].password << endl;
			}
		}
	}
	return 0;
}