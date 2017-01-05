#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
	int address;
	int key;
};

bool com(node a, node b)
{
	return a.key < b.key;
}

int main()
{
	int n , head;
	node link[100001];
	vector<node> solve;
	scanf("%d %d", &n, &head);
	for (int i = 0; i < n; i++)
	{
		int ta, tk,tn;
		scanf("%d%d%d", &ta, &tk, &tn);
		link[ta].key = tk;
		link[ta].address = tn;
	}
	int tmp = head;
	while (tmp != -1)
	{
		node tnode;
		tnode.address = tmp;
		tnode.key = link[tmp].key;
		solve.push_back(tnode);
		tmp = link[tmp].address;
	}
	sort(solve.begin(), solve.end(), com);
	if (solve.size()==0)
		printf("0 -1\n");
	else
		printf("%d %05d\n", solve.size(), solve[0].address);
	for (int i = 0; i < solve.size(); i++)
	{
		if (i != solve.size() - 1)
		{
			printf("%05d %d %05d\n", solve[i].address, solve[i].key, solve[i + 1].address);
		}
		else
			printf("%05d %d -1\n", solve[i].address, solve[i].key);
	}
	return 0;
}