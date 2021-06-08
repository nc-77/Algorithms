#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e6+10;
int v[maxn],w[maxn],f[maxn],cnt[maxn];
int main()
{
    //freopen("in.txt","r",stdin);
    int sum,m,n,s;
   while(cin>>sum>>m>>n>>s)
   {    set0(f),set0(cnt);
       for(int i=1;i<=n;i++) cin>>v[i]>>w[i];
       for(int i=1;i<=n;i++)
    	for(int j=w[i];j<=m;j++)
        {
            f[j]=max(f[j],f[j-w[i]]+v[i]);
            if(f[j]==f[j-w[i]]+v[i]) cnt[j]=cnt[j-w[i]]+1;
        }
    	int flag=0;
        for(int i=1;i<=m;i++)
        {
            if(f[i]>=sum&&cnt[i]<=s)
            {
                flag=1;
                cout<<m-i<<endl;
                break;
            }
        }
        if(!flag) cout<<-1<<endl;
   }
}

