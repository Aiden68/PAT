#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n, flag = -1;
	int arr[105] = { 0 };
	int sortarr[105] = { 0 };
	int temparr[105] = { 0 };
	int heap[105] = { 99999999 };
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
		temparr[i] = arr[i];
	}
	for(int i = 0; i < n; i++)
		scanf("%d",&sortarr[i]);
	for(int i = 0; i < n; i++)
	{
		if(sortarr[i] > sortarr[i + 1])
		{
			flag = i + 1;
			break;
		}
	}
	int i = flag;
	for(; i < n; i++)
	{
		if(sortarr[i] != arr[i])
			break;
	}
	if(i == n)
	{
		printf("Insertion Sort\n");
		sort(sortarr,sortarr + flag + 1);
		for(int i = 0; i < n; i++)
		{
			if(i != 0)
				printf(" ");
			printf("%d", sortarr[i]);
		}
	}
	else
	{
		printf("Heap Sort\n");
		sort(temparr, temparr + n);
		int cnt = 0;
		int i = n - 1;
		for(; i >= 0; i--)
		{
			if(sortarr[i] != temparr[i])
				break;
		}
		for(int j = 0; j <= i; j++)
		{
			heap[++cnt] = sortarr[j];
		}
		int te = 1;
		heap[1] = heap[cnt--];
		while(te * 2  < cnt)
		{
			if(heap[te] < heap[te * 2]||heap[te] < heap[te * 2 + 1])
			{
				if(heap[te * 2] > heap[te * 2 + 1])
				{
					int temp = heap[te * 2];
					heap[te * 2] = heap[te];
					heap[te] = temp;
					te *= 2;
				}
				else
				{
					int temp = heap[te * 2 + 1];
					heap[te * 2 + 1] = heap[te];
					heap[te] = temp;
					te = te * 2 + 1;
				}
			}
		}
		if(te * 2 == cnt && heap[te] < heap[te * 2])
		{
			int temp = heap[te * 2];
			heap[te * 2] = heap[te];
			heap[te] = temp;
		}
		int space = 0;
		for(int k = 1; k <= cnt; k++)
		{
			if(space != 0)
				printf(" ");
			else
				space++;
			printf("%d",heap[k]);
		}
		for(int k = i; k < n; k++)
		{
			if(space != 0)
				printf(" ");
			else
				space++;
			printf("%d",temparr[k]);
		}
	}
	return 0;
}