#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Car{
	string plate;
	int time;
	string status;
};

struct record{
	string plate;
	int in;
	int out;
};
bool com(Car a, Car b)
{
	if (a.plate != b.plate)
		return a.plate < b.plate;
	else if (a.time != b.time)
		return a.time < b.time;
}
bool com1(record a, record b)
{
	return a.in < b.in;
}
int timeToInt(string time)
{
	int h = (time[0] - '0') * 10 + (time[1] - '0');
	int m = (time[3] - '0') * 10 + (time[4] - '0');
	int s = (time[6] - '0') * 10 + (time[7] - '0');
	return h * 3600 + m * 60 + s;
}
int result[80001] = { 0 };
int main()
{
	int n, k;
	vector<Car> car;
	vector<record> r;
	int query[80005] = { 0 };
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		char tp[10], t[10], s[5];
		Car tmp;
		scanf("%s%s%s", tp, t, s);
		tmp.plate = tp;
		tmp.time = timeToInt(t);
		tmp.status = s;
		car.push_back(tmp);
	}
	for (int i = 0; i < k; i++)
	{
		char time[10];
		scanf("%s", time);
		query[i] = timeToInt(time);
	}
	sort(car.begin(), car.end(), com);
	int maxtime = 0;
	vector<string> plate;
	int size = 0;
	int tm = 0;
	for (int i = 0; i < car.size(); i++)
	{
		if (i == car.size() - 1)
			break;
		if (car[i].plate == car[i + 1].plate && car[i].status == "in"&&car[i + 1].status == "out")
		{
			record re;
			re.plate = car[i].plate;
			re.in = car[i].time;
			re.out = car[i + 1].time;
			if (size != 0 && re.plate == r[size - 1].plate)
				tm += (re.out - re.in);
			else
				tm = re.out - re.in;
			if (maxtime < tm)
			{
				plate.clear();
				plate.push_back(re.plate);
				maxtime = tm;
			}
			else if (maxtime == tm)
				plate.push_back(re.plate);
			r.push_back(re);
			size++;
			i++;
		}
	}
	sort(r.begin(), r.end(), com1);
	int i = 0, j = 0;
	int flag = 0;
	while (i < k&&j < r.size())
	{
		if (r[j].in <= query[i])
		{
			int ti = i;
			while (ti < k&&r[j].out > query[ti])
			{
				result[ti]++;
				ti++;
			}
			j++;
		}
		else
			i++;
	}
	for (int i = 0; i < k; i++)
		printf("%d\n", result[i]);
	for (int i = 0; i < plate.size(); i++)
		printf("%s ", plate[i].c_str());
	printf("%02d:%02d:%02d", maxtime / 3600, maxtime % 3600 / 60, maxtime % 60);
	return 0;
}