#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> output, toutput;
int n, k, p;
int factor[25] = { 0 };
int fsum = -1;
void dfs(int s,int sum,int tfsum,int tk)
{
	if(sum == n&&tfsum > fsum&&tk == k)
	{
		output = toutput;
		fsum = tfsum;
		return;
	}
	if(sum > n||tk > k)
		return;
	for(int i = s; i > 0 ;i--) 
	{
		toutput.push_back(i);
		dfs(i,sum + factor[i], tfsum + i, tk + 1);
		toutput.pop_back();
	}	
}
int main()
{
	scanf("%d%d%d", &n, &k, &p);
	int t = 1;
	int i = 0;
	for(; ; i++)
	{
		t = pow((double)i + 1,p);
		if(t > n)
			break;
		factor[i + 1] = t;
	}
	dfs(i,0,0,0);
	if(fsum == -1)
		printf("Impossible");
	else
	{
		printf("%d =",n);
		for(int i = 0; i < output.size(); i++)
		{
			if(i != 0)
				printf(" +");
			printf(" %d^%d",output[i],p);
		}
	}
	return 0;
}