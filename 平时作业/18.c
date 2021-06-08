#include<stdio.h>
typedef struct Node
{
    int left,right;
    int par;
    int lev;
    int val;
}Node;
typedef struct wuhu
{
    int flag;
    int a,b;
}wuhu;
wuhu Q[105000];
Node node[105000];
int hash[105000];
void insert(int x,int root)
{
    
    if(hash[x]>hash[root]){
        if(node[root].right==-1){
            node[root].right=x;
            node[x].par=root;
            node[x].lev=node[root].lev+1;
            return;
        }
        else insert(x,node[root].right);
    }
    else{
        if(node[root].left==-1){
            node[root].left=x;
            node[x].par=root;
            node[x].lev=node[root].lev+1;
            return;
        }
        else insert(x,node[root].left);
    }
}
int main()
{
   int n;
   scanf("%d",&n);
   int root;
   scanf("%d",&root);
   hash[0]=root;
   root=0;
   node[root].par=node[root].left=node[root].right=-1;
   node[root].lev=0;
   node[root].val=hash[root];
   for(int i=1;i<n;i++){
       int x;
       scanf("%d",&x);
       hash[i]=x;
       node[i].val=x;
        x=i;
       node[x].par=node[x].left=node[x].right=-1;
       insert(x,root);
   }
   int m;
   scanf("%d",&m);
   for(int i = 0; i < m; ++i)
    {

        char temp[50];
        scanf("%d %s ", &Q[i].a, temp);
        if(temp[0] == 'i')
        {
            scanf("%s %s", temp, temp);
            if(temp[0] == 'r' && temp[1] == 'o')
            {
                Q[i].b = Q[i].a;
                Q[i].flag = 1;
            }
            else
            {
                if(temp[0] == 'p')
                {
                    Q[i].flag = 3;
                    scanf(" %s %d", temp, &Q[i].b);
                }
                else if(temp[0] == 'l')
                {
                    Q[i].flag = 4;
                    scanf(" %s %s %d", temp, temp, &Q[i].b);
                }
                else if(temp[0] == 'r')
                {
                    Q[i].flag = 5;
                    scanf(" %s %s %d", temp, temp, &Q[i].b);
                }
            }
        }
        else if(temp[0] == 'a')
        {
            scanf("%d %s %s", &Q[i].b, temp, temp);
            if(temp[0] == 'o')
            {
                Q[i].flag = 6;
                scanf(" %s %s %s", temp, temp, temp);
            }
            else if(temp[0] == 's')
            {
                Q[i].flag = 2;
            }
        }
    }
   for(int i=0;i<m;i++){
       int a,b;
       a=Q[i].a;
       b=Q[i].b;
       int F=0;
       for(int j=0;j<n;j++){
           if(hash[j]==a){
               a=j;
               F++;
               break;
           }
       }
       for(int j=0;j<n;j++){
           if(hash[j]==b){
               b=j;
               F++;
               break;
           }
       }
       if(F!=2) {
           puts("No");
           continue;
       }
       if(Q[i].flag==1){
           if(a==root) puts("Yes");
           else puts("No");
       }
       else if(Q[i].flag==2){
           if(node[a].par==node[b].par) puts("Yes");
           else puts("No");
       }
       else if(Q[i].flag==3){
           if(node[b].par==a) puts("Yes");
           else puts("No");
       }
       else if(Q[i].flag==4){
           if(node[b].left==a) puts("Yes");
           else puts("No");
       }
       else if(Q[i].flag==5){
           if(node[b].right==a) puts("Yes");
           else puts("No");
       }
       else if(Q[i].flag==6){
           if(node[a].lev==node[b].lev) puts("Yes");
           else puts("No");
       }
       
   }
   return 0;
}
