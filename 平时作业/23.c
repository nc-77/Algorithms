#include<stdio.h>
#include<math.h>
#define maxn 50010
int n;
int root_cnt;
double g[maxn][3];
typedef struct Node
{
    int vis;
    int op;
    double number;
    int x,y;
}Node;

Node node[maxn];
int out[maxn];
int root[maxn];
double f2[maxn];
double f1[maxn];

void dfs(int now,int tag){
    if(node[now].vis)
        return;
    node[now].vis=1;
    
    int x=node[now].x;
    int y=node[now].y;
    if(node[now].op==0){
        f1[now]=node[now].number;
        f2[now]=(now==tag?1.0:0.0);
    }
    else if(node[now].op==1){
        dfs(x,tag);
        dfs(y,tag);
        f1[now]=f1[x]+f1[y];
        f2[now]=f2[x]+f2[y];
    }
    else if(node[now].op==2){

        dfs(x,tag);
        dfs(y,tag);
        f1[now]=f1[x]-f1[y];
        f2[now]=f2[x]-f2[y];
    } 
    else if(node[now].op==3){

        dfs(x,tag);
        dfs(y,tag);
        f1[now]=f1[x]*f1[y];
        f2[now]=f1[x]*f2[y]+f2[x]*f1[y];
    } 
    else if(node[now].op==4){
        dfs(x,tag);
        f1[now]=exp(f1[x]);
        f2[now]=exp(f1[x])*f2[x];
    } 
    else if(node[now].op==5){
        dfs(x,tag);
        f1[now]=log(f1[x]);
        f2[now]=f2[x]/f1[x];
    } 
    else if(node[now].op==6){
        dfs(x,tag);
        f1[now]=sin(f1[x]);
        f2[now]=cos(f1[x])*f2[x];
    } 
    //printf("f1[%d]=%3.lf\n",now,f1[now]);
}

int main()
{
   scanf("%d",&n);
   for(int i=0;i<n;i++){
      int op;
      scanf("%d",&op);
      node[i].op=op;
      if(op==0){
          scanf("%lf",&node[i].number);
          root[root_cnt++]=i;
      }
      else if(op==1||op==2||op==3){
          scanf("%d %d",&node[i].x,&node[i].y);
          out[node[i].x]++;
          out[node[i].y]++;
      }
      else{
          scanf("%d",&node[i].x);
          out[node[i].x]++;
      }
   }

   int out_node;

   for(int i=0;i<n;i++){
       if(!out[i]){
           out_node=i;
       }
   }
   //printf("out_node=%d\n",out_node);
   int first=1;
   for(int i=0;i<root_cnt;i++){
       for(int j=0;j<n;j++){
           node[j].vis=0;
       }
       dfs(out_node,root[i]);
       if(first){
           printf("%.3lf\n",f1[out_node]);
           printf("%.3lf",f2[out_node]);
           first=0;
       }
       else{
           printf(" %.3lf",f2[out_node]);
       }
       
   }
   return 0;
}
