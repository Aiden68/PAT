#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct signRecord
{
	string account;
	int hourIn;
	int minuteIn;
	int secondIn;
	int hourOut;
	int minuteOut;
	int secondOut;
};

void strToTime(string time, signRecord &s, int flag)
{
	if (flag == 0)
	{
		s.hourIn = (time[0] - '0') * 10 + (time[1] - '0');
		s.minuteIn = (time[3] - '0') * 10 + (time[4] - '0');
		s.secondIn = (time[6] - '0') * 10 + (time[7] - '0');
	}
	else
	{
		s.hourOut = (time[0] - '0') * 10 + (time[1] - '0');
		s.minuteOut = (time[3] - '0') * 10 + (time[4] - '0');
		s.secondOut = (time[6] - '0') * 10 + (time[7] - '0');
	}
}

void stringToTime(signRecord &s, string in, string out)
{
	strToTime(in, s, 0);
	strToTime(out, s, 1);
}

bool compareIn(signRecord a, signRecord b)
{
	if (a.hourIn != b.hourIn)
		return a.hourIn < b.hourIn;
	else if (a.minuteIn != b.minuteIn)
		return a.minuteIn < b.minuteIn;
	else
		return a.secondIn < b.secondIn;
}

bool compareOut(signRecord a, signRecord b)
{
	if (a.hourOut != b.hourOut)
		return a.hourOut < b.hourOut;
	else if (a.minuteOut != b.minuteOut)
		return a.minuteOut < b.minuteOut;
	else
		return a.secondOut < b.secondOut;
}
int main()
{
	int n;
	cin >> n;
	signRecord *sr = new signRecord[n];
	for (int i = 0; i < n; i++)
	{
		string in, out;
		cin >> sr[i].account >> in >> out;
		stringToTime(sr[i], in, out);
	}
	sort(sr, sr + n, compareIn);
	cout << sr[0].account << " ";
	sort(sr, sr + n, compareOut);
	cout << sr[n - 1].account;
	return 0;
}