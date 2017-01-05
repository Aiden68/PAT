#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Book{
	string id;
	string title;
	string name;
	string keyWord;
	string publisher;
	string year;
};

int strToInt(string str)
{
	int tmp = 0;
	for (int i = 0; i < str.size(); i++)
	{
		tmp = (tmp * 10 + str[i] - '0');
	}
	return tmp;
}

vector<string> strSplit(string str)
{
	vector<string> tmp;
	int flag = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			string temp;
			temp = str.substr(flag, i-flag);
			flag = i + 1;
			tmp.push_back(temp);
		}
		if (i == str.size() - 1)
		{
			string temp;
			temp = str.substr(flag, i);
			flag = i + 1;
			tmp.push_back(temp);
		}
	}
	return tmp;
}
int main()
{
	int n,m;
	vector<int> out;
	Book book[10001];
	cin >> n;
	vector<string> *keyword = new vector<string>[n];
	string tmpYear;
	getline(cin, tmpYear);
	for (int i = 0; i < n; i++)
	{
		getline(cin, book[i].id);
		getline(cin, book[i].title);
		getline(cin, book[i].name);
		getline(cin, book[i].keyWord);
		keyword[i] = strSplit(book[i].keyWord);
		getline(cin, book[i].publisher);
		getline(cin, book[i].year);
	}
	string tmpStr,tm;
	getline(cin, tm);
	m = strToInt(tm);
	for (int i = 0; i < m; i++)
	{
		out.clear();
		string tmp;
		getline(cin, tmp);
		int seq = tmp[0] - '0';
		tmp = tmp.erase(0, 3);
		if (tmp.size() == 4&&tmp[0] >= '1'&&tmp[0] <= '3')
		{
			for (int i = 0; i < n; i++)
			{
				if (book[i].year == tmp)
				{
					out.push_back(strToInt(book[i].id));
				}
			}
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (book[i].title == tmp || book[i].name == tmp || book[i].publisher == tmp)
				{
					out.push_back(strToInt(book[i].id));
				}				
			}
		}
		for (int i = 0; i < n; i++)
		{
//			vector<string> temp = strSplit(book[i].keyWord);
			for (int j = 0; j < keyword[i].size(); j++)
			{
				if (tmp == keyword[i][j])
				{
					out.push_back(strToInt(book[i].id));
					break;
				}
			}
		}
		sort(out.begin(), out.end());
		cout << seq << ": " << tmp << endl;
		if (out.size() == 0)
			cout << "Not Found" << endl;
		for (int i = 0; i < out.size(); i++)
		{
			if (i == 0)
				printf("%07d\n", out[i]);
			else if (out[i] != out[i-1])
				printf("%07d\n", out[i]);
		}	
	}
	return 0;
}