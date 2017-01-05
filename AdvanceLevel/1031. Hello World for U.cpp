#include<iostream>
#include<string>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int n = str.length();
	int n1, n2;
	n1 = n2 = n / 3;
	if (n % 3 == 0){
		n2 = n2 + 2;
	}
	else if (n % 3 == 1){
		n2 += 1;
		n1 = n2;
	}
	else {
		n2 += 1;
		n1 = n2;
		n2++;
	}
	for (int i = 1; i < n1; i++){
		cout<<str[i-1];
		for (int j = 0; j < n2 - 2; j++){
			cout<<" ";
		}
		cout<<str[n - i]<<endl;
	}
	for (int i = n1 - 1; i < n1 + n2 - 1; i++){
		cout<<str[i];
	}
	return 0;
}