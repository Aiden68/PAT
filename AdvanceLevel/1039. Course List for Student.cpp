#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
#define max 27 * 26 * 26 * 10
int nameToInt(char *name)
{
	int tmp = 0;
	tmp = (name[0]-'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 + (name[3] - '0');
	return tmp;
}

int main()
{
	int n, k;
	char name[5];
	vector<int> course[max];
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++)
	{
		int courseNum, num;
		scanf("%d %d", &courseNum, &num);
		for (int j = 0; j < num; j++)
		{
			scanf("%s", name);
			int temp = nameToInt(name);
			course[temp].push_back(courseNum);
		}
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%s", name);
		int temp = nameToInt(name);
		int size = course[temp].size();
		sort(course[temp].begin(), course[temp].end());
		printf("%s %d", name, size);
		for (int j = 0; j < size; j++)
		{
			printf(" %d", course[temp][j]);
		}
		printf("\n");
	}
	return 0;
}

