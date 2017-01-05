#include"iostream"
#include"string"
using namespace std;

int main()
{
	string engNum[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	string num;
	int sum(0);
	int temp[10] = { 0 };
	cin >> num;
	for (int i = 0; i < num.size(); i++)
	{
		sum += (num[i] - '0');
	}
	int count(0);
	while (sum != 0)
	{
		temp[count++] = sum % 10;
		sum /= 10;
	}
	if (count != 0)
	{
		cout << engNum[temp[count - 1]];
		for (int i = count - 2; i >= 0; i--)
		{
			cout << " " << engNum[temp[i]];
		}
	}
	else
		cout << "zero";
	return 0;
}
