#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct Student{
	int id;
	string name;
	int grade;
};

bool compareId(Student a, Student b)
{
	return a.id < b.id;
}

bool compareName(Student a, Student b)
{
	if (a.name != b.name)
		return a.name < b.name;
	else
		return a.id < b.id;
}

bool compareGrade(Student a, Student b)
{
	if (a.grade != b.grade)
		return a.grade < b.grade;
	else
		return a.id < b.id;
}
int main()
{
	int n, c;
	cin >> n >> c;
	Student student[100000];
	for (int i = 0; i < n; i++)
	{
		char name[10];
//		cin >> student[i].id >> student[i].name;
		scanf("%d%s%d", &student[i].id, name, &student[i].grade);
		student[i].name = name;
	}
	switch (c)
	{
		case 1:
			sort(student, student + n, compareId);
			break;
		case 2:
			sort(student, student + n, compareName);
			break;
		case 3:
			sort(student, student + n, compareGrade);
			break;
	}
	for (int i = 0; i < n; i++)
	{
		printf("%06d ", student[i].id);
		cout << student[i].name ;
		printf(" %d\n", student[i].grade);
	}
	return 0;
}


