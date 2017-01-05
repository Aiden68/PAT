#include<iostream>
#include<string>
#include<deque>
using namespace std;

int stringToInt(string a)
{
	int tmp = 0;
	for (int i = 0; i < a.size(); i++)
	{
		tmp = tmp * 10 + a[i] - '0';
	}
	return tmp;
}

int main()
{
	int n, m;
	int count = 0;
	int space = 0;
	int treemap[101][101] = { {0} };
	deque<int> q;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int k;
		string a;
		cin >> a >> k;
		for (int i = 0; i < k; i++)
		{
			int ti = stringToInt(a);
			int tj;
			string tmp;
			cin >> tmp;
			tj = stringToInt(tmp);
			treemap[ti][tj] = 1;
		}
	}
	int end = 1;
	int layer = 1;
	if (n == 1)
		cout << 1;
	else
	{
		q.push_back(1);
		int tend = 0;
		while (!q.empty())
		{
			int tmp = q.front();
			q.pop_front();
			int flag = 0;
			for (int i = tmp + 1; i <= n; i++)
			{
				if (treemap[tmp][i] == 1)
				{
					q.push_back(i);
					flag = 1;
					tend = i;
				}
			}
			if (flag == 0)
			{
				count++;
			}
			if (tmp == end)
			{
				if (space == 0)
					space++;
				else
					cout << " ";
				cout << count;
				end = tend;
				count = 0;
			}
		}
	}
	return 0;
}
