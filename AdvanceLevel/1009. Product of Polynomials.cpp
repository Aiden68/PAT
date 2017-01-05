#include<iostream>
#include<iomanip>
using namespace std;

struct p{
	double c;
	int e;
};

int main()
{
	int a, b;
	p pa[1001];
	p pb[1001];
	p pc[1001];
	double out[2001] = { 0 };
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		cin >> pa[i].e >> pa[i].c;
	}
	cin >> b;
	int cnt = 0;
	for (int i = 0; i < b; i++)
	{
		cin >> pb[i].e >> pb[i].c;
		for (int j = 0; j < a; j++)
		{
			int temp = pb[i].e + pa[j].e;
			out[temp] += pb[i].c * pa[j].c;
//			pc[j].c = pb[i].c * pa[j].c;
		}
	}
	for (int i = 2000; i >= 0; i--)
	{
		if (out[i] > -0.0000005&&out[i] < 0.0000005){
			out[i] = 0;
		}
		else
			cnt++;
	}
	cout << cnt;
	for (int i = 2000; i >= 0; i--)
	{
		if (out[i] != 0){
			cout << " " << i << " " <<  setiosflags(ios::fixed)<< setprecision(1)<< out[i];
		}
	}
	return 0;
}