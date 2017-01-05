#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int m, n, k;
//	vector<int> stack1[1001];
	vector<int> stack;
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int flag = 0;
		int isflag = 0;
		int cnt = 1;
		stack.clear();
		for (int j = 0; j < n; j++)
		{
			int tmp;
			scanf("%d", &tmp);
			if (isflag == 1)
				continue;
			if (tmp == m)
				flag = 1;
			int top = stack.size() - 1;
			if (stack.size() == 0)
			{
				for (int k = cnt; k < tmp; k++)
					stack.push_back(k);				
			}
			else if (stack[top] == tmp)
			{
				stack.pop_back();
			}
			else if (stack[top] < tmp)
			{
				for (int k = cnt; k < tmp; k++)
					stack.push_back(k);
			}
			else if (stack[top] > tmp)
			{
				printf("NO\n");
				isflag = 1;
			}
			if (stack.size() + 1 > m&&isflag == 0)
			{
				printf("NO\n");
				isflag = 1;
			}
			if (cnt < tmp + 1)
				cnt = tmp + 1;
		}
		if (isflag == 0)
			printf("YES\n");
	}
	return 0;
}