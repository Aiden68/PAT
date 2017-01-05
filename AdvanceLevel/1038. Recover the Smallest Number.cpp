#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(string a, string b)
{
	string tmp = a;
	a += b;
	b += tmp;
	return a < b;
}

int main()
{
	vector<string> strNum;
	string tmp;
	int tn , n;
	string min;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		strNum.push_back(tmp);
	}
	sort(strNum.begin(), strNum.end(),compare);
	for (int i = 0; i < strNum.size(); i++)
	{
		min += strNum[i];
	}
	while (min[0] == '0')
		min.erase(0, 1);
	for (int i = 0; i < min.size(); i++)
	{
		cout << min[i];
	}
	if (min.size() == 0)
		cout << 0;
	return 0;
}