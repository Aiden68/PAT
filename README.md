# PAT
data structure and algorithm
```
#include<iostream>
#include<string>
using namespace std;

int main()
{
  int n, cnt = 0;
  bool flag[10000] = { false };
  scanf("%d", &n);
  for(int i = 0; i < n; i++)
  {
      string str;
      cin >> str;
      int sum = 0;
      for(int j = 0; j < str.size(); j++)
      {
          sum += str[j] - '0';
      }
      if(flag[sum] == false)
      {
      	  cnt++;
          flag[sum] = true;
      }
  }
  printf("%d\n", cnt);
  int space = 0;
  for(int i  = 0; i < 10000; i++)
  {    
      if(flag[i])
	  {
		  if(space != 0)
		    printf(" ");
	      else
			space++;  
		  printf("%d",i);
	  }
  }
  return 0;
}
```
