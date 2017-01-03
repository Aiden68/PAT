#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	vector<int> v, v1,v2;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	v1 = v;
	sort(v1.begin(), v1.end());
	int cnt = 0;
	int space = 0;
	int max = v[0];
	for (int i = 0; i < n; i++)
	{
		if (v[i] == v1[i])
		{
			if (i == 0 || i == n - 1)
			{
				cnt++;
				v2.push_back(v[i]);
			}
			else if (max < v[i])
			{
				max = v[i];
				cnt++;
				v2.push_back(v[i]);
			}
		}
		if (max < v[i])
			max = v[i];
	}
	printf("%d\n", cnt);
	for (int i = 0; i < v2.size(); i++)
	{
		if (i != 0)
			printf(" ");
		printf("%d", v2[i]);
	}
        printf("\n");
	return 0;
}