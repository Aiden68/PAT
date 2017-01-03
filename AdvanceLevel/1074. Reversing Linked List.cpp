#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

struct Node{
	int value;
	int next;
};
int main()
{
	int head, n, k;
	Node list[100000] = { 0 };
	int rlist[100000] = { 0 };
	map<int, int> m;
	scanf("%d%d%d",&head,&n,&k);
	for(int i = 0; i < n; i++)
	{
		int address;
		scanf("%d",&address);
		scanf("%d%d",&list[address].value, &list[address].next);
		m.insert(pair<int,int>(list[address].value,address));
	}
	int cnt = 0;
	while(head != -1)
	{
		rlist[cnt++] = list[head].value;
		head = list[head].next;
	}
	int temp = 0;
	while(temp + k <= cnt)
	{
		reverse(rlist + temp,rlist + temp + k);
		temp += k;
	}
	for(int i = 0; i < cnt; i++)
	{
		if(i != 0)
			printf("%05d\n%05d",m[rlist[i]],m[rlist[i]]);
		else
			printf("%05d",m[rlist[i]]);
		printf(" %d ",rlist[i]);
		if(i == cnt - 1)
			printf("-1");
	}
	return 0;
}