#include<iostream>
#include<vector>
using namespace std;

class treeNode{
public:
	int data ;
	int left ;
	int right ;
	treeNode()
	{
		data = -999999;
		left = -1;
		right = -1;
	}
};

treeNode tree[1001];
treeNode treeMirror[1001];

void insert(int v,int root)
{
	int tmp = tree[v].data;
	if(tmp < tree[root].data)
	{
		if(tree[root].left == -1)
			tree[root].left = v;
		else
			insert(v,tree[root].left);
	}
	else
	{
		if(tree[root].right == -1)
			tree[root].right = v;
		else
			insert(v,tree[root].right);
	}
}

void insertMirror(int v,int root)
{
	int tmp = treeMirror[v].data;
	if(tmp >= treeMirror[root].data)
	{
		if(treeMirror[root].left == -1)
			treeMirror[root].left = v;
		else
			insertMirror(v,treeMirror[root].left);
	}
	else
	{
		if(treeMirror[root].right == -1)
			treeMirror[root].right = v;
		else
			insertMirror(v,treeMirror[root].right);
	}
}

void preOrder(treeNode *tree,int root,vector<int> &v)
{
	if(tree[root].data != -999999)
		v.push_back(tree[root].data);
	if(tree[root].left != -1)
		preOrder(tree,tree[root].left,v);
	if(tree[root].right != -1)
		preOrder(tree,tree[root].right,v);
}

int space = 0;
void postOrder(treeNode *tree,int root)
{
	if(tree[root].left != -1)
		postOrder(tree,tree[root].left);
	if(tree[root].right != -1)
		postOrder(tree,tree[root].right);
	if(tree[root].data != -999999)
	{
		if(space == 0)
			space++;
		else
			cout << " ";
		cout << tree[root].data;
	}
}
int main()
{
	int n;
	vector<int> v1,v2,v3;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		v1.push_back(tmp);
		tree[i].data = tmp;
		treeMirror[i].data = tmp;
		if(i != 0)
		{
			insert(i,0);
			insertMirror(i,0);
		}
	}
	preOrder(tree,0,v2);
	preOrder(treeMirror,0,v3);
	if(v1 != v2&&v1 != v3)
		cout<< "NO";
	else if(v1 == v2)
	{
		cout<< "YES" << endl;
		postOrder(tree,0);
	}
	else if(v1 == v3)
	{
		cout<< "YES" << endl;
		postOrder(treeMirror,0);
	}
	return 0;
}