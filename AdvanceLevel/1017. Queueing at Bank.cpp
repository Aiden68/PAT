#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

struct customer{
	int startTime;
	int processTime;
};

bool com(customer a, customer b){
	return a.startTime < b.startTime;
}

int stringToTime(string str){
	int time;
	int h = (str[0] - '0') * 10 + (str[1] - '0');
	int m = (str[3] - '0') * 10 + (str[4] - '0');
	int s = (str[6] - '0') * 10 + (str[7] - '0');
	time = h * 3600 + m * 60 + s;
	return time;
}

int main()
{
	int tn,n, k;
	int waitTime(0);
	int endTime = 8 * 3600;
	int window[1001];
	customer c[10001];
	cin >> n >> k;
	tn = n;
	int j = 0;
	for (int i = 0; i < tn; i++)
	{
		string temp;
		int t;
		cin >> temp >> t;
		if (stringToTime(temp) > (17 * 3600)){
			n--;
			continue;
		}
		c[j].startTime = stringToTime(temp);
		c[j++].processTime = t * 60;
	}
	sort(c, c + n,com);
	int cnt = 0;
	for (int i = 0; i < k&&cnt < n; i++)
	{
		cnt++;
		if (c[i].startTime < 8 * 3600){
			waitTime += (8 * 3600 - c[i].startTime);
			window[i] = 8 * 3600 + c[i].processTime;
	/*		if (endTime > (8 * 3600 + c[i].processTime * 60)){
				endTime = 8 * 3600 + c[i].processTime * 60;
			}*/
		}
		else{
			window[i] = (c[i].startTime + c[i].processTime);
		}
	}
	while (cnt < n){
		sort(window, window + k);
		if (c[cnt].startTime < window[0]){
			waitTime += (window[0] -c[cnt].startTime);
			window[0] += c[cnt].processTime;
		}
		else{
			window[0] = c[cnt].startTime + c[cnt].processTime;
		}
		cnt++;
	}
	printf("%.1f", waitTime * 1.0 / 60 /n);
	return 0;
}