#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n, m;
	vector<int> input;;
	int coin[1005] = { 0 };
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		input.push_back(tmp);
		coin[tmp]++;
	}
	sort(input.begin(), input.end());
	int flag = 0;
	for (int i = 0; i < input.size(); i++)
	{
		if (coin[input[i]]>0)
		{
			int tmp = m - input[i];
			if (tmp == input[i])
			{
				if (coin[tmp] > 1)
				{
					printf("%d %d", input[i], tmp);
					flag = 1;
					break;
				}
			}
			else
			{
				if (coin[tmp] > 0)
				{
					if (input[i] <= tmp)
						printf("%d %d", input[i], tmp);
					else
						printf("%d %d", tmp, input[i]);
					flag = 1;
					break;
				}
			}
		}
	}
	if (flag == 0)
	{
		cout << "No Solution";
	}
	return 0;
}