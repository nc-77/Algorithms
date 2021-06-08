#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
struct edge
{
	int to,cost;
};
int n,m,path[210];
int r[210][1100],d[210],vis[210];
void dijkstra(int s)
{	//cout<<"here"<<endl;
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	d[s]=0;
	for(int i=0;i<n;i++)
	{	int MIN=inf;
		int p;
		for(int j=0;j<n;j++)
		{	
			if(!vis[j]&&d[j]<MIN)
			{
				p=j;
				MIN=d[j];
			}
		}
		vis[p]=1;
		if(MIN==inf) break;
		
		for(int j=0;j<n;j++)
		{
			//d[j]=min(d[j],d[p]+r[p][j]);
			if(d[j]>d[p]+r[p][j])
			{
				d[j]=d[p]+r[p][j];
				path[j]=p;
			}
		}
	
	}
	
	
}
int main()
{
	while(cin>>n>>m)
	{	int a,b,c,start,end;
		for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
                if(i==j) r[i][j]=0;
                else r[i][j]=inf;
        }

		for(int i=0;i<m;i++)
		{
			cin>>a>>b>>c;
			if(c<r[a][b])
			r[a][b]=r[b][a]=c;
		}
		cin>>start>>end;
		memset(path,0,sizeof(path));
		dijkstra(start);

		if(d[end]==inf)
		puts("-1");
		else 
		{
			cout<<d[end]<<endl;
		
		}
	}
}
