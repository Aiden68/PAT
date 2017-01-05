#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s1, s2;
	int flag[300] = { 0 };
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s2.size(); i++)
	{
		int tmp = (int)s2[i];
		flag[tmp] = 1;
	}
	for (int i = 0; i < s1.size(); i++)
	{
		int tmp = (int)s1[i];
		if (flag[tmp] == 0)
			cout << s1[i];
	}
	return 0;
}