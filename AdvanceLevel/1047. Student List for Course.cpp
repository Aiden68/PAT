#include<cstdio>  
#include<iostream>  
#include<cstring>  
#include<cmath>  
#include<string>  
#include<vector>  
#include<map>  
#include<set>  
#include<algorithm>  
#include<sstream>  
using namespace std;  
vector<string>mapx[2505];  
int main()  
{  
    int n,k,c,x;  
    char ch[10];  
    string s;  
    scanf("%d%d",&n,&k);  
    for(int i=0;i<n;++i)  
    {  
        scanf("%s%d",ch,&c);  
        s=string(ch);  
        for(int j=0;j<c;++j)  
        {  
            scanf("%d",&x);  
            mapx[x].push_back(s);  
        }  
    }  
    int len;  
    for(int i=1;i<=k;++i)  
    {  
        len=mapx[i].size();  
        sort(mapx[i].begin(),mapx[i].end());  
        printf("%d %d\n",i,len);  
        for(int j=0;j<len;++j)  
            printf("%s\n",mapx[i][j].c_str());  
    }  
    return 0;  
}