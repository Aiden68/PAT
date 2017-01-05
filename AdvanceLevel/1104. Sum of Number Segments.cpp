#include<iostream>
#include<string>
using namespace std;

int main()
{
	int n;
	double sum(0);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		double tmp;
		scanf("%lf", &tmp);
		sum += (tmp * (n - i) * (i + 1));
	}
	printf("%.2lf", sum);
	return 0;
}