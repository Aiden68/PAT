#include<iostream>
#include<vector>
using namespace std;

bool flag[20002];
struct Node{
	int addr;
	int next;
	int key;
};
vector<Node> v1,v2;

int main()
{
	int head, n;
	Node node[100005];
	int flag[20002] = { 0 };
	vector<Node> v1, v2;
	scanf("%d%d", &head, &n);
	for (int i = 0; i < n; i++)
	{
		int addr;
		scanf("%d", &addr);
		scanf("%d%d", &node[addr].key, &node[addr].next);
		node[addr].addr = addr;
	}
	int tmp = head;
	while (tmp != -1)
	{
		int tkey = abs(node[tmp].key);
		if (flag[tkey] == 0)
		{
			flag[tkey] = 1;
			v1.push_back(node[tmp]);
		}
		else
		{
			v2.push_back(node[tmp]);
		}
		tmp = node[tmp].next;
	}
	for (int i = 0; i < v1.size(); i++)
	{
		if (i != v1.size() - 1)
			printf("%05d %d %05d\n", v1[i].addr, v1[i].key, v1[i+1].addr);
		else
			printf("%05d %d -1\n", v1[i].addr, v1[i].key);
	}
	for (int i = 0; i < v2.size(); i++)
	{
		if (i != v2.size() - 1)
			printf("%05d %d %05d\n", v2[i].addr, v2[i].key, v2[i+1].addr);
		else
			printf("%05d %d -1\n", v2[i].addr, v2[i].key);
	}
	return 0;
}