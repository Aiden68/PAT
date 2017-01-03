#include<iostream>
#include<string>
using namespace std;

int main()
{
	string pat;
	long long p = 0, a = 0, t = 0;
	cin >> pat;
	for (int i = 0; i < pat.size(); i++)
	{
		if (pat[i] == 'P')
			p++;
		else if (pat[i] == 'A')
			a += p;
		else
			t += a;
	}
	printf("%lld", t % 1000000007);
	return 0;
}