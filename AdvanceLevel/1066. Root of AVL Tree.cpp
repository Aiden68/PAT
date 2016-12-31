#include<iostream>
using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}
struct Node{
	int value;
	struct Node *left, *right;
};

Node* rotateLL(Node *root)
{
	Node *t = root->left;
	root->left = t->right;
	t->right = root;
	return t;
}

Node* rotateRR(Node *root)
{
	Node *t = root->right;
	root->right = t->left;
	t->left = root;
	return t;
}

Node* rotateLR(Node *root)
{
	Node *t = root->left;
	root->left = rotateRR(t);
	return rotateLL(root);
}

Node* rotateRL(Node *root)
{
	Node *t = root->right;
	root->right = rotateLL(t);
	return rotateRR(root);
}

int getHeight(Node *node)
{
	if (node == NULL)
		return 0;
	return max(getHeight(node->left),getHeight(node->right)) + 1;
}
bool isBalance(Node* root)
{
	return abs(getHeight(root->left) - getHeight(root->right)) < 2;
}

Node* insert(Node* root,int val)
{
	if (root == NULL)
	{
		root = new Node();
		root->value = val;
		root->left = root->right = NULL;
	}
	else if (val < root->value)
	{
		root->left = insert(root->left, val);
		if (!isBalance(root))
			root = val > root->left->value ? rotateLR(root) : rotateLL(root);
	}
	else
	{
		root->right = insert(root->right, val);
		if (!isBalance(root))
			root = val > root->right->value ? rotateRR(root) : rotateRL(root);
	}
	return root;
}

void preOrderTraversal(Node* root)
{
	if(root != NULL)
		printf("%d ",root->value);
	if(root->left != NULL)
		preOrderTraversal(root->left);
	if(root->right != NULL)
		preOrderTraversal(root->right);
}
int main()
{
	int n , val;
	Node *root = NULL;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &val);
		root = insert(root,val);
	}
	printf("%d\n", root->value);
	preOrderTraversal(root);
	return 0;
}