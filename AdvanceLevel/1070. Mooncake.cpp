#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct mooncake{
	double storage;
	double price;
};

bool com(mooncake a, mooncake b){ return a.price > b.price; }
int main()
{
	int n, d;
	vector<mooncake> mc;
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++)
	{
		double amount;
		scanf("%lf", &amount);
		mooncake m;
		m.storage = amount;
		m.price = 0;
		mc.push_back(m);
	}
	for (int i = 0; i < n; i++)
	{
		double price;
		scanf("%lf", &price);
		mc[i].price = price/mc[i].storage;
	}
	sort(mc.begin(), mc.end(), com);
	double profit = 0;
	for (int i = 0; i < n; i++)
	{
		if (d - mc[i].storage > 0)
		{
			profit += mc[i].price * mc[i].storage;
			d -= mc[i].storage;
		}
		else
		{
			profit += mc[i].price * d;
			break;
		}
	}
	printf("%.2lf", profit);
	return 0;
}