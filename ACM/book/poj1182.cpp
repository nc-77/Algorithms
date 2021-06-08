#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<map>
#include<set>
using namespace std;
#define MAX_N 150010
int par[MAX_N];
int high[MAX_N];//Ê÷µÄ¸ß¶È

void init(int n)
{
	for(int i=0;i<n;i++)
	{
		par[i]=i;
		high[i]=0;
	}
} 
int find(int x)
{
	if(par[x]==x)
	return x;
	else
	return par[x]=find(par[x]);
}
void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(high[x]<high[y])
	par[x]=y;
	else 
	{
		par[y]=x;
		if(high[x]==high[y]) high[x]++;
	}
}
bool same(int x,int y)
{
	return find(x)==find(y);	
}
int main()
{	int x,y,t,n,k,ans;
	scanf("%d%d",&n,&k);
	init(n*3);
	for(int i=0;i<k;i++)
	{
		scanf("%d%d%d",&t,&x,&y);
		x--;
		y--;
		if(x<0||x>=n||y<0||y>=n)
		{
			ans++;
			//cout<<i+1<<endl;
			continue;
		}
		if(t==1)
		{
			if(same(x,y+n)||same(x,y+2*n))
			{
				ans++;
				//cout<<i+1<<endl;
			}
			else 
			{
				unite(x,y);
				unite(x+n,y+n);
				unite(x+2*n,y+2*n);
			}
		}
		else 
		{
			if(same(x,y)||same(x,y+2*n))
			{
				ans++;
				//cout<<i+1<<endl;
			}
			else
			{
				unite(x,y+n);
				unite(x+n,y+2*n);
				unite(x+2*n,y);
			}
		}
		
	}
	
	printf("%d\n",ans);
 } 
