#include<iostream>
#include<string>
using namespace std;

string solve(string str,int n,int &digit)
{
	string result = "0.";
	int point = -1;
	int nonZero = -1;
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i] == '.')
			point = i;
		else if(str[i] != '0'&&nonZero == -1)
			nonZero = i;
		if(point != -1 && nonZero != -1)
			break;
	}
	if(nonZero == -1)
	{
		for(int i = 0; i < n; i++)
			result += '0';
		result += "*10^";
		digit = 0;
		return result;
	}
	if(point == -1)
		point = str.size();
	digit = point - nonZero;
	if(digit < 0)
		digit++;
	for(int i = nonZero; i < str.size()&&result.size() < n + 2; i++)
	{
		if(str[i] != '.')
			result += str[i];
	}
	while(result.size() - 2 < n)
		result += '0';
	result += "*10^";
	return result;
}
int main()
{
	int n, digita, digitb;
	string a, b, strA, strB;
	cin >> n >> a >>b;
	strA = solve(a, n, digita);
	strB = solve(b, n, digitb);
	if(strA == strB && digita == digitb)
		printf("YES %s%d",strA.c_str(),digita);
	else
		printf("NO %s%d %s%d",strA.c_str(),digita,strB.c_str(),digitb);
	return 0;
}