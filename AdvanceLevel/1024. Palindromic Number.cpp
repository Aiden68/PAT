#include<iostream>
#include<string>
using namespace std;

long long reverse(long long n)
{
	long long rn = 0;
	while (n != 0)
	{
		int digital = n % 10;
		n /= 10;
		rn = rn * 10 + digital;
	}
	return rn;
}

string reverse(string n)
{
	string rn;
	int cnt = n.size();
	while (cnt > 0)
		rn += n[--cnt];
	return rn;
}

string add(string a, string b)
{
	string sum = "";
	int cf = 0;
	int lenA = a.size();
	int lenB = b.size();
	while (lenA > 0 && lenB > 0)
	{
		int tmp = (a[--lenA] - '0') + (b[--lenB] - '0') + cf;
		if (tmp > 9)
		{
			tmp -= 10;
			cf = 1;
		}
		else
			cf = 0;
		string str = " ";
		str[0] = (tmp + '0');
		str += sum;
		sum = str;
	}
	if (lenA == 0 && lenB == 0 && cf == 1)
	{
		string str = "1";
		str += sum;
		sum = str;
	}
	while (lenA > 0)
	{
		int tmp = (a[--lenA] - '0') + cf;
		if (tmp > 9)
		{
			tmp -= 10;
			cf = 1;
		}
		else
			cf = 0;
		string str = " ";
		str[0] = (tmp + '0');
		str += sum;
		sum = str;
	}
	while (lenB > 0)
	{
		int tmp = (b[--lenB] - '0') + cf;
		if (tmp > 9)
		{
			tmp -= 10;
			cf = 1;
		}
		else
			cf = 0;
		string str = " ";
		str[0] = (tmp + '0');
		str += sum;
		sum = str;
	}
	return sum;
}

int main()
{
	string RN,N;
	int k;
	cin >> N >> k;
	RN = reverse(N);
	int cnt = 0;
	while (N != RN && cnt < k)
	{
		N = add(N, RN);
		RN = reverse(N);
		cnt++;
	}
	cout << N << endl;
	cout << cnt;
	return 0;
}