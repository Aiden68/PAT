#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int nc, np;
	long long coupon[100000];
	long long product[100000];
	cin >> nc;
	for (int i = 0; i < nc; i++)
	{
		cin >> coupon[i];
	}
	cin >> np;
	for (int i = 0; i < np; i++)
	{
		cin >> product[i];
	}
	sort(coupon, coupon + nc);
	sort(product, product + np);
	int tc = nc;
	int tp = np;
	long long sum = 0;
	nc--;
	np--;
	while (coupon[nc] >= 0 && product[np] >= 0 && nc >= 0 && np >= 0)
	{
		sum += (coupon[nc--] * product[np--]);
	}
	int c = 0;
	int p = 0;
	while (coupon[c] < 0 && product[p] < 0 && c < tc && p < tp)
	{
		sum += (coupon[c++] * product[p++]);
	}
	cout << sum;
	return 0;
}