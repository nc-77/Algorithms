#include<stdio.h>
#include<string.h>
#define MAX_V 1000
#define inf 0x3f3f3f3f

typedef struct edge
{
	int len,cost;
}edge;
int d[MAX_V],vis[MAX_V],cost[MAX_V];
int n;
edge g[MAX_V][MAX_V];

void dijk(int s){
    memset(d,inf,sizeof(d));
    d[s]=0;
    for(int i=0;i<n;i++){
        int MIN=inf;
            int p;
        for(int j=0;j<n;j++){
            
            if(!vis[j]&&d[j]<MIN){
                p=j;
                MIN=d[j];
            }
             
        }
       vis[p]=1;
       //printf("p=%d\n",p);
             for(int j=0;j<n;j++){
                 if(d[p]+g[p][j].len<d[j]){
                     d[j]=d[p]+g[p][j].len;
                     cost[j]=cost[p]+g[p][j].cost;
                 }
                    
                else if(d[p]+g[p][j].len==d[j]&&cost[p]+g[p][j].cost<cost[j]){
                     cost[j]=cost[p]+g[p][j].cost;
                }
                 
             }
        
                //for(int j=0;j<n;j++)
                //printf("%d  %d\n",j,d[j]);
            
    }
}
int main()
{
   int m,s,D;
   scanf("%d %d %d %d",&n,&m,&s,&D);
   for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        if(i!=j)g[i][j].len=inf;
    }
    for(int i=0;i<m;i++){
        int x,y,len,cost;
        scanf("%d %d %d %d",&x,&y,&len,&cost);
        g[x][y].len=g[y][x].len=len;
        g[x][y].cost=g[y][x].cost=cost;
    }
    dijk(s);
    printf("%d %d",d[D],cost[D]);
   return 0;
}
