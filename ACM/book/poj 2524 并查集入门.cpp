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
#define MAX_N 50010
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
{
	int n,m,num=1;
	while(cin>>n>>m&&!(n==0&&m==0))
	{	int ans=0;
		init(n);
		while(m--)
		{
			int s1,s2;
			cin>>s1>>s2;
			s1--;
			s2--; 
			unite(s1,s2);
		}
		for(int i=0;i<n;i++)
		{
			if(i==par[i]) ans++;
		}
		printf("Case %d: %d\n",num++,ans);
	}
}
