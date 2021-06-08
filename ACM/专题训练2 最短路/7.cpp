#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
map<string,int>mp;
string start,last;
int d[1050],vis[1050],r[1050][1050],num;
void dijkstra(int s)
{	memset(vis,0,sizeof(vis));
	d[s]=0;
	for(int i=0;i<num;++i)
	{	int MIN=inf;
		int p;
		for(int j=0;j<num;++j)
		{	
			if(!vis[j]&&d[j]<MIN)
			{
				p=j;
				MIN=d[j];
			}
		}//从尚未使用过的顶点中选择一个距离最小的点
		vis[p]=1;
		if(MIN==inf) break;	//所有顶点都已经用过
		for(int j=0;j<num;++j)
		d[j]=min(d[j],d[p]+r[p][j]);//更新相邻顶点的最短距离	
	}
	if(d[2]==inf) cout<<"-1"<<endl;
	else cout<<d[2]<<endl;
}
int main()
{	ios::sync_with_stdio(false); 
	int m;
	while(cin>>m&&m!=-1)
	{	mp.clear();
		memset(d,0x3f,sizeof(d));
		memset(r,0x3f,sizeof(r));
		for(int i=0;i<=200;++i)
		r[i][i]=0;
		cin>>start>>last;
		{
			mp[start]=1;
			mp[last]=2;
			num=3;
		}
		while(m--)
		{
			string s1,s2;
			int cost;
			cin>>s1>>s2>>cost;
			if(mp[s1]==0)
			mp[s1]=num++;
			if(mp[s2]==0)
			mp[s2]=num++;
			r[mp[s1]][mp[s2]]=r[mp[s2]][mp[s1]]=cost;
		}
		if(start==last) 
		{
			cout<<"0"<<endl;
			continue;
		}
		dijkstra(1);
	}
	
}
