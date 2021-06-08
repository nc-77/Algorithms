#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
map<ll,ll>mp;
#define int long long
signed main()
{
   
   //system("pause");
   int t;
   cin>>t;
   ll sum=1;
   for(ll i=1;i<=100100;i++) mp[i]=sum,sum+=i;
   while(t--)
   {
       ll n,k;
       cin>>n>>k;
       int x,y;
       string s;
       for(int i=1;i<=n;i++) s+='a';
       for(int i=1;i<=n;i++)
       {
          
            if(mp[i+1]>k)
            {   
                x=i;
                y=k-mp[x]+1;
                break;
            }
       }
       //debug(x),debug(y);
       s[n-x-1]='b';
       s[n-y]='b';
       cout<<s<<endl;
   }
   return 0;
}
