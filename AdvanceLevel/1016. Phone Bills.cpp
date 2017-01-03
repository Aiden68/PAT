#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;
int toll[24];
struct Record{
	string name;
	string stime;
	int time;
	int status;
};

void strTimeToint(int &d,int &h,int &m,string time)
{
	d = (time[3] - '0') * 10 + (time[4] - '0');
	h = (time[6] - '0') * 10 + (time[7] - '0');
	m = (time[9] - '0') * 10 + (time[10] - '0');
}
int timeConvert(string time)
{
	int day, hour, min;
	strTimeToint(day,hour,min,time);
	return day * 24 * 60 + hour * 60 + min;
}

bool com(Record a,Record b)
{
	if(a.name != b.name)
		return a.name < b.name;
	else 
		return a.time < b.time;
}

int calBill(string start,string end)
{
	int bill = 0;
	int sd, sh, sm, ed, eh, em;
	strTimeToint(sd,sh,sm,start);
	strTimeToint(ed,eh,em,end);
	for(int i = sd; i <= ed; i++)
	{
		int j;
		if(i == sd)
			j = sh;
		else
			j = 0;
		for(; j < 24; j++)
		{
			if(sh == eh && sd == ed)
			{
				bill += ((em - sm) * toll[j]);
				break;
			}
			else if(i == sd && j == sh)
			{
				bill += ((60 - sm) * toll[j]);
			}
			else if(i == ed && j == eh)
			{
				bill += (em * toll[j]);
				break;
			}
			else
			{
				bill += 60 * toll[j];
			}
		}
	}
	return bill;
}

struct Bill{
	string name;
	string start;
	string end;
	int lastTime;
	int bill;
};
int main()
{
	int n;
	vector<Record> record;
	vector<Bill> bill;
	int month = 0;
	map<string, int> flag;
	for(int i = 0; i < 24; i++)
	{
		scanf("%d",&toll[i]);
	}
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		string name,time,status;
		Record tempRecord;
		cin >> tempRecord.name >> time >> status;
		if(month == 0)
			month = (time[0] - '0') * 10 +time[1] - '0';
		tempRecord.time = timeConvert(time);
		tempRecord.stime = time;
		if(status == "on-line")
			tempRecord.status = 1;
		else
			tempRecord.status = 0;
		record.push_back(tempRecord);
	}
	sort(record.begin(),record.end(),com);
	for(int i = 0; i < record.size() - 1; i++)
	{
		if(record[i].name == record[i + 1].name&&record[i].status == 1&&record[i + 1].status == 0)
		{	
			Bill tempBill;
			tempBill.name = record[i].name;
			tempBill.bill = calBill(record[i].stime, record[i + 1].stime);
			tempBill.start = record[i].stime.erase(0,3);
			tempBill.end = record[i + 1].stime.erase(0,3);
			tempBill.lastTime = record[i + 1].time - record[i].time;
			bill.push_back(tempBill);
			i++;
		}
	}
	double total = 0;
	for(int i = 0; i < bill.size(); i++)
	{
		if(i != 0 && bill[i].name != bill[i - 1].name)
		{
			printf("Total amount: $%.2lf\n",total / 100);
			total = 0;
		}
		if(flag[bill[i].name] == 0)
		{
			flag[bill[i].name]++;
			printf("%s %02d\n",bill[i].name.c_str(),month);
		}
		printf("%s %s %d $%.2lf\n",bill[i].start.c_str(),bill[i].end.c_str(),bill[i].lastTime, bill[i].bill / 100.0);
		total += bill[i].bill;
		if(i == bill.size() - 1)
			printf("Total amount: $%.2lf\n",total / 100);
	}
	return 0;
}