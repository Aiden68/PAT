#include<iostream>
using namespace std;

int treeArray[100001] = { 0 };
int n = 100001;

void add(int pos, int value)
{
	int k = pos;
	while (k < n)
	{
		treeArray[k] += value;
		k += k&-k;
	}
}

int getSum(int pos)
{
	int sum(0);
	int k = pos;
	while (k > 0)
	{
		sum += treeArray[k];
		k -= k&-k;
	}
	return sum;
}

int search(int value)
{
	int l = 0;
	int r = n;
	while (l < r - 1)
	{
		int mid, res;
		if ((l + r) % 2 == 0)
			mid = (l + r) / 2;
		else
			mid = (l + r + 1) / 2;
		res = getSum(mid);
		if (res < value)
			l = mid;
		else
			r = mid;
	}
	return l + 1;
}
int main()
{
	int num;
	int stack[100001] = { 0 };
	int top = 0;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		char tmp[20];
		scanf("%s", tmp);
		if (tmp[1] == 'o')
		{
			if (top == 0)
				printf("Invalid\n");
			else
			{
				printf("%d\n", stack[--top]);
				add(stack[top], -1);
			}				
		}
		else if (tmp[1] == 'u')
		{
			scanf("%d", &stack[top++]);
			add(stack[top - 1], 1);
		}
		else if (tmp[1] == 'e')
		{
			if (top == 0)
				printf("Invalid\n");
			else if (top % 2 == 0)
				printf("%d\n", search(top / 2));
			else
				printf("%d\n", search((top + 1) / 2));
		}
	}
	return 0;
}