#include<iostream>
using namespace std;

int main()
{
	int m, n;
	int color[480000] = { 0 };
	cin >> m >> n;
	int cnt = 1;
	for (int i = 0; i < m * n; i++)
	{
		scanf("%d", &color[i]);
	}
	int dominantColor = color[0];
	for (int i = 1; i < m * n; i++)
	{
		if (color[i] == dominantColor)
			cnt++;
		else if (cnt == 1)
			dominantColor = color[i];
		else
			cnt--;
	}
	cout << dominantColor;
	return 0;
}