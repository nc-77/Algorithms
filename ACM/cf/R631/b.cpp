#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn];
bool check(int x,int st,int ed)
{   map<ll,ll>mp;
    for(int i=st;i<=ed;i++)
    mp[a[i]]=1;
    for(int i=1;i<=x;i++) if(mp[i]!=1) return false;
    return true;
}
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n;
       cin>>n;
       int mx=0;
       for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
        int s1=0,s2=0,c1=0,c2=0;
        if(check(mx,1,mx)&&check(n-mx,mx+1,n)){c1=1;s1=mx;}
        if(check(n-mx,1,n-mx)&&check(mx,n-mx+1,n)){c2=1;s2=n-mx;}
        if(s1==s2) c2=0;
        cout<<c1+c2<<endl;
        if(c1) cout<<s1<<" "<<n-s1<<endl;
        if(c2) cout<<s2<<" "<<n-s2<<endl;
   }
   //system("pause");
   return 0;
}
