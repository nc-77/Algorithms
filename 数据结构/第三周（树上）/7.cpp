#include<iostream>
#include<vector>
#include<queue>
#define debug(x) cout<<#x<<'='<<x<<endl
using namespace std;
queue<int>que;
int fa[15];
vector<int>g[15];
void bfs()
{
    int flag=1;
    while(!que.empty())
    {   
         int cur=que.front();
        que.pop();
        if(g[cur].size()==0) 
        {
            if(!flag)cout<<" "<<cur;
        else cout<<cur,flag=0; 
        }
        for(int i=0;i<g[cur].size();i++)
        que.push(g[cur][i]);
    }
   
}
int main()
{
   int n;
   cin>>n;
   for(int i=0;i<n;i++) fa[i]=-1;
   for(int i=0;i<n;i++)
   {
       char l,r;
       cin>>l>>r;
       if(l!='-')g[i].push_back(l-'0'),fa[l-'0']=i;
       if(r!='-')g[i].push_back(r-'0'),fa[r-'0']=i;
   }
    for(int i=0;i<n;i++)
    {
        if(fa[i]==-1) {
            que.push(i);
            break;
        }
    }  
   bfs();
   return 0;
}
