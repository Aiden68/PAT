#include<iostream>
#include<map>
using namespace std;

struct BinTree{
	int data;
	int left;
	int right;
};
int space = 0;
void inOrder(int root,BinTree tree[])
{
	if(tree[root].left != -1)
		inOrder(tree[root].left,tree);
	if(space == 0)
		space++;
	else
		printf(" ");
	printf("%d",tree[root].data);
	if(tree[root].right != -1)
		inOrder(tree[root].right,tree);
}
int main()
{
	int n, root;
	int pre[31];
	int post[31];
	bool flag[31] = { false };
	map<int, int> m, m1;
	BinTree tree[31];
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &pre[i]);
		m[pre[i]] = i;
		tree[i].data = pre[i];
		tree[i].left = tree[i].right = -1;
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &post[i]);
		post[i] = m[post[i]];
		m1[post[i]] = i;
	}
	flag[0] = true;
	for(int i = 0; i < n - 1; i++)
	{
		int pos = m1[i];
		if(pos == 0)
		{
			if(flag[i + 1] == false)
			{
				tree[i].left = i + 1;
				flag[i + 1] = true;
			}
		}
		else if(i + 1 == post[pos - 1]&&flag[i + 1] == false)
		{
			tree[i].right = i + 1;
			flag[i + 1] = true;
		}
		else
		{
			if(flag[post[pos - 1]] == false)
			{
				tree[i].right = post[pos - 1];
				flag[post[pos - 1]] = true;
			}
			if(flag[i + 1] == false)
			{
				tree[i].left = i + 1;
				flag[i + 1] = true;
			}
		}
	}
	bool unique = true;
	for(int i = 0; i < n; i++)
	{
		if(tree[i].left == -1&&tree[i].right != -1)
		{
			printf("No\n");
			unique = false;
			break;
		}
		else if(tree[i].right == -1&&tree[i].left != -1)
		{
			printf("No\n");
			unique = false;
			break;
		}
	}
	if(unique)
		printf("Yes\n");
	inOrder(0,tree);
	printf("\n");
	return 0;
}