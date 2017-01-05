#include"iostream"
using namespace std;

int main()
{
	int N;
	int time(0);
	int floor(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		if (temp >= floor)
		{
			time += (temp - floor) * 6 + 5;
			floor = temp;
		}
		else
		{
			time += (floor - temp) * 4 + 5;
			floor = temp;
		}
	}
	cout << time<<endl;
	return 0;
}