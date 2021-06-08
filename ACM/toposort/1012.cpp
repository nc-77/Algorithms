#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e4+10;
int n,m,sum,in[maxn],par[maxn],u[maxn],v[maxn];
char op[maxn];
vector<int>g[maxn],topo;
int f1,f2;
int Find(int x)
{
    if(par[x]==x)
	return x;
	else
	return par[x]=Find(par[x]);
}
void unite(int x,int y)
{
    x=Find(x);
    y=Find(y);
    if(x==y) return;
    else if(x>y) par[y]=x;
    else par[x]=y;
}
void toposort()
{   topo.clear();
    priority_queue<int,vector<int>,greater<int>>que;
    for(int i=0;i<n;i++)
    {
        if(in[i]==0&&par[i]==i) que.push(i);
        if(que.size()>1) 
        {
            f1=0;
        }
    }
    while(!que.empty())
    {
        int u=que.top();
        topo.push_back(u);
        que.pop();
        for(int i=0;i<g[u].size();i++)
        {
            int v=g[u][i];
            in[v]--;
            if(in[v]==0) que.push(v);
            if(que.size()>1) 
            {
                f1=0;
            }
        }
    }
     if(topo.size()!=sum) f2=0;
     else f2=1;
}
int main()
{   
   while(cin>>n>>m)
   {    f1=f2=1;
       for(int i=0;i<=n;i++) g[i].clear(),in[i]=0,par[i]=i;
       for(int i=0;i<m;i++) 
       {
           scanf("%d %c %d",&u[i],&op[i],&v[i]);
           if(op[i]=='=') 
           {
               unite(u[i],v[i]);
           }
       }
       sum=0;
       for(int i=0;i<n;i++) if(par[i]==i) sum++;
       for(int i=0;i<m;i++)
       {  
           int x=Find(u[i]);
           int y=Find(v[i]);
           if(op[i]=='>')
           {
               if(x==y) f2=0;
               else if(x!=y)
               {
                   g[x].push_back(y);
                    in[y]++; 
               }     
           }
           else if(op[i]=='<') 
           {
               if(x==y) f2=0;
               else if(x!=y)
               {
                   g[y].push_back(x);
                    in[x]++; 
               }     
           }
          
       }
       //debug(f2);
       if(f2==0) 
       {
           cout<<"CONFLICT"<<endl;
           continue;
       }
        toposort();
        if(f2==0) cout<<"CONFLICT"<<endl;
        else if(f1==0) cout<<"UNCERTAIN"<<endl;
        else cout<<"OK"<<endl;
        
   }
   
   return 0;
}
