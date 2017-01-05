#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	int max = 1;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++)
	{
		int l = i - 1;
		int r = i + 1;
		int tmax = 1;
		while (l > -1 && r < str.size()&&str[l] == str[r])
		{
			tmax += 2;
			l--;
			r++;
		}
		if (tmax > max)
			max = tmax;
		if (i + 1 < str.size() && str[i] == str[i + 1])
		{
			int tmax = 2;
			int l = i - 1;
			int r = i + 2;
			while (l > -1 && r < str.size() && str[l] == str[r])
			{
				tmax += 2;
				l--;
				r++;
			}
			if (tmax > max)
				max = tmax;
		}
	}
	cout << max;
	return 0;
}