#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int ufs[2009] = { 0 };
int getHead(int a)
{
	if(ufs[a] == a)
		return a;
	while(ufs[a] > 0)
		a = ufs[a];
	return a;
}

void unite(int a,int b)
{
    int ha = getHead(a);
	int hb = getHead(b);
	if(ha != hb)
	{
		if(ufs[a] == a&&ufs[b] == b)
		{
			ufs[a] = -2;
			ufs[b] = a;
		}
		else if(ufs[ha] < 0&&ufs[hb] < 0)
		{
			ufs[ha] += ufs[hb];
			ufs[hb] = ha;
		}
		else if(ufs[ha] < 0)
		{
			ufs[ha]--;
			ufs[hb] = ha;
		}
		else if(ufs[hb] < 0)
		{
			ufs[hb]--;
			ufs[ha] = hb;
		}
	}
}
int main()
{
	int n, k;
	int weight[2009] = { 0 };
	int weightGang[2009] = { 0 };
	int totalWeight[2009] = { 0 };
	int headMark[2009] = { 0 };
	string name[2009];
	map<string, int> nameId;
	map<string, int>::iterator it;
	int idCnt = 1;
	scanf("%d%d",&n, &k);
	for(int i = 0; i <= n; i++)
		ufs[i] = i;
	for(int i = 0; i < n; i++)
	{
		string name1,name2;
		int time, id1, id2;
		cin >> name1 >> name2;
		scanf("%d",&time);
		it = nameId.find(name1);
		if(it == nameId.end())
		{
			id1 = idCnt;
			nameId.insert(pair<string,int>(name1,idCnt++));
		}
		else
			id1 = nameId[name1];
		it = nameId.find(name2);
		if(it == nameId.end())
		{
			id2 = idCnt;
			nameId.insert(pair<string,int>(name2,idCnt++));
		}
		else
			id2 = nameId[name2];
		name[id1] = name1;
		name[id2] = name2;
		weight[id1] += time;
		weight[id2] += time;
		weightGang[id1] += time;
		unite(id1,id2);
	}
	int cntGang = 0;
	for(int i = 1; i <= n; i++)
	{
		int h = getHead(i);
		if(ufs[i] != i && abs(ufs[h]) > 2)
		{
			if(headMark[h] == 0)
				headMark[h] = i;
			else if(weight[headMark[h]] < weight[i])
				headMark[h] = i;
			totalWeight[h] += weightGang[i];
			if(totalWeight[h] - weightGang[i] <= k&&totalWeight[h] > k)
				cntGang++;
		}
	}
	printf("%d\n",cntGang);
	vector<string> output;
	for(int i = 1; i <= n; i++)
	{
		if(headMark[i] != 0&&totalWeight[i] > k)
			output.push_back(name[headMark[i]]);
	}
	sort(output.begin(),output.end());
	for(int i = 0; i < output.size(); i++)
		printf("%s %d\n",output[i].c_str(),abs(ufs[getHead(nameId[output[i]])]));
	return 0;
}