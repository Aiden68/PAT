#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct treeNode{
	int value = -1;
	int left = -1;
	int right = -1;
}tree[101];
int findRoot[101] = { 0 };
int root = -1;
int arr[101] = { 0 };
int cnt = 0;
int space = 0;
queue<int> q;

void inOrder(int r)
{
	if (tree[r].left != -1)
		inOrder(tree[r].left);
	tree[r].value = arr[cnt++];
	if (tree[r].right != -1)
		inOrder(tree[r].right);
}

void levelTrivasal()
{
	q.push(root);
	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		if (space == 0)
			space++;
		else
			printf(" ");
		printf("%d", tree[tmp].value);
		if (tree[tmp].left != -1)
			q.push(tree[tmp].left);
		if (tree[tmp].right != -1)
			q.push(tree[tmp].right);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &tree[i].left, &tree[i].right);
		if (tree[i].left != -1)
			findRoot[tree[i].left] = 1;
		if (tree[i].right != -1)
			findRoot[tree[i].right] = 1;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		if (findRoot[i] == 0)
		{
			root = i;
			break;
		}
	}
	inOrder(root);
	levelTrivasal();
	return 0;
}