#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn],mx[maxn];
map<int,int>mp;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int n,k,m;
       cin>>n>>m>>k;
       mp.clear();
       for(int i=1;i<=n;i++) mx[i]=0;
       for(int i=1;i<=n;i++) cin>>a[i];
       set<int>s;
       for(int i=1;i<=k;i++)
       {
           s.insert(a[i]);
           mp[a[i]]++;
           mx[1]=s.size();
       }
        int ans=mx[1];
        for(int i=2;i+k-1<=n;i++)
        {
            mx[i]=mx[i-1];
            if(--mp[a[i-1]]==0) mx[i]--;
            if(++mp[a[i+k-1]]==1) mx[i]++;
            ans=min(ans,mx[i]);
        }
        cout<<ans<<endl;
   }
   //system("pause");
   return 0;
}
