#include<stdio.h>
#include<string.h>
#define maxn 100000
#define inf 0x3f3f3f3f
int V,E;// 顶点数,边数
int d[maxn],vis[maxn];
int transfer[maxn];// 每个站点换乘次数
int pre[maxn],path[maxn]; // 记录前驱
int pos[maxn]; // 存储最终路径
int company[maxn]; // 每个站点由哪条路线过来
typedef struct edge
{
    int from,to,cost;
    int company;
}edge;
edge es[maxn];

void add_edge(int from,int to,int line){
    es[E].from=from;
    es[E].to=to;
    es[E].cost=1;
    es[E].company=line;
    E++;
}

void bellman_ford(int start){
    /* pre记录路径 */
    memset(pre,-1,sizeof(pre));
    memset(d,0x3f,sizeof(d));

    d[start]=0;

    for(int i=0;i<V;i++){
        /* flag标记本次是否更新 */
        int flag=0;
        for(int j=0;j<E;j++){
            edge e=es[j];
            if(d[e.to]>d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
                pre[e.to]=e.from;
                company[e.to]=e.company;
                transfer[e.to]=transfer[e.from];
                /* 需要换乘 */
                if(e.company!=company[e.from]){
                    transfer[e.to]++;
                }
                flag=1;
            }
            else if(d[e.to]==d[e.from]+e.cost){
                 /* 距离相同的情况下换乘次数更少则更新 */
                 if(transfer[e.to]>transfer[e.from]+(e.company!=company[e.from])){
                    company[e.to]=e.company;
                    pre[e.to]=e.from;
                    transfer[e.to]=transfer[e.from]+(e.company!=company[e.from]);
                    flag=1;
                }
                
            }
        }
        /* 如果此次没更新代表之后也不会更新,直接return */
        if(!flag) return;
    }
}
void get_path(int start,int end) //还原路径
{
    
	if(d[end]==inf){
        printf("Sorry, no line is available.\n");
        return;
    }
    /* path存储路径上的每个站点 
       pos存储需要换乘的站点 */
    int path_cnt=0 ,pos_cnt=0,tmp=end;
    

    /* 根据pre前驱记录还原path */
    while(1){
        path[path_cnt++]=tmp;
        if(pre[tmp]==-1) break;
        tmp=pre[tmp];
    }
    /* 根据path选取出需要换乘的站点 */
    pos[pos_cnt++]=start;
    for(int i=path_cnt-2;i>0;i--){
        if(company[path[i]]!=company[path[i-1]])
            pos[pos_cnt++]=path[i];
    }
    pos[pos_cnt++]=end;
    printf("%d\n",path_cnt-1);

    for(int i=0;i<pos_cnt-1;i++){
        printf("Go by the line of company #%d from %04d to %04d.\n",company[pos[i+1]],pos[i],pos[i+1]);
    }
}
int main()
{
   printf("Please enter information about Hangzhou Metro Station:\n");
   int n;
   scanf("%d",&n);
   for(int i=0;i<n;i++){
       printf("Line provided by company %d:\n",i);
       int k;
       scanf("%d",&k);
       V+=k;
       int pre_station=-1;
       /* 建图 */
       while(k--){
           int this_station;
           scanf("%4d",&this_station);
           if(pre_station!=-1){
               add_edge(pre_station,this_station,i+1);
               add_edge(this_station,pre_station,i+1);
           }
           pre_station=this_station;
       }
   }
   printf("Please enter the number of questions:\n");
   int Q;
   scanf("%d",&Q);
   while(Q--){
       printf("Please enter the start station and the end station:\n");
       int start,end;
       scanf("%4d%4d",&start,&end);
       bellman_ford(start);
       get_path(start,end);
   }
   return 0;
}
