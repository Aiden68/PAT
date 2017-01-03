#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Rank{
	int id;
	int score;
	int solvedNum;
	int flag[6];
};

bool com(Rank a,Rank b)
{
	if(a.score != b.score)
		return a.score > b.score;
	else if(a.solvedNum != b.solvedNum)
		return a.solvedNum > b.solvedNum;
	else
		return a.id <b.id;
}
int main()
{
	int n, k, m;
	int score[6] = { 0 };
	int user[10010][6] = {{ 0 }};
	Rank userRank[10010];
	fill(user[0],user[0] + 10010 * 6, -1);
	scanf("%d%d%d",&n,&k,&m);
	for(int i = 1; i <= k; i++)
		scanf("%d",&score[i]);
	for(int i = 1; i <= n; i++)
	{
		userRank[i].id = i;
		userRank[i].score = -1;
		userRank[i].solvedNum = 0;
		fill(userRank[i].flag, userRank[i].flag + 6,-1);
	}
	for(int i = 0; i < m; i++)
	{
		int id, problemid, scoreobtained;
		scanf("%d%d%d",&id,&problemid,&scoreobtained);
		if(scoreobtained > user[id][problemid])
		{
			user[id][problemid] = scoreobtained;
			if(userRank[id].score == -1)
				userRank[id].score = scoreobtained;
			if(userRank[id].flag[problemid] < scoreobtained)
				userRank[id].flag[problemid] = scoreobtained;
		}
		if(scoreobtained == -1&&userRank[id].flag[problemid] == -1)
			userRank[id].flag[problemid] = 0;
	}
	for(int i = 1; i <= n; i++)
	{
		if(userRank[i].score != -1)
		{
			userRank[i].score = 0;
			for(int j = 1; j <= k; j++)
			{
				if(userRank[i].flag[j] == score[j])
					userRank[i].solvedNum++;
				if(userRank[i].flag[j] != -1)
					userRank[i].score += userRank[i].flag[j];
			}
		}
	}
	sort(userRank + 1,userRank + n + 1,com);
	int cnti = 1, cntj = 1;
	for(int i = 1; i <= n; i++)
	{
		if(userRank[i].score != -1)
		{
			if(cnti == 1)
				printf("%d ",cnti);
			else
			{
				if(userRank[i].score == userRank[cnti - 1].score)
					printf("%d ",cntj);
				else
				{
					printf("%d ",cnti);
					cntj = cnti;
				}
			}
			cnti++;
			printf("%05d %d",userRank[i].id,userRank[i].score);
			for(int j = 1; j <= k; j++)
			{
				printf(" ");
				if(userRank[i].flag[j] == -1)
					printf("-");
				else
					printf("%d",userRank[i].flag[j]);
			}
			printf("\n");
		}
	}
	return 0;
}