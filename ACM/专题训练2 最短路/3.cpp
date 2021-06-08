#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define MAX_V 1005
using namespace std;
int n;
int d[MAX_V][MAX_V],pre[MAX_V][MAX_V],beg,last;
int cost[MAX_V];
void floyd()
{	//memset(pre,-1,sizeof(pre));
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                {
                	if(d[i][j]>d[i][k]+d[k][j])
                	{
                		d[i][j]=d[i][k]+d[k][j];
                		pre[i][j]=pre[k][j];
                		//printf("i%d j%d k%d ,%d\n",i,j,k,pre[i][j]);
					}
					else if(d[i][j]==d[i][k]+d[k][j])
					{
						pre[i][j]=min(pre[i][j],pre[k][j]);
						//printf("i%d j%d k%d ,%d\n",i,j,k,pre[i][j]);
					}
				}
}
int main()
{
	while(cin>>n&&n!=0)
	{	memset(d,0,sizeof(d));
		int beg,last;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{	if(i==j) pre[i][j]=inf;
				else pre[i][j]=i;
				scanf("%d",&d[j][i]);
				if(d[j][i]==-1)
				d[j][i]=inf;
			}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&cost[i]);
			for(int j=1;j<=n;j++)
			{	
				if(d[j][i]!=inf)
				d[j][i]+=cost[i];
			}
		}
		floyd();

		while(~scanf("%d%d",&last,&beg)&&!(beg==-1&&last==-1))
		{	printf("From %d to %d :\n",last,beg);
			printf("Path: ");
			int t=last;
			while(1)
			{	if(t==inf) break;
				if(t==beg)
				printf("%d",t);
				else                
				printf("%d-->",t);
				t=pre[beg][t];
			}
			printf("\n");
			printf("Total cost : %d\n\n",d[beg][last]-cost[last]);
		
		}
	}
}
