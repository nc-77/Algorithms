#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int n,s;
bool check(int x)
{
    if(x>=1&&x<=n-1) return false;
    if(x==s-n+1) return false;
    if(x>=s-n+2&&x<=s) return false;
    return true;
}
int main()
{
   //ios::sync_with_stdio(false);
   
   cin>>n>>s;
   int k=s/2;
   int x=s-k;
    if(check(k)&&check(x))
    {
        cout<<"YES"<<endl;
        for(int i=1;i<n;i++)
        cout<<1<<" ";
        cout<<s-n+1<<endl;
        cout<<k<<endl;
    }
    else cout<<"NO"<<endl;
   //system("pause");
   return 0;
}
