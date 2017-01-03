#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Player{
	int arrivetime;
	int vip;
	int playtime;
};
struct Table{
	int idletime;
	bool vip;
};

bool com(Player a, Player b){return a.arrivetime < b.arrivetime;}

int main()
{
	int n, k, m, hh, mm, ss;
	int tablenum[105] = { 0 };
	vector<Player> player;
	bool flag[10001] = { false };
	Table table[105] = { 8 * 3600, false};
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		Player tplayer;
		scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &tplayer.playtime, &tplayer.vip);
		tplayer.arrivetime = hh * 3600 + mm * 60 + ss;		
		if(tplayer.playtime > 120)
			tplayer.playtime = 120;
		player.push_back(tplayer);
	}
	sort(player.begin(), player.end(), com);
	scanf("%d%d",&k,&m);
	for (int i = 0; i < m; i++)
	{
		int temp;
		scanf("%d", &temp);
		table[temp].vip = true;
	}
	for(int i = 1; i <= k; i++)
		table[i].idletime = 8 * 3600;
	for(int i = 0; i < n; i++)
	{
		if(flag[i]||player[i].arrivetime >= 21 * 3600)
			continue;
		int min = 3600 * 21,vmin = 3600 * 21,index = -1,vindex = -1;
		int servetable = 0, serveid = i, at = player[i].arrivetime, st = 3600 * 21;
		for(int j = 1; j <= k; j++)
		{
			if(at > table[j].idletime)
				table[j].idletime = at;
			if(!table[j].vip&&min > table[j].idletime)
			{
				min = table[j].idletime;
				index = j;
			}
			else if(table[j].vip&&vmin > table[j].idletime)
			{
				vmin = table[j].idletime;
				vindex = j;
			}
		}
		if(player[i].vip == 1)
		{
			if(vmin == at||(min > at&&vmin < min))
				servetable = 1;
		}
		else
		{
			if(vmin == at&&min == at&&vindex < index)
				servetable = 1;
			else if(vmin == at&&min > at)
				servetable = 1;
			else if(min > at&&vmin > at)
			{
				if(vmin <= min)
				{
					servetable = 1;
					int ti = i + 1;
					while(ti < n&&player[ti].arrivetime <= vmin)
					{
						if(player[ti].vip == 1&&flag[ti]==false)
						{
							serveid = ti;
							i--;
							break;
						}
						ti++;
					}
				}
			}
		}
		flag[serveid] = true;
		at = player[serveid].arrivetime;
		if(servetable == 1)
		{
			if(vindex == -1)
				continue;
			st = vmin;
			table[vindex].idletime = st + player[serveid].playtime * 60;
			if(st < 21 * 3600)
				tablenum[vindex]++;
		}
		else
		{
			if(index == -1)
				continue;
			st = min;
			table[index].idletime = st + player[serveid].playtime * 60;
			if(st < 21 * 3600)
				tablenum[index]++;
		}
		if (st >= 21 * 3600)
			break;
		printf("%02d:%02d:%02d ", at / 3600, at / 60 % 60, at % 60);
		printf("%02d:%02d:%02d %d\n", st / 3600, st / 60 % 60, st % 60,(st - at + 30) / 60);
	}
	for (int i = 1; i <= k; i++)
	{
		if (i != 1)
			printf(" ");
		printf("%d", tablenum[i]);
	}
	return 0;
}