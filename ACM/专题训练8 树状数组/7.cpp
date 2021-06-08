#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int maxn=2e3+10;
int bit[maxn+1][maxn];
int n;
void add(int x,int y)
 {
     for(int i=x;i<=n;i+=i&-i)
     {
         for(int j=y;j<=n;j+=j&-j)
         bit[i][j]=!bit[i][j];
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
     return s%2;
 }
int main()
{	ios::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {	set0(bit);
    	int q;
		cin>>n>>q;
		while(q--)
		{
			char ch;
			cin>>ch;
			int x1,y1,x2,y2;
			if(ch=='C')
			{
				cin>>x1>>y1>>x2>>y2;
				add(x1,y1);
				add(x2+1,y1);
				add(x1,y2+1);
				add(x2+1,y2+1);
			}
			else
			{
				cin>>x1>>y1;
				cout<<sum(x1,y1)<<endl;
			}
		 } 
		 if(t)cout<<endl;
	} 
}

