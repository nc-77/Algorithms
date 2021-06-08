#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
struct node
{
    int s,w,num;
}a[maxn];
bool cmp(node x,node y){
    return x.s<y.s;
}
int par[maxn],dp[maxn];
int main()
{  int cnt=1;
   while(cin>>a[cnt].w>>a[cnt].s)
   {
       a[cnt].num=cnt;
       cnt++;
   }
    sort(a+1,a+cnt,cmp);
    cnt--;
    int ans=1;
    for(int i=1;i<=cnt;i++) dp[i]=1;
    for(int i=2;i<=cnt;i++)
    {
        for(int j=1;j<i;j++)
        {
            if(a[i].w<a[j].w&&a[i].s>a[j].s)
            {
                if(dp[j]+1>dp[i]) dp[i]=dp[j]+1,par[i]=j;
                ans=max(ans,dp[i]);
            }
        }
    }
        
    int m=1;
    for(int i=1;i<=cnt;i++) if(dp[i]==ans)  m=i;
    cout<<ans<<endl;
    while(m)
    {
        cout<<a[m].num<<endl;
        m=par[m];
    }
   //system("pause");
   return 0;
}
