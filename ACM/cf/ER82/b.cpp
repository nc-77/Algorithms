#include<bits/stdc++.h>
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
#define ll long long
using namespace std;
const int maxn=2e6+10;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n,a,b;
        cin>>n>>a>>b;
        ll x,y;
        if(n%2==0) x=n/2;
        else x=n/2+1;
        y=n-x;
        ll t=x/a;
        if(x%a!=0) t++;
        ll ans=(t-1)*(a+b)+x-(t-1)*a;
        if(b*(t-1)<y) ans+=y-b*(t-1);
        cout<<ans<<endl;
    }
}
