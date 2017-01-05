#include<iostream>
#include<cstdio>
#include<deque>
#include<vector>
using namespace std;

struct finishTime{
	int h;
	int m;
	int c;
};

bool compare(finishTime a, finishTime b){
	if (a.h != b.h){
		return a.h < b.h;
	}
	else{
		return a.m < b.m;
	}
}

vector<int> v[21];
int getMin(int n,finishTime *f){
	int min = 0;
	for (int i = 1; i < n; i++)
	{
		if (compare(f[v[i].front()], f[v[min].front()]))
			min = i;
	}
	return min;
}

bool inTime(finishTime a,int i,int *time){
	a.h = a.h - (time[i] / 60);
	a.m = a.m - (time[i] % 60);
	if (a.m < 0){
		a.m += 60;
		a.h -= 1;
	}
	if (a.h < 17)
		return true;
	else
		return false;
}

int main()
{
	int n, m, k, q;
	deque<int> dq[21];

	finishTime f[1001];
	cin >> n >> m >> k >> q;
	int time[1001];
	int query[1001];
	for (int i = 1; i <= k; i++)
	{
		cin >> time[i];
	}
	for (int i = 0; i < q; i++)
	{
		cin >> query[i];
	}
	int cnt = 1;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0){
				f[cnt].m = time[cnt] % 60;
				f[cnt].h = time[cnt] / 60 + 8;
				f[cnt].c = j;
			}
			else{
//				cout << v[j][i - 1] << endl;
				f[cnt].m = (time[cnt] + f[v[j][i-1]].m) % 60;
				f[cnt].h = (time[cnt] + f[v[j][i - 1]].m) / 60 + f[v[j][i - 1]].h;
				f[cnt].c = j;
			}
			v[j].push_back(cnt++);
		}
	}
	while (cnt <= k){
		int tmp = getMin(n, f);
		vector< int >::iterator k = v[tmp].begin();
		v[tmp].erase(k);
		f[cnt].m = (time[cnt] + f[v[tmp][m - 2]].m) % 60;
		f[cnt].h = (time[cnt] + f[v[tmp][m - 2]].m) / 60 + f[v[tmp][m - 2]].h;
		f[cnt].c = tmp;
		v[tmp].push_back(cnt++);
	}
	for (int i = 0; i < q; i++)
	{
		if (inTime(f[query[i]], query[i],time))
			printf("%.2d:%.2d\n", f[query[i]].h, f[query[i]].m);
		else
			cout << "Sorry" << endl;
	}
	return 0;
}