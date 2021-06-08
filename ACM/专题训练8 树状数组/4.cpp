#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int maxn=1005;
int bit[maxn][maxn],n;
int lowbit(int x)
 {
     return x&(-x);
 }
 void add(int x,int y,int c)
 {	
     for(int i=x;i<=maxn;i+=lowbit(i))
     {
         for(int j=y;j<=maxn;j+=lowbit(j))
         bit[i][j]+=c;
     }
 }
 int sum(int x,int y)
 {	
     int s=0;
     for(int i=x;i>0;i-=lowbit(i))
     {
         for(int j=y;j>0;j-=lowbit(j))
         s+=bit[i][j];
     }
     return s;
 }
//int  qz(int x,int y)
//{
//	return sum(x,y)-sum(x,y-1)-sum(x-1,y)+sum(x-1,y-1);
//}
int ans(int x1,int y1,int x2,int y2)
{	
	//return sum(x1,y1)-sum(x1,y2-1)-sum(x2-1,y1)+sum(x2-1,y2-1);
	return (sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1));
}
int main()
{	
	int t;
	cin>>t;
	for(int k=1;k<=t;k++)
	{	 printf("Case %d:\n",k);
		int q;
		scanf("%d",&q);
		//cout<<q<<endl;
		set0(bit);
		for(int i=1;i<=maxn;i++)
        for(int j=1;j<=maxn;j++)
         add(i,j,1);
		char op[5];
		while(q--)
		{	int x1,y1,x2,y2,d;
			 scanf("%s",op);
			if(op[0]=='S')
			{
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				if(x1>x2) swap(x1,x2);
				if(y1>y2) swap(y1,y2);
				printf("%d\n",ans(x1+1,y1+1,x2+1,y2+1));
			}
			else if(op[0]=='D')
			{
				scanf("%d%d%d",&x1,&y1,&d);
				int t=ans(x1+1,y1+1,x1+1,y1+1);
				if(t<d) d=t;
				add(x1+1,y1+1,-d);
			}
			else if(op[0]=='M')
			{
				scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&d);
				int t=ans(x1+1,y1+1,x1+1,y1+1);
				if(t<d) d=t;
				add(x1+1,y1+1,-d);
				add(x2+1,y2+1,d);
			}
			else if(op[0]=='A')
			{	scanf("%d%d%d",&x1,&y1,&d);
				add(x1+1,y1+1,d);
			}
			
		}
	}
}
