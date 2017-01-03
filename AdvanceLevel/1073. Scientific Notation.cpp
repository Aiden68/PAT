#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str, e, num;
	int point, exponent ,digit;
	cin >> str;
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i] == '.')
			point = i;
		if(str[i] == 'E')
		{
			digit = i;
			for(int j = i + 1; j < str.size(); j++)
				e += str[j];
		}
	}
	sscanf(e.c_str(),"%d",&exponent);
	if(str[0] == '-')
			num += '-';
	int temp = point - 1 + exponent;
	if(temp <= 0)
	{
		num += "0.";
		for(int i = 0; i < -temp; i++)
			num += '0';
	}
	digit -= 3;
	for(int i = 1; i < str.size(); i++)
	{
		if(str[i] == 'E')
			break;
		if(str[i] != '.')
			num += str[i];
		if(temp > 0 &&exponent < digit)
		{
			if(i == point + exponent)
				num += '.';
		}
	}
	if(exponent > digit)
	{
		for(int i = 0; i < exponent - digit; i++)
			num += '0';
	}
	cout<<num;
	return 0;
}