#include<iostream>
#include<string>
using namespace std;

void solve(string n1,string n2,long long radix,long long r)
{
	long long dn1 = 0, dn2 = -1,rmin = 1;
	for(long long i = 0; i < n1.size(); i++)
	{
		if(n1[i] >= '0'&&n1[i] <= '9')
			dn1 = (dn1 * radix) + (n1[i] - '0');
		else
			dn1 = (dn1 * radix) + (n1[i] - 'a' + 10);
	}
	for(long long i = 0; i < n2.size(); i++)
	{
		if(n2[i] >= '0'&&n2[i] <= '9')
		{
			if(rmin < n2[i] - '0')
				rmin = n2[i] - '0';
		}
		else
		{
			if(rmin < n2[i] - 'a' + 10)
				rmin = n2[i] - 'a' + 10;
		}
	}
	if(n2.size() == 1)
	{
		dn2 = 0;
		r = rmin + 1;
		if(n2[0] >= '0'&&n2[0] <= '9')
			dn2 = (n2[0] - '0');
		else
			dn2 = (n2[0] - 'a' + 10);
	}
	else
	{
		long long ll = rmin + 1, rr = 9000000000000;	
		while(dn1 != dn2&&ll <= rr)
		{
			dn2 = 0;
			r = (ll + rr) / 2; 
			for(long long i = 0; i < n2.size(); i++)
			{
				if(n2[i] >= '0'&&n2[i] <= '9')
					dn2 = (dn2 * r) + (n2[i] - '0');
				else
					dn2 = (dn2 * r) + (n2[i] - 'a' + 10);
			}
			if(dn2 < 0)
			{
				rr /= 2;
				continue;
			}
			if(dn2 > dn1)
				rr = r - 1; 			
			else if(dn2 < dn1)
				ll = r + 1;
		}
	}
	if(dn1 == dn2)
	{
		if(dn1 == 1)
			printf("2");
		else
			cout<<r;
	}
	else
		cout<<"Impossible";
}
int main()
{
	string n1, n2;
	long long tag, radix, r = 2;
	cin>> n1 >> n2;
	scanf("%lld%lld", &tag, &radix);
	if(tag == 1)
		solve(n1,n2,radix,r);
	else
		solve(n2,n1,radix,r);
	return 0;
}