#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	int arr[101];
	int sortarr[101];
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&sortarr[i]);
	}
	int flag = 0;
	for(int i = 0; i < n - 1; i++)
	{
		if(sortarr[i] > sortarr[i + 1])
		{
			flag = i + 1;
			break;
		}
	}
	int result = 0;
	for(int i = flag; i < n; i++)
	{
		if(sortarr[i] !=arr[i])
		{
			result = 1;
			break;
		}
	}
	if(result == 0)
	{
		sort(sortarr,sortarr + flag + 1);
		printf("Insertion Sort\n");
	}
	else
	{
		printf("Merge Sort\n");
		int size = -1;
		int pre = -1;
		for(int i = 0; i < n - 1; i++)
		{
			if(sortarr[i] > sortarr[i + 1])
			{
				if(size == -1)
				{
					size = i - pre;
					pre = i;
				}
				else if(size > i - pre)
				{
					size = i - pre;
					pre = i;
				}
			}
		}
		int temp = 0;
		size *= 2;
		while(temp + size < n)
		{
			sort(sortarr + temp, sortarr + temp + size);
			temp += size;
		}
		sort(sortarr + temp, sortarr + n);
	}
	for(int i = 0; i < n; i++)
	{
		if(i != 0)
			printf(" ");
		printf("%d",sortarr[i]);
	}
	return 0;
}