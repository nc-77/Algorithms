#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const ll inf = (1LL<<62)+1;
const int maxn=2e6+10;
template<class T>inline void read(T &x) {
    x=0; int ch=getchar(),f=0;
    while(ch<'0'||ch>'9'){if (ch=='-') f=1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    if(f)x=-x;
}
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,47,53};
ll ans;
int type,k;
void dfs(int pos,ll value,ll num)
{
    if(num>k||pos>15) return;
    if(num==k) 
    {
        ans=min(ans,value);
        return;
    }
    for(int i=1;i<=63;i++)
    {
         if(value > ans/prime[pos] || num*(i+1)>k)
         break;
        value=value*prime[pos];
        if(k%(num*(i+1))==0)
        dfs(pos+1,value,num*(i+1));
    }
}
ll pnum[50000],s[50000];
map<ll,ll>pri;
void fac(ll n)
{
    for(int i=2;i<=n/i;i++)
    { 
          while(n%i==0)
        {
            pri[i]++;
            n=n/i;
        }
    }
    if(n>1) pri[n]++;
}
void work()
{
    for(int i=1;i<=60000;i++)
    {
        pri.clear();
        fac(i);
        pnum[i]=1;
        for(auto x:pri)
        {
            pnum[i]*=(x.second+1);
        }
        s[i]=inf;

    }
    for(ll i=1;i<=60000;i++)
    {
        s[i-pnum[i]]=min(s[i-pnum[i]],i);
    }
}
int main()
{  
   int t;
   read(t);
   
   work();
//    for(int ca=1;ca<=t;ca++)
//    {
       
//        read(type),read(k);
//        printf("Case %d: ", ca);
//         ans=inf;
        
//         if(type==0)
//         {
//             dfs(0,1,1);
//             if(ans>=inf) printf("INF\n");
//             else printf("%I64d\n", ans);
//         }
//         else
//         {
//             if(s[k]==inf)  printf("Illegal\n");
//             else printf("%d\n", s[k]);
//         }
        
//    }
   //system("pause");
   return 0;
}
