#include"iostream"
using namespace std;

struct xiang
{
	int e;
	double a;
};

int main()
{
	int n1,n2;
	cin >> n1;
	xiang *a = new xiang[n1];
	for (int i = 0; i < n1; i++)
	{
		cin >> a[i].e >> a[i].a;
	}
	cin >> n2;
	xiang *b = new xiang[n2];
	for (int i = 0; i < n2; i++)
	{
		cin >> b[i].e >> b[i].a;
	}
	xiang *c = new xiang[n1 + n2];
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < n1 && j < n2)
	{
		if (a[i].e == b[j].e)
		{
			c[k].e = a[i].e;
			if ((a[i].a + b[j].a) == 0)
			{
				i++;
				j++;
				continue;
			}		
			c[k++].a = a[i++].a + b[j++].a;
		}
		else if (a[i].e < b[j].e)
		{
			c[k].e = b[j].e;
			c[k++].a = b[j++].a;
		}
		else
		{
			c[k].e = a[i].e;
			c[k++].a = a[i++].a;
		}
	}
	if (i == n1)
	{
		for (; j < n2; j++)
		{
			c[k].e = b[j].e;
			c[k++].a = b[j].a;
		}
	}
	else
	{
		for (; i < n1; i++)
		{
			c[k].e = a[i].e;
			c[k++].a = a[i].a;
		}
	}
	cout << k;
	if (k > 0)
	{
		cout << " " << c[0].e << " ";
		printf("%.1lf", c[0].a);
	}
	for (int i = 1; i < k; i++)
	{
		cout << " " << c[i].e << " " ;
		printf("%.1lf", c[i].a);
	}
	return 0;
}