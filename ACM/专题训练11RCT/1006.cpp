#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll k,n;
map<ll,ll>vis;
int p[15];
struct node
{
    string num;
    ll m;
};
string ans;
void bfs()
{
    queue<node>que;
    for(int i=1;i<10;i++)
    {
        if(p[i]) continue;
        if(i%k==0) {
            ans=to_string(i);
            return;
        }
        if(!vis[i%k]) {
            que.push({to_string(i),i%k});
        vis[i%k]=1;
        }
    }
    while(!que.empty())
    {
        node now=que.front();
        que.pop();
        string num=now.num;
        ll m=now.m;
        
        if(m==0){
            ans=num;
            return;
        }
        for(int i=0;i<10;i++)
        {
            if(p[i]) continue;
            node nex;
            nex.num=num+to_string(i);
            nex.m=(((m%k)*10)%k+i%k)%k;
            if(nex.m==0)
            {
                ans=nex.num;
                return;
            }
            if(!vis[nex.m])
            {
                que.push(nex);
                vis[nex.m]=1;
                
            }
        }
    }
}
signed main()
{
   
    int ca=1;
    while(~scanf("%lld%lld", &k, &n))
    {
        vis.clear();
        set0(p);
        ans="";
        for(int i=1;i<=n;i++) 
        {
            int x;
            read(x);
            p[x]=1;
        }
        bfs();
        cout<<"Case "<<ca++<<": ";
        if(ans!="") cout<<ans<<endl;
        else cout<<-1<<endl;
    }
   //system("pause");
   return 0;
}
