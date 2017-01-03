#include<iostream>
#include<queue>
using namespace std;

struct treeNode{
	int left = -1;
	int right = -1;
};

treeNode tree[10];
int space1 = 0;
void inOrder(int root)
{
	if (tree[root].left != -1)
		inOrder(tree[root].left);
	if (space1 == 0)
		space1++;
	else
		printf(" ");
	printf("%d", root);
	if (tree[root].right != -1)
		inOrder(tree[root].right);
}

int main()
{
	int n;
	int root = -1;
	int findroot[10] = { 0 };
	queue<int> q;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		getchar();
		char l, r;
		scanf("%c %c", &l, &r);
		if (l != '-')
		{
			tree[i].left = l - '0';
			findroot[l - '0'] = 1;
		}
		if (r != '-')
		{
			tree[i].right = r - '0';
			findroot[r - '0'] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (findroot[i] == 0)
		{
			root = i;
			break;
		}
	}
	q.push(root);
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		int tmp = tree[v].left;
		tree[v].left = tree[v].right;
		tree[v].right = tmp;
		if (tree[v].left != -1)
			q.push(tree[v].left);
		if (tree[v].right != -1)
			q.push(tree[v].right);
	}
	q.push(root);
	int space = 0;
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		if (space == 0)
			space++;
		else
			printf(" ");
		printf("%d", v);
		if (tree[v].left != -1)
			q.push(tree[v].left);
		if (tree[v].right != -1)
			q.push(tree[v].right);
	}
	printf("\n");
	inOrder(root);
	return 0;
}