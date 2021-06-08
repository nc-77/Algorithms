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
                	if(d[i][j]>d[i][k]+d[k][j]+cost[k])
                	{
                		d[i][j]=d[i][k]+d[k][j]+cost[k];
                		pre[i][j]=pre[i][k];
                		//printf("i%d j%d k%d ,%d\n",i,j,k,pre[i][j]);
					}
					else if(d[i][j]==d[i][k]+d[k][j]+cost[k])
					{
						pre[i][j]=min(pre[i][j],pre[i][k]);
						//printf("i%d j%d k%d ,%d\n",i,j,k,pre[i][j]);
					}
				}
}
int main()
{
	while(scanf("%d",&n)&&n!=0)
	{	memset(d,0,sizeof(d));
		int beg,last;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			{	if(i==j) pre[i][j]=inf;
				else pre[i][j]=j;
				scanf("%d",&d[i][j]);
				if(d[i][j]==-1)
				d[i][j]=inf;
			}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&cost[i]);
//			for(int j=1;j<=n;j++)
//			{	
//				if(d[j][i]!=inf)
//				d[j][i]+=cost[i];
//			}
		}
		floyd();
		int a,b;
		while(~scanf("%d%d",&a,&b))
		{	if(a==-1 && b==-1) break;
			printf("From %d to %d :\n",a,b);
			printf("Path: ");
			int i = pre[a][b];
            printf("%d",a);
            while(i != inf)
            {
                printf("-->%d",i);
                i = pre[i][b];
            }
            printf("\n");
			printf("Total cost : %d\n\n",d[a][b]);
		
		}
	}
}
