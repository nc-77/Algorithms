#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
#define int long long
#define mod 998244353
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[550][550],l[550][550];
signed main()
{
   ios::sync_with_stdio(false);
   int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) 
    {
        for(int j=1;j<=m;j++) 
        {
            cin>>a[i][j];
            a[i][j]%=mod;
        }
    }

    int ans=0;
    while(k--){
        char op;
        int x,t;
        cin>>op>>x>>t;
        if(op=='r'){
            for(int j=1;j<=m;j++)
            {
                ans=(ans+((t-l[x][j])%mod*a[x][j]%mod)%mod)%mod;
                l[x][j]=t;
            }
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                ans=(ans+((t-l[i][x])%mod*a[i][x]%mod)%mod)%mod;
                l[i][x]=t;
            }
        }
        
    }
    cout<<ans<<endl;
   //system("pause");
   return 0;
}
