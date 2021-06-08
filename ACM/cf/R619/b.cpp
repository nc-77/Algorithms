#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn=2e5+10;
ll a[maxn];
int vis[maxn];
ll ans[maxn];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {   set0(a);
        int n;
        cin>>n;
        int cnt=0;
        int maxx=0,min=0x3f,ans=-1;
        for(int i=1;i<n;i++)
        {cin>>a[i];
        if(a[i]!=-1&&a[i-1]==-1)
        {
            maxx=max(maxx,a[i]);
            minn=min(minn,a[i]);
        }

        }
        if(a[0]!=-1&&a[1]==-1)
        {
            maxx=max(maxx,a[0]);
            minn=min(minn,a[0]);
        }
        ans=(maxx+minn)/2;
        for(int i=1;i<n-1;i++)
        {
            if(a[i]==-1&&a[i-1]!=-1&&a[i+1]!=-1)
            {
                ans=max(ans,(a[i+1]-a[i-1])/2);
            }
        }
        int q=0;
        for(int i=0;i<n-1;i++)
        {
            if(a[i]==-1)  q=max(q,a[i+1]-a[i]);
        }
        for(int i=1;i<n;i++)
        {
            if(a[i]==-1)  q=max(q,a[i]-a[i-1]);
        }
        cout<<q<<" "<<ans<<endl;
    }
}
