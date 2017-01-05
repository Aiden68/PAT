#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	long long int n1, n2;
	vector<long long int> num;
	scanf("%lld", &n1);
	for (int i = 0; i < n1; i++)
	{
		long long int tmp;
		scanf("%lld", &tmp);
		num.push_back(tmp);
	}
	scanf("%lld", &n2);
	for (int i = 0; i < n2; i++)
	{
		long long int tmp;
		scanf("%lld", &tmp);
		num.push_back(tmp);
	}
	sort(num.begin(), num.end());
	printf("%lld", num[(num.size() - 1) / 2]);
	return 0;
}