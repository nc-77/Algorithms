#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
int n,k,m;
map<int,int>vis,pre;
map<int,char>op;
int mod(int a,int b)
{
    return (a%b+b)%b;
}
struct node
{
    int step,n;
}cur,nex;
void bfs()
{
    int tag=mod(n+1,k);
    
    queue<node>que;
    cur.step=0,cur.n=mod(n,m*k);
    que.push(cur);
    vis[cur.n]=1;
    op[cur.n]='#';
    while(!que.empty())
    {
        cur=que.front();
        que.pop();
        if(cur.n%k==tag) 
        {
            cout<<cur.step<<endl;
            string ans;
            //debug(op[cur.n]);
            while(op[cur.n]!='#')
            {
                //debug(cur.n);
                ans+=op[cur.n];
                cur.n=pre[cur.n];
            }
            reverse(ans.begin(),ans.end());
            cout<<ans<<endl;
            return;
            
        }
        nex.step=cur.step+1;
        for(int i=0;i<4;i++)
        {
            if(i==0) nex.n=mod(cur.n+m,m*k);
            else if(i==1) nex.n=mod(cur.n-m,m*k);
            else if(i==2) nex.n=mod(cur.n*m,m*k);
            else nex.n=mod(cur.n%m,m*k);
            if(!vis[nex.n]) 
            {
                que.push(nex);
                pre[nex.n]=cur.n;
                if(i==0) op[nex.n]='+';
                else if(i==1) op[nex.n]='-';
                else if(i==2) op[nex.n]='*';
                else op[nex.n]='%';
                vis[nex.n]=1;
                //debug(nex.n),debug(pre[nex.n]);
            }
        }

    }
    cout<<0<<endl;
}
signed main()
{
   //ios::sync_with_stdio(false);
    while(cin>>n>>k>>m)
    {
        if(!n&&!k&&!m) break;
        vis.clear(),pre.clear(),op.clear();
        bfs();
    }
   //system("pause");
   return 0;
}
