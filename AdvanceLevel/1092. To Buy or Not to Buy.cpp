#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s1, s2;
	int arr[123] = { 0 };
	getline(cin, s1);
	getline(cin, s2);
	for (int i = 0; i < s1.size(); i++)
	{
		int temp = s1[i];
		arr[temp]++;
	}
	int cnt = 0;
	for (int i = 0; i < s2.size(); i++)
	{
		int temp = s2[i];
		arr[temp]--;
		if (arr[temp] < 0){
			cnt++;
		}
	}
	if (cnt > 0){
		cout << "No " << cnt;
	}
	else
	{
		cout << "Yes " << s1.size() - s2.size();
	}
	return 0;
}