#include<bits/stdc++.h>
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
set<int>s;
int main()
{
	int n;
	cin>>n;
	init(10000+10);
	while(n--)
	{
		int k;
		cin>>k;
		int x;
		cin>>x;
		s.insert(x);
		k--;
		for(int i=1;i<=k;i++)
		{	int y;
			cin>>y;
			s.insert(y);
			unite(x,y);
		}
	}
	set<int>::iterator it;
	int sum=0,len=s.size();
	for(it=s.begin ();it!=s.end ();it++)
    {
        if(par[*it]==*it) sum++;
    }
    cout<<len<<" "<<sum<<endl;
	int q;
	cin>>q;
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		if(same(a,b)) puts("Y");
		else puts("N");
	}
	
}
