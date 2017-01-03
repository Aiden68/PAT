#include<iostream>
using namespace std;

struct BinTree{
	int data;
	BinTree *left, *right;
};

BinTree* insert(BinTree *root,BinTree *t)
{
	if(!root)
	{
		root = new BinTree();
		root = t;
	}
	else if(t->data <= root->data)
		root->left = insert(root->left,t);
	else
		root->right = insert(root->right,t);
	return root;
}

int maxdeep = 0;
int cnt[1005];
int visit[1005];
void dfs(BinTree *root,int deep)
{
	cnt[deep]++;
	if(maxdeep < deep)
		maxdeep = deep;
	if(root->left != NULL)
		dfs(root->left,deep + 1);
	if(root->right	 != NULL)
		dfs(root->right,deep + 1);
}
int main()
{
	int n;
	scanf("%d",&n);
	BinTree *root = NULL;
	for(int i = 0; i < n; i++)
	{
		BinTree *t = new BinTree();
		t->data = 0;
		t->left = NULL;
		t->right = NULL;
		scanf("%d",&t->data);
		root = insert(root,t);
	}
	dfs(root,0);
	printf("%d + %d = %d",cnt[maxdeep],cnt[maxdeep - 1],cnt[maxdeep]+cnt[maxdeep - 1]);
	return 0;
}