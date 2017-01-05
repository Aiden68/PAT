#include<iostream>
#include<vector>
using namespace std;

struct startEndPair{
	int start;
	int end;
};

void solve(vector<startEndPair> &sep,int start,int end)
{
	startEndPair tsep;
	tsep.start = start + 1;
	tsep.end = end + 1;
	sep.push_back(tsep);
}

int main()
{
	int n , m;
	int diamond[100001] = { 0 };
	int start = 0;
	int end = 0;
	int sum = 0;
	int flag = 0;
	int min = 900000000;
	vector<startEndPair> sep;
	scanf("%d %d",&n,&m);
	for(int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d",&tmp);
		diamond[i] = tmp;
		sum += tmp;
		while(sum > m)
		{
			if(flag == 0)
			{
				if(sum < min)
				{
					min = sum;
					sep.clear();
					solve(sep,start,i);
				}
				else if(sum == min)
					solve(sep,start,i);
			}
			sum -= diamond[start];
			start++;
		}
		if(sum == m && flag == 0)
		{
			sep.clear();
			solve(sep,start,i);
			flag = 1;
		}
		else if(sum == m)
			solve(sep,start,i);
	}
	for(int i = 0; i < sep.size(); i++)
	{
		printf("%d-%d\n",sep[i].start,sep[i].end);
	}
	return 0;
}