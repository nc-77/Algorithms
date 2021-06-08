#include<stdio.h>
#include<string.h>
#define inf 0x3f3f3f3f
int rescue[1010],g[505][505],pre[1010],vis[1010];
int d[505];
int sum[505],ans[505];
int n,m,s,D;
int path[505];
void printpath()
{
   int cnt;
   int tmp=D;
   while(1){
      
      path[cnt++]=tmp;
      tmp=pre[tmp];
      if(tmp==s) break;
   }
   printf("%d",s);
   for(int i=cnt-1;i>=0;i--){
      printf(" %d",path[i]);
   }
}
void dijkstra()
{
   memset(d,inf,sizeof(d));
   d[s]=0;
   sum[s]=1;
   for(int i=0;i<n;i++)
   {
      // 挑选距离最短的点P
      int MIN=inf;
      int p;
      for(int j=0;j<n;j++){
         if(!vis[j]&&d[j]<MIN){
            MIN=d[j];
            p=j;
         }
      }
      vis[p]=1;
      //printf("p=%d\n",p);
      // 对点P进行松弛操作
      for(int j=0;j<n;j++){
         if(!vis[j]&&d[p]+g[p][j]<d[j]){
            d[j]=d[p]+g[p][j];
            sum[j]=sum[p];
            pre[j]=p;
            ans[j]=ans[p]+rescue[j];
         }
         else if(!vis[j]&&d[p]+g[p][j]==d[j]){
            sum[j]+=sum[p];
            if(ans[p]+rescue[j]>ans[j]){
               pre[j]=p;
            ans[j]=ans[p]+rescue[j];
            }
         }

      }
      // for(int i=0;i<n;i++){
      //    printf("i=%d,ans=%d\n",i,ans[i]);
      // }
   }
}
int main()
{
   
   scanf("%d %d %d %d",&n,&m,&s,&D);
   for(int i=0;i<n;i++)
   scanf("%d",&rescue[i]);
   memset(g,inf,sizeof(g));
   for(int i=0;i<n;i++){
      ans[i]=rescue[i];

      g[i][i]=0;
   }
   
   for(int i=0;i<m;i++){
      int x,y;
      int cost;
      scanf("%d %d %d",&x,&y,&cost);
      g[x][y]=g[y][x]=cost;
   }

   dijkstra();
   //printf("%d\n",d[D]);
   printf("%d %d\n",sum[D],ans[D]);
   printpath();
   return 0;
}
