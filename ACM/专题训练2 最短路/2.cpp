#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,point[1010],pre[1010];
struct edge
{
	int from,to,cost;
};
edge es[1010];
int d[1010];
void getpath(int t)
{
	int path[1010],cnt=0;
	for(int i=0;i<=n;i++)
	{
		path[i]=t;
		t=pre[t];
		cnt++;
		if(t==0) break;
	}
	reverse(path,path+cnt);
	printf("circuit : ");
	for(int i=0;i<cnt;i++)
	{	
		if(i!=cnt-1) printf("%d->",path[i]);
		else printf("1\n");
	} 
	
}

void solve(int s)
{
    for(int i=0;i<=n;i++)
    {	int flag=0;
        for(int j=0;j<m;j++)
        {
            edge e=es[j];
            if(d[e.to]<d[e.from]+e.cost)
            {
                d[e.to]=d[e.from]+e.cost;
                //flag=1;
                pre[e.to]=e.from;
            }

            //if(flag==0) return ;
    }
}
}
int main()
{
	int T,cnt=1;
	cin>>T;
	while(T--)
	{	memset(point,0,sizeof(point));
		memset(d,0,sizeof(d));
		memset(pre,0,sizeof(pre));
		cin>>n;
		for(int i=1;i<=n;i++)
		cin>>point[i];
		point[n+1]=0;
		cin>>m;
		for(int i=0;i<m;i++)
		{
			cin>>es[i].from>>es[i].to;
			es[i].cost=point[es[i].to];
		}
		solve(1);
		printf("CASE %d#\npoints : %d\n",cnt++,d[n+1]);
		getpath(n+1);
		if(T!=0)printf("\n");

	}
}
