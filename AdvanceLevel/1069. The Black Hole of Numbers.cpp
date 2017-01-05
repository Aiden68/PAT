#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	string str;
	char c[4];
	vector<char> v;
	cin >> str;
	if (str.size() == 1)
		str = "000" + str;
	else if (str.size() == 2)
		str = "00" + str;
	else if (str.size() == 3)
		str = "0" + str;
	string re = "    ";
	string rstr = "";
	while (re != "6174" && re != "0000")
	{
		v.clear();
		for (int i = 0; i < str.size(); i++)
			v.push_back(str[i]);
		sort(v.begin(), v.end());
		for (int i = 0; i < str.size(); i++)
			str[i] = v[i];
		int flag = 0;
		for (int i = 3; i >= 0; i--)
		{
			printf("%c", str[i]);
			rstr += str[i];
			int tmp = str[3 - i] - str[i] - flag;
			if (tmp < 0)
			{
				tmp += 10;
				flag = 1;
			}
			else
				flag = 0;
			re[i] = tmp + '0';
		}
		printf(" - %s = %s\n", str.c_str(),re.c_str());
		str = re;
	}
	return 0;
}