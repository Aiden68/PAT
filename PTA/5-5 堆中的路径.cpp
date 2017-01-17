#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

int insertHeap(int heap[], int val, int size)
{
	heap[++size] = val;
	int cnt = size;
	while (cnt > 1)
	{
		if (heap[cnt] < heap[cnt / 2])
		{
			swap(heap[cnt], heap[cnt / 2]);
		}
		cnt /= 2;
	}
	return size;
}

int popHeap(int heap[],int& size)
{
	int val = heap[1];
	heap[1] = heap[size];
	size--;
	int i = 1;
	int j = i * 2;
	while (j <= size)
	{
		if (j + 1 <= size && heap[j] > heap[j + 1])
			j = j + 1;
		if (heap[i] > heap[j])
		{
			swap(heap[i], heap[j]);
			i = j;
			j *= 2;
		}
		else
			break;
	}
	return val;
}

int main()
{
//	cout << INT_MAX;
	int n, m;
	int size = 0;
	int heap[1010] = { 0 };
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		int temp;
		scanf("%d", &temp);
		size = insertHeap(heap, temp, size);
	}
	for (int i = 0; i < m; i++)
	{
		int temp;
		scanf("%d", &temp);
		int space = 0;
		while (temp > 0)
		{
			if (space == 0)
				space++;
			else
				printf(" ");
			printf("%d", heap[temp]);
			temp /= 2;
		}
		printf("\n");
	}
	//附加从堆中弹出元素，应用（PAT1098）
	while (size != 0)
	{
		printf("%d ", popHeap(heap, size));
	}
	return 0;
}