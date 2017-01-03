#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int head1,head2,n;
	int list[1000000];
	bool nextMark[1000000] = { 0 };
	vector<int> sameNext;
	int flag = 0;
	scanf("%d%d%d", &head1, &head2, &n);
	for(int i = 0; i < n; i++)
	{
		int address,next;
		char data;
		scanf("%d %c %d",&address, &data, &next);
		list[address] = next;
		if(next == -1)
			flag++;
		else if(nextMark[next] == 0)
			nextMark[next] = 1;
		else
		{
			sameNext.push_back(next);
		}
	}
	if(head1 == head2)
	{
		printf("%05d",head1);
		return 0;
	}
	if(sameNext.size() == 0)
	{
		printf("-1");
		return 0;
	}
	for(int i = 0; i < sameNext.size(); i++)
	{
		int temp = head1;
		flag = 0;
		while(temp != -1)
		{
			if(temp == sameNext[i])
			{
				flag++;
				break;
			}
			temp = list[temp];
		}
		if(flag == 1)
		{
			temp = head2;
			while(temp != -1)
			{
				if(temp == sameNext[i])
				{
					flag = 2;
					printf("%05d",sameNext[i]);
					break;
				}
				temp = list[temp];
			}
			if(flag == 2)
				break;
		}
	}
	if(flag != 2)
		printf("-1");
	return 0;
}