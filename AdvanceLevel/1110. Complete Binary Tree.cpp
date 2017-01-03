#include<iostream>
#include<vector>
using namespace std;

struct Tree{
	int left;
	int right;
}tree[21];;

vector<int> v[21];
int cnt[21];
int maxdeep = 0;
void dfs(int root,int deep)
{
	if(deep > maxdeep)
		maxdeep = deep;
	cnt[deep]++;
	v[deep].push_back(root);
	if(tree[root].left != -1)
		dfs(tree[root].left, deep + 1);
	if(tree[root].right != -1)
		dfs(tree[root].right, deep + 1);
}
int main()
{
	int n, root, temp;;
	int findroot[21] = { 0 };
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		char l[3],r[3];
		getchar();
		scanf("%s %s",l, r);
		if(l[0] == '-')
			tree[i].left = -1;
		else
		{
			sscanf(l,"%d",&temp);
			tree[i].left = temp;
			findroot[temp] = 1;
		}
		if(r[0] == '-')
			tree[i].right = -1;
		else
		{
			sscanf(r,"%d",&temp);
			tree[i].right = temp;
			findroot[temp] = 1;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(findroot[i] == 0)
		{
			root = i;
			break;
		}
	}
	dfs(root,0);
	temp = 1;
	if(maxdeep == 0)
	{
		printf("YES 0");
		return 0;
	}
	for(int i = 0; i < maxdeep; i++)
	{	
		if(i != 0)
			temp *= 2;
		if(cnt[i] != temp)
		{
			printf("NO %d",root);
			return 0;
		}
	}
	temp = 0;
	for(int i = 0;i < v[maxdeep - 1].size(); i++)
	{
		if(tree[v[maxdeep - 1][i]].left == -1)
			break;
		else if(tree[v[maxdeep - 1][i]].right == -1)
		{
			temp++;
			break;
		}
		temp += 2;
	}
	if(temp == cnt[maxdeep])
		printf("YES %d",v[maxdeep][v[maxdeep].size() - 1]);
	else
		printf("NO %d",root);
	return 0;
}