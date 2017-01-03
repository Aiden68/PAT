#include<iostream>
#include<string>
#include<set>
#include<map>
using namespace std;

bool isAN(char c)
{
	if (c >= '0'&&c <= '9' || c >= 'a' &&c <= 'z' || c >= 'A' &&c <= 'Z')
		return true;
	else
		return false;
}
int main()
{
	string input,str;
	set<string> s;
	map<string, int> m;
	int size = 0;
	getline(cin, input);
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= 'A'&&input[i] <= 'Z')
			input[i] += 32;
	}
	for (int i = 0; i < input.size(); i++)
	{
		if (isAN(input[i]))
		{
			str += input[i];
		}
		else if (str != "")
		{
			map<string, int> ::iterator it;
			it = m.find(str);
			if (it != m.end())
				m[str]++;
			else
				m.insert(pair<string, int>(str, 1));
			str = "";
		}
		if (i == input.size() - 1 && str != "")
		{
			map<string, int> ::iterator it;
			it = m.find(str);
			if (it != m.end())
				m[str]++;
			else
				m.insert(pair<string, int>(str, 1));
			str = "";
		}
	}
	int max;
	string output;
	for (map<string, int> ::iterator it = m.begin(); it != m.end(); it++)
	{
		if (it == m.begin())
		{
			output = it->first;
			max = it->second;
		}
		else if (it->second > max)
		{
			output = it->first;
			max = it->second;
		}
	}
	cout << output << " " << max;
	return 0;
}