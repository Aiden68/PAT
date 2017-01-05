#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	vector<int> v;
	int sum(0);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
		sum += tmp;
	}
	sort(v.begin(), v.end());
	int tsum(0);
	for (int i = 0; i < v.size()/2; i++)
	{
		tsum += v[i];
	}
	if (v.size() % 2 == 0)
		printf("0 ");
	else
		printf("1 ");
	printf("%d", sum - 2 * tsum);
	return 0;
}