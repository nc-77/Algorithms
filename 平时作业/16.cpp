#include<iostream>
#include<queue>
#include<cstring>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
struct Node
{
    int L,R;
    int val;
}node[11];
int par[11];
void bfs(int root){
    queue<Node>que;
    que.push(node[root]);
    int first=0;
    while(!que.empty()){
        Node cur=que.front();
        que.pop();
        if(cur.L==-1&&cur.R==-1){
            if(!first)cout<<cur.val;
            else
                cout<<" "<<cur.val;
            first=1;
        }
        if(cur.L!=-1)que.push(node[cur.L]);
        if(cur.R!=-1)que.push(node[cur.R]);
    }
}
int main()
{
   int n;
   cin>>n;
   memset(par,-1,sizeof(par));
   for(int i=0;i<n;i++)
   {
       char ls,rs;
       cin>>ls>>rs;
       if(ls>='0'&&ls<='9'){
           node[i].L=ls-'0';
           par[ls-'0']=i;
       }
       else node[i].L=-1;
       if(rs>='0'&&rs<='9'){
           node[i].R=rs-'0';
           par[rs-'0']=i;
       }
       else node[i].R=-1;
       node[i].val=i;
   }
   int root;
    for(int i=0;i<n;i++){
        if(par[i]==-1){
            root=i;
            break;
        }
    }
    bfs(root);
   return 0;
}
