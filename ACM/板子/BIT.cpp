#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
//[1,n]
int bit[maxn+1],n;
int sum(int i)
{
	int s=0;
	while(i>0)
	{
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}
void add(int i,int x)
{
	while(i<=n)
	{
		bit[i]+=x;
		i+=i&-i;
	}
}
 void add(int x,int y,int c)
 {
     for(int i=x;i<=maxn;i+=i&-i)
     {
         for(int j=y;j<=maxn;j+=j&-j)
         bit[i][j]+=c;
     }
 }
 int sum(int x,int y)
 {
     int s=0;
     for(int i=x;i>0;i-=i&-i)
     {
         for(int j=y;j>0;j-=j&-j)
         s+=bit[i][j];
     }
     return s;
 }
