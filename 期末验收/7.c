#include<stdio.h>
#define inf 0x3f3f3f3f
#define min(a,b) (a)<(b)?(a):(b)
int d[15][15];
int n,m;
/* floyd算法求解最短路 */
void floyd()
{
   for(int k=0;k<n;k++)
      for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
         d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
int vis[15];
int flag;
int start,end;
/* dfs判断能否从start到达end */
void dfs(int now)
{
   /* 标记过已到达的点 */
   vis[now]=1;
   /* 能到达标记 flag为1 */
   if(now==end) flag=1;
   /* flag为1后直接return */
   if(flag) return;
   for(int i=0;i<n;i++)
   {
      if(d[now][i]==1&&!vis[i]){
         dfs(i);
      }
   }
}
int main()
{
   
   scanf("%d%d",&n,&m);
   for(int i=0;i<m;i++)
   {
      int x,y;
      scanf("%d%d",&x,&y);
      d[x][y]=d[y][x]=1;
   }
   
   scanf("%d%d",&start,&end);
   /* 初始化距离 */
   for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
      {
         if(d[i][j]) continue;
         if(i==j) d[i][j]=0;
         else  d[i][j]=inf;
      }
         
   floyd();
   vis[start]=1;
   /* 判断能否从start到达end */
   dfs(start);
   
   if(!flag){
      printf("There is no path between %d and %d.",start,end);
   }
   else{
      printf("The length of the shortest path between %d and %d is %d.",start,end,d[start][end]);
   }
   return 0;
}
