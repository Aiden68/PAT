#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Applicant{
	int ge;
	int g;
	int id;
	int choice[6];
};

bool com(Applicant a,Applicant b)
{
	if(a.g != b.g)
		return a.g > b.g;
	else if(a.ge != b.ge)
		return a.ge > b.ge;
	else
		return a.id < b.id;
}
int main()
{
	int n, m, k;
	vector<int> admitId[101];
	vector<int> s[6];
	vector<Applicant> applicant;
	int num[101] = { 0 };
	int idToi[40001] = { 0 };
	bool admitflag[40001]= {false};
	scanf("%d%d%d",&n, &m, &k);
	for(int i = 0; i < m; i++)
		scanf("%d", &num[i]);
	for(int i = 0; i < n; i++)
	{
		int ge,gi;
		Applicant app;
		app.id = i;
		scanf("%d%d",&ge, &gi);
		app.ge = ge;
		app.g = ge + gi;
		for(int j = 0; j < k; j++)
		{
			int schoolNum;
			scanf("%d", &schoolNum);
			app.choice[j] = schoolNum;
		}
		applicant.push_back(app);
	}
	sort(applicant.begin(),applicant.end(),com);
	for(int i = 0; i < applicant.size(); i++)
		idToi[applicant[i].id] = i;
	for(int i = 0; i < n; i++)
	{	
		for(int j = 0; j < k; j++)
		{
			int school = applicant[i].choice[j];
			int last = admitId[school].size() - 1;
			int id = applicant[i].id;
			if(num[school] > 0)
			{
				num[school]--;
				admitId[school].push_back(id);
				break;
			}
			else if(num[school] == 0&&applicant[idToi[admitId[school][last]]].g == applicant[i].g
				&&applicant[idToi[admitId[school][last]]].ge == applicant[i].ge)
			{
				admitId[school].push_back(id);
				break;
			}
		}		
	}
	for(int i = 0; i < m; i++)
	{
		sort(admitId[i].begin(),admitId[i].end());
		for(int j = 0; j < admitId[i].size(); j++)
		{
			if(j != 0)
				printf(" ");
			printf("%d",admitId[i][j]);
		}
		printf("\n");
	}
	return 0;
}