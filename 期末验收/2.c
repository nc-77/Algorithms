#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define inf 0x3f3f3f3f
int ch[1010];
int que[1010];
int n,m;
int tail,head,size;
int vis[1010];// 标记队列中已经被去除的元素
typedef struct solution
{
    char sol_ch[1010][1010]; //记录每个方案中每个字符的编码
}solution;

typedef struct node
{
    int flag;// 代表该节点为一个字符的编码 
    struct node *left,*right;
}node;

void read()
{
    /* 读入原字符 */
    scanf("%d",&n);
    for(int i=0;i<n;i++){
       char one_ch;
       int one_cnt;
       getchar();// 去上一行的回车
       scanf("%c %d",&one_ch,&one_cnt);
       ch[one_ch-'0']=one_cnt;
       que[tail++]=one_cnt;
       size++;
   }
}
/* 计算采取哈夫曼编码的情况下的最优解 */
int cul_ans(){
    int ans=0;
    while(size>0){
        if(size>=2){
           
        /* 找队列中最小的两个值xy */
            int x=inf,y=inf;
            int x_index,y_index;
            for(int i=head;i<tail;i++){
                if(vis[i]) continue;
                if(que[i]<x){
                    x=que[i];
                    x_index=i;
                }
            }
            vis[x_index]=1;
            for(int i=head;i<tail;i++){
                if(vis[i]) continue;
                if(que[i]<y){
                    y=que[i];
                    y_index=i;
                }
            }
            vis[y_index]=1;
            ans+=(x+y);
            size-=2;
        /* 让(x+y) 入队 */
            que[tail++]=(x+y);
            size+=1;
        }
        else if(size==1){
            int index=que[head];
            ans+=ch[index];
            size--;
        }
    }
    return ans;
}
/* 检查是否符合前缀编码 */
int check(char * s,node *T)
{

    int size=strlen(s);
    for(int i=0;i<size;i++)
    {
        if(s[i]=='0'){
            if(!T->left){
                node *tmp=(node *)malloc(sizeof(node));
                tmp->left=tmp->right=NULL;
                tmp->flag=0;
                T->left=tmp;
            }
            else{
                if(T->left->flag) {return 0;}
            }
            T=T->left;
        }
        else{
            if(!T->right){
                node *tmp=(node *)malloc(sizeof(node));
                tmp->left=tmp->right=NULL;
                tmp->flag=0;
                T->right=tmp;
            }
            else{
                if(T->right->flag) {return 0;}
            }
            T=T->right;
        }
    }
    if(T->right||T->left) return 0;
    T->flag=1;
    return 1;
}

int main()
{
   read();
   int ans=cul_ans();

   scanf("%d",&m);
   for(int i=0;i<m;i++){
       /* 读入并检查每个方案 */
        int res=0;
        int flag=1;
        solution Solution;
        /* 初始化01树 */
        node* root=(node *)malloc(sizeof(node));
        root->left=root->right=NULL;
       for(int j=0;j<n;j++){
           getchar(); //去上一行的回车
           char one_ch;
           scanf("%c",&one_ch);
           getchar();
           scanf("%s",Solution.sol_ch[one_ch-'0']);
           /* res统计总字节数 */
           res+=ch[one_ch-'0']*strlen(Solution.sol_ch[one_ch-'0']);
           if(flag) flag=check(Solution.sol_ch[one_ch-'0'],root); 
       }
       if(res==ans&&flag) puts("Yes");
       else puts("No");
   }

   return 0;
}
