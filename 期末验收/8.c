#include<stdio.h>
int g[105][105];/* 记录边 */
int in[105];/* 记录每个点的入读 */
int vis[105];/* 记录是否访问过 */
int que[105];/* 模拟队列 */
int n;
void bfs(){
    int tail=0,head=0,size=0;
    /* 将入度为0的点加入队列 */
    for(int i=1;i<=n;i++){
        if(!in[i]){
            que[tail++]=i;
            vis[i]=1;
            size++;
        }
        
    }
    while(size>0){
        /* 取出队头元素 */
        int top=que[head++];
        size--;
        for(int i=1;i<=n;i++){
            /* 删边 */
            if(g[top][i]){
                g[top][i]=0;
                in[i]--;
                /* 入度为0且没访问过就入队 */
                if(in[i]==0){
                    if(!vis[i]) {
                        que[tail++]=i;
                        vis[i]=1;
                        size++;
                    }
                }
            }
        }
        
    }
    return;
}
int main()
{

   scanf("%d",&n);
   for(int i=1;i<=n;i++){
       int k;
       scanf("%d",&k);
       in[i]=k;
       while(k--){
           int x;
           scanf("%d",&x);
           g[x][i]=1;
       }
   }
   bfs();
   /* sum表示所有点入度和 */
   int sum=0;
   for(int i=1;i<=n;i++){
       sum+=in[i];
   }
   if(sum) printf("0");
   else printf("1");
   return 0;
}
