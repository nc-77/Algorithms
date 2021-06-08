#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int main()
{
   ll u,v;
   cin>>u>>v;
    if(u==v&&u==0)
    {
        puts("0");
        return 0;
    }
    if(u==v)
    {
        puts("1");
        cout<<u<<endl;
        return 0;
    }
    if(u>v) {puts("-1");return 0;};
    if((u-v)%2) {puts("-1");return 0;};
    ll x=(v-u)/2;
    
    if((u^x)==u+x)
    {
        puts("2");
        cout<<u+x<<" "<<x<<endl;
    }
    else 
    {
        puts("3");
        cout<<u<<" "<<x<<" "<<x<<endl;
    }
   //system("pause");
   return 0;
}
