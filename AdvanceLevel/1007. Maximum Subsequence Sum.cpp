#include"iostream"
using namespace std;

int main()
{
	int n;
	cin >> n;
	int *num = new int[n];
	int max = 0;
	int sum = 0;
	int start = 0;
	int end = 0;
	int tstart = 0;
	int tend = 0;
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	for (int i = 0; i < n; i++)
	{
		int tmp = num[i];
		if (tmp >= 0)
		{
			flag = 1;
		}
		sum += tmp;
		if (sum > max||(sum ==0&&max ==0))
		{
			max = sum;
			end = i;
			start = tstart;
		}
		if (sum < 0)
		{
			tstart = i + 1;
			sum = 0;
		}
	}
	if (flag == 0)
	{
		cout << 0<<" "<<num[0]<<" "<<num[n-1];
	}
	else
	{
		cout << max << " " << num[start] << " " << num[end];
	}
	return 0;
}