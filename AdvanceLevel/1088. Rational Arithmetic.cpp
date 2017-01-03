#include<iostream>
#include<string>
using namespace std;

long int n,m;
long int maxDivisor(long int m,long int n)
{
	while(n != 0)
	{
		long int temp = m;
		m = n;
		n = temp % n;
	}
	return m;
}

void solve(long int &a,long int &b)
{
	long int maxd = maxDivisor(abs(a),abs(b));
	a /= maxd;
	b /= maxd;
}
void output(long int a,long int b)
{
	string str = "";
	if(a == 0)
		printf("%d",0);
	else if(a < 0)
	{
		a = abs(a);
		if(a / b != 0)
		{
			if(a %b !=0)
				printf("(-%ld %ld/%ld)",a/b,a%b,b);
			else
				printf("(-%ld)",a/b);
		}
		else
		{
			if(a % b != 0)
				printf("(-%ld/%ld)",a,b);
			else
				printf("0");
		}
	}
	else
	{
		if(a / b != 0)
		{
			if(a %b !=0)
				printf("%ld %ld/%ld",a/b,a%b,b);
			else
				printf("%ld",a/b);
		}
		else
		{	if(a % b != 0)
				printf("%ld/%ld",a,b);
			else
				printf("0");
		}
	}
}

void re(long int a,long int b,long int c,long int d,int flag)
{
	switch(flag)
	{
		case 1:
			n = a * d + c * b;
			m = b * d;
			break;
		case 2:
			n = a * d - c * b;
			m = b * d;
			break;
		case 3:
		    n = a * c;
			m = b * d;
			break;
		case 4:
		    n = a * d;
			m = b * c;
			break; 
	}
	if(m < 0)
	{
		n *= -1;
		m *= -1;
	}
}
int main()
{
	string numA,numB;
	long int a, b, c, d;
	string temp = "";
	char fuhao[5] = {' ','+','-','*','/'};
	cin >> numA >> numB;
	for(int i = 0; i < numA.size(); i++)
	{
		if(numA[i] != '/')
			temp += numA[i];
		else
			{
				sscanf(temp.c_str(),"%ld",&a);
				temp = "";
			}
	}
	sscanf(temp.c_str(),"%ld",&b);
	temp = "";
	for(int i = 0; i < numB.size(); i++)
	{
		if(numB[i] != '/')
			temp += numB[i];
		else
			{
				sscanf(temp.c_str(),"%ld",&c);
				temp = "";
			}
	}
	sscanf(temp.c_str(),"%ld",&d);
	solve(a,b);
	solve(c,d);
	for(int i = 1; i < 5; i++)
	{
		re(a,b,c,d,i);
		solve(n,m);
		output(a,b);
		printf(" %c ",fuhao[i]);
		output(c,d);
		printf(" = ");
		if(i == 4&&c == 0)
			printf("Inf");
		else
			output(n,m);
		printf("\n");
	 } 
	return 0;
 } 