#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
ll a[maxn];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
    cin>>n;
    ll mi=-1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        
    }
    ll mx=a[1];
    for(int i=2;i<=n;i++)
    {
        if(a[i]<mx)
        mi=max(mi,mx-a[i]);
        mx=max(a[i],mx);
    }
        if(mi==-1) {
            puts("0");
            continue;
        }
    //debug(mi);
        ll st=2;
        int ans=0;
        for(int i=1;i<=100;i++)
        {
            if(st-1>=mi)  {
                ans=i;
                break;
            }
            st=st*2;
        }
        cout<<ans<<endl;
    }
   

   //system("pause");
   return 0;
}
