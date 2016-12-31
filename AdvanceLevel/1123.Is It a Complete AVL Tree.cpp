/*
**AVL树与levelTraversal
*/
#include<iostream>
#include<queue>
using namespace std;

int n;
int cnt = 0;
bool flag = true;

struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	TreeNode(int value)
	{
		val = value;
		left = NULL;
		right = NULL;
	}
};

TreeNode* rotateLL(TreeNode* root)
{
	TreeNode* temp = root->left;
	root->left = temp->right;
	temp->right = root;
	return temp;
}

TreeNode* rotateRR(TreeNode* root)
{
	TreeNode* temp = root->right;
	root->right = temp->left;
	temp->left = root;
	return temp;
}

TreeNode* rotateLR(TreeNode* root)
{
	root->left = rotateRR(root->left);
	return rotateLL(root);
}

TreeNode* rotateRL(TreeNode* root)
{
	root->right = rotateLL(root->right);
	return rotateRR(root);
}
int getHeight(TreeNode* root)
{
	if(root == NULL)
		return 0;
	return max(getHeight(root->left), getHeight(root->right)) + 1;
}

bool isBalance(TreeNode* root)
{
	return abs(getHeight(root->left) - getHeight(root->right)) < 2;
}

TreeNode* insert(TreeNode* root, int val)
{
	if(root == NULL)
	{
		root = new TreeNode(val);
	}
	else if(val < root->val)
	{
		root->left = insert(root->left, val);
		if(!isBalance(root))
		{
			return val < root->left->val ? rotateLL(root) : rotateLR(root); 
		}
	}
	else
	{
		root->right = insert(root->right, val);
		if(!isBalance(root))
		{
			return val < root->right->val ? rotateRL(root) : rotateRR(root); 
		}
	}
	return root;
}

void levelTraversal(TreeNode* root)
{
	int space = 0;
	queue<TreeNode*> q;
	q.push(root);
	cnt++;
	while(!q.empty())
	{
		TreeNode* temp = q.front();
		q.pop();
		if(space == 0)
			space++;
		else
			printf(" ");
		printf("%d", temp->val);
		if(temp->left != NULL)
		{
			q.push(temp->left);
			cnt++;
		}
		else if(cnt != n)
		{
			flag = false;
		}
		if(temp->right != NULL)
		{
			q.push(temp->right);
			cnt++;
		}
		else if(cnt != n)
		{
			flag = false;
		}
	}
}

int main()
{

	TreeNode* root = NULL;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int val;
		scanf("%d", &val);
		root = insert(root, val);
	}
	levelTraversal(root);
	if(flag)
		printf("\nYES");
	else
		printf("\nNO");
	return 0;
}