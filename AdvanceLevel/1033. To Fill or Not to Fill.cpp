#include<iostream>
#include<algorithm>
using namespace std;

struct Station{
	double price;
	double dis;
};

bool compare(Station a, Station b)
{
	return a.dis < b.dis;
}

int main()
{
	double c, D, d;
	int n;
	cin >> c >> D >> d >> n;
	Station stop[501];
	for (int i = 0; i < n; i++)
	{
		cin >> stop[i].price >> stop[i].dis;
	}
	sort(stop, stop + n, compare);
	if (stop[0].dis > 0.0000001)
	{
		cout << "The maximum travel distance = ";
		printf("%.2lf", 0.00);
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		if (i == n - 1)
		{
			if (c * d + stop[i].dis < D )
			{
				cout << "The maximum travel distance = ";
				printf("%.2lf", (c * d + stop[i].dis) * 1.0);
				return 0;
			}
			break;
		}
		if (c * d + stop[i].dis < stop[i + 1].dis)
		{
			cout <<"The maximum travel distance = ";
			printf("%.2lf", (c * d + stop[i].dis) * 1.0);
			return 0;
		}
	}
	double sum = 0;
	int i = 0;
	int reachDis = 0;
	while(i < n)
	{
		int cnt = i + 1;
		int min = cnt;
		int flag = 0;
		if (min == n)
		{
			sum += (D - reachDis) * stop[i].price;
			break;
		}
		while (stop[i].dis + c * d >= stop[cnt].dis&&cnt < n)
		{
			if (stop[cnt].price < stop[i].price)
			{
				min = cnt;
				sum += (stop[min].dis - reachDis) * stop[i].price;
				reachDis = stop[min].dis;
				flag = 1;
				i = min;
				break;
			}
			if (stop[cnt].price < stop[min].price)
			{
				min = cnt;
			}
			cnt++;
		}
		if (flag == 1)
			continue;
		else if (stop[i].dis + c * d > D)
		{
			sum += (D - reachDis) * stop[i].price;
			break;
		}
		sum += (c * d + stop[i].dis - reachDis) * stop[i].price;
		reachDis = stop[i].dis + c * d;
		i = min;
	}
	printf("%.2lf", sum / d);
	return 0;
}