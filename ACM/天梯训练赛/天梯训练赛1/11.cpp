#include<bits/stdc++.h>
using namespace std;
#define MAX_N 10010
int par[MAX_N];
map<int,int>mp,vis;
struct node1
{	int fa,ma,k;
	int kid[10];
	int num;
	int nhouse;
	int phouse;
}man[10100];
struct node2
{	int m;
	int people;
	double nhouse;
	double phouse;	
}family[10100];
bool cmp(node2 f1,node2 f2)
{
	if(f1.phouse>f2.phouse) return true;
	else if(f1.phouse==f2.phouse) return f1.m<f2.m;
}
int find(int x)
{
	if(par[x]==x) return x;
	else return(par[x]=find(par[x]));
}
void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return;
	else if(x>y) par[x]=y;
	else par[y]=x; 
}
int main()
{	
	int n,id=0;
	cin>>n;
	for(int i=1;i<=9999;i++)
	par[i]=i;
	for(int i=1;i<=n;i++)
	{
		int fa,ma,kid,k;
		cin>>man[i].num>>man[i].fa>>man[i].ma>>man[i].k;
		if(man[i].fa!=-1)unite(man[i].num,man[i].fa);
		if(man[i].ma!=-1)unite(man[i].num,man[i].ma);
		for(int j=1;j<=man[i].k;j++)
		{
			cin>>man[i].kid[j];
			if(man[i].kid[j]!=-1)
			unite(man[i].kid[j],man[i].num);
		}
		cin>>man[i].nhouse>>man[i].phouse;
	}
	for(int i=1;i<=n;i++)
	{	
		int minn=find(man[i].num);
		int t=mp[minn];
		if(t==0) 
		{
			mp[minn]=++id;
			family[id].m=minn;
			if(!vis[man[i].num])
			{
				family[id].people++;
				vis[man[i].num]=1;
			}
			if(man[i].fa!=-1&&vis[man[i].fa]==0)
			{
				family[id].people++;
				vis[man[i].fa]=1;
			}
			if(man[i].ma!=-1&&vis[man[i].ma]==0)
			{
				family[id].people++;
				vis[man[i].ma]=1;
			}
			for(int j=1;j<=man[i].k;j++)
			{
				if(man[i].kid[j]!=-1&&vis[man[i].kid[j]]==0)
				{
				family[id].people++;
				vis[man[i].kid[j]]=1;
				}
			}
			family[id].nhouse+=man[i].nhouse;
			family[id].phouse+=man[i].phouse;
			
			//cout<<id<<" "<<family[id].people<<" "<<family[id].nhouse<<" "<<family[id].phouse<<endl;
		}
		else
		{	if(!vis[man[i].num])
			{
				family[t].people++;
				vis[man[i].num]=1;
			
			}
			if(man[i].fa!=-1&&vis[man[i].fa]==0)
			{
				family[t].people++;
				vis[man[i].fa]=1;

			}
			if(man[i].ma!=-1&&vis[man[i].ma]==0)
			{
				family[t].people++;
				vis[man[i].ma]=1;

			}
			for(int j=1;j<=man[i].k;j++)
			{
				if(man[i].kid[j]!=-1&&vis[man[i].kid[j]]==0)
				{	
				family[t].people++;
				vis[man[i].kid[j]]=1;
				}
			}
			family[t].nhouse+=man[i].nhouse;
			family[t].phouse+=man[i].phouse;
			//cout<<t<<" "<<family[t].people<<" "<<family[t].nhouse<<" "<<family[t].phouse<<endl;
		}
		
	}
	for(int i=1;i<=id;i++)
	{		if(family[i].people>0)
			{
				family[i].nhouse/=family[i].people;
				family[i].phouse/=family[i].people;
			}
	
	}
	if(id>1)
	sort(family+1,family+id+1,cmp);
	cout<<id<<endl;
	for(int i=1;i<=id;i++)
	printf("%04d %d %.3f %.3f\n",family[i].m,family[i].people,family[i].nhouse,family[i].phouse);
}
