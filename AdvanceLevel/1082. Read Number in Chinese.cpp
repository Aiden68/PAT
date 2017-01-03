#include<iostream>
#include<string>
#include<vector>
using namespace std;

string numStr[10] = { "","yi","er", "san", "si", "wu" , "liu", "qi" ,"ba" , "jiu" };
string s[4] = {"","Shi","Bai","Qian"};
int main()
{
	string str;
	vector<string> v;
	cin >> str;
	if (str[0] == '-')
	{
		v.push_back("Fu");
		str.erase(0, 1);
	}
	if (str == "0" || str == "-0")
	{
		printf("ling");
		return 0;
	}
	int flag = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i]!= '0')
		{
			if (i != 0 && (str.size() - i - 1) % 4 != 3 && str[i - 1] == '0')
				v.push_back("ling");
			v.push_back(numStr[str[i] - '0']);
			if (str.size() - i <= 8 && str.size() - i >= 5)
				flag = 1;
			if ((str.size() - i - 1) % 4 != 0)
			{
				v.push_back(s[(str.size() - i - 1) % 4]);
			}
		}
		if (str.size() - i == 9)
		{
			v.push_back("Yi");
			/*if (str[i + 1] == '0')
				v.push_back("ling");*/
		}
		if (str.size() - i == 5&&flag == 1)
		{
			v.push_back("Wan");
			/*if (str[i + 1] == '0')
				v.push_back("ling");*/
		}
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (i != 0)
			printf(" ");
		printf("%s", v[i].c_str());
	}
	return 0;
}