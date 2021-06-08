#include<bits/stdc++.h>
#define ll long long
#define debug(x) cout<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
//#define int long long
const int inf=0x3f3f3f3f;
const int maxn=2e6+10;
int a[maxn],b[maxn];
map<int,int>mp;
map<int,int>ans;
int main()
{
   //ios::sync_with_stdio(false);
   int n,st=0;
   cin>>n;
   for(int i=1;i<=n;i++) {
      cin>>a[i];
      mp[a[i]]=1;
   }
   for(int i=1;i<=n;i++) {
      cin>>b[i];
      mp[b[i]]=i-mp[b[i]];
   }
   int f=1;
   for(int i=1;i<=n;i++){
      ans[mp[i]]++;
      f=max(f,ans[mp[i]]);
   }
   cout<<f<<endl;
   //system("pause");
   return 0;
}
