#include<iostream>
#include<string>
#include<stack>
using namespace std;

int n;
int pre[31] = { 0 };
int in[31] = { 0 };
int post[31] = { 0 };
int cnt = 0;
void solve(int l1,int r1,int l2,int r2)
{
	if (r1 < l1)
		return;
	if (r1 == l1)
	{
		post[cnt++] = pre[l1];
		return;
	}
	post[cnt++] = pre[l1];
	int i = l2;
	for (; i <= r2; i++)
	{
		if (in[i] == pre[l1])
			break;
	}
	solve(l1 + i - l2 + 1, r1, i + 1, r2);
	solve(l1 + 1, l1 + i - l2, l2, i - 1);
}
int main()
{	
	stack<int> s;
	scanf("%d", &n);
	int cntp = 0;
	int cnti = 0;
	for (int i = 0; i < n*2; i++)
	{
		string str;
		int tmp;
		cin >> str;
		if (str == "Push")
		{
			scanf("%d", &tmp);
			s.push(tmp);
			pre[cntp++] = tmp;
		}
		else if (str == "Pop")
		{
			in[cnti++] = s.top();
			s.pop();
		}
	}
	solve(0, n - 1, 0, n - 1);
	for (int i = n - 1; i >= 0; i--)
	{
		if (i != n - 1)
			printf(" ");
		printf("%d", post[i]);
	}
	return 0;
}