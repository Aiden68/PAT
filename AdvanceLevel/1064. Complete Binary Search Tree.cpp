#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct Lr{
	int l;
	int r;
};

void solve(int l, int r)
{

}
int main()
{
	int n,m;
	vector<int> v,bottom,vc;
	queue<Lr> lr;
	scanf("%d", &n);
	int cnt = 2;
	while (n > cnt - 1)
		cnt *= 2;
	cnt /= 2;
	cnt -= 1;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	if (n == 1)
	{
		printf("%d", v[0]);
		return 0;
	}
	sort(v.begin(), v.end());
	int j = 0;
	for (int i = 0; i < n - cnt; i++)
	{
		bottom.push_back(v[j]);
		v[j] = -1;
		j += 2;
	}
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] != -1)
			vc.push_back(v[i]);
	}
	Lr tlr;
	tlr.l = 0;
	tlr.r = vc.size() - 1;
	lr.push(tlr);
	int space = 0;
	while (lr.size() != 0)
	{
		int tmp;
		Lr ttlr = lr.front();
		lr.pop();
		int mid = (ttlr.l + ttlr.r) / 2;
		if (ttlr.r > ttlr.l)
		{
			tlr.l = ttlr.l;
			tlr.r = mid - 1;
			lr.push(tlr);
			tlr.l = mid + 1;
			tlr.r = ttlr.r;
			lr.push(tlr);
		}
		if (space == 0)
			space++;
		else
			printf(" ");
		printf("%d", vc[mid]);
	}
	for (int i = 0; i < bottom.size(); i++)
	{
		if (space == 0)
			space++;
		else
			printf(" ");
		printf("%d", bottom[i]);
	}
	return 0;
}