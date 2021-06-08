#include<stdio.h>
#include<stdlib.h>
#define maxn 125000

typedef struct Es
{
   int from,to,cost;
   int equal,exist,del;
}Es;
int cmp(const void*a,const void*b)
{
    return (*(Es*)a).cost-(*(Es*)b).cost;
}
Es es[maxn];
int par[maxn];
int g[505][505];
int vis[maxn];
int n,m;
/* 并查集部分 */
void init(int n){
	for(int i=0;i<n;i++) par[i]=i;
} 
int find(int x)
{
	if(par[x]==x) return x;
	else return par[x]=find(par[x]);
}
void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return;
	par[x]=y;
}
int same(int x,int y){
	return find(x)==find(y);	
}
/* 最小生成树 */
int kruskal()
{
	
	init(n);
	int res=0;
	for(int i=0;i<m;i++)
	{
      if(es[i].del) continue;
		if(!same(es[i].from,es[i].to))
		{
			res+=es[i].cost;
         es[i].exist=1;
			unite(es[i].from,es[i].to);
		}
	}
	return res;
}
void dfs(int now){
   if(vis[now]) return;
   vis[now]=1;
   //printf("now=%d\n",now);
   for(int i=1;i<=n;i++){
      if(g[now][i]&&!vis[i]){
         //printf("i=%d\n",i);
         //vis[i]=1;
         dfs(i);
      }
   }
}
int main()
{
   scanf("%d %d",&n,&m);
   for(int i=0;i<m;i++){
      scanf("%d%d%d",&es[i].from,&es[i].to,&es[i].cost);
      g[es[i].from][es[i].to]=g[es[i].to][es[i].from]=es[i].cost;
   }
   if(m<1000){
      for(int i=0;i<m;i++){
      for(int j=0;j<m;j++){
         if(i!=j&&es[i].cost==es[j].cost)
            es[i].equal=es[j].equal=1;
      }
   }
   }
   
   // for(int i=1;i<=n;i++)
   //    for(int j=1;j<=n;j++)
   //    printf("g[%d][%d]=%d\n",i,j,g[i][j]);
   /* 判断是否连通 */
   int area=0;
   for(int i=1;i<=n;i++){
      if(!vis[i]){
         dfs(i);
         area++;
      }
   }
   /* 非联通情况 */
   if(area>1){
      printf("No MST\n%d\n",area);
      return 0;
   }
   /* 联通情况 */
   
   qsort(es,m,sizeof(Es),cmp);
   int ans=kruskal();
   if(m>1000){
      printf("%d\nNo",ans);
      return 0;
   }
   int flag=1;
   int res;
   for(int i=0;i<m;i++){
      if(es[i].equal&&es[i].exist){
         es[i].del=1;
         res=kruskal();
         es[i].del=0;
         if(res==ans) {
            flag=0;
            break;
         }
      }
   }
   printf("%d\n",ans);
   if(flag) puts("Yes");
   else puts("No");
}