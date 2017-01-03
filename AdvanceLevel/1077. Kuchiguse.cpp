#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
	int n, cnt = 0;
	map<string,int> lcs;
	string s[101],pre;
	scanf("%d",&n);
	getchar();
	getline(cin,pre);
	int flag = 0;
	for(int i = 1; i < n; i++)
	{
		string str; 
		string suffix;
		getline(cin,str);
		int lens = str.size() - 1;
		int lenp = pre.size() - 1;
		while(lens >=0 && lenp >= flag && str[lens] == pre[lenp])
		{
			lens--;
			lenp--;
		}
		if(lenp + 1 > flag)
			flag = lenp + 1;
	}
	if(flag == pre.size())
		cout<<"nai";
	else
	{
		for(int i = flag; i < pre.size(); i++)
			cout<<pre[i];
	}
	return 0;
}