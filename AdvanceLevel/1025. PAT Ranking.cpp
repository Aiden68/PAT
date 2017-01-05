#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

struct Testee{
	string id;
	int score;
	int location;
};

bool compare(Testee a, Testee b)
{
	if (a.score != b.score)
		return a.score > b.score;
	else
		return a.id < b.id;
}
int main()
{
	int n;
	cin >> n;
	int k;
	int locationRank[101] = { 0 };
	int tmpRank[101] = { 0 };
	vector<Testee> testee;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			Testee tmp;
			cin >> tmp.id >> tmp.score;
			tmp.location = i + 1;
			testee.push_back(tmp);
		}
	}
	sort(testee.begin(), testee.end(), compare);
	cout << testee.size() << endl;
	int tmp = -1;
	for (int i = 0; i < testee.size(); i++)
	{
		int l = testee[i].location;
		cout << testee[i].id << " ";
		if (i == 0 )
		{
			tmp = i + 1;
			cout << tmp;
		}
		else if (testee[i].score != testee[i - 1].score)
		{
			tmp = i + 1;
			cout << tmp;
		}
		else
			cout << tmp;
		cout << " " << l << " ";
		int ti = i;
		int flag = 0;
		++locationRank[l];
		if (locationRank[l] == 0)
		{
			cout << locationRank[l] << endl;
			tmpRank[l] = locationRank[l];
		}
		else
		{
			while (ti > 0 && testee[i].score == testee[--ti].score)
			{
				if (l == testee[ti].location)
				{
					cout << tmpRank[l] << endl;
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				cout << locationRank[testee[i].location] << endl;
				tmpRank[l] = locationRank[l];
			}
			else
				flag = 0;
		}	
	}
	return 0;
}
