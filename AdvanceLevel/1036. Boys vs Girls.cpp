#include<iostream>
#include<string>
using namespace std;

struct student{
	string name;
	string gender;
	string major;
	int grade;
};

int main()
{
	int n;
	cin >> n;
	student max,min;
	max.grade = -1;
	min.grade = 101;
	for (int i = 0; i < n; i++)
	{
		student tmp;
		cin >> tmp.name >> tmp.gender >> tmp.major >> tmp.grade;
		if (tmp.gender == "M"){
			if (tmp.grade < min.grade){
				min.name = tmp.name;
				min.gender = tmp.gender;
				min.major = tmp.major;
				min.grade = tmp.grade;
			}
		}
		else{
			if (tmp.grade > max.grade){
				max.name = tmp.name;
				max.gender = tmp.gender;
				max.major = tmp.major;
				max.grade = tmp.grade;
			}
		}
	}
	if (max.grade == -1){
		cout << "Absent" << endl;
	}
	else{
		cout << max.name << " " << max.major << endl;
	}
	if (min.grade == 101){
		cout << "Absent" << endl;
	}
	else{
		cout << min.name << " " << min.major << endl;
	}
	if (max.grade == -1 || min.grade == 101){
		cout << "NA";
	}
	else{
		cout << max.grade - min.grade;
	}
	return 0;
}